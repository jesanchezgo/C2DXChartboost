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

#include "C2DXChartboost.h"

#import <Chartboost/Chartboost.h>

// CBLocations mapped
C2DXCBLocation const C2DXCBLocationStartup        = [CBLocationStartup cStringUsingEncoding:NSUTF8StringEncoding];
C2DXCBLocation const C2DXCBLocationHomeScreen     = [CBLocationHomeScreen cStringUsingEncoding:NSUTF8StringEncoding];
C2DXCBLocation const C2DXCBLocationMainMenu       = [CBLocationMainMenu cStringUsingEncoding:NSUTF8StringEncoding];
C2DXCBLocation const C2DXCBLocationGameScreen     = [CBLocationGameScreen cStringUsingEncoding:NSUTF8StringEncoding];
C2DXCBLocation const C2DXCBLocationAchievements   = [CBLocationAchievements cStringUsingEncoding:NSUTF8StringEncoding];
C2DXCBLocation const C2DXCBLocationQuests         = [CBLocationQuests cStringUsingEncoding:NSUTF8StringEncoding];
C2DXCBLocation const C2DXCBLocationPause          = [CBLocationPause cStringUsingEncoding:NSUTF8StringEncoding];
C2DXCBLocation const C2DXCBLocationLevelStart     = [CBLocationLevelStart cStringUsingEncoding:NSUTF8StringEncoding];
C2DXCBLocation const C2DXCBLocationLevelComplete  = [CBLocationLevelComplete cStringUsingEncoding:NSUTF8StringEncoding];
C2DXCBLocation const C2DXCBLocationTurnComplete   = [CBLocationTurnComplete cStringUsingEncoding:NSUTF8StringEncoding];
C2DXCBLocation const C2DXCBLocationIAPStore       = [CBLocationIAPStore cStringUsingEncoding:NSUTF8StringEncoding];
C2DXCBLocation const C2DXCBLocationItemStore      = [CBLocationItemStore cStringUsingEncoding:NSUTF8StringEncoding];
C2DXCBLocation const C2DXCBLocationGameOver       = [CBLocationGameOver cStringUsingEncoding:NSUTF8StringEncoding];
C2DXCBLocation const C2DXCBLocationLeaderBoard    = [CBLocationLeaderBoard cStringUsingEncoding:NSUTF8StringEncoding];
C2DXCBLocation const C2DXCBLocationSettings       = [CBLocationSettings cStringUsingEncoding:NSUTF8StringEncoding];
C2DXCBLocation const C2DXCBLocationQuit           = [CBLocationQuit cStringUsingEncoding:NSUTF8StringEncoding];
C2DXCBLocation const C2DXCBLocationDefault        = [CBLocationDefault cStringUsingEncoding:NSUTF8StringEncoding];

// CBLoadError mapped
C2DXCBLoadError const C2DXCBLoadErrorInternal                           = CBLoadErrorInternal;
C2DXCBLoadError const C2DXCBLoadErrorInternetUnavailable                = CBLoadErrorInternetUnavailable;
C2DXCBLoadError const C2DXCBLoadErrorTooManyConnections                 = CBLoadErrorTooManyConnections;
C2DXCBLoadError const C2DXCBLoadErrorWrongOrientation                   = CBLoadErrorWrongOrientation;
C2DXCBLoadError const C2DXCBLoadErrorFirstSessionInterstitialsDisabled  = CBLoadErrorFirstSessionInterstitialsDisabled;
C2DXCBLoadError const C2DXCBLoadErrorNetworkFailure                     = CBLoadErrorNetworkFailure;
C2DXCBLoadError const C2DXCBLoadErrorNoAdFound                          = CBLoadErrorNoAdFound;
C2DXCBLoadError const C2DXCBLoadErrorSessionNotStarted                  = CBLoadErrorSessionNotStarted;
C2DXCBLoadError const C2DXCBLoadErrorUserCancellation                   = CBLoadErrorUserCancellation;
C2DXCBLoadError const C2DXCBLoadErrorNoLocationFound                    = CBLoadErrorNoLocationFound;

// CBClickError mapped
C2DXCBClickError const C2DXCBClickErrorUriInvalid       = CBClickErrorUriInvalid;
C2DXCBClickError const C2DXCBClickErrorUriUnrecognized  = CBClickErrorUriUnrecognized;
C2DXCBClickError const C2DXCBClickErrorAgeGateFailure   = CBClickErrorAgeGateFailure;
C2DXCBClickError const C2DXCBClickErrorInternal         = CBClickErrorInternal;


// ChartboostDelegateBridge
@interface C2DXChartboostDelegateBridge : NSObject<ChartboostDelegate>
@end

static C2DXChartboostDelegateBridge* s_pDelegateBridge = nil;

static C2DXChartboost* s_pC2DXChartboost = NULL;

#pragma mark - Create & Destroy

C2DXChartboost* C2DXChartboost::getInstance()
{
    if (s_pC2DXChartboost == NULL)
    {
        s_pC2DXChartboost = new C2DXChartboost();
        s_pDelegateBridge = [[C2DXChartboostDelegateBridge alloc] init];
    }
    return s_pC2DXChartboost;
}

void C2DXChartboost::startWithAppId(const char * appId, const char * appSignature)
{
    [Chartboost startWithAppId:[NSString stringWithUTF8String:appId]
                  appSignature:[NSString stringWithUTF8String:appSignature]
                      delegate:s_pDelegateBridge];
}

void C2DXChartboost::purgeC2DXChartboost()
{
    CC_SAFE_DELETE(s_pC2DXChartboost);
    [s_pDelegateBridge dealloc];
}

#pragma mark - Interstitial Methods

void C2DXChartboost::cacheInterstitial(C2DXCBLocation location)
{
    [Chartboost cacheInterstitial : [NSString stringWithUTF8String:location]];
}

void C2DXChartboost::showInterstitial(C2DXCBLocation location)
{
    [Chartboost showInterstitial : [NSString stringWithUTF8String:location]];
}

bool C2DXChartboost::hasInterstitial(C2DXCBLocation location)
{
    return [Chartboost hasInterstitial: [NSString stringWithUTF8String:location]];
}

void C2DXChartboost::setShouldRequestInterstitialsInFirstSession(bool shouldRequest)
{
    [Chartboost setShouldRequestInterstitialsInFirstSession:shouldRequest];
}

#pragma mark - Rewarded Videos Methods

void C2DXChartboost::cacheRewardedVideo(C2DXCBLocation location)
{
    return [Chartboost cacheRewardedVideo: [NSString stringWithUTF8String:location]];
}

void C2DXChartboost::showRewardedVideo(C2DXCBLocation location)
{
    return [Chartboost showRewardedVideo:[NSString stringWithUTF8String:location]];
}

bool C2DXChartboost::hasRewardedVideo(C2DXCBLocation location)
{
    return [Chartboost hasRewardedVideo: [NSString stringWithUTF8String:location]];
}

#pragma mark - Chartboost Delegate Implementation
/*
 * Chartboost Delegate Methods
 */
@implementation C2DXChartboostDelegateBridge

#pragma mark - Interstitial Delegate Methods
- (BOOL)shouldRequestInterstitial:(CBLocation)location {
    if (C2DXChartboostDelegate* delegate = C2DXChartboost::getInstance()->getDelegate()) {
        return delegate->shouldRequestInterstitial([location UTF8String]);
    }
    
    return YES;
}

- (BOOL)shouldDisplayInterstitial:(CBLocation)location {
    if (C2DXChartboostDelegate* delegate = C2DXChartboost::getInstance()->getDelegate()) {
        return delegate->shouldDisplayInterstitial([location UTF8String]);
    }

    return YES;
}

- (void)didDisplayInterstitial:(CBLocation)location {
    if (C2DXChartboostDelegate* delegate = C2DXChartboost::getInstance()->getDelegate()) {
        delegate->didDisplayInterstitial([location UTF8String]);
    }
}

- (void)didCacheInterstitial:(CBLocation)location {
    if (C2DXChartboostDelegate* delegate = C2DXChartboost::getInstance()->getDelegate()) {
        delegate->didCacheInterstitial([location UTF8String]);
    }
}

- (void)didFailToLoadInterstitial:(CBLocation)location withError:(CBLoadError)error {
    if (C2DXChartboostDelegate* delegate = C2DXChartboost::getInstance()->getDelegate()) {
        delegate->didFailToLoadInterstitial([location UTF8String], error);
    }
}

- (void)didFailToRecordClick:(CBLocation)location withError:(CBClickError)error {
    if (C2DXChartboostDelegate* delegate = C2DXChartboost::getInstance()->getDelegate()) {
        delegate->didFailToRecordClick([location UTF8String], error);
    }
}

- (void)didDismissInterstitial:(CBLocation)location {
    if (C2DXChartboostDelegate* delegate = C2DXChartboost::getInstance()->getDelegate()) {
        delegate->didDismissInterstitial([location UTF8String]);
    }
}

- (void)didCloseInterstitial:(CBLocation)location {
    if (C2DXChartboostDelegate* delegate = C2DXChartboost::getInstance()->getDelegate()) {
        delegate->didCloseInterstitial([location UTF8String]);
    }
}

- (void)didClickInterstitial:(CBLocation)location {
    if (C2DXChartboostDelegate* delegate = C2DXChartboost::getInstance()->getDelegate()) {
        delegate->didClickInterstitial([location UTF8String]);
    }
}

- (BOOL)shouldRequestInterstitialsInFirstSession {
    if (C2DXChartboostDelegate* delegate = C2DXChartboost::getInstance()->getDelegate()) {
        return delegate->setShouldRequestInterstitialsInFirstSession();
    }

    return YES;
}

#pragma mark - Rewarded Video Delegate Methods

- (BOOL)shouldDisplayRewardedVideo:(CBLocation)location {
    if (C2DXChartboostDelegate* delegate = C2DXChartboost::getInstance()->getDelegate()) {
        return delegate->shouldDisplayRewardedVideo([location UTF8String]);
    }
    
    return YES;
}

- (void)didDisplayRewardedVideo:(CBLocation)location {
    if (C2DXChartboostDelegate* delegate = C2DXChartboost::getInstance()->getDelegate()) {
        return delegate->didDisplayRewardedVideo([location UTF8String]);
    }
}

- (void)didCacheRewardedVideo:(CBLocation)location {
    if (C2DXChartboostDelegate* delegate = C2DXChartboost::getInstance()->getDelegate()) {
        return delegate->didCacheRewardedVideo([location UTF8String]);
    }
}

- (void)didFailToLoadRewardedVideo:(CBLocation)location withError:(CBLoadError)error {
    if (C2DXChartboostDelegate* delegate = C2DXChartboost::getInstance()->getDelegate()) {
        return delegate->didFailToLoadRewardedVideo([location UTF8String], error);
    }
}

- (void)didDismissRewardedVideo:(CBLocation)location {
    if (C2DXChartboostDelegate* delegate = C2DXChartboost::getInstance()->getDelegate()) {
        return delegate->didDismissRewardedVideo([location UTF8String]);
    }
}

- (void)didCloseRewardedVideo:(CBLocation)location {
    if (C2DXChartboostDelegate* delegate = C2DXChartboost::getInstance()->getDelegate()) {
        return delegate->didCloseRewardedVideo([location UTF8String]);
    }
}

- (void)didClickRewardedVideo:(CBLocation)location {
    if (C2DXChartboostDelegate* delegate = C2DXChartboost::getInstance()->getDelegate()) {
        return delegate->didClickRewardedVideo([location UTF8String]);
    }
}

- (void)didCompleteRewardedVideo:(CBLocation)location withReward:(int)reward {
    if (C2DXChartboostDelegate* delegate = C2DXChartboost::getInstance()->getDelegate()) {
        return delegate->didCompleteRewardedVideo([location UTF8String], reward);
    }
}

@end