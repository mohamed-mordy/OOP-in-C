#include "square.h"

static double Square_perimeter(const Square * const self);
static double Square_area(const Square * const self);

void Square_constructor(
        Square * const self,
        double x0, double y0, double len)
{
    static const ShapeVTable vt = {
        (double (*)(const Shape * const))&Square_perimeter,
        (double (*)(const Shape * const))&Square_area
    };
    Shape_constructor(&self->super, x0, y0);
    self->super.vptr = &vt;
    self->length = len;
}

void Square_destructor(Square * const self)
{
    (void)self;
}

static double Square_perimeter(const Square * const self)
{
    return self->length * 4.0;
}

static double Square_area(const Square * const self)
{
    return self->length * self->length;
}

