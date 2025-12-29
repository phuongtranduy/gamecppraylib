

#pragma once
#include "raylib.h"
#include "raymath.h"
#include <string>
#include <cstdint>

class LoadedImage
{
    public:
        LoadedImage(const std::string& imagePath, const uint32_t& numberOfFrameX = 1, const uint32_t& numberOfFrameY = 1);
        ~LoadedImage();

    private:
        std::string m_imagePath;    
        uint32_t m_numberOfFrameX;
        uint32_t m_numberOfFrameY;
        Texture2D m_imageTex2D;
        Image m_image;
        Color* m_imageColor;

};