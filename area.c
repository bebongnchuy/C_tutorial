// This program calculates the area of a circle and prints it

#include <stdio.h>
float areaOfCircle(float radius);
float areaOfTriangle(float base, float height);


int main(){
    float areaOfCircl, areaOfTriangl, radius = 0;
    printf("Enter the radius of the circle: ");
    scanf("%f", &radius);
    areaOfCircl = areaOfCircle(radius);

    float base = 0, height = 0;
    printf("Enter the base and height of the triangle: ");
    scanf("%f %f", &base, &height);
    areaOfTriangl = areaOfTriangle(base, height);

    float area = areaOfCircl + areaOfTriangl;
    printf("\nThe area of the triangle is: %.2f", areaOfTriangl);
    printf("\nThe area of the circle is: %.2f", areaOfCircl);
    printf("\nThe total area is: %.2f", area);

    getchar();

    return 0;

}

float areaOfCircle(float radius){
    return 3.14159 * radius * radius;
}

float areaOfTriangle(float base, float height){
    return 0.5 * base * height;
}


