package com.example.duanlei.ndkdemo;

import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.widget.TextView;
import android.widget.Toast;

import com.example.ndklib.NdkTest;

public class MainActivity extends AppCompatActivity {

    // Used to load the 'native-lib' library on application startup.
//    static {
//        System.loadLibrary("hello-lib");
//    }

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        // Example of a call to a native method
        TextView tv = (TextView) findViewById(R.id.sample_text);
        tv.setText(NdkTest.sayHelloWorld());

        String filePath = "/mnt/sdcard/boys.txt";
        Toast.makeText(this, filePath, Toast.LENGTH_SHORT).show();
        NdkTest.writeFile(filePath);

        //操作数组
        int[] testData = new int[]{1,2,3,4,5};
        NdkTest.operationArray(testData);

        //将传入的数组先拷贝一份，操作完以后再将数据拷贝回原数组
        int[] testData2 = new int[]{1,2,3,4,5};
        NdkTest.operationArray2(testData2);

    }

//    //自定义的native函数
//    public native String sayHelloWorld();
//
//    public native void writeFile(String filePath);
//
//    public native void operationArray(int[] args);
//
//    public native void operationArray2(int[] args);
}
