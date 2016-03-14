#include "NativeAd.h"
#include "JNICommon.h"
#include "AdListener.h"
#include "AdRequest.h"

namespace com_ucweb_union_ads_sdk {
namespace {
class NativeAdAsset
{
public:
NativeAdAsset(jobject javaObj) {
  mJavaObj.Reset(javaObj);
}
const std::string& getTitle() const{
  ScopedJniMethodInfo info;
  JniMethodInfo_& rawInfo = info.get();
    if( JniHelper::getMethodInfo(rawInfo
                                   , "com.ucweb.union.ads.NativeAdAssets"
                                   , "getTitle"
                                   , "()Ljava/lang/String;")) {
       jstring ret = (jstring)rawInfo.env->CallObjectMethod(mJavaObj.get(), rawInfo.methodID);
       mTitle = JniHelper::jstring2string(ret);
    } else {
        LOGE("Failed to get method NativeAdImpl.NativeAdImpl!");
    }
    return mTitle;
}
const std::string& getDescrption() const{
  ScopedJniMethodInfo info;
  JniMethodInfo_& rawInfo = info.get();
    if( JniHelper::getMethodInfo(rawInfo
                                   , "com.ucweb.union.ads.NativeAdAssets"
                                   , "getDescription"
                                   , "()Ljava/lang/String;")) {
       jstring ret = (jstring)rawInfo.env->CallObjectMethod(mJavaObj.get(), rawInfo.methodID);
       mTitle = JniHelper::jstring2string(ret);
    } else {
        LOGE("Failed to get method NativeAdImpl.NativeAdImpl!");
    }
    return mTitle;
}
const std::string& getIconUrl() const{
  ScopedJniMethodInfo info;
  JniMethodInfo_& rawInfo = info.get();
    if( JniHelper::getStaticMethodInfo(rawInfo
                                   , "com.ucweb.union.ads.NativeAdImpl"
                                   , "getIconUrl"
                                   , "(Lcom/ucweb/union/ads/NativeAdAssets;)Ljava/lang/String;")) {
       jstring ret = (jstring)rawInfo.env->CallStaticObjectMethod(rawInfo.classID, rawInfo.methodID, mJavaObj.get());
       mTitle = JniHelper::jstring2string(ret);
    } else {
        LOGE("Failed to get method NativeAdImpl.getIconUrl!");
    }
    return mTitle;
}
const std::string& getCoverUrl() const{
  ScopedJniMethodInfo info;
  JniMethodInfo_& rawInfo = info.get();
    if( JniHelper::getStaticMethodInfo(rawInfo
                                   , "com.ucweb.union.ads.NativeAdImpl"
                                   , "getCoverUrl"
                                   , "(Lcom/ucweb/union/ads/NativeAdAssets;)Ljava/lang/String;")) {
       jstring ret = (jstring)rawInfo.env->CallStaticObjectMethod(rawInfo.classID, rawInfo.methodID, mJavaObj.get());
       mTitle = JniHelper::jstring2string(ret);
    } else {
        LOGE("Failed to get method NativeAdImpl.getCoverUrl!");
    }
    return mTitle;
}
private:
  ScopedJavaGlobalRef mJavaObj;
  mutable std::string mTitle;
  mutable std::string mDescription;
  mutable std::string mIconUrl;
  mutable std::string mCoverUrl;
};

}//namespace

class NativeAdImpl {
public:
NativeAdImpl():mNativeAdAssets(0), mRequest(0)
{
	ScopedJniMethodInfo info;
	JniMethodInfo_& rawInfo = info.get();
    if( JniHelper::getMethodInfo(rawInfo
                                   , "com.ucweb.union.ads.NativeAdImpl"
                                   , "<init>"
                                   , "(Landroid/content/Context;)V")) {
        mJavaNativeAd.Reset(rawInfo.env->NewObject(rawInfo.classID, rawInfo.methodID, Context::get()));
    } else {
        LOGE("Failed to get method NativeAdImpl.NativeAdImpl!");
    }
}
~NativeAdImpl()
{
  if(mNativeAdAssets){
    delete mNativeAdAssets;
  }
  if(mRequest){
    delete mRequest;
  }
}
void setListener(AdListener* listener){
    ScopedJniMethodInfo info;
    JniMethodInfo_& rawInfo = info.get();
    if( JniHelper::getMethodInfo(rawInfo
                                   , "com.ucweb.union.ads.NativeAdImpl"
                                   , "setAdListener"
                                   , "(J)V")) {
        rawInfo.env->CallVoidMethod(mJavaNativeAd.get(), rawInfo.methodID, reinterpret_cast<jlong>(listener));
    } else {
        LOGE("Failed to get method NativeAdImpl.setAdListener!");
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
                                   , "com.ucweb.union.ads.NativeAdImpl"
                                   , "loadAd"
                                   , "(Lcom/ucweb/union/ads/AdRequest;)V")) {
        rawInfo.env->CallVoidMethod(mJavaNativeAd.get(), rawInfo.methodID, request.asJavaObject());
    } else {
        LOGE("Failed to get method NativeAdImpl.loadAd!");
    }
}
void stopLoading(){
    ScopedJniMethodInfo info;
  JniMethodInfo_& rawInfo = info.get();
    if( JniHelper::getMethodInfo(rawInfo
                                   , "com.ucweb.union.ads.NativeAdImpl"
                                   , "stopLoading"
                                   , "()V")) {
        rawInfo.env->CallVoidMethod(mJavaNativeAd.get(), rawInfo.methodID);
    } else {
        LOGE("Failed to get method NativeAdImpl.stopLoading!");
    }
}

const std::string& getTitle() const{
  return mNativeAdAssets->getTitle();
}
const std::string& getDescription() const{
  return mNativeAdAssets->getDescrption();
}
const std::string& getIconUrl() const{
  return mNativeAdAssets->getIconUrl();
}
const std::string& getCoverUrl() const{
  return mNativeAdAssets->getCoverUrl();
}

void onLoaded() {
  ScopedJniMethodInfo info;
  JniMethodInfo_& rawInfo = info.get();
    if( JniHelper::getMethodInfo(rawInfo
                                   , "com.ucweb.union.ads.NativeAdImpl"
                                   , "getNativeAdAssets"
                                   , "()Lcom/ucweb/union/ads/NativeAdAssets;")) {
        jobject nativeAdAssetObj = rawInfo.env->CallObjectMethod(mJavaNativeAd.get(), rawInfo.methodID);
        mNativeAdAssets = new NativeAdAsset(nativeAdAssetObj);
    } else {
        LOGE("Failed to get method NativeAdImpl.getNativeAdAssets!");
    }
}
  
private:
  NativeAdAsset* mNativeAdAssets;
	ScopedJavaGlobalRef mJavaNativeAd;
  const AdRequest* mRequest;
};//NativeAdImpl


namespace {

class AdListenerInterceptor : public AdListener{
public:
  AdListenerInterceptor(AdListener * listener, NativeAdImpl& nativeAdImpl):mAdListener(listener), mNativeAdImpl(nativeAdImpl){

  }
  virtual ~AdListenerInterceptor(){

  }
  virtual void onLoaded() override{
    mNativeAdImpl.onLoaded();
    if(mAdListener)
    {
      mAdListener->onLoaded();
    }
  }
  virtual void onClosed() override{
    if(mAdListener)
    {
      mAdListener->onClosed();
    }
  }
  virtual void onOpened() override{
    if(mAdListener)
    {
      mAdListener->onOpened();
    }
  }
  virtual void onClicked() override{
    if(mAdListener)
    {
      mAdListener->onClicked();
    }
  }
  virtual void onError(const AdError& error) override{
    if(mAdListener)
    {
      mAdListener->onError(error);
    }
  }
private:
  AdListener* mAdListener;
  NativeAdImpl& mNativeAdImpl;
};
} //namespace

NativeAd::NativeAd(): mImpl(new NativeAdImpl()){
}
NativeAd::~NativeAd(){
	delete mImpl;
}
//should be a weak reference
void NativeAd::setListener(AdListener* listener){
	mImpl->setListener(new AdListenerInterceptor(listener, *mImpl));
}
void NativeAd::load(const AdRequest& request){
	mImpl->load(request);
}
void NativeAd::stopLoading(){
	mImpl->stopLoading();
}
const std::string& NativeAd::getTitle() const{
  return mImpl->getTitle();
}
const std::string& NativeAd::getDescription() const{
  return mImpl->getDescription();
}
const std::string& NativeAd::getIconUrl() const{
  return mImpl->getIconUrl();
}
const std::string& NativeAd::getCoverUrl() const{
  return mImpl->getCoverUrl();
}
}//com_ucweb_union_ads_sdk