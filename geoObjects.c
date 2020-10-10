#include<stdio.h>

struct  GeoObject {
    enum {CIR = 0, REC, TRG} Gcode;

    union     {
         struct circle {int x, y, r;} c;
         struct rectangle {int x, y, w, h;} r;
         struct triangle {int x, y, h, b;} t;        
    };
};
//defining the function type
typedef void(* Drawfunc) (struct GeoObject);

void DrawCircle (struct GeoObject go){
    printf("Centre of the circle is %d %d\n", go.c.x, go.c.y);
    printf("The radius of the circle is %d\n", go.c.r);
}

void DrawRectangle (struct GeoObject go) {
    printf("The bottom left corner of the rectnagle is :- %d %d\n", go.r.x, go.r.y);
    printf("The height and the width of the rectangle is :- %d %d\n", go.r.w, go.r.h);
}

void DrawTriangle (struct GeoObject go) {
    printf("The bottom left corner of the trg is :- %d %d\n", go.t.x, go.t.y);
    printf("The height and the base of the rght angle triangle is %d %d\n", go.t.h, go.t.b);
}

Drawfunc DrawArr[] = {//the three different functions will be its arg 
                    DrawCircle, DrawRectangle, DrawTriangle};
//driver function to operate the code
int main() {
    struct GeoObject go;
    //driver code for circle
    go.Gcode = CIR;
    go.c.x = 1;
    go.c.y = 2;
    go.c.r = 3;
    DrawArr[go.Gcode](go);


    //driver code for rectangle
    go.Gcode = REC;
    go.r.x = 1;
    go.r.y = 2;
    go.r.w  = 3;
    go. r.h = 4;

    DrawArr[go.Gcode](go);
    return 0;
}