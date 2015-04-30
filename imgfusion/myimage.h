#ifndef MYIMAGE_H
#define MYIMAGE_H
#include <iostream>
using namespace std;
class MyImage
{
public:
    MyImage();
    ~MyImage();

    int imageFormat;                            //图像格式
    bool hasAlphaChannel;                       //是否有a通道
    bool isGrayscale;                           //RGB三分量是否相同
    int bitPlaneCount;                          //单像素有效使用位数
    int byteCount;                              //图像所占字节数
    int bytesPerLine;                           //单行像素所占字节数
    int colorCount;                             //灰度图像可以表示的颜色总数，彩色图像的值为0
    int depth;                                  //单像素点占用位数
    int height;                                 //图像纵向像素个数
    int width;                                  //图像横向像素个数
    unsigned char *imageData;                   //图像像素数据首地址
    MyImage WDT(const string _wname, const int _level )const;
    MyImage IWDT(const string _wname, const int _level )const;
    void wavelet( const string _wname, MyImage &_lowFilter, MyImage &_highFilter )const;
    MyImage waveletDecompose(const MyImage &_lowFilter, const MyImage &_highFilter )const;
    MyImage waveletReconstruct(const MyImage &_lowFilter, const MyImage &_highFilter )const;
    MyImage SHEARLET(const string _sname, const int _level )const;
    MyImage ISHEARLET(const string _sname, const int _level )const;
    void shear( const string _sname, MyImage &_lowFilter, MyImage &_highFilter )const;
    MyImage shearletDecompose(const MyImage &_lowFilter, const MyImage &_highFilter )const;
    MyImage shearletReconstruct(const MyImage &_lowFilter, const MyImage &_highFilter )const;

};

#endif // MYIMAGE_H
