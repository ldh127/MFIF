#include "myimage.h"

MyImage::MyImage()
{

}

MyImage::~MyImage()
{

}
MyImage MyImage::WDT(const string _wname, const int _level )const
{

}
MyImage MyImage::IWDT(const string _wname, const int _level )const
{

}
void MyImage::wavelet( const string _wname, MyImage &_lowFilter, MyImage &_highFilter )const
{

}
MyImage MyImage::waveletDecompose(const MyImage &_lowFilter, const MyImage &_highFilter )const
{

}
MyImage MyImage::waveletReconstruct(const MyImage &_lowFilter, const MyImage &_highFilter )const
{

}
MyImage MyImage::SHEARLET(const string _sname, const int _level )const
{

}
MyImage MyImage::ISHEARLET(const string _sname, const int _level )const
{

}
void MyImage::shear( const string _sname, MyImage &_lowFilter, MyImage &_highFilter )const
{

}
MyImage MyImage::shearletDecompose(const MyImage &_lowFilter, const MyImage &_highFilter )const
{

}
MyImage MyImage::shearletReconstruct(const MyImage &_lowFilter, const MyImage &_highFilter )const
{

}
