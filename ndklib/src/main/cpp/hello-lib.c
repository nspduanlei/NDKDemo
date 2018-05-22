//
// Created by duanlei on 2018/5/21.
//
#include <jni.h>
#include <stdio.h>
#include <string.h>
#include <android/log.h>


//log定义
#define  LOG    "JNILOG" // 这个是自定义的LOG的TAG
#define  LOGD(...)  __android_log_print(ANDROID_LOG_DEBUG,LOG,__VA_ARGS__) // 定义LOGD类型
#define  LOGI(...)  __android_log_print(ANDROID_LOG_INFO,LOG,__VA_ARGS__) // 定义LOGI类型
#define  LOGW(...)  __android_log_print(ANDROID_LOG_WARN,LOG,__VA_ARGS__) // 定义LOGW类型
#define LOGE(...)  __android_log_print(ANDROID_LOG_ERROR,LOG,__VA_ARGS__) // 定义LOGE类型
#define LOGF(...)  __android_log_print(ANDROID_LOG_FATAL,LOG,__VA_ARGS__) // 定义LOGF类型


JNIEXPORT jstring JNICALL
Java_com_example_ndklib_NdkTest_sayHelloWorld(JNIEnv *env, jobject instance) {
    return (*env)->NewStringUTF(env, "hello world!!!!!!!!");
}

JNIEXPORT void JNICALL
Java_com_example_ndklib_NdkTest_writeFile(JNIEnv *env, jobject instance,
                                                        jstring filePath_) {
    const char *filePath = (*env)->GetStringUTFChars(env, filePath_, 0);

    FILE *file = fopen(filePath, "a+");

    char data[] = "I am a boy";

    fwrite(data, strlen(data), 1, file);

    if (file != NULL) {
        fclose(file);
    }

    (*env)->ReleaseStringUTFChars(env, filePath_, filePath);
}

JNIEXPORT void JNICALL
Java_com_example_ndklib_NdkTest_operationArray(JNIEnv *env, jobject instance,
                                                             jintArray args_) {

    //获得数组指针
    jint *args = (*env)->GetIntArrayElements(env, args_, NULL);

    //获得数组长度
    jint len = (*env)->GetArrayLength(env, args_);
    for (int i = 0; i < len; ++i) {
        ++args[i];
    }

    (*env)->ReleaseIntArrayElements(env, args_, args, 0);
}

JNIEXPORT void JNICALL
Java_com_example_ndklib_NdkTest_operationArray2(JNIEnv *env, jobject instance,
                                                              jintArray args_) {
    //声明一个native层的数组， 用于拷贝原数组
    jint nativeArray[5];

    //将传入的 jintArray数组拷贝到 nativeArray
    (*env)->GetIntArrayRegion(env, args_, 0, 5, nativeArray);

    for (int i = 0; i < 5; ++i) {
        //给每个元素加5
        nativeArray[i] += 5;
    }

    LOGE("我是log---------------------");


    //将操作完成的结果拷贝回jintArray
    (*env)->SetIntArrayRegion(env, args_, 0, 5, nativeArray);


}