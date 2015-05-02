#ifndef IMG_FUSION_DIALOG_H
#define IMG_FUSION_DIALOG_H

#include <QDialog>
namespace Ui {
class img_fusion_Dialog;
}

class img_fusion_Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit img_fusion_Dialog(QWidget *parent = 0);
    ~img_fusion_Dialog();

private slots:
    void on_loadImg_1_clicked();

    void on_loadImg_2_clicked();

    void on_imgFusion_clicked();

    void on_fusionMethod_currentIndexChanged(int index);

    void on_fusionLayer_currentIndexChanged(int index);

private:
    Ui::img_fusion_Dialog *ui;
public:
    struct fusionPara
    {
        QString method;                             //融合方法
        int layer;                               //融合层数
    };
    struct MyImage
    {
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
    };
    MyImage *pMyImage1,*pMyImage2,*pMyImageDest;
    QImage *pSourceImage1,*pSourceImage2,*pDestImage,*pScaledImage;
    fusionPara *pFusionPara;
    QString strFromNum,imagePath,infoString;
    void printInfo(const QString &info)const;
    void chooseImage();
    void getMyImage(MyImage *&pMyImage, QImage *&pImage)const;
    void showMyImageInfo(MyImage *&pMyImage,QString &imageName);
    bool checkMyImage(MyImage *&pMyImage1,MyImage *&pMyImage2)const;
    void getFusionParaFromConf(fusionPara *&pFusionPara)const;
    bool imageFusion(MyImage *&pMyImage1,MyImage *&pMyImage2,MyImage *&pMyImageDest,fusionPara *&pFusionPara);
    void printImageEvaluation(MyImage *&pMyImageDest)const;
};

#endif // IMG_FUSION_DIALOG_H
