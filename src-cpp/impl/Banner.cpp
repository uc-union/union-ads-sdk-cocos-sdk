#include "Banner.h"
#include "JNICommon.h"
#include "AdListener.h"
#include "AdRequest.h"

namespace com_ucweb_union_ads_sdk {

class BannerImpl {
public:
BannerImpl():mRequest(0)
{
	ScopedJniMethodInfo info;
	JniMethodInfo_& rawInfo = info.get();
    if( JniHelper::getMethodInfo(rawInfo
                                   , "com.ucweb.union.ads.BannerAdViewImpl"
                                   , "<init>"
                                   , "(Landroid/content/Context;)V")) {
        mJavaBanner.Reset(rawInfo.env->NewObject(rawInfo.classID, rawInfo.methodID, Context::get()));
    } else {
        LOGE("Failed to get method BannerAdViewImpl.BannerAdViewImpl!");
    }
}
~BannerImpl()
{
  if(mRequest){
    delete mRequest;
  }
}
void setShowRect(int x, int y, int w, int h) {
  ScopedJniMethodInfo info;
  JniMethodInfo_& rawInfo = info.get();
    if( JniHelper::getMethodInfo(rawInfo
                                   , "com.ucweb.union.ads.BannerAdViewImpl"
                                   , "setShowRect"
                                   , "(IIII)V")) {
        rawInfo.env->CallVoidMethod(mJavaBanner.get(), rawInfo.methodID, x, y, w, h);
    } else {
        LOGE("Failed to get method BannerAdViewImpl.setShowRect!");
    }
}
void show() {
    ScopedJniMethodInfo info;
    JniMethodInfo_& rawInfo = info.get();
    if( JniHelper::getMethodInfo(rawInfo
                                   , "com.ucweb.union.ads.BannerAdViewImpl"
                                   , "show"
                                   , "()V")) {
        rawInfo.env->CallVoidMethod(mJavaBanner.get(), rawInfo.methodID);
    } else {
        LOGE("Failed to get method BannerAdViewImpl.show!");
    }
}
void setListener(AdListener* listener){
    ScopedJniMethodInfo info;
    JniMethodInfo_& rawInfo = info.get();
    if( JniHelper::getMethodInfo(rawInfo
                                   , "com.ucweb.union.ads.BannerAdViewImpl"
                                   , "setAdListener"
                                   , "(J)V")) {
        rawInfo.env->CallVoidMethod(mJavaBanner.get(), rawInfo.methodID, reinterpret_cast<jlong>(listener));
    } else {
        LOGE("Failed to get method BannerAdViewImpl.setAdListener!");
    }
}
void load(const AdRequest& request){
  if(mRequest){
    delete mRequest;
  }
  mRequest = &request;
	ScopedJniMethodInfo info;
	JniMethodInfo_& rawInfo = info.get();
    if( JniHelper::getMethodInfo(rawInfo
                                   , "com.ucweb.union.ads.BannerAdViewImpl"
                                   , "loadAd"
                                   , "(Lcom/ucweb/union/ads/AdRequest;)V")) {
        rawInfo.env->CallVoidMethod(mJavaBanner.get(), rawInfo.methodID, request.asJavaObject());
    } else {
        LOGE("Failed to get method BannerAdViewImpl.loadAd!");
    }
}
void stopLoading(){
    ScopedJniMethodInfo info;
    JniMethodInfo_& rawInfo = info.get();
    if( JniHelper::getMethodInfo(rawInfo
                                   , "com.ucweb.union.ads.BannerAdViewImpl"
                                   , "stopLoading"
                                   , "()V")) {
        rawInfo.env->CallVoidMethod(mJavaBanner.get(), rawInfo.methodID);
    } else {
        LOGE("Failed to get method BannerAdViewImpl.stopLoading!");
    }
}

private:
	ScopedJavaGlobalRef mJavaBanner;
  const AdRequest* mRequest;
};//BannerImpl

Banner::Banner(): mImpl(new BannerImpl()){
}
Banner::~Banner(){
	delete mImpl;
}
void Banner::show()
{
  mImpl->show();
}
void Banner::setShowRect(int x, int y, int w, int h)
{
  mImpl->setShowRect(x, y, w, h);
}
//should be a weak reference
void Banner::setListener(AdListener* listener){
	mImpl->setListener(listener);
}
void Banner::load(const AdRequest& request){
	mImpl->load(request);
}
void Banner::stopLoading(){
	mImpl->stopLoading();
}

}//com_ucweb_union_ads_sdk
