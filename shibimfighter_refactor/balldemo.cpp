//@ Makefile: mingw32-make
//@ Exe: ./build/Test.exe
#include "include/raylib.h"
#include "include/raymath.h"
#include "include/physac.h"

int main() {
    int screenWidth = 1000;
    int screenHeight = 1000;

    InitWindow(screenWidth, screenHeight, "Ball");
    // void SetWindowIcon(Image "");
    Vector2 ballPosition = {(float)screenWidth/2, (float)screenHeight/2};
    SetTargetFPS(60);

    while (!WindowShouldClose()) {
        if (IsKeyDown(KEY_D)) ballPosition.x += 5.0f;
        if (IsKeyDown(KEY_A)) ballPosition.x -= 5.0f;
        if (IsKeyDown(KEY_W)) ballPosition.y -= 5.0f;
        if (IsKeyDown(KEY_S)) ballPosition.y += 5.0f;

        BeginDrawing();
            ClearBackground(Color {255, 255, 255, 255});
            DrawText("move the ball with wasd keys", 10, 10, 50, DARKGRAY);
            DrawCircleV(ballPosition, 50, MAROON);
        EndDrawing();
    }
    CloseWindow();
    return 0;
}