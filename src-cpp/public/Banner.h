#ifndef _COM_UCWEB_UNION_ADS_SDK_BANNER_
#define _COM_UCWEB_UNION_ADS_SDK_BANNER_
#include "Ad.h"

namespace com_ucweb_union_ads_sdk{
	class AdListener;
	class AdRequest;
	class BannerImpl;
	class Banner : public Ad
	{
	public:
		Banner();
	 	~Banner();
        void setShowRect(int x, int y, int w, int h);
        void setShowPosition(int x, int y);
        void show();
        void setListener(AdListener* listener) override;
        void load(const AdRequest& request) override;
        void stopLoading() override;
	private:
		Banner(const Banner&);
		Banner& operator=(const Banner&);
		BannerImpl* mImpl;
	};
}
#endif //_COM_UCWEB_UNION_ADS_SDK_BANNER_