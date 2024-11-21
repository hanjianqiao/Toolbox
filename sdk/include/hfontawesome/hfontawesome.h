#ifndef H_MATH_GEO_H
#define H_MATH_GEO_H

#include <hqt/gui/hfonticon.h>
#include "QtAwesomeEnumGenerated.h"
#include "hfontawesome_global.h"

HFONTAWESOME_BEGIN_NAMESPACE

struct NamedIcon {
    const char *name;
    unsigned short id;
};

class HFONTAWESOME_EXPORT HFontawesome
{
public:
    HFontawesome() = delete;

    static QIcon icon(int fontIndex, int character, const h::qt::HFontIconIconOption &options = h::qt::HFontIconIconOption());
    static unsigned short idForName(const QString &name);
    static QString nameForId(unsigned short id);

private:
    static void initialize();

    static h::qt::HFontIcon *s_fontIcon;

    static const NamedIcon s_faCommonIconArray[];
    static const NamedIcon s_faBrandsIconArray[];
    static const NamedIcon s_faProIconArray[];
    static const NamedIcon s_faRegularFreeIconArray[];

    static QHash<QString, unsigned short> s_nameIdHash;
    static QHash<unsigned short, QString> s_idNameHash;
};

HFONTAWESOME_END_NAMESPACE

#endif
