package com.ucweb.union.ads;

import android.app.Activity;
import android.content.Context;
import android.view.ViewGroup;
import android.widget.FrameLayout;


/**
 * Created by wangli on 1/18/16.
 */
public class BannerAdViewImpl extends BannerAdView {
  private Activity mActivity;

  public BannerAdViewImpl(Context context) {
    super(context);
    mActivity = (Activity) context;
  }

  @Override
  public synchronized void loadAd(final AdRequest adRequest) {
    mActivity.runOnUiThread(new Runnable() {
      @Override
      public void run() {
        BannerAdViewImpl.super.loadAd(adRequest);
      }
    });
  }

  private int mX;
  private int mY;
  private int mW;
  private int mH;

  public void setShowRect(int x, int y, int w, int h) {
    mX = x;
    mY = y;
    mW = w;
    mH = h;
  }

  public void show() {
    mActivity.runOnUiThread(new Runnable() {
      @Override
      public void run() {
        ViewGroup content = (ViewGroup) mActivity.findViewById(android.R.id.content);
        content.removeView(BannerAdViewImpl.this);
        FrameLayout.LayoutParams marginLayoutParams = new FrameLayout.LayoutParams(mW, mH);
        marginLayoutParams.setMargins(mX, mY, 0, 0);
        content.addView(BannerAdViewImpl.this, marginLayoutParams);
      }
    });
  }

  public void setAdListener(long listenerPtr) {
    setAdListener(new AdListenerProxy(listenerPtr));
  }
}
