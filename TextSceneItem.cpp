#include "TextSceneItem.h"


TextSceneItem::TextSceneItem()
{
    setGeometry(QRect(0,0,200,200));
}

void TextSceneItem::setShadowEnabled(bool enabled)
{
    if(enabled) {
        auto effect = new QGraphicsDropShadowEffect();
        setGraphicsEffect(effect);
    } else {
        setGraphicsEffect(nullptr);
    }
    update();
}

void TextSceneItem::setDrawBackground(bool enabled)
{
    mDrawBackground = enabled;
    update();
}

void TextSceneItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    auto text = QString("This is some test text");
    auto color = QColor(Qt::red);
    auto rect =  boundingRect();

    // Workaround for issue
    if (mDrawBackground) {
        painter->setBrush(QColor(255,255,255,50));
        painter->drawRect(rect);
    }

    // Paint text
    painter->setPen(color);

    auto boxHeight = 10;

    QTextDocument document(text);
    for (auto block = document.begin(); block != document.end(); block = block.next()) {
        QTextLayout textLayout(block);
        textLayout.setCacheEnabled(true);
        auto blockHeight = 0;
        textLayout.setCacheEnabled(true);

        textLayout.beginLayout();
        while (true) {
            auto line = textLayout.createLine();
            if (!line.isValid()) {
                break;
            }

            line.setLineWidth(rect.width());
            blockHeight += 10;
            line.setPosition(rect.topLeft());
            blockHeight += line.height();
        }
        textLayout.endLayout();

        textLayout.draw(painter, QPoint(0, boxHeight));

        textLayout.drawCursor(painter, QPointF(0, boxHeight), 10, 2);

        boxHeight += blockHeight;
    }
}
