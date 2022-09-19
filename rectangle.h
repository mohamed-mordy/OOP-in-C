#ifndef __RECTANGLE_H__
#define __RECTANGLE_H__

#include "shape.h"

typedef struct {
    Shape super;
    double width;
    double height;
} Rectangle;

void Rectangle_constructor(
        Rectangle * const self,
        double x0, double y0,
        double h0, double w0);
void Rectangle_destructor(
        Rectangle * const self);

#endif /* __RECTANGLE_H__ */

