#include "train.h"
#include <QBrush>

Train::Train(qreal x, qreal y, qreal width, qreal height) : QGraphicsRectItem(x, y, width, height) {
    setBrush(QBrush(Qt::red)); // set color
}
