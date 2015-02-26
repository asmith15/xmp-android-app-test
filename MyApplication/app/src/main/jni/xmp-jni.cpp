#include <jni.h>

#define UNIX_ENV 1 // for XMP_Environment.h

#include <string>
#define XMP_INCLUDE_XMPFILES 1 //if using XMPFiles
#define TXMP_STRING_TYPE std::string
/**
 * Clients must compile XMP.incl_cpp to ensure that all client-side glue code is generated. Do this by
 * including it in exactly one of your source files.
 * This has to happen before the #include "XMP.hpp" below
 */
#include "XMP.incl_cpp"

#include "XMP.hpp"

const char* doSomeXMPStuffInCPP()
{
    SXMPMeta::Initialize();
}

extern "C" {

    jstring
    Java_com_example_andrew_myapplication_XMPlib_doSomeXMPStuff( JNIEnv* env,
                                                                 jobject thiz )
    {
        if(!SXMPMeta::Initialize())
        {
            return env->NewStringUTF("Could not initialize SXMPMeta");
        }
        // This returns true but causes the app to crash like this:
        // 02-25 18:27:12.852    2960-2960/com.example.andrew.myapplication A/libc﹕ Fatal signal 6 (SIGABRT), code -6 in tid 2960 (w.myapplication)
        /*if (!SXMPFiles::Initialize())
        {
            return env->NewStringUTF("Could not initialize SXMPFiles.");
        }*/

        // Do XMP stuff here

	//SXMPFiles::Terminate();
	//SXMPMeta::Terminate();

        return env->NewStringUTF("XMP toolkit seems to be working!");
    }
}
