


#include "LoadedImage.hpp"
#include <filesystem>
#include <sstream>

LoadedImage::LoadedImage(const std::string& imagePath, const uint32_t& numberOfFrameX, const uint32_t& numberOfFrameY)
    : m_imagePath(imagePath)
    , m_numberOfFrameX(numberOfFrameX)
    , m_numberOfFrameY(numberOfFrameY)
    , m_imageColor(nullptr)
{
    if(!std::filesystem::exists(m_imagePath))
    {
        std::stringstream ss;
        ss << m_imagePath << " does not exist.";
        throw std::runtime_error(ss.str());
    }
    
    m_imageTex2D = LoadTexture(m_imagePath.c_str());
    m_image = LoadImage(m_imagePath.c_str());
    m_imageColor = LoadImageColors(m_image);
}

LoadedImage::~LoadedImage()
{
    if(m_imageColor != nullptr)
    {
        UnloadImageColors(m_imageColor);
    }
    UnloadImage(m_image);
    UnloadTexture(m_imageTex2D);
}