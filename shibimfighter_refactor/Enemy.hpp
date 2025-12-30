/**
* License
* 
*/
/**
* @file     Enemy.hpp
* @brief    The Enemy class 
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

#ifndef ENEMY_HPP
#define ENEMY_HPP
#include "BaseSpace.hpp"
#include "Fighter.hpp"
#include "Bullet.hpp"
#include <list>

/**
 * @class Enemy
 * @author PhuongTD1
 * @date 02/09/2022
 * @file Enemy.hpp
 * @brief 
 */
class Enemy : public BaseSpace
{
private:
	Fighter * mTarget;
	bool mIsBoss{false};
	Texture2D mTargetBulletTex;
	Texture2D mBossTex;
	Texture2D mFireTargetTex;
	Color * mpBossColor{nullptr};
	Color * mpBulletColor{nullptr};
	Color * mpTargetColor{nullptr};
	float speedOfFiring{};
	
public:
    Enemy() {    
        //std::cout << "default cons\n";
       // BaseSpace::Tick(10);
	}
    Enemy(Texture2D aImage, float aNumberOfFrameX, float aNumberOfFrameY, float aWindowWidth, float aWindowHeight,bool aIsBoss=false);
    ~Enemy();
    virtual void Tick(float aDeltaTime) override;
    virtual Vector2 getScreenPos() override;
	void setTarget(Fighter * aTarget) {mTarget = aTarget; mpTargetColor = mTarget->mpTargetColor;}
	void setIsBoss(bool aIsBoss) {mIsBoss = aIsBoss;}
	virtual void setRotation(float aRotation) override;
	std::list<Enemy> mWeapon;
};

#endif // ENEMY_HPP
