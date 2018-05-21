//
// Created by duanlei on 2018/5/21.
//
#include <jni.h>
#include <stdio.h>
#include <string.h>

JNIEXPORT jstring JNICALL
Java_com_example_duanlei_ndkdemo_MainActivity_sayHelloWorld(JNIEnv *env, jobject instance) {
    return (*env)->NewStringUTF(env, "hello world!!!!!!!!");
}

JNIEXPORT void JNICALL
Java_com_example_duanlei_ndkdemo_MainActivity_writeFile(JNIEnv *env, jobject instance,
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