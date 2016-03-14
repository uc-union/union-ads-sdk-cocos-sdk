#ifndef _COM_UCWEB_UNION_ADS_SDK_ADERROR_
#define _COM_UCWEB_UNION_ADS_SDK_ADERROR_

#include <string>

namespace com_ucweb_union_ads_sdk{
class AdError
{
public:
static const int ERROR_CODE_NETWORK_ERROR = 1000;
static const int ERROR_CODE_NO_FILL = 1001;
static const int ERROR_CODE_INTERNAL_ERROR = 1002;
static const int ERROR_CODE_SERVER_ERROR = 1003;
static const int ERROR_CODE_REMOTE_CLOSED = 1004;

virtual int getErrorCode() const = 0;
virtual const std::string& getErrorMsg() const = 0;
};
}
#endif //_COM_UCWEB_UNION_ADS_SDK_ADERROR_
