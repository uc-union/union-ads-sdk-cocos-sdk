#ifndef _COM_UCWEB_UNION_ADS_SDK_ADREQUEST_
#define _COM_UCWEB_UNION_ADS_SDK_ADREQUEST_

#include <string>
class _jobject;

namespace com_ucweb_union_ads_sdk{
	class AdRequest 
	{
	public:
        virtual ~AdRequest(){}
        virtual _jobject* asJavaObject() const = 0;
        class Params {
            public:
                virtual ~Params(){}
                virtual _jobject* asJavaObject() const = 0;
        };
        class Builder{
            public:
                virtual ~Builder(){}
                virtual Builder& pub(const std::string& pub) = 0;
                virtual Builder& testDeviceId(const std::string& testDeviceId) = 0;
                virtual Builder& withParams(const Params& param) = 0;
                virtual AdRequest& build() = 0;
        };
        static Builder& newBuilder();
	};
}
#endif //_COM_UCWEB_UNION_ADS_SDK_ADREQUEST_
