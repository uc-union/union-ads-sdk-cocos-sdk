package com.ucweb.union.ads;

import android.app.Activity;
import android.content.Context;

import java.util.List;

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

  public static int getCoverCount(NativeAdAssets assets) {
    List<NativeAdAssets.Image> covers = assets.getCovers();
    if (covers == null) {
      return 0;
    }
    return covers.size();
  }

  public static NativeAdAssets.Image getCoverAt(NativeAdAssets assets, int index) {
    List<NativeAdAssets.Image> covers = assets.getCovers();
    if (covers == null) {
      return null;
    }
    if (index >= covers.size()) {
      return null;
    }
    return covers.get(index);
  }

  public static NativeAdAssets.Image filterImageBySize(NativeAdAssets assets,
                                                       int width,
                                                       int height) {
    return ImageFilter.filter(assets.getCovers(), width, height);
  }
}
