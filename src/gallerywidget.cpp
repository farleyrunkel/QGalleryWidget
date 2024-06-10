#include "gallerywidget.h"
#include <QPropertyAnimation>


GalleryWidget::GalleryWidget(QWidget *parent) : QScrollArea(parent)
{
    center_widget = new QWidget(this);

    item_spacing_h = 10;
    item_spacing_v = 10;

    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setWidget(center_widget);
}

/**
 * 加载数据，初始化列表
 * 并且开启显示动画
 */
void GalleryWidget::loadData(const QList<GalleryPhotoData> &list)
{
    clearWidgets();
    createWidgets(list);
    resizeGallery();
}

/**
 * 清除所有现有的图片控件
 */
void GalleryWidget::clearWidgets()
{
    foreach (GalleryPhotoWidget* widget, widgets) {
        widget->deleteLater();
    }
    widgets.clear();
}

/**
 * 根据数据创建新的图片控件
 */
void GalleryWidget::createWidgets(const QList<GalleryPhotoData> &list)
{
    foreach (const GalleryPhotoData &data, list)
    {
        widgets.append(new GalleryPhotoWidget(data, center_widget));
    }
}

/**
 * 重新调整所有控件的位置
 */
void GalleryWidget::resizeGallery(QPoint emit_pos)
{
    if (widgets.isEmpty()) return;

    int col_count = calculateColumnCount();
    int row_count = calculateRowCount(col_count);
    int total_height = calculateTotalHeight(row_count);

    center_widget->setMinimumHeight(total_height);
    center_widget->resize(center_widget->width(), total_height);

    int total_left = calculateTotalLeft(col_count);
    int total_top = item_spacing_v;

    positionWidgets(col_count, total_left, total_top);
}

/**
 * 计算列数
 */
int GalleryWidget::calculateColumnCount() const
{
    int gpw_width = GalleryPhotoWidget::fixed_width;
    int bar_width = verticalScrollBar()->width();
    int col_count = qMax((center_widget->width() - item_spacing_h - bar_width) / (gpw_width + item_spacing_h), 1);
    return qMin(col_count, widgets.size());
}

/**
 * 计算行数
 */
int GalleryWidget::calculateRowCount(int col_count) const
{
    return qMax((widgets.size() + col_count - 1) / col_count, 1);
}

/**
 * 计算总高度
 */
int GalleryWidget::calculateTotalHeight(int row_count) const
{
    int gpw_height = GalleryPhotoWidget::fixed_height;
    return row_count * (gpw_height + item_spacing_v) + item_spacing_v * 2;
}

/**
 * 计算控件左边距
 */
int GalleryWidget::calculateTotalLeft(int col_count) const
{
    int gpw_width = GalleryPhotoWidget::fixed_width;
    return (center_widget->width() - col_count * (gpw_width + item_spacing_h)) / 2;
}

/**
 * 重新定位所有控件
 */
void GalleryWidget::positionWidgets(int col_count, int total_left, int total_top)
{
    int gpw_width = GalleryPhotoWidget::fixed_width;
    int gpw_height = GalleryPhotoWidget::fixed_height;

    int cur_row = 0, cur_col = 0;
    for (GalleryPhotoWidget *widget : qAsConst(widgets))
    {
        QPoint pos(total_left + cur_col * (gpw_width + item_spacing_h), total_top + cur_row * (gpw_height + item_spacing_v));
        animateWidgetPosition(widget, pos);

        if (++cur_col >= col_count)
        {
            cur_col = 0;
            ++cur_row;
        }
    }
}

/**
 * 为控件设置位置动画
 */
void GalleryWidget::animateWidgetPosition(GalleryPhotoWidget *widget, const QPoint &pos)
{
    QPropertyAnimation *ani = new QPropertyAnimation(widget, "pos");
    ani->setStartValue(widget->pos());
    ani->setEndValue(pos);
    ani->setDuration(300);
    ani->setEasingCurve(QEasingCurve::OutQuad);
    connect(ani, &QPropertyAnimation::finished, ani, &QObject::deleteLater);
    ani->start();
}

void GalleryWidget::resizeEvent(QResizeEvent *event)
{
    QScrollArea::resizeEvent(event);
    center_widget->setFixedWidth(width());
    resizeGallery();
}
