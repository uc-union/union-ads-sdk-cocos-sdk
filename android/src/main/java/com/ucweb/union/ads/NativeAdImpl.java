package com.ucweb.union.ads;

import android.app.Activity;
import android.content.Context;

/**
 * Created by wangli on 1/18/16.
 */
public class NativeAdImpl extends NativeAd {
  private Activity mActivity;

  public NativeAdImpl(Context context) {
    super(context);
    mActivity = (Activity) context;
  }

  @Override
  public synchronized void loadAd(final AdRequest adRequest) {
    mActivity.runOnUiThread(new Runnable() {
      @Override
      public void run() {
        NativeAdImpl.super.loadAd(adRequest);
      }
    });

  }

  public void setAdListener(long listenerPtr) {
    setAdListener(new AdListenerProxy(listenerPtr));
  }

  public static String getIconUrl(NativeAdAssets assets) {
    if (assets.getIcon() == null) {
      return "";
    }
    return assets.getIcon().getUrl();
  }

  public static String getCoverUrl(NativeAdAssets assets) {
    if (assets.getCover() == null) {
      return "";
    }
    return assets.getCover().getUrl();
  }
}
