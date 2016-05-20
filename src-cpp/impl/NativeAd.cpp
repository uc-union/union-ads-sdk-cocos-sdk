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
  if(mTitle.empty()) {
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
  }
  return mTitle;
}
const std::string& getDescrption() const{
  if(mDescription.empty()) {
    ScopedJniMethodInfo info;
    JniMethodInfo_& rawInfo = info.get();
    if( JniHelper::getMethodInfo(rawInfo
                                   , "com.ucweb.union.ads.NativeAdAssets"
                                   , "getDescription"
                                   , "()Ljava/lang/String;")) {
       jstring ret = (jstring)rawInfo.env->CallObjectMethod(mJavaObj.get(), rawInfo.methodID);
       mDescription = JniHelper::jstring2string(ret);
    } else {
        LOGE("Failed to get method NativeAdImpl.NativeAdImpl!");
    }
  }
    return mDescription;
}
const std::string& getIconUrl() const{
  if(mIconUrl.empty()) {
    ScopedJniMethodInfo info;
    JniMethodInfo_& rawInfo = info.get();
    if( JniHelper::getStaticMethodInfo(rawInfo
                                   , "com.ucweb.union.ads.NativeAdImpl"
                                   , "getIconUrl"
                                   , "(Lcom/ucweb/union/ads/NativeAdAssets;)Ljava/lang/String;")) {
       jstring ret = (jstring)rawInfo.env->CallStaticObjectMethod(rawInfo.classID, rawInfo.methodID, mJavaObj.get());
       mIconUrl = JniHelper::jstring2string(ret);
    } else {
        LOGE("Failed to get method NativeAdImpl.getIconUrl!");
    }
  }
  return mIconUrl;
}
const std::vector<Image>& getCovers() const {
  if(mCovers.empty()){
    int count = getCoverCount();
    for(int i = 0;i < count; ++i) {
      mCovers.push_back(getCoverAt(i));
    }
  }
  return mCovers;
}
const Image filterImageBySize(int width, int height) const {
    ScopedJniMethodInfo info;
    JniMethodInfo_& rawInfo = info.get();
    if( JniHelper::getStaticMethodInfo(rawInfo
                                   , "com.ucweb.union.ads.NativeAdImpl"
                                   , "filterImageBySize"
                                   , "(Lcom/ucweb/union/ads/NativeAdAssets;II)Lcom/ucweb/union/ads/NativeAdAssets$Image;")) {
       jobject obj = rawInfo.env->CallStaticObjectMethod(rawInfo.classID, rawInfo.methodID, mJavaObj.get(), width, height);
       if(obj) {
         int w = getImageWidth(obj);
         int h = getImageHeight(obj);
         const std::string& imageUrl = getImageUrl(obj);
         return Image(w, h, imageUrl);
       }
       else{
         LOGE("Filter no img match specified size!");
       }
    } else {
        LOGE("Failed to get method NativeAdImpl.getCoverCount!");
    }
    return Image();
}
private:
  int getCoverCount() const{
    ScopedJniMethodInfo info;
    JniMethodInfo_& rawInfo = info.get();
    if( JniHelper::getStaticMethodInfo(rawInfo
                                   , "com.ucweb.union.ads.NativeAdImpl"
                                   , "getCoverCount"
                                   , "(Lcom/ucweb/union/ads/NativeAdAssets;)I")) {
       return rawInfo.env->CallStaticIntMethod(rawInfo.classID, rawInfo.methodID, mJavaObj.get());
    } else {
        LOGE("Failed to get method NativeAdImpl.getCoverCount!");
    }
    return 0;
  }
  Image getCoverAt(int index) const{
    ScopedJniMethodInfo info;
    JniMethodInfo_& rawInfo = info.get();
    if( JniHelper::getStaticMethodInfo(rawInfo
                                   , "com.ucweb.union.ads.NativeAdImpl"
                                   , "getCoverAt"
                                   , "(Lcom/ucweb/union/ads/NativeAdAssets;I)Lcom/ucweb/union/ads/NativeAdAssets$Image;")) {
       jobject obj =  rawInfo.env->CallStaticObjectMethod(rawInfo.classID, rawInfo.methodID, mJavaObj.get(), index);
       if(obj) {
         int w = getImageWidth(obj);
         int h = getImageHeight(obj);
         const std::string& imageUrl = getImageUrl(obj);
         return Image(w, h, imageUrl);
       }
       else{
         LOGE("invalid img!");
       }
    } else {
        LOGE("Failed to get method NativeAdImpl.getCoverAt!");
    }
    return Image();
  }

  static int getImageWidth(jobject javaImg) {
    ScopedJniMethodInfo info;
    JniMethodInfo_& rawInfo = info.get();
    if( JniHelper::getMethodInfo(rawInfo
                                   , "com/ucweb/union/ads/NativeAdAssets$Image"
                                   , "getWidth"
                                   , "()I")) {
       return rawInfo.env->CallIntMethod(javaImg, rawInfo.methodID);
    } else {
        LOGE("Failed to get method Image.getWidth!");
    }
    return 0;
  }

  static int getImageHeight(jobject javaImg) {
    ScopedJniMethodInfo info;
    JniMethodInfo_& rawInfo = info.get();
    if( JniHelper::getMethodInfo(rawInfo
                                   , "com/ucweb/union/ads/NativeAdAssets$Image"
                                   , "getHeight"
                                   , "()I")) {
       return rawInfo.env->CallIntMethod(javaImg, rawInfo.methodID);
    } else {
        LOGE("Failed to get method Image.getHeight!");
    }
    return 0;
  }

  static std::string getImageUrl(jobject javaImg) {
    ScopedJniMethodInfo info;
    JniMethodInfo_& rawInfo = info.get();
    if( JniHelper::getMethodInfo(rawInfo
                                   , "com/ucweb/union/ads/NativeAdAssets$Image"
                                   , "getUrl"
                                   , "()Ljava/lang/String;")) {
       jstring url =  (jstring)rawInfo.env->CallObjectMethod(javaImg, rawInfo.methodID);
       return JniHelper::jstring2string(url);
    } else {
        LOGE("Failed to get method Image.getUrl!");
    }
    return "";
  }
private:
  ScopedJavaGlobalRef mJavaObj;
  mutable std::string mTitle;
  mutable std::string mDescription;
  mutable std::string mIconUrl;
  mutable std::string mCoverUrl;
  mutable std::vector<Image> mCovers;
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
const std::vector<Image>& getCovers() const {
  return mNativeAdAssets->getCovers();
}
const Image filterImageBySize(int width, int height) const {
  return mNativeAdAssets->filterImageBySize(width, height);
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
const std::vector<Image>& NativeAd::getCovers() const {
 return mImpl->getCovers();
}
const Image NativeAd::filterImageBySize(int width, int height) const {
 return mImpl->filterImageBySize(width, height);  
}
}//com_ucweb_union_ads_sdk