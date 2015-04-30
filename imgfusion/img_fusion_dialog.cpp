#include "img_fusion_dialog.h"
#include "ui_img_fusion_dialog.h"
#include <QFileDialog>
#include <QMessageBox>
#include <QLineEdit>
#include <QPixmap>
#include <QTextBrowser>
#include <QImage>
#include <QDir>
img_fusion_Dialog::img_fusion_Dialog(QWidget *parent) :
    QDialog(parent),                                                                //QDialog是基类，先初始化基类成员
    ui(new Ui::img_fusion_Dialog),
    pMyImage1(new MyImage),pMyImage2(new MyImage),pMyImageDest(new MyImage),    //初始化成员变量
    pSourceImage1(new QImage),pSourceImage2(new QImage),pDestImage(new QImage),
    pScaledImage(new QImage),
    pFusionPara(new fusionPara),
    strFromNum(),imagePath(),infoString()
{
    ui->setupUi(this);                                                              //启动对话框
    ui->fusionMethod->addItem("Wavelet");
    ui->fusionMethod->addItem("Shearlet");
    ui->fusionLayer->addItem("2");
    ui->fusionLayer->addItem("3");
    ui->fusionLayer->addItem("4");
}

img_fusion_Dialog::~img_fusion_Dialog()
{
    delete ui;
    delete pMyImage1;
    delete pMyImage2;
    delete pMyImageDest;
    delete pSourceImage1;
    delete pSourceImage2;
    delete pDestImage;
    delete pScaledImage;
    delete pFusionPara;
}
//打印信息
void img_fusion_Dialog::printInfo(const QString &info) const
{
     ui->fusionInfo->append(info);
}
//获取图片信息
void img_fusion_Dialog::getMyImage(MyImage *&pMyImage, QImage *&pImage) const
{
    if(pImage->isNull())QMessageBox::information(NULL, "提示", "没有选择图片",0);
    pMyImage->imageFormat=pImage->format();
    pMyImage->hasAlphaChannel=pImage->hasAlphaChannel();
    pMyImage->isGrayscale=pImage->isGrayscale();
    pMyImage->bitPlaneCount=pImage->bitPlaneCount();
    pMyImage->byteCount=pImage->byteCount();
    pMyImage->bytesPerLine=pImage->bytesPerLine();
    pMyImage->colorCount=pImage->colorCount();
    pMyImage->depth=pImage->depth();
    pMyImage->height=pImage->height();
    pMyImage->width=pImage->width();
    pMyImage->imageData=pImage->bits();                                                 //只获取不显示                                                      //只获取不显示
}
//打印图像信息
void img_fusion_Dialog::showMyImageInfo(MyImage *&pMyImage, QString &imageName)
{
    if(0==pMyImage->imageFormat)
    {
        printInfo(imageName + "的格式是：Format_Invalid");
    }
    else if(3==pMyImage->imageFormat)
    {
        printInfo(imageName + "的格式是：Format_Indexed8");
    }
    else if(4==pMyImage->imageFormat)
    {
        printInfo(imageName + "的格式是：Format_RGB32");
    }
    else if(5==pMyImage->imageFormat)
    {
         printInfo(imageName + "的格式是：Format_ARGB32");
    }
    if(pMyImage->hasAlphaChannel)
    {
         printInfo(imageName + "有a通道");
    }
    else
    {
         printInfo(imageName + "没有a通道");
    }
    if(pMyImage->isGrayscale)
    {
         printInfo(imageName + "是灰度图像");
    }
    else
    {
         printInfo(imageName + "不是灰度图像");
    }
    printInfo(imageName+ "单像素有效使用位数是： " + strFromNum.setNum(pMyImage->bitPlaneCount));
    printInfo(imageName+ "所占总字节数是： " + strFromNum.setNum(pMyImage->byteCount));
    printInfo(imageName+ "单行像素所占字节数是： " + strFromNum.setNum(pMyImage->bytesPerLine));
    printInfo(imageName+ "灰度图像可以表示的颜色总数是： " + strFromNum.setNum(pMyImage->colorCount));
    printInfo(imageName+ "单像素点占用位数是： " + strFromNum.setNum(pMyImage->depth));
    printInfo(imageName+ "图像纵向像素个数是： " + strFromNum.setNum(pMyImage->height));
    printInfo(imageName+ "图像横向像素个数是： " + strFromNum.setNum(pMyImage->width));
}
//选择图像
void img_fusion_Dialog::chooseImage()
{
    QFileDialog *fileDialog = new QFileDialog(this);
    fileDialog->setWindowTitle("选择图像");
    fileDialog->setDirectory(".");
    if(fileDialog->exec() == QDialog::Accepted)
    {
        imagePath = fileDialog->selectedFiles()[0];
        printInfo("您所选择的图像是： " + imagePath);
    }
    else
    {
        printInfo("您没有选择任何图像");
    }
}
//融合条件检查
bool img_fusion_Dialog::checkMyImage(MyImage *&pMyImage1,MyImage *&pMyImage2)const
{
    if((pMyImage1->imageFormat==pMyImage2->imageFormat)&&(pMyImage1->depth==pMyImage2->depth)
            &&(pMyImage1->width==pMyImage2->width)&&(pMyImage1->height==pMyImage2->height))
    {
        printInfo("两幅图像已配准，可以进行多聚焦融合");
        return true;
    }
    else
    {
        printInfo("两幅图像未配准，不能进行多聚焦融合");
        QMessageBox::information(NULL, "提示", "图片没有配准",0);
        return false;
    }
}
//获取融合参数
void img_fusion_Dialog::getFusionParaFromConf(fusionPara *&pFusionPara)const
{
    pFusionPara->method=ui->fusionMethod->currentText();
    pFusionPara->layer=ui->fusionLayer->currentText().toInt();
}
//图像融合
bool img_fusion_Dialog::imageFusion(MyImage *&pMyImage1,MyImage *&pMyImage2,MyImage *&pMyImageDest,fusionPara *&pFusionPara)
{
    if(pFusionPara->method=="Wavelet")
    {

    }
    if(pFusionPara->method=="Shearlet")
    {

    }
    return true;
}
//打印图像评价结果
void img_fusion_Dialog::printImageEvaluation(MyImage *&pMyImageDest) const
{
    printInfo("图像评价结果是： ");
}
/*
 * 点击图片一按钮，打开图像1，获取像素数据，打印图像信息
*/
void img_fusion_Dialog::on_loadImg_1_clicked()
{
   //选择图片
   chooseImage();
   ui->imgPath_1->setText(imagePath);
   //显示图片信息
   pSourceImage1->load(ui->imgPath_1->text());
   getMyImage(pMyImage1,pSourceImage1);
   infoString="图像1";
   showMyImageInfo(pMyImage1,infoString);
   //显示图片
   QSize imgTextLabelSize= ui->imgTextLabel->size();
   *pScaledImage=pSourceImage1->scaled(imgTextLabelSize);
   ui->imgTextLabel->setPixmap(QPixmap::fromImage(*pScaledImage));
}
/*
 * 点击图片二按钮，打开图像2，获取像素数据，打印图像信息
*/
void img_fusion_Dialog::on_loadImg_2_clicked()
{
    //选择图片
    chooseImage();
    ui->imgPath_2->setText(imagePath);
    //显示图片信息
    pSourceImage2->load(ui->imgPath_2->text());
    getMyImage(pMyImage2,pSourceImage2);
    infoString="图像2";
    showMyImageInfo(pMyImage2,infoString);
    //显示图片
    QSize imgTextLabelSize= ui->imgTextLabel->size();
    *pScaledImage=pSourceImage2->scaled(imgTextLabelSize);
    ui->imgTextLabel->setPixmap(QPixmap::fromImage(*pScaledImage));
}
//选择融合方法
void img_fusion_Dialog::on_fusionMethod_currentIndexChanged(int index)
{
    infoString="您所选择的融合方法是： ";
    printInfo(infoString + ui->fusionMethod->currentText());
}
//选择融合层数
void img_fusion_Dialog::on_fusionLayer_currentIndexChanged(int index)
{
    infoString="您所选择的融合层数是： ";
    printInfo(infoString + ui->fusionLayer->currentText());
}
/*
 * 点击启动融合按钮，融合两幅图像，显示融合图像，打印融合信息
*/
void img_fusion_Dialog::on_imgFusion_clicked()
{
    if(pSourceImage1->isNull()||pSourceImage2->isNull())
    {
        QMessageBox::information(NULL, "提示", "请选择图片",0);
    }
    if(!checkMyImage(pMyImage1,pMyImage2))return;
    getFusionParaFromConf(pFusionPara);
    imageFusion(pMyImage1,pMyImage2,pMyImageDest,pFusionPara);
    printImageEvaluation(pMyImageDest);
    QSize imgTextLabelSize= ui->imgTextLabel->size();
    *pScaledImage=pDestImage->scaled(imgTextLabelSize);
    ui->imgTextLabel->setPixmap(QPixmap::fromImage(*pScaledImage));
}


