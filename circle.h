#ifndef __CIRCLE_H__
#define __CIRCLE_H__

#include "shape.h"

typedef struct {
    Shape super; /* Inherited Class */
    double radius;
} Circle;

void Circle_constructor(Circle * const self,
                        double x0, double y0,
                        double r0);

void Circle_destructor(Circle * const self);

#endif /* __CIRCLE_H__ */
