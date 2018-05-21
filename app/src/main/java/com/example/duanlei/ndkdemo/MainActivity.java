package com.example.duanlei.ndkdemo;

import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.widget.TextView;
import android.widget.Toast;

public class MainActivity extends AppCompatActivity {

    // Used to load the 'native-lib' library on application startup.
    static {
        System.loadLibrary("hello-lib");
    }

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        // Example of a call to a native method
        TextView tv = (TextView) findViewById(R.id.sample_text);
        tv.setText(sayHelloWorld());

        String filePath = "/mnt/sdcard/boys.txt";
        Toast.makeText(this, filePath, Toast.LENGTH_SHORT).show();
        writeFile(filePath);

    }

    //自定义的native函数
    public native String sayHelloWorld();

    public native void writeFile(String filePath);
}
