#ifndef H_MATH_GEO_H
#define H_MATH_GEO_H

#include <hqt/gui/hfonticon.h>
#include "QtAwesomeEnumGenerated.h"
#include "hfontawesome_global.h"

HFONTAWESOME_BEGIN_NAMESPACE

class HFONTAWESOME_EXPORT HFontawesome
{
public:
    HFontawesome() = delete;

    static QIcon icon(int fontIndex, int character, const h::qt::HFontIconIconOption &options = h::qt::HFontIconIconOption());

private:
    static void initialize();
    static h::qt::HFontIcon *s_fontIcon;
};

HFONTAWESOME_END_NAMESPACE

#endif
