#include <jni.h>
#include <android/bitmap.h>
#include <opencv2/core.hpp>
#include <opencv2/imgproc.hpp>

using namespace cv;

static void bitmapToMatARGB8888(JNIEnv* env, jobject bitmap, cv::Mat& out) {
    AndroidBitmapInfo info;
    void* pixels = nullptr;
    if (AndroidBitmap_getInfo(env, bitmap, &info) < 0) return;
    if (AndroidBitmap_lockPixels(env, bitmap, &pixels) < 0) return;
    out = cv::Mat(info.height, info.width, CV_8UC4, pixels);
}

static void unlockBitmap(JNIEnv* env, jobject bitmap) {
    AndroidBitmap_unlockPixels(env, bitmap);
}

extern "C" JNIEXPORT void JNICALL
Java_com_azurex_flam_1assignment1_MainActivity_processFrameNative(
        JNIEnv* env,
        jobject /* thiz */,
        jobject inputBitmap,
        jobject outputBitmap,
        jdouble threshold1,
        jdouble threshold2) {
    Mat inRgba;
    bitmapToMatARGB8888(env, inputBitmap, inRgba);

    if (inRgba.empty()) {
        return;
    }

    Mat gray, edges, outRgba;
    cvtColor(inRgba, gray, COLOR_RGBA2GRAY);
    Canny(gray, edges, (double)threshold1, (double)threshold2);
    cvtColor(edges, outRgba, COLOR_GRAY2RGBA);

    Mat outMat;
    bitmapToMatARGB8888(env, outputBitmap, outMat);
    if (!outMat.empty()) {
        if (outMat.size() != outRgba.size()) {
            // Resize to output size if needed
            cv::Mat resized;
            cv::resize(outRgba, resized, outMat.size());
            resized.copyTo(outMat);
        } else {
            outRgba.copyTo(outMat);
        }
        unlockBitmap(env, outputBitmap);
    }
    unlockBitmap(env, inputBitmap);
}