#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"

#include "C2DXChartboost.h"

class HelloWorld : public cocos2d::Layer, public C2DXChartboostDelegate
{
public:
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::Scene* createScene();

    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();  
    
    // a selector callback
    void menuCloseCallback(cocos2d::Ref* pSender);
    void menuCacheInterstitialCallback(cocos2d::Ref* pSender);
    void menuShowInterstitialCallback(cocos2d::Ref* pSender);
    void menuCacheVideoCallback(cocos2d::Ref* pSender);
    void menuShowVideoCallback(cocos2d::Ref* pSender);
    
    // C2DXChartboostDelegate method
    bool shouldRequestInterstitial(C2DXCBLocation location);
    bool shouldDisplayInterstitial(C2DXCBLocation location);
    void didDisplayInterstitial(C2DXCBLocation location);
    void didCacheInterstitial(C2DXCBLocation location);
    void didFailToLoadInterstitial(C2DXCBLocation location, C2DXCBLoadError error);
    void didFailToRecordClick(C2DXCBLocation location, C2DXCBClickError error);
    void didDismissInterstitial(C2DXCBLocation location);
    void didCloseInterstitial(C2DXCBLocation location);
    void didClickInterstitial(C2DXCBLocation location);
    bool shouldDisplayRewardedVideo(C2DXCBLocation location);
    void didDisplayRewardedVideo(C2DXCBLocation location);
    void didCacheRewardedVideo(C2DXCBLocation location);
    void didFailToLoadRewardedVideo(C2DXCBLocation location, C2DXCBLoadError error);
    void didDismissRewardedVideo(C2DXCBLocation location);
    void didCloseRewardedVideo(C2DXCBLocation location);
    void didClickRewardedVideo(C2DXCBLocation location);
    void didCompleteRewardedVideo(C2DXCBLocation location, int reward);
    
    // implement the "static create()" method manually
    CREATE_FUNC(HelloWorld);
};

#endif // __HELLOWORLD_SCENE_H__
