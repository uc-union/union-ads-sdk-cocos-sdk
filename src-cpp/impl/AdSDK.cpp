#include "AdSDK.h"
#include "JNICommon.h"

namespace com_ucweb_union_ads_sdk{
using cocos2d::JniHelper;
void AdSDK::init()
{
  
	ScopedJniMethodInfo info;
	JniMethodInfo_& rawInfo = info.get();
  
    if( JniHelper::getStaticMethodInfo(rawInfo
                                       , "com.ucweb.union.ads.UnionAdsSdk"
                                       , "start"
                                       , "(Landroid/content/Context;)V")) {

        rawInfo.env->CallStaticVoidMethod(rawInfo.classID, rawInfo.methodID, Context::get());
    } else {
       LOGE("Failed to get method MediationSdk.start!");
    }	
    
}

}//com_ucweb_union_ads_sdk