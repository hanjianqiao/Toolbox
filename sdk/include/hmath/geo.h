#ifndef H_MATH_GEO_H
#define H_MATH_GEO_H

#include "hmath_global.h"

HMATH_BEGIN_NAMESPACE

struct Point
{
    int x;
    int y;
};

struct Size
{
    int width;
    int height;
};

struct Rect
{
    Point topLeft;
    Size size;
};

class HMATH_EXPORT Geo
{
public:
    Geo() = delete;

    static double distance(const Point &p1, const Point &p2);
    static double longestDistanceToVertex(const Point &p, const Rect &r);
};

HMATH_END_NAMESPACE

#endif
