#ifndef GALLERYWIDGET_H
#define GALLERYWIDGET_H

#include <QObject>
#include <QWidget>
#include <QPixmap>
#include <QDebug>
#include <QScrollArea>
#include <QPropertyAnimation>
#include <QScrollBar>
#include "galleryphotowidget.h"

class GalleryWidget : public QScrollArea
{
    Q_OBJECT
public:
    GalleryWidget(QWidget *parent = nullptr);

    void resizeGallery(QPoint emit_pos = QPoint(0, 0));
    void loadData(const QList<GalleryPhotoData> &list);

protected:
    void resizeEvent(QResizeEvent *event) override;

signals:
    void signalPictureClicked(GalleryPhotoWidget* bean);

public slots:

public:
     int item_spacing_h;
     int item_spacing_v;

private:
    QList<GalleryPhotoWidget*> widgets;
    QWidget* center_widget;
    void animateWidgetPosition(GalleryPhotoWidget *widget, const QPoint &pos);
    void positionWidgets(int col_count, int total_left, int total_top);
    int calculateTotalLeft(int col_count) const;
    int calculateRowCount(int col_count) const;
    int calculateTotalHeight(int row_count) const;
    int calculateColumnCount() const;
    void createWidgets(const QList<GalleryPhotoData> &list);
    void clearWidgets();

    int getMaxWidgetHeight() const;
    int getMaxWidgetWidth() const;
};

#endif // GALLERYWIDGET_H
