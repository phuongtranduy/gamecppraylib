// SPDX-License-Identifier: GPL-2.0
/**
* @file     Fighter.hpp
* @brief    The Fighter class 
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
#ifndef FIGHTER_HPP
#define FIGHTER_HPP
#include "BaseSpace.hpp"
#include "Bullet.hpp"
#include <list>

/**
 * @class Fighter
 * @author PhuongTD1
 * @date 02/09/2022
 * @file Fighter.hpp
 * @brief 
 */
class Fighter : public BaseSpace
{
private:
	Texture2D mBullet{LoadTexture("texture/bullet.png")};
	Texture2D mExplosion{LoadTexture("texture/medium_explosion.png")};
	Texture2D mBigExplosion{LoadTexture("texture/explosion.png")};
	Explosion *mpExplosion{nullptr};
	int mFightingLevel{0};
	float mBouncingTime{0};
public:
    Fighter(Texture2D aImage, float aNumberOfFrameX, float aNumberOfFrameY, float aOffsetX, float aWindowWidth, float aWindowHeight);
    ~Fighter();
    virtual void Tick(float aDeltaTime) override;
    virtual Vector2 getScreenPos() ;
	std::list<Bullet> mWeapon;
	void setFightingLevel(int aFightingLEvel) { mFightingLevel = aFightingLEvel;}
	int getFightingLevel() {return mFightingLevel;}
};

#endif // FIGHTER_HPP
