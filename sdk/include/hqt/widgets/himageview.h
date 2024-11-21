#ifndef HIMAGEVIEW_H
#define HIMAGEVIEW_H

#include <QWidget>
#include <QScrollArea>
#include <QLabel>
#include <QPixmap>
#include "../hqt_global.h"

HQT_BEGIN_NAMESPACE

class HQT_EXPORT HImageView : public QScrollArea
{
    Q_OBJECT
public:
    explicit HImageView(QWidget *parent = nullptr);

    void setPixmap(const QPixmap &pixmap);
signals:

private:
    QLabel *m_imageLabel;
};

HQT_END_NAMESPACE

#endif // HIMAGEVIEW_H
