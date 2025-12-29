

#pragma once
#include "raylib.h"
#include "raymath.h"
#include <string>
#include <cstdint>

class LoadedImage /*RAII object */
{
    public:
        LoadedImage(const std::string& imagePath, const uint32_t& numberOfFrameX = 1, const uint32_t& numberOfFrameY = 1);
        ~LoadedImage();
        const Texture2D& GetImageTex2D() const
        {
            return m_imageTex2D;
        }

        const Color* GetImageColorPointer() const
        {
            return m_imageColor;
        }

    private:
        std::string m_imagePath;    
        uint32_t m_numberOfFrameX;
        uint32_t m_numberOfFrameY;
        Texture2D m_imageTex2D;
        Image m_image;
        Color* m_imageColor;
};