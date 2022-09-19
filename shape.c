#include "shape.h"

double Shape_perimeter(const Shape * const self);
double Shape_area(const Shape * const self);

void Shape_constructor(
        Shape * const self, double x0, double y0)
{
    static const ShapeVTable vt = {
        &Shape_perimeter,
        &Shape_area
    };
    self->vptr = &vt;
    self->x = x0;
    self->y = y0;
}

void Shape_destructor(Shape * const self)
{
    (void)self;
}

double Shape_perimeter(const Shape * const self)
{
    (void)self;
    return 0.0;
}

double Shape_area(const Shape * const self)
{
    (void)self;
    return 0.0;
}

