plugins {
    alias(libs.plugins.android.application)
}

android {
    namespace = "com.azurex.flam_assignment1"
    compileSdk = 35

    defaultConfig {
        applicationId = "com.azurex.flam_assignment1"
        minSdk = 24
        targetSdk = 35
        versionCode = 1
        versionName = "1.0"

        testInstrumentationRunner = "androidx.test.runner.AndroidJUnitRunner"
        externalNativeBuild {
            cmake {
                cppFlags += "-std=c++17"
                // Supply OpenCV_DIR from local.properties (opencv.dir)
                val props = java.util.Properties()
                val lp = rootProject.file("local.properties")
                if (lp.exists()) {
                    props.load(java.io.FileInputStream(lp))
                    val ocv = props.getProperty("opencv.dir")
                    if (ocv != null) {
                        val norm = ocv.replace('\\', '/')
                        arguments += listOf("-DOpenCV_DIR=${norm}/sdk/native/jni")
                    }
                }
            }
        }
    }

    buildTypes {
        release {
            isMinifyEnabled = false
            proguardFiles(
                getDefaultProguardFile("proguard-android-optimize.txt"),
                "proguard-rules.pro"
            )
        }
    }
    compileOptions {
        sourceCompatibility = JavaVersion.VERSION_11
        targetCompatibility = JavaVersion.VERSION_11
    }
    externalNativeBuild {
        cmake {
            path = file("src/main/cpp/CMakeLists.txt")
            version = "3.22.1"
        }
    }
    buildFeatures {}
}

dependencies {
    implementation(libs.jvm.core)
    implementation(libs.androidx.appcompat)
    implementation(libs.material)
    implementation(libs.androidx.constraintlayout)
    testImplementation(libs.junit)
    androidTestImplementation(libs.androidx.junit)
    androidTestImplementation(libs.androidx.espresso.core)
}