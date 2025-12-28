// SPDX-License-Identifier: GPL-2.0
/**
* @file     Explosion.cpp
* @brief    The Explosion class' definition
* @author   Phuong D. Tran <phuong1988vn@gmail.com>
* @date     26-Aug-2022
* @version  v0.1
* @note
 */


/*=============================================================================
Revision History:
                        Modification       Tracking
Author                  Date D/M/Y         Number     Description of Changes
Phuong Tran Duy         26-Aug-2022                   Init version
=============================================================================*/
#include "Explosion.hpp"

Explosion::Explosion(Texture2D aImage, float aNumberOfFrameX, float aNumberOfFrameY, float aWindowWidth, float aWindowHeight)
{
	BaseSpace::mImage = aImage;
    BaseSpace::mWindowWidth = aWindowWidth;
    BaseSpace::mWindowHeight = aWindowHeight;
    BaseSpace::mNumberofFrameX = aNumberOfFrameX;
	BaseSpace::mNumberofFrameY = aNumberOfFrameY;
	BaseSpace::mWidth = BaseSpace::mImage.width/BaseSpace::mNumberofFrameX;
	BaseSpace::mHeight = BaseSpace::mImage.height/BaseSpace::mNumberofFrameY;
}

Explosion::Explosion(Texture2D aImage, float aNumberOfFrameX, float aNumberOfFrameY, float aWindowWidth, float aWindowHeight, Vector2 aScreenPos)
{
	BaseSpace::mImage = aImage;
    BaseSpace::mWindowWidth = aWindowWidth;
    BaseSpace::mWindowHeight = aWindowHeight;
    BaseSpace::mNumberofFrameX = aNumberOfFrameX;
	BaseSpace::mNumberofFrameY = aNumberOfFrameY;
	BaseSpace::mWidth = BaseSpace::mImage.width/BaseSpace::mNumberofFrameX;
	BaseSpace::mHeight = BaseSpace::mImage.height/BaseSpace::mNumberofFrameY;
	//setScreenPos(Vector2{aScreenPos.x - mWidth/2, aScreenPos.y});
    setScreenPos(Vector2{aScreenPos.x - mWidth/2, aScreenPos.y - mHeight/2 });
}

Explosion::~Explosion()
{
	
}


void Explosion::Tick(float aDeltaTime)
{
   // draw the fighter
	if (!getAlive()) return;

   BaseSpace::Tick(aDeltaTime);
   mRunningTime += aDeltaTime;
   if (mRunningTime >= mUpdateTIme)
   {
	   mFrameX++;
	   if(mFrameX >= mNumberofFrameX)
		   setAlive(false);
	   mRunningTime = 0;
   }
}

Vector2 Explosion::getScreenPos()
{
    return mScreenPos;
}