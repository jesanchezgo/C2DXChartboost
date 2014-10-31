#include "HelloWorldScene.h"

USING_NS_CC;

Scene* HelloWorld::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = HelloWorld::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    /////////////////////////////
    // 2. add a menu item with "X" image, which is clicked to quit the program
    //    you may modify it.

    // add a "close" icon to exit the progress. it's an autorelease object
    auto closeItem = MenuItemImage::create(
                                           "CloseNormal.png",
                                           "CloseSelected.png",
                                           CC_CALLBACK_1(HelloWorld::menuCloseCallback, this));
    
	closeItem->setPosition(Vec2(origin.x + visibleSize.width - closeItem->getContentSize().width/2 ,
                                origin.y + closeItem->getContentSize().height/2));

    // create menu, it's an autorelease object
    auto menu = Menu::create(closeItem, nullptr);
    menu->setPosition(Vec2::ZERO);
    this->addChild(menu, 1);

    
    MenuItemFont* pCacheItem = MenuItemFont::create("Cache Interstitial", CC_CALLBACK_1(HelloWorld::menuCacheInterstitialCallback, this));
    pCacheItem->setFontSizeObj(24);
    pCacheItem->setPosition(Point(origin.x + visibleSize.width/2 ,
                                origin.y + visibleSize.height * 0.80));
    menu->addChild(pCacheItem);
    
    MenuItemFont* pShowItem = MenuItemFont::create("Show Interstitial", CC_CALLBACK_1(HelloWorld::menuShowInterstitialCallback, this));
    pShowItem->setPosition(Point(origin.x + visibleSize.width/2 ,
                               origin.y + visibleSize.height * 0.60));
    pShowItem->setFontSizeObj(24);
    menu->addChild(pShowItem);

    MenuItemFont* pCacheVideoItem = MenuItemFont::create("Cache Rewarded Video", CC_CALLBACK_1(HelloWorld::menuCacheVideoCallback, this));
    pCacheVideoItem->setFontSizeObj(24);
    pCacheVideoItem->setPosition(Point(origin.x + visibleSize.width/2 ,
                                  origin.y + visibleSize.height * 0.40));
    menu->addChild(pCacheVideoItem);
    
    MenuItemFont* pShowVideoItem = MenuItemFont::create("Show Rewarded Video", CC_CALLBACK_1(HelloWorld::menuShowVideoCallback, this));
    pShowVideoItem->setPosition(Point(origin.x + visibleSize.width/2 ,
                                 origin.y + visibleSize.height * 0.20));
    pShowVideoItem->setFontSizeObj(24);
    menu->addChild(pShowVideoItem);
    
    C2DXChartboost::getInstance()->setDelegate(this);
    
    return true;
}

void HelloWorld::menuCacheInterstitialCallback(Ref* pSender)
{
    C2DXChartboost::getInstance()->cacheInterstitial(C2DXCBLocationHomeScreen);
}

void HelloWorld::menuShowInterstitialCallback(Ref* pSender)
{
    if ( C2DXChartboost::getInstance()->hasInterstitial(C2DXCBLocationHomeScreen))
    {
        C2DXChartboost::getInstance()->showInterstitial(C2DXCBLocationHomeScreen);
    }
}

void HelloWorld::menuCacheVideoCallback(Ref* pSender)
{
    C2DXChartboost::getInstance()->cacheRewardedVideo(C2DXCBLocationHomeScreen);
}

void HelloWorld::menuShowVideoCallback(Ref* pSender)
{
    if ( C2DXChartboost::getInstance()->hasRewardedVideo(C2DXCBLocationHomeScreen))
    {
        C2DXChartboost::getInstance()->showRewardedVideo(C2DXCBLocationHomeScreen);
    }
}

void HelloWorld::menuCloseCallback(Ref* pSender)
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WP8) || (CC_TARGET_PLATFORM == CC_PLATFORM_WINRT)
	MessageBox("You pressed the close button. Windows Store Apps do not implement a close button.","Alert");
    return;
#endif

    Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}

#pragma mark - C2DXChartboostDelegate method

bool HelloWorld::shouldRequestInterstitial(C2DXCBLocation location)
{
    CCLOG("should request interstitial at location %s", location);

    return true;
}

bool HelloWorld::shouldDisplayInterstitial(C2DXCBLocation location)
{
    CCLOG("should display interstitial at location %s", location);
    
    return true;
}

void HelloWorld::didDisplayInterstitial(C2DXCBLocation location)
{
    CCLOG("did display interstitial at location %s", location);
}

void HelloWorld::didCacheInterstitial(C2DXCBLocation location)
{
    CCLOG("did cache interstitial at location %s", location);
}

void HelloWorld::didFailToLoadInterstitial(C2DXCBLocation location, C2DXCBLoadError error)
{
    CCLOG("did fail to load interstitial at location %s", location);
    
    if (error == C2DXCBLoadErrorInternal)
    {
        CCLOG("Unknown internal error");
    }
    else if (error == C2DXCBLoadErrorInternetUnavailable)
    {
        CCLOG("Network is currently unavailable");
    }
    else if (error == C2DXCBLoadErrorTooManyConnections)
    {
        CCLOG("Too many requests are pending for that location");
    }
    else if (error == C2DXCBLoadErrorWrongOrientation)
    {
        CCLOG("Interstitial loaded with wrong orientation");
    }
    else if (error == C2DXCBLoadErrorFirstSessionInterstitialsDisabled)
    {
        CCLOG("Interstitial disabled, first session");
    }
    else if (error == C2DXCBLoadErrorNetworkFailure)
    {
        CCLOG("Network request failed");
    }
    else if (error == C2DXCBLoadErrorNoAdFound)
    {
        CCLOG("No ad received");
    }
    else if (error == C2DXCBLoadErrorSessionNotStarted)
    {
        CCLOG("Session not started");
    }
    else if (error == C2DXCBLoadErrorUserCancellation)
    {
        CCLOG("User manually cancelled the impression");
    }
    else if (error == C2DXCBLoadErrorNoLocationFound)
    {
        CCLOG("No location detected");
    }
}

void HelloWorld::didFailToRecordClick(C2DXCBLocation location, C2DXCBClickError error)
{
    CCLOG("did fail to record click interstitial at location %s", location);
    
    if (error == C2DXCBClickErrorUriInvalid)
    {
        CCLOG("Invalid URI");
    }
    else if (error == C2DXCBClickErrorUriUnrecognized)
    {
        CCLOG("The device does not know how to open the protocol of the URI");
    }
    else if (error == C2DXCBClickErrorAgeGateFailure)
    {
        CCLOG("User failed to pass the age gate");
    }
    else if (error == C2DXCBClickErrorInternal)
    {
        CCLOG("Unknown internal error");
    }
}

void HelloWorld::didDismissInterstitial(C2DXCBLocation location)
{
    CCLOG("did dismiss interstitial at location %s", location);
}

void HelloWorld::didCloseInterstitial(C2DXCBLocation location)
{
    CCLOG("did close interstitial at location %s", location);
}

void HelloWorld::didClickInterstitial(C2DXCBLocation location)
{
    CCLOG("did click interstitial at location %s", location);
}

bool HelloWorld::shouldDisplayRewardedVideo(C2DXCBLocation location)
{
    CCLOG("should display rewarded video at location %s", location);
    
    return true;
}

void HelloWorld::didDisplayRewardedVideo(C2DXCBLocation location)
{
    CCLOG("did display rewarded video at location %s", location);
}

void HelloWorld::didCacheRewardedVideo(C2DXCBLocation location)
{
    CCLOG("did cache rewarded video at location %s", location);
}

void HelloWorld::didFailToLoadRewardedVideo(C2DXCBLocation location, C2DXCBLoadError error)
{
    CCLOG("did fail to load rewarded video at location %s", location);
}

void HelloWorld::didDismissRewardedVideo(C2DXCBLocation location)
{
    CCLOG("did dismiss rewarded video at location %s", location);
}

void HelloWorld::didCloseRewardedVideo(C2DXCBLocation location)
{
    CCLOG("did close rewarded video at location %s", location);
}

void HelloWorld::didClickRewardedVideo(C2DXCBLocation location)
{
    CCLOG("did click rewarded video at location %s", location);
}

void HelloWorld::didCompleteRewardedVideo(C2DXCBLocation location, int reward)
{
    CCLOG("did complete rewarded video at location %s", location);
}
