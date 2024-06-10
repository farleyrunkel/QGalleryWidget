#include "galleryphotowidget.h"
#include "gallerywidget.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    GalleryWidget w;

    QList<GalleryPhotoData> list;
    srand(time(0));
    int count = rand() % 10 + 5;
    for (int i = 0; i < count; i++)
    {
        QPixmap pixmap(":/images/background.png");
        QString title = "凤翎谱" + QString::number(i);
        QString subTitle = "作者：北宫懒懒" + QString::number(i);
        GalleryPhotoData data{pixmap, title, subTitle};
        list.append(data);
    }

    w.loadData(list);

    w.show();

    return a.exec();
}
