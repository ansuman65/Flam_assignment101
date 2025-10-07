# Edge Detection Viewer (Android + OpenCV C++ + OpenGL + Web)

## Features
- Android Camera2 preview using `TextureView`
- JNI bridge to C++ with OpenCV Canny edge detection
- OpenGL ES 2.0 renderer displays processed frames as texture
- Minimal TypeScript web viewer to display a sample processed frame and FPS

## Android Setup
1. Install Android NDK via SDK Manager.
2. Ensure OpenCV Android SDK is installed; update `OpenCV_DIR` in `app/src/main/cpp/CMakeLists.txt` if needed.
3. Open project in Android Studio, let it sync, and run on device.
4. Place `libopencv_java4.so` in `app/src/main/jniLibs/<abi>/` (already included for `arm64-v8a` and `armeabi-v7a`).

## JNI / C++
- Native code in `app/src/main/cpp/native-lib.cpp`:
  - Converts `Bitmap` to `cv::Mat`, runs `Canny`, converts back to RGBA.
- Shared lib name: `flam_assignment1` (loaded in `MainActivity`).

## OpenGL
- `GLRenderer` renders a full-screen textured quad with the processed Bitmap.

## Web Viewer
- In `web/`, run:
  - `npm init -y` (once)
  - `npm i -D typescript`
  - `npx tsc`
  - Open `web/index.html` in a browser. Edit the inline `placeholder` string to a base64 PNG to preview.

## Repo / Submission
- Commit regularly with meaningful messages.
- Include screenshots or a GIF in this README when ready.

## Notes
- Package: `com.azurex.flam_assignment1`.
- App name: "Edge Detection Viewer".
- Min SDK 24, Camera permission requested at runtime.

