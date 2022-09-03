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

#ifndef EXPLOSION_HPP
#define EXPLOSION_HPP
#include "BaseSpace.hpp"

/**
 * @class Explosion
 * @author PhuongTD1
 * @date 02/09/2022
 * @file Explosion.hpp
 * @brief 
 */
class Explosion : public BaseSpace
{
public:
	Explosion(Texture2D aImage, float aNumberOfFrameX, float aNumberOfFrameY, float aWindowWidth, float aWindowHeight);
	Explosion(Texture2D aImage, float aNumberOfFrameX, float aNumberOfFrameY, float aWindowWidth, float aWindowHeight, Vector2 aScreenPos);
	~Explosion();
	virtual void Tick(float aDeltaTime) override;
    virtual Vector2 getScreenPos() ;

};

#endif // EXPLOSION_HPP
