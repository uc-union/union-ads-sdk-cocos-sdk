#ifndef _COM_UCWEB_UNION_ADS_SDK_IMPL_JNICOMMON__
#define _COM_UCWEB_UNION_ADS_SDK_IMPL_JNICOMMON__

#if(CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
	#include <jni.h>
    #include "platform/android/jni/JniHelper.h"
#endif
#define  LOG_TAG    "UNION_ADS_SDK"
#define  LOGD(...)  __android_log_print(ANDROID_LOG_DEBUG,LOG_TAG,__VA_ARGS__)
#define  LOGE(...)  __android_log_print(ANDROID_LOG_ERROR,LOG_TAG,__VA_ARGS__)

namespace com_ucweb_union_ads_sdk{
using cocos2d::JniMethodInfo_;
class ScopedJniMethodInfo {
public:
	ScopedJniMethodInfo();
	~ScopedJniMethodInfo();
	JniMethodInfo_& get();
private:
	JniMethodInfo_ mInfo;
	ScopedJniMethodInfo(const ScopedJniMethodInfo&);
	ScopedJniMethodInfo& operator=(const ScopedJniMethodInfo&);
};
class ScopedJavaGlobalRef
{
public:
	ScopedJavaGlobalRef();
	void Reset(jobject javaObj);
	~ScopedJavaGlobalRef();
	jobject get() const;
private:
	jobject mJavaObj;
	ScopedJavaGlobalRef(const ScopedJavaGlobalRef&);
	ScopedJavaGlobalRef& operator=(const ScopedJavaGlobalRef&);
};

class Context
{
public:
  static jobject get();
};

jstring string2jstring(JNIEnv* env, const std::string& string);

}//com_ucweb_union_ads_sdk
using namespace cocos2d;
#endif //_COM_UCWEB_UNION_ADS_SDK_IMPL_JNICOMMON__