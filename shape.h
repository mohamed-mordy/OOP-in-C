#ifndef __SHAPE_H__
#define __SHAPE_H__

typedef struct ShapeVTable ShapeVTable;
typedef struct Shape {
    const ShapeVTable * vptr;
    double x;
    double y;
} Shape;

struct ShapeVTable {
    double (*perimeter)(const Shape * const);
    double (*area)(const Shape * const);
};

void Shape_constructor(
        Shape * const self, double x0, double y0);

void Shape_destructor(Shape * const self);

static inline
double Shape_area_vcall(
        const Shape * const self)
{
    return (*self->vptr->area)(self);
}

static inline
double Shape_perimeter_vcall(
        const Shape * const self)
{
    return (*self->vptr->perimeter)(self);
}

#endif /* __SHAPE_H__ */

