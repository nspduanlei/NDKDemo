package com.example.ndklib;

public class NdkTest {

    static {
        System.loadLibrary("hello-lib");
    }

    //自定义的native函数
    public static native String sayHelloWorld();

    public static native void writeFile(String filePath);

    public static native void operationArray(int[] args);

    public static native void operationArray2(int[] args);
}
