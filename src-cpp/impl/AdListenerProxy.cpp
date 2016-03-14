#include <jni.h>
#include <string>

#include "JNICommon.h"
#include "AdListener.h"
#include "AdError.h"

using namespace com_ucweb_union_ads_sdk;
namespace
{
class AdErrorImpl : public AdError
{
public:
	AdErrorImpl(jobject javaObj){
		mJavaObj.Reset(javaObj);
	}
    virtual int getErrorCode() const override {
    	ScopedJniMethodInfo info;
		JniMethodInfo_& rawInfo = info.get();
	    if( JniHelper::getMethodInfo(rawInfo
	                                   , "com.ucweb.union.ads.AdError"
	                                   , "getErrorCode"
	                                   , "()I")) {

	        return rawInfo.env->CallIntMethod(mJavaObj.get(), rawInfo.methodID);
	    } else {
	        LOGE("Failed to get method AdError.getErrorCode!");
	        return -1;
	    }
    }
    virtual const std::string& getErrorMsg() const override {
    	if(mErrorMsg.empty()) {
	    	ScopedJniMethodInfo info;
			JniMethodInfo_& rawInfo = info.get();
		    if( JniHelper::getMethodInfo(rawInfo
		                                   , "com.ucweb.union.ads.AdError"
		                                   , "getErrorMessage"
		                                   , "()Ljava/lang/String;")) {

		        jstring jstringValue = (jstring)rawInfo.env->CallObjectMethod(mJavaObj.get(), rawInfo.methodID);
		    	mErrorMsg = JniHelper::jstring2string(jstringValue);
		    } else {
		        LOGE("Failed to get method AdError.getErrorMessage!");
		        mErrorMsg = "no error msg";
		    }
		}
	    return mErrorMsg;
    }
private:
	ScopedJavaGlobalRef mJavaObj;
	mutable std::string mErrorMsg;
};
}//namespace



#ifdef __cplusplus
extern "C" {
#endif
/*
 * Class:     com_ucweb_union_ads_AdListenerProxy
 * Method:    nativeOnAdLoaded
 * Signature: (J)V
 */
JNIEXPORT void JNICALL Java_com_ucweb_union_ads_AdListenerProxy_nativeOnAdLoaded
  (JNIEnv *, jobject, jlong nativePtr){
  	AdListener* listener = reinterpret_cast<AdListener*>(nativePtr);
  	listener->onLoaded();
  }

/*
 * Class:     com_ucweb_union_ads_AdListenerProxy
 * Method:    nativeOnAdClosed
 * Signature: (J)V
 */
JNIEXPORT void JNICALL Java_com_ucweb_union_ads_AdListenerProxy_nativeOnAdClosed
  (JNIEnv *, jobject, jlong nativePtr){
  	AdListener* listener = reinterpret_cast<AdListener*>(nativePtr);
  	listener->onClosed();
  }

/*
 * Class:     com_ucweb_union_ads_AdListenerProxy
 * Method:    nativeOnAdOpened
 * Signature: (J)V
 */
JNIEXPORT void JNICALL Java_com_ucweb_union_ads_AdListenerProxy_nativeOnAdOpened
  (JNIEnv *, jobject, jlong nativePtr){
  	AdListener* listener = reinterpret_cast<AdListener*>(nativePtr);
  	listener->onOpened();
  }

/*
 * Class:     com_ucweb_union_ads_AdListenerProxy
 * Method:    nativeOnAdClicked
 * Signature: (J)V
 */
JNIEXPORT void JNICALL Java_com_ucweb_union_ads_AdListenerProxy_nativeOnAdClicked
  (JNIEnv *, jobject, jlong nativePtr){
  	AdListener* listener = reinterpret_cast<AdListener*>(nativePtr);
  	listener->onClicked();
  }

  /*
 * Class:     com_ucweb_union_ads_AdListenerProxy
 * Method:    nativeOnAdError
 * Signature: (JLcom/ucweb/union/ads/AdError;)V
 */
JNIEXPORT void JNICALL Java_com_ucweb_union_ads_AdListenerProxy_nativeOnAdError
  (JNIEnv *, jobject, jlong nativePtr, jobject error){
  	  	AdListener* listener = reinterpret_cast<AdListener*>(nativePtr);
  	listener->onError(AdErrorImpl(error));
  }

#ifdef __cplusplus
}
#endif
