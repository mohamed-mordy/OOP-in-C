#include "rectangle.h"

static double Rectangle_perimeter(const Rectangle * const self);
static double Rectangle_area(const Rectangle * const self);

void Rectangle_constructor( Rectangle * const self,
                            double x0, double y0,
                            double h0, double w0)
{
    static const ShapeVTable vt = {
        (double (*)(const Shape * const))&Rectangle_perimeter,
        (double (*)(const Shape * const))&Rectangle_area
    };
    Shape_constructor(&self->super, x0, y0);
    self->super.vptr = &vt;
    self->width = w0;
    self->height = h0;
}

void Rectangle_destructor( Rectangle * const self)
{
    (void)self;
}

static double Rectangle_perimeter(const Rectangle * const self)
{
    return (self->height + self->width) * 2.0;
}

static double Rectangle_area(const Rectangle * const self)
{
    return self->height * self->width;
}
