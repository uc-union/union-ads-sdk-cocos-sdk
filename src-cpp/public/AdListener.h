#ifndef _COM_UCWEB_UNION_ADS_SDK_ADLISTENER_
#define _COM_UCWEB_UNION_ADS_SDK_ADLISTENER_

namespace com_ucweb_union_ads_sdk{
	class AdError;
	class AdListener 
	{
	public:
	    virtual	~AdListener(){};
        virtual void onLoaded() = 0;
        virtual void onClosed() = 0;
        virtual void onOpened() = 0;
        virtual void onClicked() = 0;
        virtual void onError(const AdError& error) = 0;

	};
}
#endif //_COM_UCWEB_UNION_ADS_SDK_ADLISTENER_
