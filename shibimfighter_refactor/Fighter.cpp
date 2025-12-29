// SPDX-License-Identifier: GPL-2.0
/**
* @file     Fighter.cpp
* @brief    The Fighter class' definition
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
#include "Fighter.hpp"

Fighter::Fighter(Texture2D aImage, float aNumberOfFrameX, float aNumberOfFrameY, float aOffsetX, float aWindowWidth, float aWindowHeight)
{
	BaseSpace::mImage = aImage;
    BaseSpace::mWindowWidth = aWindowWidth;
    BaseSpace::mWindowHeight = aWindowHeight;
    BaseSpace::mNumberofFrameX = aNumberOfFrameX;
	BaseSpace::mNumberofFrameY = aNumberOfFrameY;
	BaseSpace::mWidth = BaseSpace::mImage.width/BaseSpace::mNumberofFrameX - 2 * aOffsetX;
	BaseSpace::mHeight = BaseSpace::mImage.height/BaseSpace::mNumberofFrameY;
	BaseSpace::mOffsetX = aOffsetX;
	setScreenPos(Vector2{mWindowWidth/2-BaseSpace::mWidth/2, mWindowHeight - mHeight});
	//mBullet = LoadTexture("texture/bullet.png");
}

Fighter::~Fighter()
{
	UnloadTexture(mBullet);;
	UnloadTexture(mExplosion);
	UnloadTexture(mBigExplosion);
}

void Fighter::Tick(float aDeltaTime)
{
	//std::cout << "mSpeed=" << mSpeed << std::endl;
   // draw the fighter
	if (!getAlive()) {
		//    if(mpExplosion == nullptr) 
		// 	mpExplosion = new Explosion(mBigExplosion, 8, 1, mWindowWidth, mWindowHeight, Vector2{mScreenPos.x, mScreenPos.y});
		//    else 
		// 	   mpExplosion->Tick(aDeltaTime);
		
		return;
	}
	

    if (IsKeyDown(KEY_LEFT)){
        mVelocity.x -= 1.0;
		mBouncingTime+=aDeltaTime;
		
	}
    if (IsKeyDown(KEY_RIGHT)){
        mVelocity.x += 1.0;
		mBouncingTime+=aDeltaTime;
		
	}
    if (IsKeyDown(KEY_UP)){
        mVelocity.y -= 1.0;
		mBouncingTime+=aDeltaTime;
		
	}
    if (IsKeyDown(KEY_DOWN)){
        mVelocity.y += 1.0;
		mBouncingTime+=aDeltaTime;
	}

	if (IsKeyReleased(KEY_LEFT) || IsKeyReleased(KEY_RIGHT) || IsKeyReleased(KEY_UP) ||IsKeyReleased(KEY_DOWN)) mBouncingTime=0;
	if(mBouncingTime > 1.0/9.5f ) mSpeed = 500;
	else mSpeed = mOriginSpeed;
   mScreenPos = Vector2Add(mScreenPos, Vector2Scale(Vector2Normalize(mVelocity), mSpeed * aDeltaTime));
	//mScreenPos = Vector2Add(mScreenPos, Vector2Scale(Vector2Normalize(mVelocity), 1));

   //Checking boundary
   if (mScreenPos.x >= mWindowWidth - mWidth) mScreenPos.x = mWindowWidth - mWidth;
   if (mScreenPos.x <= 0) mScreenPos.x = 0;
   if (mScreenPos.y >= mWindowHeight - mHeight) mScreenPos.y = mWindowHeight - mHeight;
   if (mScreenPos.y <= 0) mScreenPos.y = 0;
   mVelocity = {};
  
   mRunningTime += aDeltaTime;
   //if (mRunningTime >= 7.0f/9.0f)// speed to fire
   if (mRunningTime >= 1.5f/9.0f)// speed to fire
   {
	   //Push back create temp object then copy and delete temp => Texture is deleted
		//mWeapon.push_back(Bullet(LoadTexture("texture/bullet.png"), 4, 1, mWindowWidth, mWindowHeight, mScreenPos));
	    if(mFightingLevel >= 0)
			addBullet(mBullet, mExplosion, 4, 1, mWindowWidth, mWindowHeight, Vector2{mScreenPos.x + mWidth/2, mScreenPos.y});
		
		if(mFightingLevel >= 1)
		{
			addBullet(mBullet, mExplosion, 4, 1, mWindowWidth, mWindowHeight, Vector2{mScreenPos.x, mScreenPos.y + mHeight/2});
			addBullet(mBullet, mExplosion, 4, 1, mWindowWidth, mWindowHeight, Vector2{mScreenPos.x + mWidth, mScreenPos.y + mHeight/2});
		}
		
		if(mFightingLevel >= 2)
		{
			//fighting 45 degree to left
			addBullet(mBullet, mExplosion, 4, 1, mWindowWidth, mWindowHeight, Vector2{mScreenPos.x, mScreenPos.y + mHeight/2}, -45.0f);
			
			//fighting 45 degree to right
			addBullet(mBullet, mExplosion, 4, 1, mWindowWidth, mWindowHeight, Vector2{mScreenPos.x + mWidth, mScreenPos.y+ mHeight/2}, 45.0f);			
		}
		mRunningTime = 0;

		//std::cout << "size of weapon=" << mWeapon.size() << std::endl;
   }

   
/*   for (auto &q: mWeapon)
   {
	   q.Tick(aDeltaTime);
	   if (q.getScreenPos().y < -q.getHeight() ) ;//mWeapon.erase(q);
   }*/
   
	for ( auto it1 = mWeapon.begin(); it1 != mWeapon.end(); it1++)
	{
		it1->Tick(aDeltaTime);
		//if (it1->getScreenPos().y < -it1->getHeight() ) mWeapon.erase(it1);;//mWeapon.erase(q);
	}
	
   BaseSpace::Tick(aDeltaTime);
}

Vector2 Fighter::getScreenPos()
{
    return mScreenPos;
}