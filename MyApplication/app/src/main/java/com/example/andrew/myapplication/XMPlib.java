package com.example.andrew.myapplication;

import android.util.Log;

public class XMPlib
{
    public void test()
    {
        Log.d("Test", doSomeXMPStuff());
    }

    public native String  doSomeXMPStuff();

    static {
        System.loadLibrary("xmp-jni");
    }
}
