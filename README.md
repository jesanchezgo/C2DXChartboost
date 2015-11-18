C2DXChartboost
==============

A C++ wrapper of [Chartboost](https://chartboost.com) for [Cocos2d-X](https://github.com/cocos2d/cocos2d-x). Supports Android and iOS.

Features implemented:
* Interstitial Ads 
* Rewarded Videos

Based on [ChartboostX](https://github.com/wenbin1989/Chartboost-x) project.

Software Version
================

* ###Chartboost SDK
	* Android: v5.0
	* iOS: v5.0.2

* ###cocos2d-x
	* cocos2d-x-3.2 or higher

How to use C2DXChartboost
=========================
***iOS and Android will share the same `C2DXChartboost.h` header file. You need add `C2DXChartboost/C2DXChartboost.h` to your `Classes` folder in the beginning.***

### iOS

All the following files you need in iOS are in `C2DXChartboost/ios` folder.

1. Add the previous `C2DXChartboost.h` to your Xcode project
2. Add `C2DXChartboost_ios.mm` to your Xcode project
3. Add the Chartboost.framework into your Xcode project's Frameworks folder.
4. Be sure you've also linked these frameworks:
  * StoreKit.framework
  * Foundation.framework
  * CoreGraphics.framework
  * UIKit.framework
5. In your `AppController.mm`, `didFinishLaunchingWithOptions` method, initialize C2DXChartboost:

```
C2DXChartboost::getInstance()->startWithAppId("<HERE_YOUR_APP_ID>", "<HERE_YOUR_SIGNATURE_ID>");
```


### Android
All the following files you need in Android are in `C2DXChartboost/android` folder.

1. Add the package `es.jesanchezgo.C2DXChartboost` and its `C2DXChartboostBridge.java` to your Eclipse project.
*(You can just add the whole `es` folder to `src` folder in Eclipse project, and refresh in Eclipse)*
2. Add the `ChartBoost.jar` file as an external jar to your project.
*(You can just add the `ChartBoost.jar` file to `libs` fold in Eclipse project, and refresh in Eclipse)*
3. Add `C2DXChartboost_android.cpp`, `C2DXChartboostJni.cpp` and `C2DXChartboostJni.h` to your `jni` folder.
4. Add `C2DXChartboost_android.cpp`, `C2DXChartboostJni.cpp` to your jni's `Android.mk`.
5. In the java implementation of your main activity (which should have been created by the Cocos2d-X script), `import es.jesanchezgo.C2DXChartboost.*;`
6. At the beginning of `onCreate(Bundle savedInstanceState)`, right after `super.onCreate(savedInstanceState)`, add the following code:

		C2DXChartboostBridge.initC2DXChartboostBridge(this);
		C2DXChartboostBridge.startWithAppId("<HERE_YOUR_APP_ID>","<HERE_YOUR_SIGNATURE_ID>");

7. Add the following code to your main activity:

    		@Override
    		public void onStart() {
        		super.onStart();
        		Chartboost.onStart(this);
    		}
	    
	    	@Override
	    	protected void onPause() {
		        super.onPause();
	        	Chartboost.onPause(this);
	    	}
	
	    	@Override
	    	protected void onResume() {
		        Chartboost.onResume(this);
	        	super.onResume();        
	    	}
	
			@Override
	    	public void onStop() {
	        	super.onStop();
	        	Chartboost.onStop(this);
	    	}
	
	    	@Override
	    	public void onDestroy() {
	        	super.onDestroy();
	        	Chartboost.onDestroy(this);
	    	}
	
	    	@Override
	    	public void onBackPressed() {
	        	if (Chartboost.onBackPressed())
	            		return;
	        	else
	            	super.onBackPressed();
	    	}

8. Add the following xml to your Android Manifest file:

	Add permissions:

		<uses-permission android:name="android.permission.INTERNET" />
		<uses-permission android:name="android.permission.ACCESS_NETWORK_STATE" />
	
	Optional permissions:
	
		<uses-permission android:name="android.permission.WRITE_EXTERNAL_STORAGE" />
		<uses-permission android:name="android.permission.ACCESS_WIFI_STATE" />
	
9. Add the Google Play Services library as a dependency of your project.
     - The Google Play Services library has its own set of integration instructions, including additions to your Android 	Manifest and Proguard configuration
     - You can follow the setup instructions outlined by Google at the [Google Developer website](https://developer.android.com/google/play-services/setup.html)

#Example Project
1. iOS: C2DXCharboostExample/proj.ios_mac/ios/C2DXChartboostExample.xcodeproj
2. Android: C2DXCharboostExample/proj.android

***You need to change the build script (such as build_native.sh) according to your own environment before compiling***.


##Email: <jesanchezgo@gmail.com>
##Blog: <http://games-jesanchezgo.rhcloud.com>
