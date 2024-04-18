#include <iostream>
#include "ImageDansDiaporama.h"
using namespace std;

ImageDansDiaporama::ImageDansDiaporama(unsigned int position, unsigned int rang):
    m_pos(position),
    m_rang(rang){
}

ImageDansDiaporama::ImageDansDiaporama(const ImageDansDiaporama & original):
    m_pos(original.m_pos),
    m_rang(original.m_rang){
}

unsigned int ImageDansDiaporama::getPosition() const
{
    return m_pos;
}

unsigned int ImageDansDiaporama::getRang() const
{
    return m_rang;
}

Image ImageDansDiaporama::getImage() const
{
    return m_image;
}

void ImageDansDiaporama::setPosition(unsigned int position)
{
    m_pos = position;
}

void ImageDansDiaporama::setRang(unsigned int rang)
{
    m_rang = rang;
}
