#include "circle.h"

#define PI (22.0/7.0)

static double Circle_perimeter(const Circle * const self);
static double Circle_area(const Circle * const self);

void Circle_constructor(Circle * const self,
                        double x0, double y0,
                        double r0)
{
    const static ShapeVTable vt = {
        (double(*)(const Shape * const))&Circle_perimeter,
        (double(*)(const Shape * const))&Circle_area
    };
    Shape_constructor(&self->super, x0, y0);
    self->super.vptr = &vt;
    self->radius = r0;
}

void Circle_destructor(Circle * const self)
{
    (void)self;
}

static double Circle_perimeter(const Circle * const self)
{
    return 2.0 * PI * self->radius;
}

static double Circle_area(const Circle * const self)
{
    return PI * self->radius * self->radius;
}

