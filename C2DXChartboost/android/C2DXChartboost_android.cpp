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
#include "C2DXChartboostJni.h"

// CBLocations mapped
C2DXCBLocation const C2DXCBLocationStartup        = "Startup";
C2DXCBLocation const C2DXCBLocationHomeScreen     = "Home Screen";
C2DXCBLocation const C2DXCBLocationMainMenu       = "Main Menu";
C2DXCBLocation const C2DXCBLocationGameScreen     = "Game Screen";
C2DXCBLocation const C2DXCBLocationAchievements   = "Achievements";
C2DXCBLocation const C2DXCBLocationQuests         = "Quests";
C2DXCBLocation const C2DXCBLocationPause          = "Pause";
C2DXCBLocation const C2DXCBLocationLevelStart     = "Level Start";
C2DXCBLocation const C2DXCBLocationLevelComplete  = "Level Complete";
C2DXCBLocation const C2DXCBLocationTurnComplete   = "Turn Complete";
C2DXCBLocation const C2DXCBLocationIAPStore       = "IAP Store";
C2DXCBLocation const C2DXCBLocationItemStore      = "Item Store";
C2DXCBLocation const C2DXCBLocationGameOver       = "Game Over";
C2DXCBLocation const C2DXCBLocationLeaderBoard    = "Leaderboard";
C2DXCBLocation const C2DXCBLocationSettings       = "Settings";
C2DXCBLocation const C2DXCBLocationQuit           = "Quit";
C2DXCBLocation const C2DXCBLocationDefault        = "Default";

// CBLoadError mapped
C2DXCBLoadError const C2DXCBLoadErrorInternal                           = 0;
C2DXCBLoadError const C2DXCBLoadErrorInternetUnavailable                = 1;
C2DXCBLoadError const C2DXCBLoadErrorTooManyConnections                 = 2;
C2DXCBLoadError const C2DXCBLoadErrorWrongOrientation                   = 3;
C2DXCBLoadError const C2DXCBLoadErrorFirstSessionInterstitialsDisabled  = 4;
C2DXCBLoadError const C2DXCBLoadErrorNetworkFailure                     = 5;
C2DXCBLoadError const C2DXCBLoadErrorNoAdFound                          = 6;
C2DXCBLoadError const C2DXCBLoadErrorSessionNotStarted                  = 7;
C2DXCBLoadError const C2DXCBLoadErrorImpressionAlreadyVisible           = 8;
C2DXCBLoadError const C2DXCBLoadErrorNoHostActivity		                = 9;
C2DXCBLoadError const C2DXCBLoadErrorUserCancellation                   = 10;
C2DXCBLoadError const C2DXCBLoadErrorNoLocationFound                    = 11;

// CBClickError mapped
C2DXCBClickError const C2DXCBClickErrorUriInvalid       = 0;
C2DXCBClickError const C2DXCBClickErrorUriUnrecognized  = 1;
C2DXCBClickError const C2DXCBClickErrorAgeGateFailure   = 2;
C2DXCBClickError const C2DXCBClickErrorNoHostActivity   = 3;
C2DXCBClickError const C2DXCBClickErrorInternal         = 4;

static C2DXChartboost* s_pC2DXChartboost = NULL;

C2DXChartboost* C2DXChartboost::getInstance()
{
    if (s_pC2DXChartboost == NULL)
    {
    	s_pC2DXChartboost = new C2DXChartboost();
    }
    return s_pC2DXChartboost;
}

void C2DXChartboost::purgeC2DXChartboost()
{
    CC_SAFE_DELETE(s_pC2DXChartboost);
}

void C2DXChartboost::startWithAppId(const char * appId, const char * appSignature)
{
	startWithAppId(appId, appSignature);
}

/*
void ChartboostX::startSession()
{
    installJNI();
}
*/
void C2DXChartboost::cacheInterstitial(C2DXCBLocation location)
{
    cacheInterstitialJNI(location);
}

void C2DXChartboost::showInterstitial(C2DXCBLocation location)
{
    showInterstitialJNI(location);
}

bool C2DXChartboost::hasInterstitial(C2DXCBLocation location)
{
	return hasInterstitialJNI(location);
}

void C2DXChartboost::cacheRewardedVideo(C2DXCBLocation location)
{
	cacheRewardedVideoJNI(location);
}

void C2DXChartboost::showRewardedVideo(C2DXCBLocation location)
{
	showRewardedVideoJNI(location);
}

bool C2DXChartboost::hasRewardedVideo(C2DXCBLocation location)
{
	return hasRewardedVideoJNI(location);
}
