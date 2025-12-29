// SPDX-License-Identifier: GPL-2.0
/**
* @file     BaseSpace.cpp
* @brief    Definition for the base class of spaceship
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
#include "BaseSpace.hpp"
BaseSpace::BaseSpace(std::shared_ptr<LoadedImage> loadedImage)
: m_loadedImage(loadedImage)
{}

void BaseSpace::Tick(float aDeltaTime) {
	
    // draw the character	
    Rectangle source{mFrameX * mWidth+mOffsetX, mFrameY*mHeight, mWidth, mHeight};
    Rectangle dest{mScreenPos.x, mScreenPos.y, mScale*mWidth, mScale*mHeight};
    DrawTexturePro(mImage, source, dest, mOrigin, mfRotation, WHITE);
	//DrawTexturePro(m_loadedImage->GetImageTex2D(), source, dest, mOrigin, mfRotation, WHITE);
	//Show all rectangles bounding to objects
	DrawRectangleLines(mScreenPos.x, mScreenPos.y, mScale*mWidth, mScale*mHeight,RED);

	if(mbAnimation)
	{
		mFrameX++;
		if (mFrameX >= mNumberofFrameX) mFrameX = 0;
	}
} 

Rectangle BaseSpace::getCollisionRec() {
	
	return Rectangle {
		mScreenPos.x,
		mScreenPos.y,
		mWidth,
		mHeight
		};	
	
}