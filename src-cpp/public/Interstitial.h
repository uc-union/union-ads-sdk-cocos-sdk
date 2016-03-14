#ifndef _COM_UCWEB_UNION_ADS_SDK_INTERSTITIAL_
#define _COM_UCWEB_UNION_ADS_SDK_INTERSTITIAL_

#include "Ad.h"

namespace com_ucweb_union_ads_sdk {
	class AdListener;
	class AdRequest;
	class InterstitialImpl;
	class Interstitial : public Ad
	{
	public:
		Interstitial();
	 	~Interstitial();
	 	void show();
        virtual void setListener(AdListener* listener) override;
        virtual void load(const AdRequest& request) override;
        virtual void stopLoading() override;
	private:
		Interstitial(const Interstitial&);
		Interstitial& operator=(const Interstitial&);
		InterstitialImpl* mImpl;
	};
}
#endif //_COM_UCWEB_UNION_ADS_SDK_INTERSTITIAL_