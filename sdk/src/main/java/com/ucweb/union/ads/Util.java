package com.ucweb.union.ads;

import android.content.Context;

public class Util {
  public static int dip2px(Context context, int dpValue) {
    final float scale = context.getResources().getDisplayMetrics().density;
    return (int) (dpValue * scale + 0.5f);
  }
}
