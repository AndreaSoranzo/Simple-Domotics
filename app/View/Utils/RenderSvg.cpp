#include "RenderSvg.h"

#include <QPainter>
#include <QSvgRenderer>

QPixmap renderSVG(const QString& path, const QSize& size) {
    QSvgRenderer svgRenderer(path);
    QPixmap pixmap(size);
    pixmap.fill(Qt::transparent);
    QPainter painter(&pixmap);
    svgRenderer.render(&painter);
    return pixmap;
}