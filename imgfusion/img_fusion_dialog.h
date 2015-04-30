#ifndef IMG_FUSION_DIALOG_H
#define IMG_FUSION_DIALOG_H

#include <QDialog>
#include "MyImage.h"
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
