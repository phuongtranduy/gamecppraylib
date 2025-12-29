#include "raylib.h"
#include <iostream>
int main() {
    // ... Initialization (InitWindow, etc.) ...
    InitWindow(800, 450, "raylib image cropping example");

    // Load an image
    Image image = LoadImage("texture/modern_rival_space_s.png");

    // Define the crop area (e.g., crop a 100x100 area starting at x=50, y=50)
    
    Rectangle cropArea = {0, 0, image.width/4, image.height/4 };

    // Crop the image (modifies 'image' in-place)
    ImageCrop(&image, cropArea);

    Color* imageColorBeforeRotate =  LoadImageColors(image);
    ImageRotate(&image, 180);//ImageRotate(Image *image, int degrees);
    Color* imageColorAfterRotate =  LoadImageColors(image);

    std::cout << "PPPPPPPPPPPPP image.width=" << image.width << " image.height=" << image.height << std::endl;
    int x = image.width / 2;
    int y = 7*image.height/8;
    Color* pointofBeforeRotate = imageColorBeforeRotate + y * image.width + x;

    std::cout << "BeforeRotatePoint: r=" <<  static_cast<int>(pointofBeforeRotate->r)
                                << " g=" <<  static_cast<int>(pointofBeforeRotate->g)
                                << " b=" <<  static_cast<int>(pointofBeforeRotate->b)
                                << " a=" <<  static_cast<int>(pointofBeforeRotate->a) 
                                << std::endl;
    std::cout << "=====================\n";
    Color* pointofAfterRotate = imageColorAfterRotate + y * image.width + x;
    std::cout << "BeforeAfterPoint: r=" <<   static_cast<int>(pointofAfterRotate->r)
                                << " g=" <<  static_cast<int>(pointofAfterRotate->g)
                                << " b=" <<  static_cast<int>(pointofAfterRotate->b)
                                << " a=" <<  static_cast<int>(pointofAfterRotate->a) 
                                << std::endl;
    
    /*
INFO: IMAGE: Data loaded successfully (160x160 | R8G8B8A8 | 1 mipmaps)
PPPPPPPPPPPPP image.width=40 image.height=40
BeforeRotatePoint: r=83 g=78 b=69 a=55
=====================
BeforeAfterPoint: r=90 g=53 b=46 a=143
INFO: TEXTURE: [ID 3] Texture loaded successfully (40x40 | R8G8B8A8 | 1 mipmaps)

    typedef struct Color {
    unsigned char r;        // Color red value
    unsigned char g;        // Color green value
    unsigned char b;        // Color blue value
    unsigned char a;        // Color alpha value
    } Color;
    */

    // Upload the modified image to GPU memory to create a texture for drawing
    Texture2D texture = LoadTextureFromImage(image);

    // Unload the image data from RAM after creating the texture
    UnloadImage(image);

    // ... Main game loop and drawing ...
    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(RAYWHITE);
        DrawTexture(texture, 100, 100, WHITE); // Draw the cropped texture
        DrawText("Cropped image", 100, 250, 20, DARKGRAY);
        EndDrawing();
    }

    // ... De-initialization (UnloadTexture, CloseWindow, etc.) ...
    UnloadTexture(texture);
    CloseWindow();
    return 0;
}