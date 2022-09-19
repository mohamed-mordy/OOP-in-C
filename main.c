#include "shape.h"
#include "square.h"
#include "rectangle.h"
#include "circle.h"
#include <stdlib.h>
#include <stdio.h>

void CalcArea(Shape const * shapes[]);
void CalcPerimeter(Shape const * shapes[]);

Shape sh1;
Square sq1;
Rectangle re1;
Circle ci1;

int main()
{
    Shape sh2;
    Square sq2;
    Rectangle re2;
    Circle ci2;

    Shape * shp = malloc(sizeof (Shape));
    Square * sqp = malloc(sizeof (Square));
    Rectangle * rep = malloc(sizeof (Rectangle));
    Circle * cip = malloc(sizeof (Circle));
    const Shape * my_shapes[] = {
        &sh1, &sh1, shp,
        (Shape *)&sq1, (Shape *)&sq2, (Shape *)sqp, /* Upcasting that is absolutely safe. */
        (Shape *)&re1, (Shape *)&re2, (Shape *)rep, /* It is done implicitly in languages */
        (Shape *)&ci1, (Shape *)&ci2, (Shape *)cip, /* other than C, but C requires it */
        (Shape *)0    /* Sentinal */
    };

    /* constructor calls */
    Shape_constructor(&sh1, 1, 2);
    Shape_constructor(&sh2, 3, 4);
    Shape_constructor(shp, 5, 6);

    Square_constructor(&sq1, 7, 8, 20);
    Square_constructor(&sq2, 9, 10, 30);
    Square_constructor(sqp, 11, 12, 40);

    Rectangle_constructor(&re1, 13, 14, 10, 20);
    Rectangle_constructor(&re2, 15, 16, 20, 30);
    Rectangle_constructor(rep, 17, 18, 30, 40);

    Circle_constructor(&ci1, 1, 1, 10);
    Circle_constructor(&ci2, 5, 5, 20);
    Circle_constructor(cip, 3, 7, 30);

    /* Run-Time Polymorphism */
    CalcArea(my_shapes);
    CalcPerimeter(my_shapes);

    /* In this program destructors actually do nothing */
    /* calling here just for completeness */
    Shape_destructor(&sh1);
    Shape_destructor(&sh2);
    Shape_destructor(shp);

    Square_destructor(&sq1);
    Square_destructor(&sq2);
    Square_destructor(sqp);

    Rectangle_destructor(&re1);
    Rectangle_destructor(&re2);
    Rectangle_destructor(rep);

    Circle_destructor(&ci1);
    Circle_destructor(&ci2);
    Circle_destructor(cip);

    /* cleanup */
    free(shp); 
    free(sqp); 
    free(rep); 
    free(cip); 
    return 0;
}

void CalcArea(Shape const * shapes[])
{
    for (int i = 0; shapes[i] != (Shape *)0; ++i) {
        printf("%8.3f\n", Shape_area_vcall(shapes[i]));
    }
}


void CalcPerimeter(Shape const * shapes[])
{
    for (int i = 0; shapes[i] != (Shape *)0; ++i) {
        printf("%8.3f\n", Shape_perimeter_vcall(shapes[i]));
    }
}

