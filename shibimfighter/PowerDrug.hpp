/**
* License
* 
*/
/**
* @file     PowerDrug.hpp
* @brief    The PowerDrug class
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
#ifndef POWERDRUG_HPP
#define POWERDRUG_HPP
#include "BaseSpace.hpp"
#include "Fighter.hpp"

/**
 * @class PowerDrug
 * @author PhuongTD1
 * @date 02/09/2022
 * @file PowerDrug.hpp
 * @brief 
 */
class PowerDrug : public BaseSpace
{
	Fighter * mTarget;
	Sound hitlevelsound;
public:
	PowerDrug(Texture2D aImage, float aNumberOfFrameX, float aNumberOfFrameY, float aWindowWidth, float aWindowHeight);
	~PowerDrug();
    virtual void Tick(float aDeltaTime) override;
    virtual Vector2 getScreenPos() override;
	void setTarget(Fighter * aTarget) {mTarget = aTarget;}
};

#endif // POWERDRUG_HPP
