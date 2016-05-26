#include "Util.h"
#include "JNICommon.h"

namespace com_ucweb_union_ads_sdk{
using cocos2d::JniHelper;
int Util::dp2Pixel(int dp)
{
  
	ScopedJniMethodInfo info;
	JniMethodInfo_& rawInfo = info.get();
  
    if( JniHelper::getStaticMethodInfo(rawInfo
                                       , "com.ucweb.union.ads.Util"
                                       , "dip2px"
                                       , "(Landroid/content/Context;I)I")) {

        return rawInfo.env->CallStaticIntMethod(rawInfo.classID, rawInfo.methodID, Context::get(), dp);
    } else {
       LOGE("Failed to get method Util.dp2Pixel!");
    }	
    return dp;
}

}//com_ucweb_union_ads_sdk