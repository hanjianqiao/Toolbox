#ifndef HFONTICON_H
#define HFONTICON_H

#include <QString>
#include <QHash>
#include <QFont>
#include <QIcon>
#include <QChar>
#include <QVariant>
#include "../hqt_global.h"

HQT_BEGIN_NAMESPACE

class HFontIconPrivate;
class HFontIcon;


class HQT_EXPORT HFontIconIconOption{
public:
    HFontIconIconOption();

    QColor color(QIcon::Mode mode, QIcon::State state) const;
    QColor duotoneColor(QIcon::Mode mode, QIcon::State state) const;
    QString text(QIcon::Mode mode, QIcon::State state) const;
    qreal scaleFactor() const;
    int fontIndex() const;
    bool duotone() const;

    void setFontIndex(int index);
    void setDuotone(bool duotone);
    void setScaleFactor(qreal scaleFactor);
    void setText(const QString &text, QIcon::State state = QIcon::State::On, QIcon::Mode mode = QIcon::Mode::Normal);
    void setColor(const QColor &color, QIcon::State state = QIcon::State::On, QIcon::Mode mode = QIcon::Mode::Normal);
    void setDuotoneColor(const QColor &color, QIcon::State state = QIcon::State::On, QIcon::Mode mode = QIcon::Mode::Normal);

private:
    bool m_duotone;
    double m_scaleFactor;
    int m_fontIndex;
    QString m_text[2][4];
    QColor m_color[2][4];
    QColor m_duotoneColor[2][4];
};

class HQT_EXPORT HFontIconIconPainter
{
public:
    virtual ~HFontIconIconPainter();
    virtual void paint(HFontIcon* HFontIcon, QPainter* painter, const QRect& rect,  QIcon::Mode mode, QIcon::State state,
                       const HFontIconIconOption &options) = 0;
};

struct HQT_EXPORT HFontIconFontRegisterInfo{
    QString fontFamily;
    QFont::Weight weight;
    QString fileName;
    int fontID;

    HFontIconFontRegisterInfo(const QString &fileName, QFont::Weight weight);
};

class HQT_EXPORT HFontIcon
{
    Q_DECLARE_PRIVATE(HFontIcon)
public:
    static HFontIcon *g();
    static bool initializeG(const QList<HFontIconFontRegisterInfo> &fonts);

    HFontIcon();
    ~HFontIcon();
    QFont font(int fontIndex, int size) const;
    bool registerFonts(const QList<HFontIconFontRegisterInfo> &fonts);

    const QList<HFontIconFontRegisterInfo> &registeredFonts() const;
    QIcon icon(HFontIconIconPainter *painter, const HFontIconIconOption &options);
    QIcon icon(int fontIndex, int character, const HFontIconIconOption &options = HFontIconIconOption());

private:
    static HFontIcon *s_singleton;

    HFontIconIconPainter *m_defaultPainter;
    QList<HFontIconFontRegisterInfo> m_registeredFonts;
    QHash<QString, int> m_iconNameIndexHash;

    HFontIconPrivate *d_ptr;
};

HQT_END_NAMESPACE

#endif // HFONTICON_H
