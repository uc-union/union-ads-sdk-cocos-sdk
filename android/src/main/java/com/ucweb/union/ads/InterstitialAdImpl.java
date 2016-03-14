package com.ucweb.union.ads;


import android.app.Activity;
import android.content.Context;

/**
 * Created by wangli on 1/18/16.
 */
public class InterstitialAdImpl extends InterstitialAd{
  private Activity mActivity;

  public InterstitialAdImpl(Context context) {
    super(context);
    mActivity = (Activity) context;
  }

  @Override
  public synchronized void loadAd(final AdRequest adRequest) {
    mActivity.runOnUiThread(new Runnable() {
      @Override
      public void run() {
        InterstitialAdImpl.super.loadAd(adRequest);
      }
    });
  }

  public void setAdListener(long listenerPtr) {
    setAdListener(new AdListenerProxy(listenerPtr));
  }
}
