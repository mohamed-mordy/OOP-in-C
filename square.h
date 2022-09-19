#ifndef __SQUARE_H__
#define __SQUARE_H__

#include "shape.h"

typedef struct {
    Shape super;
    double length;
} Square;

void Square_constructor(
        Square * const self,
        double x0, double y0, double len);
void Square_destructor(
        Square * const self);

#endif /* __SQUARE_H__ */
