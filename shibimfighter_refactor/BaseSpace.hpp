// SPDX-License-Identifier: GPL-2.0
/**
* @file     BaseSpace.hpp
* @brief    The base class of spaceship
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

#ifndef BASE_SPACE_HPP
#define BASE_SPACE_HPP
#include <iostream>
#include "raylib.h"
#include "raymath.h"

/**
 * @class BaseSpace
 * @author PhuongTD1
 * @date 26/08/2022
 * @file BaseSpace.hpp
 * @brief 
 */

class BaseSpace{

public:
    BaseSpace()=default; ///< Default Constructor
    virtual void Tick(float aDeltaTime); ///< function for it's acitivty on each frame
   virtual Vector2 getScreenPos() {
       return mScreenPos;
    }
	~BaseSpace(){}
   void setScreenPos(Vector2 aScreenPos) { mScreenPos = aScreenPos; }
   void setFrame(float aFrameX, float aFrameY) { mFrameX = aFrameX; mFrameY = aFrameY;}
   bool getAlive() {return mIsAlive;}
   void setAlive(bool aIsAlive) { mIsAlive = aIsAlive; if(!mIsAlive)mIIsAlive = 0;/*numberOfLife=0 when dead*/}
   int getIAlive() {return mIIsAlive;}
   void setIAlive(int aIIsAlive) { mIIsAlive = aIIsAlive; if(mIIsAlive <= 0) setAlive(false);}
   float getWidth() {return mWidth;}
   float getHeight() {return mHeight;}
   void setSpeed(float aSpeed) {mSpeed =mOriginSpeed= aSpeed;}
   void setFrameX(float aFrameX) { mFrameX = aFrameX;}
   void setFrameY(float aFrameY) { mFrameY = aFrameY;}
   void setRotation(float aRotation) { mfRotation = aRotation;}
   void setOrigin(Vector2 aOrigin) {mOrigin = aOrigin;}
   void setAnimation(bool abAnimation){mbAnimation = abAnimation;}
   Rectangle getCollisionRec();
   Texture2D mImage;
   Color * mpColorData{nullptr};
private:
	bool mbAnimation{false};
protected:
    
    const float mUpdateTIme{1.0/12.0}; ///< time to update animation 
    float mRunningTime{0}; ///< Counting for the time      
    float mSpeed{500.0f};
	float mOriginSpeed{500.0f};
    float mFrameX{};
	float mFrameY{};
    float mNumberofFrameX{};
    float mNumberofFrameY{};
    Vector2 mScreenPos{};
    float mWindowWidth{};
    float mWindowHeight{};
	float mWidth{}; ///< the width of character
	float mHeight{}; ///< the height of character
	float mScale{1.0};
	bool mIsAlive{true};
	int mIIsAlive{1};
	float mOffsetX{};
	float mfRotation{}; ///< float degree ex: -90.0 degree
	Vector2 mVelocity{};
	Vector2 mOrigin{};
};


#endif //BASE_SPACE_HPP