/****************************************************************************
 Copyright (c) 2014      Jesús Sánchez
 
 http://jesanchezgo.hostwp.es
 
 Permission is hereby granted, free of charge, to any person obtaining a copy
 of this software and associated documentation files (the "Software"), to deal
 in the Software without restriction, including without limitation the rights
 to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 copies of the Software, and to permit persons to whom the Software is
 furnished to do so, subject to the following conditions:
 
 The above copyright notice and this permission notice shall be included in
 all copies or substantial portions of the Software.
 
 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 THE SOFTWARE.
 ****************************************************************************/

package es.jesanchezgo.C2DXChartboost;

import org.cocos2dx.lib.Cocos2dxActivity;

import android.util.Log;

import com.chartboost.sdk.*;
import com.chartboost.sdk.Model.CBError.CBClickError;
import com.chartboost.sdk.Model.CBError.CBImpressionError;

public class C2DXChartboostBridge {
    private static final String TAG = "C2DXChartboost";
    private static Cocos2dxActivity s_activity;
    private static boolean initChartboost = false;

    private static native boolean shouldRequestInterstitial(String location);
    private static native boolean shouldDisplayInterstitial(String location);
    private static native boolean didDisplayInterstitial(String location);
    private static native void didCacheInterstitial(String location);
    private static native void didFailToLoadInterstitial(String location, int error);
    private static native void didFailToRecordClick(String uri, int error);
    private static native void didDismissInterstitial(String location);
    private static native void didCloseInterstitial(String location);
    private static native void didClickInterstitial(String location);
    
    private static native boolean shouldDisplayRewardedVideo(String location);
    private static native void didDisplayRewardedVideo(String location);    
    private static native void didCacheRewardedVideo(String location);
    private static native void didFailToLoadRewardedVideo(String location,int error);
    private static native void didDismissRewardedVideo(String location);
    private static native void didCloseRewardedVideo(String location);
    private static native void didClickRewardedVideo(String location);
    private static native void didCompleteRewardedVideo(String location, int reward);
    
    // the method must be called in main thread, before any other method
    public static void initC2DXChartboostBridge(Cocos2dxActivity activity){
    	C2DXChartboostBridge.s_activity = activity;
    }
    
    public static void startWithAppId(String appId, String appSignature) {
        // Init Chartboost
    	Chartboost.startWithAppId(C2DXChartboostBridge.s_activity, appId, appSignature);
        // Set delegate
        Chartboost.setDelegate(C2DXChartboostBridge.s_chartBoostDelegate);
        // On create
        Chartboost.onCreate(C2DXChartboostBridge.s_activity);
        
        C2DXChartboostBridge.initChartboost = true;
    }
    
    public static void cacheInterstitial(final String location) {
        Log.v(TAG, "cacheInterstitial(\"" + location + "\") is called...");
        
        C2DXChartboostBridge.s_activity.runOnUiThread(new Runnable() {
            public void run() {
            	Chartboost.cacheInterstitial(location);
            }
        });
    }
        
    public static void showInterstitial(final String location) {
        Log.v(TAG, "showInterstitial(\"" + location + "\") is called...");

        C2DXChartboostBridge.s_activity.runOnUiThread(new Runnable() {
            public void run() {
            	Chartboost.showInterstitial(location);
            }
        });
    }
        
    public static boolean hasInterstitial(final String location) {
        Log.v(TAG, "hasInterstitial(\"" + location + "\") is called...");
        
        return Chartboost.hasInterstitial(location);
    }
     
    public static void cacheRewardedVideo(final String location) {
        Log.v(TAG, "cacheRewardedVideo(\"" + location + "\") is called...");
        
        C2DXChartboostBridge.s_activity.runOnUiThread(new Runnable() {
            public void run() {
            	Chartboost.cacheRewardedVideo(location);
            }
        });
    }
        
    public static void showRewardedVideo(final String location) {
        Log.v(TAG, "cacheRewardedVideo(\"" + location + "\") is called...");

        C2DXChartboostBridge.s_activity.runOnUiThread(new Runnable() {
            public void run() {
            	Chartboost.showRewardedVideo(location);
            }
        });
    }
        
    public static boolean hasRewardedVideo(final String location) {
        Log.v(TAG, "hasInterstitial(\"" + location + "\") is called...");
        
        return Chartboost.hasRewardedVideo(location);
    }
    
    static private ChartboostDelegate s_chartBoostDelegate = new ChartboostDelegate() {
        /**
         * Interstital
         */
        @Override
        public boolean shouldRequestInterstitial(String location)
        {
            return C2DXChartboostBridge.shouldRequestInterstitial(location);
        }

        @Override
        public boolean shouldDisplayInterstitial(String location)
        {
            return C2DXChartboostBridge.shouldDisplayInterstitial(location);
        }
        
        @Override
        public void didDisplayInterstitial(final String location) {
        	C2DXChartboostBridge.s_activity.runOnGLThread(new Runnable() {
                public void run() {
                	C2DXChartboostBridge.didDisplayInterstitial(location);
                }
            });
        }
        
        @Override
        public void didCacheInterstitial(final String location) {
        	C2DXChartboostBridge.s_activity.runOnGLThread(new Runnable() {
                public void run() {
                	C2DXChartboostBridge.didCacheInterstitial(location);
                }
            });
        }
   
        @Override
        public void didFailToLoadInterstitial(final String location, final CBImpressionError error)
        {
        	C2DXChartboostBridge.s_activity.runOnGLThread(new Runnable() {
                public void run() {
                	C2DXChartboostBridge.didFailToLoadInterstitial(location, error.ordinal());
                }
            });
        }

        @Override
        public void didFailToRecordClick(final String uri, final CBClickError error)
        {
        	C2DXChartboostBridge.s_activity.runOnGLThread(new Runnable() {
                public void run() {
                	C2DXChartboostBridge.didFailToRecordClick(uri, error.ordinal());
                }
            });

        }
        
        @Override
        public void didDismissInterstitial(final String location)
        {
        	C2DXChartboostBridge.s_activity.runOnGLThread(new Runnable() {
                public void run() {
                	C2DXChartboostBridge.didDismissInterstitial(location);
		        }
		    });
        }
        
        @Override
        public void didCloseInterstitial(final String location)
        {
        	C2DXChartboostBridge.s_activity.runOnGLThread(new Runnable() {
                public void run() {
                	C2DXChartboostBridge.didCloseInterstitial(location);
		        }
		    });
        }

        @Override
        public void didClickInterstitial(final String location)
        {
        	C2DXChartboostBridge.didClickInterstitial(location);
        }

        @Override
        public boolean shouldDisplayRewardedVideo(final String location) 
        {
        	return C2DXChartboostBridge.shouldDisplayRewardedVideo(location);
        }
        
        @Override
        public void didDisplayRewardedVideo(final String location)
        {
        	C2DXChartboostBridge.s_activity.runOnGLThread(new Runnable() {
                public void run() {
                	C2DXChartboostBridge.didDisplayRewardedVideo(location);
                }
            });
        }
        
        @Override
        public void didCacheRewardedVideo(final String location)
        {
        	C2DXChartboostBridge.s_activity.runOnGLThread(new Runnable() {
                public void run() {
                	C2DXChartboostBridge.didCacheRewardedVideo(location);
                }
            });
        }
        
        @Override
        public void didFailToLoadRewardedVideo(final String location, final CBImpressionError error)
        {
        	C2DXChartboostBridge.s_activity.runOnGLThread(new Runnable() {
                public void run() {
                	C2DXChartboostBridge.didFailToLoadRewardedVideo(location, error.ordinal());
                }
            });
        }
        
        @Override
        public void didDismissRewardedVideo(final String location)
        {
        	C2DXChartboostBridge.s_activity.runOnGLThread(new Runnable() {
                public void run() {
                	C2DXChartboostBridge.didDismissRewardedVideo(location);
                }
            });
        }
        
        @Override
        public void didCloseRewardedVideo(final String location)
        {
        	C2DXChartboostBridge.s_activity.runOnGLThread(new Runnable() {
                public void run() {
                	C2DXChartboostBridge.didCloseRewardedVideo(location);
                }
            });
        }
        
        @Override
        public void didClickRewardedVideo(final String location)
        {
        	C2DXChartboostBridge.s_activity.runOnGLThread(new Runnable() {
                public void run() {
                	C2DXChartboostBridge.didClickRewardedVideo(location);
                }
            });
        }
        
        @Override
        public void didCompleteRewardedVideo(final String location, final int reward)
        {
        	C2DXChartboostBridge.s_activity.runOnGLThread(new Runnable() {
                public void run() {
                	C2DXChartboostBridge.didCompleteRewardedVideo(location, reward);
                }
            });
        }
    };
}
