#ifndef HREVEAL_H
#define HREVEAL_H

#include <QWidget>
#include <QPainter>
#include <QPropertyAnimation>
#include "../hqt_global.h"

HQT_BEGIN_NAMESPACE

class HRevealPrivate;

class HQT_EXPORT HReveal : public QWidget
{
    Q_OBJECT
    Q_DECLARE_PRIVATE(HReveal)
    Q_PROPERTY(int radius READ radius WRITE setRadius NOTIFY radiusChanged)

public:
    explicit HReveal(QWidget *parent = nullptr);

    void start(const QPoint& center);
    int radius() const;
    void setRadius(int value);
    void setDuration(int msecs);

    void paintEvent(QPaintEvent *event) override;

Q_SIGNALS:
    void backgroundGrabbed();
    void radiusChanged(int value);

private:
    void init();
    HReveal(HRevealPrivate &dd, QWidget* parent = nullptr);

};

HQT_END_NAMESPACE

#endif // HREVEAL_H
