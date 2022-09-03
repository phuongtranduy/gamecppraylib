// SPDX-License-Identifier: GPL-2.0
/**
* @file     PowerDrug.cpp
* @brief    The PowerDrug class' definition
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
#include "PowerDrug.hpp"

PowerDrug::PowerDrug(Texture2D aImage, float aNumberOfFrameX, float aNumberOfFrameY, float aWindowWidth, float aWindowHeight)
{
	BaseSpace::mImage = aImage;
    BaseSpace::mWindowWidth = aWindowWidth;
    BaseSpace::mWindowHeight = aWindowHeight;
    BaseSpace::mNumberofFrameX = aNumberOfFrameX;
	BaseSpace::mNumberofFrameY = aNumberOfFrameY;
	BaseSpace::mWidth = BaseSpace::mImage.width/BaseSpace::mNumberofFrameX;
	BaseSpace::mHeight = BaseSpace::mImage.height/BaseSpace::mNumberofFrameY;
	setSpeed(80);
	setScreenPos(Vector2{mWindowWidth/2, 0});
	hitlevelsound = LoadSound("audio/hitlevel.mp3");
}

PowerDrug::~PowerDrug()
{
	UnloadSound(hitlevelsound);
}

void PowerDrug::Tick(float aDeltaTime)
{
  //draw the Enemy
  if (!getAlive()) return;
  
   mVelocity.y = 1;
   mVelocity.x = 0;
   mScreenPos = Vector2Add(mScreenPos, Vector2Scale(Vector2Normalize(mVelocity), mSpeed * aDeltaTime));
   //Checking boundary
   if (mScreenPos.y >= mWindowHeight + mHeight) setAlive(false);
   mVelocity = {};
   
   BaseSpace::Tick(aDeltaTime);
   
   //
   if (CheckCollisionRecs(getCollisionRec(), mTarget->getCollisionRec()) && mTarget->getAlive())
   {
	   this->setAlive(false);
	   PlaySound(hitlevelsound);
	   mTarget->setFightingLevel(mTarget->getFightingLevel()+1);
   }
}
Vector2 PowerDrug::getScreenPos()
{
   // std::cout << "Enenmy Screen POS\n";
    return mScreenPos;
}
  