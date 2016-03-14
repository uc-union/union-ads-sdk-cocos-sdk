#ifndef _COM_UCWEB_UNION_ADS_SDK_NATIVEAD_REQUEST_PARAM_BUILDER_
#define _COM_UCWEB_UNION_ADS_SDK_NATIVEAD_REQUEST_PARAM_BUILDER_
namespace com_ucweb_union_ads_sdk{
	class NativeAdRequestBuilder
	{
	public:
	 	virtual ~NativeAdRequestBuilder(){}
	 	virtual NativeAdRequestBuilder& requestExternalResource(bool flag) = 0;
	 	virtual NativeAdRequestBuilder& requestCoverImageSize(int width, int height) = 0;
	 	virtual AdRequest::Builder* build() = 0;
	};
}
#endif //_COM_UCWEB_UNION_ADS_SDK_NATIVEAD_REQUEST_PARAM_BUILDER_