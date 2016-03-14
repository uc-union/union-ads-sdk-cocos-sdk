#ifndef _COM_UCWEB_UNION_ADS_SDK_AD_
#define _COM_UCWEB_UNION_ADS_SDK_AD_

namespace com_ucweb_union_ads_sdk{
	class AdListener;
	class AdRequest;
	class Ad 
	{
	public:
      virtual ~Ad(){}
      virtual void setListener(AdListener* listener) = 0;
      virtual void load(const AdRequest& request) = 0;
      virtual void stopLoading() = 0;
	};
}
#endif //_COM_UCWEB_UNION_ADS_SDK_AD_
