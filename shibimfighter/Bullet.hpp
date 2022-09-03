// SPDX-License-Identifier: GPL-2.0
/**
* @file     Bullet.hpp
* @brief    The Bullet class
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
#ifndef BULLET_HPP
#define BULLET_HPP

#include "BaseSpace.hpp"
#include "Explosion.hpp"


/**
 * @class Bullet
 * @author PhuongTD1
 * @date 02/09/2022
 * @file Bullet.hpp
 * @brief 
 */
class Bullet: public BaseSpace
{
	Texture2D mExplosion;
	bool mBeRemoved{false};
public:
	Bullet(Texture2D aImage, float aNumberOfFrameX, float aNumberOfFrameY, float aWindowWidth, float aWindowHeight);
	Bullet(Texture2D aImage, Texture2D aExplosion, float aNumberOfFrameX, float aNumberOfFrameY, float aWindowWidth, float aWindowHeight, Vector2 aScreenPos);
	~Bullet();
	virtual void Tick(float aDeltaTime) override;
    virtual Vector2 getScreenPos() ;
	Explosion *mpExplosion{nullptr};
	bool getBeRemoved() {return mBeRemoved;}
};



#endif // BULLET_HPP
