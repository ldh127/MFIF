#include "img_fusion_dialog.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    img_fusion_Dialog w;
    w.show();

    return a.exec();
}
