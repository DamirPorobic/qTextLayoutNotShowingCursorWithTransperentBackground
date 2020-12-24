#ifndef TEXTSCENEITEM_H
#define TEXTSCENEITEM_H

#include <QGraphicsWidget>
#include <QPainter>
#include <QTextLayout>
#include <QTextDocument>
#include <QTextBlock>
#include <QGraphicsDropShadowEffect>

class TextSceneItem : public QGraphicsWidget
{
public:
    explicit TextSceneItem();
    ~TextSceneItem() override = default;
    void setShadowEnabled(bool enabled);
    void setDrawBackground(bool enabled);

protected:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *) override;

private:
    bool mDrawBackground;
};

#endif // TEXTSCENEITEM_H
