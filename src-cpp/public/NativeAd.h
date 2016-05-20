#ifndef _COM_UCWEB_UNION_ADS_SDK_NATIVEAD_
#define _COM_UCWEB_UNION_ADS_SDK_NATIVEAD_
#include <string>
#include <vector>
#include "Ad.h"
namespace com_ucweb_union_ads_sdk{
	class AdListener;
	class AdRequest;
	class NativeAdImpl;
	class Image{
	public:
		Image():mWidth(0), mHeight(0), mUrl(""){}
		Image(int w, int h, const std::string& url):mWidth(w), mHeight(h), mUrl(url){}
		Image(const Image& other){
			mWidth = other.mWidth;
			mHeight = other.mHeight;
			mUrl = other.mUrl;
		}
		Image& operator=(const Image& other){
			mWidth = other.mWidth;
			mHeight = other.mHeight;
			mUrl = other.mUrl;
		}
		int getWidth() const { return mWidth; }
		int getHeight() const { return mHeight; }
		bool isValid() const { return mWidth != 0 && mHeight != 0; }
		const std::string& getUrl() const { return mUrl; }

	private:
		int mWidth;
		int mHeight;
		std::string mUrl;
	};
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
        const std::vector<Image>& getCovers() const;
        const Image filterImageBySize(int width, int height) const;
	private:
		NativeAd(const NativeAd&);
		NativeAd& operator=(const NativeAd&);
		NativeAdImpl* mImpl;
	};
}
#endif //_COM_UCWEB_UNION_ADS_SDK_NATIVEAD_