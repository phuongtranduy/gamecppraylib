// SPDX-License-Identifier: GPL-2.0
/**
* @file     main.cpp
* @brief    main fucntion
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
#include "raylib.h"
#include <iostream>
#include "raymath.h"
#include "Enemy.hpp"
#include "Fighter.hpp"
#include "Bullet.hpp"
#include "Explosion.hpp"
#include <iterator>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <thread>
#include "PowerDrug.hpp"
#include <utility>
#include <chrono>
#include <algorithm>
//#include "mingw.thread.h"
// g++ -Wall -std=c++14  main.cpp  -o main -I /home/s32v/raylib/raylib/build/raylib/include -L /home/s32v/raylib/raylib/build/raylib/ -lraylib -lGL -lm -lpthread -ldl -lrt -lX11
// gcc  main.cpp  -o main -I /home/s32v/raylib/raylib/build/raylib/include -L /home/s32v/raylib/raylib/build/raylib/ -lraylib -lGL -lm -lpthread -ldl -lrt -lX11


int main(void)
{

    std::cout << "==========================\n";
    
    // Initialization
    //--------------------------------------------------------------------------------------
    const int screenWidth = 560;
    const int screenHeight = 660;
	float fPosXRand{};
	bool Fighterlife{true};
	/* generate secret number between 1 and 10: */
	fPosXRand = (rand() % 10)*50;
	  /* initialize random seed: */
	srand (time(NULL));

    InitWindow(screenWidth, screenHeight, "fighter- phuong1988vn@gmail.com");
    SetTargetFPS(60);                   // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------
	
	Texture2D enemyText {LoadTexture("texture/modern_rival_space_s.png")};
    Enemy enemy(enemyText, 4, 4, screenWidth, screenHeight);
	std::list<Enemy> listOfEnemy;
	std::list<PowerDrug> listOfPower;
	float runningTimeofEnemy{};
	float timeForPowerDrug{};
	int numberOfPowerDrug{};
	
	
	Fighter fighter(LoadTexture("texture/terrorist_small.png"), 1, 1, 50, screenWidth, screenHeight);
	fighter.setSpeed(100);
	
	Texture2D backgroundTex {LoadTexture("texture/universe.png")};
	Texture2D powerDrugTex {LoadTexture("texture/shield.png")};
	Texture2D explosionTex {LoadTexture("texture/explosion.png")};
	Texture2D bossText {LoadTexture("texture/boss.png")};
	std::list<Explosion> listOfBossExplosion;
	
	Enemy enemyFire(LoadTexture("texture/firetarget.png"), 8, 1, screenWidth, screenHeight);
	enemyFire.setAnimation(true);
	
	Enemy eBoss(bossText, 1, 1, screenWidth, screenHeight, true);
	eBoss.setTarget(&fighter);
	eBoss.setScreenPos(Vector2{screenWidth/2.0-eBoss.getWidth()/2.0, -eBoss.getHeight()});
	eBoss.setSpeed(50);
	eBoss.setIAlive(290);// dead when colliding with 50 bullets
	int totalOfEnemyOut{0};
	int totalOfKilledEnemy{0};
	int totalOfKilledEnemyForCountToSpawnPowerDrug{0};
	const int numberOfEnemyBeforeBoss{50};
	float speedOfSpawningEnemy{7.0f/9.0f};\
	int BossLife{0};
	
	InitAudioDevice();
    Sound sound = LoadSound("audio/audio_background.wav");
	Sound hit = LoadSound("audio/hit_enemy.mp3");
	Sound failsound = LoadSound("audio/explosion.mp3");
	float timeForBossExplosionSound{};
	int totalBossExplosion{};
	//Sound hitlevelsound = LoadSound("audio/hitlevel.mp3");
	float bgY{};
	bool bStopped{false};
	char buffString[100];
	char buffBossLife[100];
	//Thread to play background sound effect
	std::thread backgroundSoundthread([&](int n){
			PlaySound(sound);
			std::cout << "Playing background sound\n";
			while(!bStopped){
				if(!IsSoundPlaying(sound))
				{
					std::cout << "Background Sound ended\n";
					PlaySound(sound);
				}
			}
			StopSound(sound);
		},10);

	// Main game loop
    while (!WindowShouldClose())        // Detect window close button or ESC key
    {
		
        const float dT{GetFrameTime()};
        
        // Update
        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();
            ClearBackground(BLANK);
			
			// Scroll background
			bgY += 20 * dT;
			if (bgY >= backgroundTex.height*2)
			{
				bgY = 0.0;
			}
			
						// draw the background
			Vector2 bg1Pos{0.0, bgY};
			DrawTextureEx(backgroundTex, bg1Pos, 0.0, 2.0, WHITE);
			Vector2 bg2Pos{0.0, bgY - backgroundTex.height*2};
			DrawTextureEx(backgroundTex, bg2Pos, 0.0, 2.0, WHITE);
			
			//ClearBackground(WHITE);
            //DrawFPS(0, 10);
			
			
			runningTimeofEnemy += dT;
			timeForPowerDrug += dT;
			
			if ((totalOfKilledEnemyForCountToSpawnPowerDrug > 0) && (totalOfKilledEnemyForCountToSpawnPowerDrug % 20 == 0) && (numberOfPowerDrug < 2)) {
			//if (timeForPowerDrug >= 10 && numberOfPowerDrug < 2) {
				listOfPower.emplace_back(powerDrugTex, 1, 1, screenWidth, screenHeight);
				listOfPower.back().setTarget(&fighter);//Net to set taret if not => crash when checking in Tick of powerDrug
				numberOfPowerDrug++;
				timeForPowerDrug = 0;
				totalOfKilledEnemyForCountToSpawnPowerDrug = 0;//Reset for the next
				std::cout << "PowerDrug comes up" << std::endl;
			}
			for ( auto it = listOfPower.begin() ; it != listOfPower.end(); it)
			{
				it->Tick(dT);
				if (it->getScreenPos().y >= screenHeight + it->getHeight())
			    {
					//Erase  object when it goes out of screen
					it=listOfPower.erase(it);//return the next it
					continue;//to avoid nonexisting mem;
			    } 
				it++;
			}
			
			if (runningTimeofEnemy >= speedOfSpawningEnemy && !bStopped)
			{
				//Add enemy into it 
				listOfEnemy.emplace_back(enemyText, 4, 4, screenWidth, screenHeight);
				fPosXRand = (rand() % 10)*50;
				listOfEnemy.back().setScreenPos(Vector2{fPosXRand, -50});
				listOfEnemy.back().setFrameX(rand() % 4);
				listOfEnemy.back().setFrameY(rand() % 4);
				listOfEnemy.back().setRotation(180.0f);
				listOfEnemy.back().setOrigin(Vector2{listOfEnemy.back().getWidth(), listOfEnemy.back().getHeight()});
				listOfEnemy.back().setTarget(&fighter);
				runningTimeofEnemy = 0;
				totalOfEnemyOut++;
				std::cout << "Total = " << listOfEnemy.size() << std::endl;
			}
			
			//BOSS go
			//if(totalOfEnemyOut >= 0 /*numberOfEnemyBeforeBoss*/) eBoss.Tick(dT);
			if(totalOfEnemyOut >= numberOfEnemyBeforeBoss) {
				eBoss.Tick(dT);	//Boss with Target and Bullet of Boss with Target will check here		
				if (fighter.getAlive()) BossLife =  eBoss.getIAlive();
				sprintf (buffBossLife, "BossLife: %d", BossLife);
				DrawText(buffBossLife, 0, 30, 20, YELLOW);
			}

			//refactor
			auto newEnd = std::remove_if(listOfEnemy.begin(), listOfEnemy.end(), [&](Enemy& item){
				// enemy item false
				if (!item.getAlive())
			    {
					return true;
			    }

				for ( auto it1 = fighter.mWeapon.begin(); it1 != fighter.mWeapon.end() && fighter.getAlive(); it1++)
				{
					if (CheckCollisionRecs(item.getCollisionRec(), it1->getCollisionRec()) && it1->getAlive())
					{
						//Kill enemy
						totalOfKilledEnemy++;
						totalOfKilledEnemyForCountToSpawnPowerDrug++;
						item.setAlive(false);
						it1->setAlive(false);//weapon
						//Remove enemy
						PlaySound(hit);
						return true;
					}
				}
				return false;
			});

			//remove enemy
			listOfEnemy.erase(newEnd, listOfEnemy.end());

			//draw enemy again
			for ( auto it = listOfEnemy.begin() ; it != listOfEnemy.end(); it++)
			{
				it->Tick(dT);//this also check target fighter with enemy
			}

			//remove bullet that is false
			auto newWeaponFighterEnd = std::remove_if(fighter.mWeapon.begin(), fighter.mWeapon.end(), [&](Bullet& item){
				if(!item.getAlive())
				{
					//Add explosion to list of explosion
					if(!item.getBeRemoved())
					{
						listOfBossExplosion.emplace_back(explosionTex, 8, 1, screenWidth, screenHeight, Vector2{item.getScreenPos()});
					}
					return true;
				}
				else
				{
					return false;
				}
			});
			//remove bullet of fighter not alive
			fighter.mWeapon.erase(newWeaponFighterEnd, fighter.mWeapon.end());
			
			
		
			//////////////////////
			//Iternale through all enemy => the purpose is to remove enemy
			// for ( auto it = listOfEnemy.begin() ; it != listOfEnemy.end(); it)
			// {
			// 	it->Tick(dT);//this also check target firhter with enemy
			// 	if (it->getScreenPos().y >= screenHeight + it->getHeight())
			//     {
			// 		//Erase enemy object when it goes out of screen
			// 		it=listOfEnemy.erase(it);//return the next it
			// 		continue;//to avoid nonexisting mem;
			//     } 
				
			// 	//Interate to check collision with bullets of target. Iterate all bullets
			// 	for ( auto it1 = fighter.mWeapon.begin(); it1 != fighter.mWeapon.end() && fighter.getAlive(); it1)
			// 	{
			// 		if (CheckCollisionRecs(it->getCollisionRec(), it1->getCollisionRec()) && it1->getAlive())
			// 		{
			// 			//Kill enemy
			// 			totalOfKilledEnemy++;
			// 			totalOfKilledEnemyForCountToSpawnPowerDrug++;
			// 			it->setAlive(false);
			// 			it1->setAlive(false);
			// 			//Remove enemy
			// 			PlaySound(hit);
			// 			it=listOfEnemy.erase(it);
			// 			std::cout << "Enemy is Killed...\n";
			// 			goto NEXTELEMENT_IT;
			// 			//fighter.mWeapon.erase(it1);//Do not remove bullet to make explosion happen
			// 		}
					
			// 		//Check to remove bullet of Target
			// 		if(it1->getAlive() == false){
						
			// 			if (it1->mpExplosion != nullptr) {
			// 				if (it1->mpExplosion->getAlive() == false){ 
			// 					//std::cout << "Can remove bullet" << std::endl;
			// 					it1 = fighter.mWeapon.erase(it1);
			// 					goto NEXT_ELEMENT_IT1;
			// 				}
			// 			}
			// 			if (it1->getBeRemoved()){//Remove bullet when it is locked
			// 				it1 = fighter.mWeapon.erase(it1);
			// 				goto NEXT_ELEMENT_IT1;
			// 			}
						
			// 		}
						
			// 		it1++;	
			// 		NEXT_ELEMENT_IT1: ;
			// 	}//for it1
			// 	it++;
			// 	NEXTELEMENT_IT: ; //need semi-colon here for 1 empty command
			// }

			fighter.Tick(dT);//will check weapon and draw on it
			
			if (fighter.getAlive() == false){
				DrawText("GAME OVER!!!", screenWidth/4, screenHeight/2, 50, RED);
				if(Fighterlife){
					std::cout << "Play sound end game\n";
					PlaySound(failsound);
					Fighterlife = false;// if the sound is played too many time continuosly => it will stuck
				}

			}
			//if (eBoss.getAlive() == false)
			if (eBoss.getAlive() == false && fighter.getAlive() ==  true)
			{

				eBoss.mWeapon.clear();
				listOfEnemy.clear();
				listOfPower.clear();
				DrawText("YOU WILL!!!", screenWidth/4, screenHeight/2, 50, RED);
				
				timeForBossExplosionSound+=dT;
				if (IsSoundPlaying(sound)) {bStopped= true;StopSound(sound);//Stop background sound
				}
				if (timeForBossExplosionSound >= 0.5){
					if(totalBossExplosion <= 3)
					{
						totalBossExplosion++;
						PlaySound(failsound);
						listOfBossExplosion.emplace_back(explosionTex, 8, 1, screenWidth, screenHeight, Vector2{(rand() % 10) *50,screenHeight/2});
					}
					timeForBossExplosionSound = 0;
				}
			}
			
			for ( auto ex = listOfBossExplosion.begin(); ex !=listOfBossExplosion.end(); ex++)
			{
				ex->Tick(dT);
			}

			auto newExplosionEnd = std::remove_if(listOfBossExplosion.begin(), listOfBossExplosion.end(), [&](auto& item){
				return !item.getAlive();
			}); 
			listOfBossExplosion.erase(newExplosionEnd, listOfBossExplosion.end());
			//std::cout << "Size of listBossExplosion:" << listOfBossExplosion.size() << std::endl;
			sprintf (buffString, "Killed Total: %d ", totalOfKilledEnemy);
			DrawText(buffString, 0, 0, 20, WHITE);
			//enemyFire.Tick(dT);
        EndDrawing();
        //----------------------------------------------------------------------------------
    }
	bStopped = true;
	backgroundSoundthread.join();
    // De-Initialization
	UnloadSound(sound);
	UnloadSound(hit);
	UnloadSound(failsound);
	CloseAudioDevice();
    // UnloadTexture(bullet);
    //--------------------------------------------------------------------------------------
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}
