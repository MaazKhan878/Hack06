#include<stdio.h>
#include<math.h>
#include"colorUtils.h"
double max(double red , double green, double blue){
    double max = (red > green)? red : green;
    return (max > blue)? max : blue;
}
double scale(int r){
    return (double)r/255.0;
} 
int rgbToCMYK(int r, int g, int b, double *c, double *m, double *y, double *k){
    if(r>255 || r<0 ||g>255 || g<0 ||b>255 || b<0){
        return 1;
    }
    double red = scale(r);
    double green = scale(g);
    double blue = scale(b);
    *k = 1 - max(red,green,blue);
    *c = (1 - r - *k)/(1 - *k);
    *m = (1 - g - *k)/(1 - *k);
    *y = (1 - b - *k)/(1 - *k);
    return 0;
}











