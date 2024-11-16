#ifndef HSHADOWFRAME_H
#define HSHADOWFRAME_H

#include <QWidget>
#include "../hqt_global.h"

HQT_BEGIN_NAMESPACE

class HQT_EXPORT HShadowFrame : public QWidget
{
    Q_OBJECT
public:
    explicit HShadowFrame(QWidget *parent = nullptr);

    void setWidget(QWidget *w);
    int thickness() const;
    void setThickness(int value);
    QColor shadowColor() const;
    void setShadowColor(const QColor &color);


protected:
    void paintEvent(QPaintEvent *event) override;

signals:

protected:
    int m_thickness;
    QColor m_shadowColor;
};

HQT_END_NAMESPACE

#endif // HSHADOWFRAME_H
