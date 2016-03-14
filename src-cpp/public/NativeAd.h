#ifndef _COM_UCWEB_UNION_ADS_SDK_NATIVEAD_
#define _COM_UCWEB_UNION_ADS_SDK_NATIVEAD_
#include <string>
#include "Ad.h"
namespace com_ucweb_union_ads_sdk{
	class AdListener;
	class AdRequest;
	class NativeAdImpl;
	class NativeAd : public Ad
	{
	public:
		NativeAd();
	 	~NativeAd();
        void setListener(AdListener* listener) override;
        void load(const AdRequest& request) override;
        void stopLoading() override;

        const std::string& getTitle() const;
        const std::string& getDescription() const;
        const std::string& getIconUrl() const;
        const std::string& getCoverUrl() const;

	private:
		NativeAd(const NativeAd&);
		NativeAd& operator=(const NativeAd&);
		NativeAdImpl* mImpl;
	};
}
#endif //_COM_UCWEB_UNION_ADS_SDK_NATIVEAD_