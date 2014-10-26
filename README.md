C2DXChartboost
==============

A C++ wrapper of [Chartboost](https://chartboost.com) for [Cocos2d-X](https://github.com/cocos2d/cocos2d-x). Supports Android and iOS.

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
***iOS and Android will share the same `C2DXChartboost.h` header file. You need add `C2DXChartboost/C2DXChartboost` to your `Classes` folder in the beginning.***

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

### Android
All the following files you need in Android are in `C2DXChartboost/android` folder.





