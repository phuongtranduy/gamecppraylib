# gamecppraylib
develop game cpp raylib
Please see the video about game on youtube link: https://www.youtube.com/watch?v=ZaC7R9c_1As

Collision detection with Boss: using How pixels perfect collision detection works?

##Using dt(deltaTime) with function  const float dT{GetFrameTime()}; //GetFrameTime: 
GetFrameTime  // Get time in seconds for last frame drawn (delta time) : between 2 times of calling BeginDrawing
    mScreenPos = Vector2Add(mScreenPos, Vector2Scale(Vector2Normalize(mVelocity), mSpeed * aDeltaTime));
   //Checking boundary
   
If we have speed*dT , we will get deltaPosition for object It will avoid lag shift for movement object

int main()
{
    //Initializing
    while(1)
    {
        const float dT{GetFrameTime()};
        
        // Update
        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();
            ClearBackground(BLANK);
            //Process Data
            //calling obj.Tick(): to updata

        EndDrawing();
    }

    //Deinitilizing
}

===============================
Note run Doxygen
doxygen Doxyfile
remember edit: INPUT=???
INPUT                  = /home/phuongtran/training/test/working/ssinew/src

open folder html generated and open file index.html

====================================
