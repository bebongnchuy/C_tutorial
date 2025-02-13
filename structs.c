#include <stdio.h>

typedef struct{
    float x;
    float y;
} Point;
int main(){
    Point pts[5] = {{1,2},{3,2},{4,2},{1,0},{6,1}};

    for (size_t i = 0; i < sizeof(pts)/sizeof(pts[0]); i++)
    {
        /* code */

        printf("(%.1f,%.1f)\n",pts[i].x,pts[i].y);
    }
    


}