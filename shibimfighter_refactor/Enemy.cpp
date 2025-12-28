// SPDX-License-Identifier: GPL-2.0
/**
* @file     Enemy.hpp
* @brief    The Enemy class' definition
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
#include "Enemy.hpp"
#include <algorithm>

Enemy::Enemy(Texture2D aImage, float aNumberOfFrameX, float aNumberOfFrameY, float aWindowWidth, float aWindowHeight, bool aIsBoss)
{
    BaseSpace::mImage = aImage;
    BaseSpace::mWindowWidth = aWindowWidth;
    BaseSpace::mWindowHeight = aWindowHeight;
    BaseSpace::mNumberofFrameX = aNumberOfFrameX;
	BaseSpace::mNumberofFrameY = aNumberOfFrameY;
	BaseSpace::mWidth = BaseSpace::mImage.width/BaseSpace::mNumberofFrameX;
	BaseSpace::mHeight = BaseSpace::mImage.height/BaseSpace::mNumberofFrameY;
	setSpeed(80);
	setScreenPos(Vector2{mWindowWidth/2, -mHeight});
	mIsBoss = aIsBoss;
	if(mIsBoss)
	{
			mTargetBulletTex=LoadTexture("texture/bullet.png");
			mFireTargetTex=LoadTexture("texture/firetarget.png");
	        //mBossTex =LoadTexture("texture/boss.png");
			//Image bossImage =GetTextureData(mBossTex);//
			Image bossImage = LoadImage("texture/boss.png");
			mpBossColor = LoadImageColors(bossImage);
							
			//Image targetImage =GetTextureData(mTargetBulletTex);//LoadImage("texture/boss.png");
			Image targetImage = LoadImage("texture/boss.png");
			mpBulletColor = LoadImageColors(targetImage);
			mFireTargetTex=LoadTexture("texture/firetarget.png");
	}
	
}

Enemy::~Enemy()
{
	std::cout << "Calling Destructor for Enemy" << std::endl;
}

void Enemy::Tick(float aDeltaTime)
{
  //draw the Enemy
  if (!getAlive()) return;
  
   mVelocity.y = 1;
   mVelocity.x = 0;
   mScreenPos = Vector2Add(mScreenPos, Vector2Scale(Vector2Normalize(mVelocity), mSpeed * aDeltaTime));
   //Checking boundary
   if (mScreenPos.y >= mWindowHeight + mHeight) setAlive(false);
   mVelocity = {};
   

   
   //
   
   //Check collision with enemy space and target
   if (CheckCollisionRecs(getCollisionRec(), mTarget->getCollisionRec()) && mTarget->getAlive())
   {
	   if(mIsBoss == false) mTarget->setAlive(false);
	   else
	   { //THis is Boss
		    //Pixel checking data
		    //std::cout << "starting checking Boss with Target " << std::endl; //Avoid load texture too many times
		   	//Image bossImage = GetTextureData(mImage);//LoadImage("texture/boss.png");
			Image bossImage = LoadImage("texture/boss.png");
			Color *bossColor = LoadImageColors(bossImage);
			Color *pbossColor = bossColor;
			//Image targetImage = GetTextureData(mTarget->mImage);//LoadImage("texture/boss.png");
			Image targetImage = LoadImage("texture/boss.png");
			Color *targetColor = LoadImageColors(targetImage);
			Color *ptargetColor = targetColor;
			
			Rectangle temp = GetCollisionRec(getCollisionRec(),mTarget->getCollisionRec());
			//std::cout << "BOSSPPP: x=" << temp.x << " y=" << temp.y << "width= " << temp.width << " height=" << temp.height <<std::endl;
			//std::cout << "BOSSHPP cast x=" << static_cast<int>(temp.width)<< " cast y=" << static_cast<int>(temp.height) << std::endl;
			Vector2 collisionRectCoor{temp.x, temp.y};
			
			Vector2 startpointBoss = Vector2Subtract(collisionRectCoor, mScreenPos);
			Vector2 startpointTarget = Vector2Subtract(collisionRectCoor, mTarget->getScreenPos());
			pbossColor += static_cast<int>(mWidth) * static_cast<int>(startpointBoss.y) + static_cast<int>(startpointBoss.x);
			ptargetColor += static_cast<int>(mTarget->getWidth()) * static_cast<int>(startpointTarget.y) + static_cast<int>(startpointTarget.x);
			bool hit{false};
			int total{0};
			Color* backupBossPointer =pbossColor;
			Color* backupTargetPointer= ptargetColor;
			for (int i = 0; i < static_cast<int>(temp.width); i++)
				for(int j=0; j < static_cast<int>(temp.height); j++)
				{
						pbossColor=backupBossPointer + static_cast<int>(mWidth)*j + i;
						ptargetColor=backupTargetPointer+ static_cast<int>(mTarget->getWidth())*j + i;
						total+= pbossColor->r & ptargetColor->r + pbossColor->g & ptargetColor->g + pbossColor->b & ptargetColor->b+pbossColor->a & ptargetColor->a;
				}
			if (total) hit = true;
			if (hit) {
				//std::cout << "HIT TARGET__________" << std::endl;
				mTarget->setAlive(false);
				return;// return when target is killed
			}
		}
	

   }
   
   
   	//if(0)
	if(mIsBoss && mTarget->getAlive())
	{
	
			//Check collision of Boss with Bullet
			//std::cout << "starting checking Boss bullet" << std::endl; //Avoid load texture too many times
			//std::cout << "pbossColor=" << pbossColor << " ptargetColor= " << ptargetColor << std::endl;		
			//Interate to check collision with bullet. Iterate all bullets
			for ( auto it1 = mTarget->mWeapon.begin(); it1 != mTarget->mWeapon.end(); it1++)
			{
				if (CheckCollisionRecs(getCollisionRec(), it1->getCollisionRec()) && it1->getAlive())
				{
					
			
					Color *pbossColor = mpBossColor;
				    Color *ptargetColor = mpBulletColor;	
							
							Rectangle temp = GetCollisionRec(getCollisionRec(),it1->getCollisionRec());
							//std::cout << "BOSSPPP: x=" << temp.x << " y=" << temp.y << "width= " << temp.width << " height=" << temp.height << " bulletsize=" << mTarget->mWeapon.size()<< std::endl;
							//std::cout << "BOSSHPP cast x=" << static_cast<int>(temp.width)<< " cast y=" << static_cast<int>(temp.height) << std::endl;
							Vector2 collisionRectCoor{temp.x, temp.y};
							
							Vector2 startpointBoss = Vector2Subtract(collisionRectCoor, mScreenPos);
							Vector2 startpointTarget = Vector2Subtract(collisionRectCoor, it1->getScreenPos());
							pbossColor += static_cast<int>(mWidth) * static_cast<int>(startpointBoss.y) + static_cast<int>(startpointBoss.x);
							ptargetColor += static_cast<int>(it1->getWidth()) * static_cast<int>(startpointTarget.y) + static_cast<int>(startpointTarget.x);
							bool hit{false};
							int total{0};
							Color* backupBossPointer =pbossColor;
							Color* backupTargetPointer= ptargetColor;
							for (int i = 0; i < static_cast<int>(temp.width); i++)
								for(int j=0; j < static_cast<int>(temp.height); j++)
								{// std::cout << "i=" << i << " j=" << j << std::endl;
										pbossColor=backupBossPointer + static_cast<int>(mWidth)*j + i;
										ptargetColor=backupTargetPointer+ static_cast<int>(it1->getWidth())*j + i;
										total+= pbossColor->r & ptargetColor->r + pbossColor->g & ptargetColor->g + pbossColor->b & ptargetColor->b+pbossColor->a & ptargetColor->a;
								}
							if (total) hit = true;
							if (hit) {
								//std::cout << "BOSS BOOMMMMMMMMMM with Boss lives=" << this->getIAlive() << std::endl;
								it1->setAlive(false);
								this->setIAlive(this->getIAlive()-1);
							}
				}
			}
	}
	
	
	if (mIsBoss && mScreenPos.y >= -4*mHeight/5.0f)
	{
			speedOfFiring+=aDeltaTime;
			if(speedOfFiring >= 2.0f)
			{
				//Center
				mWeapon.emplace_back(mFireTargetTex, 8, 1, mWindowWidth, mWindowHeight);
				mWeapon.back().setScreenPos(Vector2{mScreenPos.x+mWidth/2-15, mScreenPos.y+ mHeight - mWeapon.back().getHeight()});
				mWeapon.back().setTarget(mTarget);
				mWeapon.back().setAnimation(true);
				mWeapon.back().setSpeed(200);
				//Left
				mWeapon.emplace_back(mFireTargetTex, 8, 1, mWindowWidth, mWindowHeight);
				mWeapon.back().setScreenPos(Vector2{mScreenPos.x+mWidth/4-6, mScreenPos.y});
				mWeapon.back().setTarget(mTarget);
				mWeapon.back().setAnimation(true);
				mWeapon.back().setSpeed(200);
				
				mWeapon.emplace_back(mFireTargetTex, 8, 1, mWindowWidth, mWindowHeight);
				mWeapon.back().setScreenPos(Vector2{mScreenPos.x+mWidth/8, mScreenPos.y - 5});
				mWeapon.back().setTarget(mTarget);
				mWeapon.back().setAnimation(true);
				mWeapon.back().setSpeed(200);	
				
				//Right
				mWeapon.emplace_back(mFireTargetTex, 8, 1, mWindowWidth, mWindowHeight);
				mWeapon.back().setScreenPos(Vector2{mScreenPos.x+3*mWidth/4-21, mScreenPos.y});
				mWeapon.back().setTarget(mTarget);
				mWeapon.back().setAnimation(true);
				mWeapon.back().setSpeed(200);
				speedOfFiring = 0;
				
				mWeapon.emplace_back(mFireTargetTex, 8, 1, mWindowWidth, mWindowHeight);
				mWeapon.back().setScreenPos(Vector2{mScreenPos.x+7*mWidth/8-31, mScreenPos.y -5});
				mWeapon.back().setTarget(mTarget);
				mWeapon.back().setAnimation(true);
				mWeapon.back().setSpeed(200);
				speedOfFiring = 0;
			}

			//Refactoring. Note weapon of Boss i enemy. Weapon of fighter is Bullet
			auto newEnd = std::remove_if(mWeapon.begin(), mWeapon.end(), [&](Enemy& item){
				for ( auto it1 = mTarget->mWeapon.begin(); it1 != mTarget->mWeapon.end() && mTarget->getAlive(); it1++)
				{
					if (CheckCollisionRecs(item.getCollisionRec(), it1->getCollisionRec()) && it1->getAlive())
					{
						item.setAlive(false);
						it1->setAlive(false);
						return true;
					}
				}	
			});

			mWeapon.erase(newEnd, mWeapon.end());
			
			//draw weapon again
			for ( auto it = mWeapon.begin() ; it != mWeapon.end(); it++)
			{
				it->Tick(aDeltaTime);
			}

			//refactoring this
			// for ( auto it = mWeapon.begin() ; it != mWeapon.end(); it)
			// {
			// 	it->Tick(aDeltaTime);
			// 	for ( auto it1 = mTarget->mWeapon.begin(); it1 != mTarget->mWeapon.end() && mTarget->getAlive(); it1)
			// 	{
			// 		if (CheckCollisionRecs(it->getCollisionRec(), it1->getCollisionRec()) && it1->getAlive())
			// 		{
			// 			it->setAlive(false);
			// 			it1->setAlive(false);
			// 			//Remove enemy
			// 			it=mWeapon.erase(it);
			// 			std::cout << "Weapon Enemy is Killed...\n";
			// 			goto NEXTWEAPONENEMY_IT;
			// 			//fighter.mWeapon.erase(it1);//Do not remove bullet to make explosion happen
			// 		}
			// 		it1++;
			// 	}	
			// 	it++;
			// 	NEXTWEAPONENEMY_IT:;
			// }

	}
	
	
	BaseSpace::Tick(aDeltaTime);
   //END OF TICK function
}
Vector2 Enemy::getScreenPos()
{
   // std::cout << "Enenmy Screen POS\n";
    return mScreenPos;
}
  