#include "JNICommon.h"

namespace com_ucweb_union_ads_sdk {

   jobject Context::get() {
		ScopedJniMethodInfo info;
		JniMethodInfo_& rawInfo = info.get();
	    if( JniHelper::getStaticMethodInfo(rawInfo
	                                       , "org.cocos2dx.lib.Cocos2dxActivity"
	                                       , "getContext"
	                                       , "()Landroid/content/Context;")) {
	        jobject context = rawInfo.env->CallStaticObjectMethod(rawInfo.classID, rawInfo.methodID);
	        return context;
	    } else {
	        LOGE("Failed to get context!");
	    }	
   }

   	ScopedJniMethodInfo::ScopedJniMethodInfo(){}
	ScopedJniMethodInfo::~ScopedJniMethodInfo()
	{
		if(mInfo.classID){
			//mInfo.env->DeleteLocalRef(mInfo.classID);
			mInfo.classID = 0;
		}
	}
	JniMethodInfo_& ScopedJniMethodInfo::get(){
		return mInfo;
	}

	ScopedJavaGlobalRef::ScopedJavaGlobalRef():mJavaObj(0){}

	void ScopedJavaGlobalRef::Reset(jobject javaObj) {
		mJavaObj =  JniHelper::getEnv()->NewGlobalRef(javaObj);
	}
	ScopedJavaGlobalRef::~ScopedJavaGlobalRef() {
		if(mJavaObj){
			JniHelper::getEnv()->DeleteGlobalRef(mJavaObj);
		}
	}

	jobject ScopedJavaGlobalRef::get() const{
		return mJavaObj;
	}
	jstring string2jstring(JNIEnv* env, const std::string& string) {
		return env->NewStringUTF(string.c_str());
	}
}