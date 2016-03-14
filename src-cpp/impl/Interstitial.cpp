#include "Interstitial.h"
#include "JNICommon.h"
#include "AdListener.h"
#include "AdRequest.h"

namespace com_ucweb_union_ads_sdk {

class InterstitialImpl {
public:
InterstitialImpl():mRequest(0)
{
	ScopedJniMethodInfo info;
	JniMethodInfo_& rawInfo = info.get();
    if( JniHelper::getMethodInfo(rawInfo
                                   , "com.ucweb.union.ads.InterstitialAdImpl"
                                   , "<init>"
                                   , "(Landroid/content/Context;)V")) {
      mJavaInterstitial.Reset(rawInfo.env->NewObject(rawInfo.classID, rawInfo.methodID, Context::get()));
    } else {
        LOGE("Failed to get method InterstitialAdImpl.InterstitialAdImpl!");
    }
}
~InterstitialImpl()
{
  if(mRequest){
    delete mRequest;
  }
}
void show() {
  ScopedJniMethodInfo info;
  JniMethodInfo_& rawInfo = info.get();
    if( JniHelper::getMethodInfo(rawInfo
                                   , "com.ucweb.union.ads.InterstitialAdImpl"
                                   , "show"
                                   , "()V")) {
        rawInfo.env->CallVoidMethod(mJavaInterstitial.get(), rawInfo.methodID);
    } else {
        LOGE("Failed to get method InterstitialAdImpl.show!");
    }
}
void setListener(AdListener* listener){
    ScopedJniMethodInfo info;
    JniMethodInfo_& rawInfo = info.get();
    if( JniHelper::getMethodInfo(rawInfo
                                   , "com.ucweb.union.ads.InterstitialAdImpl"
                                   , "setAdListener"
                                   , "(J)V")) {
        rawInfo.env->CallVoidMethod(mJavaInterstitial.get(), rawInfo.methodID, reinterpret_cast<jlong>(listener));
    } else {
        LOGE("Failed to get method InterstitialAdImpl.setAdListener!");
    }
}
void load(const AdRequest& request){
  if(mRequest) {
    delete mRequest;
  }
  mRequest = &request;
	ScopedJniMethodInfo info;
	JniMethodInfo_& rawInfo = info.get();
    if( JniHelper::getMethodInfo(rawInfo
                                   , "com.ucweb.union.ads.InterstitialAdImpl"
                                   , "loadAd"
                                   , "(Lcom/ucweb/union/ads/AdRequest;)V")) {
        rawInfo.env->CallVoidMethod(mJavaInterstitial.get(), rawInfo.methodID, request.asJavaObject());
    } else {
        LOGE("Failed to get method InterstitialAdImpl.loadAd!");
    }
}
void stopLoading(){
    ScopedJniMethodInfo info;
  JniMethodInfo_& rawInfo = info.get();
    if( JniHelper::getMethodInfo(rawInfo
                                   , "com.ucweb.union.ads.InterstitialAdImpl"
                                   , "stopLoading"
                                   , "()V")) {
        rawInfo.env->CallVoidMethod(mJavaInterstitial.get(), rawInfo.methodID);
    } else {
        LOGE("Failed to get method InterstitialAdImpl.stopLoading!");
    }
}

private:
	ScopedJavaGlobalRef mJavaInterstitial;
  const AdRequest* mRequest;
};//InterstitialImpl

Interstitial::Interstitial(): mImpl(new InterstitialImpl()){
}
Interstitial::~Interstitial(){
	delete mImpl;
}
void Interstitial::show()
{
  mImpl->show();
}
//should be a weak reference
void Interstitial::setListener(AdListener* listener){
	mImpl->setListener(listener);
}
void Interstitial::load(const AdRequest& request){
	mImpl->load(request);
}
void Interstitial::stopLoading(){
	mImpl->stopLoading();
}

}//com_ucweb_union_ads_sdk
