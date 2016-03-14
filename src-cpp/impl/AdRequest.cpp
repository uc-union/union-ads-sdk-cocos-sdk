#include "AdRequest.h"
#include "JNICommon.h"

namespace com_ucweb_union_ads_sdk{
namespace {
using Builder = AdRequest::Builder;
using Params = AdRequest::Params;
class AdRequestImpl : public AdRequest{
public:
	AdRequestImpl(jobject javaObj,  const Builder* builder):mBuilder(builder){
		mJavaObj.Reset(javaObj);
	}
    virtual ~AdRequestImpl(){
    	if(mBuilder)
    	{
    		delete mBuilder;
    	}
    }
    virtual jobject asJavaObject() const override {
    	return mJavaObj.get();
    }
private:
	ScopedJavaGlobalRef mJavaObj;
    const Builder* mBuilder;
};

class BuilderImpl : public Builder
{
public:
	BuilderImpl(jobject obj){
		mJavaObj.Reset(obj);
	}
    virtual ~BuilderImpl(){}
    virtual Builder& pub(const std::string& _pub) override {
    	ScopedJniMethodInfo info;
		JniMethodInfo_& rawInfo = info.get();
	    if( JniHelper::getMethodInfo(rawInfo
	                                   , "com.ucweb.union.ads.AdRequest$Builder"
	                                   , "pub"
	                                   , "(Ljava/lang/String;)Lcom/ucweb/union/ads/AdRequest$Builder;")) {
	    	jstring pub = string2jstring(rawInfo.env, _pub);
	        rawInfo.env->CallObjectMethod(mJavaObj.get(), rawInfo.methodID, pub);
	    } else {
	        LOGE("Failed to get method Builder.pub!");
	    }
	    return *this;
    }
    virtual Builder& testDeviceId(const std::string& _testDeviceId) override {
    	ScopedJniMethodInfo info;
		JniMethodInfo_& rawInfo = info.get();
	    if( JniHelper::getMethodInfo(rawInfo
	                                   , "com.ucweb.union.ads.AdRequest$Builder"
	                                   , "testDeviceId"
	                                   , "(Ljava.lang.String;)Lcom/ucweb/union/ads/AdRequest$Builder;")) {
	    	jstring testDeviceId = string2jstring(rawInfo.env, _testDeviceId);
	        rawInfo.env->CallObjectMethod(mJavaObj.get(), rawInfo.methodID, testDeviceId);
	    } else {
	        LOGE("Failed to get method Builder.testDeviceId!");
	    }
	    return *this;
    }
    virtual Builder& withParams(const Params& param) override {
    	ScopedJniMethodInfo info;
		JniMethodInfo_& rawInfo = info.get();
	    if( JniHelper::getMethodInfo(rawInfo
	                                   , "com.ucweb.union.ads.AdRequest$Builder"
	                                   , "withOption"
	                                   , "(Lcom/ucweb/union/ads/AdRequestOption;)Lcom/ucweb/union/ads/AdRequest$Builder;")) {
	        rawInfo.env->CallObjectMethod(mJavaObj.get(), rawInfo.methodID, param.asJavaObject());
	    } else {
	        LOGE("Failed to get method Builder.withOption!");
	    }
	    return *this;
    }
    //should return scoped_ptr<AdRequest>
    virtual AdRequest& build() override{
    	jobject javaAdRequest = 0;
    	ScopedJniMethodInfo info;
		JniMethodInfo_& rawInfo = info.get();
	    if( JniHelper::getMethodInfo(rawInfo
	                                   , "com.ucweb.union.ads.AdRequest$Builder"
	                                   , "build"
	                                   , "()Lcom/ucweb/union/ads/AdRequest;")) {
	        javaAdRequest = rawInfo.env->CallObjectMethod(mJavaObj.get(), rawInfo.methodID);
	    } else {
	        LOGE("Failed to get method Builder.build!");
	    }
    	AdRequest* request = new AdRequestImpl(javaAdRequest, this);
    	return *request;
    }
private:
	ScopedJavaGlobalRef mJavaObj;
};
}
Builder& AdRequest::newBuilder() {

	jobject javaBuilder = 0;
	ScopedJniMethodInfo info;
	JniMethodInfo_& rawInfo = info.get();
    if( JniHelper::getStaticMethodInfo(rawInfo
                                       , "com.ucweb.union.ads.AdRequest"
                                       , "newBuilder"
                                       , "()Lcom/ucweb/union/ads/AdRequest$Builder;")) {

        javaBuilder = rawInfo.env->CallStaticObjectMethod(rawInfo.classID, rawInfo.methodID);
    } else {
        LOGE("Failed to get method AdRequest.newBuilder!");
    }
	Builder* builder = new BuilderImpl(javaBuilder);
	return *builder;

}

}//com_ucweb_union_ads_sdks