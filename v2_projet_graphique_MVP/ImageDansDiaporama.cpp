#include <iostream>
#include "ImageDansDiaporama.h"
using namespace std;

ImageDansDiaporama::ImageDansDiaporama():
    Image(),
    m_pos(0),
    m_rang(0){
}

ImageDansDiaporama::ImageDansDiaporama(const Image& img, unsigned int position, unsigned int rang):
    Image(img),
    m_pos(position),
    m_rang(rang){
}

ImageDansDiaporama::ImageDansDiaporama(Images& images, unsigned int position, unsigned int rang):
    Image(images[rang]),
    m_pos(position),
    m_rang(rang){
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
    return *this;
}

void ImageDansDiaporama::setPosition(unsigned int position)
{
    m_pos = position;
}

void ImageDansDiaporama::setRang(unsigned int rang)
{
    m_rang = rang;
}
