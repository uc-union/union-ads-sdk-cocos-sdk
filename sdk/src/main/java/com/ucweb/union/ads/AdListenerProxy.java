package com.ucweb.union.ads;

public class AdListenerProxy implements AdListener {
  private final long mNativePtr;

  public AdListenerProxy(long nativePtr) {
    mNativePtr = nativePtr;
  }

  @Override
  public void onAdLoaded(UnionAd unionAd) {
    nativeOnAdLoaded(mNativePtr);
  }

  @Override
  public void onAdClosed(UnionAd unionAd) {
    nativeOnAdClosed(mNativePtr);
  }

  @Override
  public void onAdShowed(UnionAd unionAd) {
    nativeOnAdOpened(mNativePtr);
  }

  @Override
  public void onAdClicked(UnionAd unionAd) {
    nativeOnAdClicked(mNativePtr);
  }

  @Override
  public void onAdError(UnionAd unionAd, AdError error) {
    nativeOnAdError(mNativePtr, error);
  }

  private native void nativeOnAdLoaded(long nativePtr);

  private native void nativeOnAdClosed(long nativePtr);

  private native void nativeOnAdOpened(long nativePtr);

  private native void nativeOnAdClicked(long nativePtr);

  private native void nativeOnAdError(long nativePtr, AdError error);

}
