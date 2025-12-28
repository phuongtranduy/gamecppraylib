// SPDX-License-Identifier: GPL-2.0
/**
* @file     Bullet.hpp
* @brief    The Bullet class' definition
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
#include "Bullet.hpp"

Bullet::Bullet(Texture2D aImage, float aNumberOfFrameX, float aNumberOfFrameY, float aWindowWidth, float aWindowHeight)
{
	BaseSpace::mImage = aImage;
    BaseSpace::mWindowWidth = aWindowWidth;
    BaseSpace::mWindowHeight = aWindowHeight;
    BaseSpace::mNumberofFrameX = aNumberOfFrameX;
	BaseSpace::mNumberofFrameY = aNumberOfFrameY;
	BaseSpace::mWidth = BaseSpace::mImage.width/BaseSpace::mNumberofFrameX;
	BaseSpace::mHeight = BaseSpace::mImage.height/BaseSpace::mNumberofFrameY;
	setScreenPos(Vector2{mWindowWidth/2, mWindowHeight/2});
}

Bullet::Bullet(Texture2D aImage, Texture2D aExplosion, float aNumberOfFrameX, float aNumberOfFrameY, float aWindowWidth, float aWindowHeight, Vector2 aScreenPos)
{
	BaseSpace::mImage = aImage;
    BaseSpace::mWindowWidth = aWindowWidth;
    BaseSpace::mWindowHeight = aWindowHeight;
    BaseSpace::mNumberofFrameX = aNumberOfFrameX;
	BaseSpace::mNumberofFrameY = aNumberOfFrameY;
	BaseSpace::mWidth = BaseSpace::mImage.width/BaseSpace::mNumberofFrameX;
	BaseSpace::mHeight = BaseSpace::mImage.height/BaseSpace::mNumberofFrameY;
	mExplosion = aExplosion;
	setSpeed(800.0f);
	setScreenPos(Vector2{aScreenPos.x - mWidth/2, aScreenPos.y});
}

Bullet::~Bullet()
{
	//UnloadTexture(mImage);
	if (mpExplosion != nullptr) delete mpExplosion;
}

void Bullet::Tick(float aDeltaTime)
{
   // draw the fighter
   if (!getAlive()) { 
	   
	   if(mScreenPos.y > -mHeight && mScreenPos.x > -mWidth && mScreenPos.x < mWindowWidth) // >=0 means that there is a collision with enemy in the screen
	   {	   
		//    if(mpExplosion == nullptr) 
		//    /*mpExplosion = new Explosion(LoadTexture("texture/medium_explosion.png"), 8, 1, 
		//    mWindowWidth, mWindowHeight, Vector2{mScreenPos.x, mScreenPos.y});*/
		//    mpExplosion = new Explosion(mExplosion, 8, 1, 
		//    mWindowWidth, mWindowHeight, Vector2{mScreenPos.x, mScreenPos.y - mHeight});
		//    else mpExplosion->Tick(aDeltaTime);
	   }

	   return;
   }
	//std::cout << "Bullet drawing\n";
   mVelocity.y -=1;
   mVelocity.x = 0;
   Matrix rotMat{};//transformation matrix newV =  Mat*oldV
   rotMat.m0 = cosf(mfRotation); rotMat.m4 = -sinf(mfRotation);
   rotMat.m1 = sinf(mfRotation); rotMat.m5 = cosf(mfRotation);
   
   mVelocity = Vector2Transform(mVelocity, rotMat);
   
   mScreenPos = Vector2Add(mScreenPos, Vector2Scale(Vector2Normalize(mVelocity), mSpeed * aDeltaTime));

   //Checking boundary
   if (mScreenPos.y <= -mHeight /*upper horizontal boundary*/
		|| mScreenPos.x <= -mWidth /*left verical boundary*/
		|| mScreenPos.x >= mWindowWidth/*right verical boundary*/) {
		setAlive(false);
		mBeRemoved = true;//out of screen
	}
   mVelocity = {};
   BaseSpace::Tick(aDeltaTime);
}

Vector2 Bullet::getScreenPos()
{
	return mScreenPos;
}