#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "geometry.h"

void testDist()
{
    // testing the function of calculating distance between some points 
    Point arr[7] = {pointInit(1, 1), pointInit(3, 1), pointInit(63, 45), pointInit(45, -61), pointInit(9, -47), pointInit(-47, -7), pointInit(51, 9)};
    float check[42] = {2, 76.0263, 76.0263, 48.6621, 48.6621, 50.636, 2, 74.4043, 74.8866, 48.3735, 50.636, 48.6621, 76.0263, 74.4043, 107.517, 106.677, 121.672, 37.9473, 76.0263, 74.8866, 107.517, 38.6264, 106.677, 70.2567, 48.6621, 48.3735, 106.677, 38.6264, 68.8186, 70, 48.6621, 50.636, 121.672, 106.677, 68.8186, 99.2975, 50.636, 48.6621, 37.9473, 70.2567, 70, 99.2975};
    int c = 0;
    for (int i = 0; i < 7; i++)
    {
        for (int j = 0; j < 7; j++)
        {
            if (i == j)
            {
                c++;
                continue;
            }
            if (fabs(distance(arr[i], arr[j]) - check[i * 7 + j - c]) > 0.001)
            {
                printf("Test Dist FAILED\n");
                return;
            }
        }
    }
    printf("Test Dist passed\n");
}
void testRef()
{
    // testing function reflectionAboutLine
    Point p1 = pointInit(1, 1);
    Point p2 = pointInit(45, 63);
    Point p3 = pointInit(-47, 9);
    Line l1 = lineInit(1, 0);
    Line l2 = lineInit(0, 1);
    Line l3 = lineInit(INFINITY, 2);
    Point points[3] = {p1, p2, p3};
    Line lines[3] = {l1, l2, l3};
    Point reflected[9] = {pointInit(1, 1), pointInit(1, 1), pointInit(3, 1), pointInit(63, 45), pointInit(45, -61), pointInit(-41, 63), pointInit(9, -47), pointInit(-47, -7), pointInit(51, 9)};
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            Point ref = reflectionAboutLine(points[i], lines[j]);
            if (ref.x != reflected[i * 3 + j].x || ref.y != reflected[i * 3 + j].y)
            {
                printf("Test Ref FAILED\n");
                return;
            }
        }
    }
    printf("Test Ref passed\n");
}

void testAngle()
{
    // testing function angleBwLines
    Line l1 = lineInit(sqrt(3), 0);
    Line l2 = lineInit(0, 1);
    Line l3 = lineInit(INFINITY, 2);
    Line l4 = lineInit(-10, 3);
    Line l5 = lineInit(78, -110);
    float check[25] = {0, -60, 30, 35.7106, 29.2655, 60, 0, 90, -84.2894, 89.2655, -30, -90, 0, -5.7106, -0.7345,
                       -35.7106, 84.2894, -5.7106, 0, -6.4451, -29.2655, -89.2655, 0.7345, 6.4451, 0};
    Line lines[5] = {l1, l2, l3, l4, l5};
    for (int i = 0; i < 5; i++)
    {
        for (int j = i; j < 5; j++)
        {
            if (fabs(angleBwLines(lines[i], lines[j]) - check[i * 5 + j]) > 0.0001)
            {
                // printf("%d %d %f %f\n",i,j,angleBwLines(lines[i],lines[j]),check[i*5+j]);
                printf("Test Angle FAILED\n");
                return;
            }
        }
    }
    printf("Test Angle passed\n");
}

void testPTL()
{
    // testing funtion which creates a line based on 2 points
    Point p1 = pointInit(1, 1);
    Point p2 = pointInit(-1000, 1);
    Point p3 = pointInit(-1000, 78);
    Point p4 = pointInit(89, -47);
    Point points[4] = {p1, p2, p3, p4};
    Line check1[3] = {lineInit(0, 1), lineInit(-0.0769, 1.0769), lineInit(-0.5455, 1.5455)};
    Line check2[2] = {lineInit(INFINITY, -1000), lineInit(-0.0441, -43.07713)};
    Line check3[1] = {lineInit(-0.1148, -36.7842)};
    for (int i = 0; i < 3; i++)
    {
        if (fabs(ptsToLine(p1, points[i + 1]).slope - check1[i].slope) > 0.0001 || fabs(ptsToLine(p1, points[i + 1]).intercept - check1[i].intercept) > 0.0001)
        {
            printf("Test PTL FAILED\n");
            return;
        }
    }
    for (int i = 0; i < 2; i++)
    {
        if (fabs(ptsToLine(p2, points[i + 2]).slope - check2[i].slope) > 0.0001 || fabs(ptsToLine(p2, points[i + 2]).intercept - check2[i].intercept) > 0.0001)
        {
            printf("Test PTL FAILED\n");
            return;
        }
    }
    if (fabs(ptsToLine(p3, p4).slope - check3[0].slope) > 0.0001 || fabs(ptsToLine(p3, p4).intercept - check3[0].intercept) > 0.0001)
    {
        printf("Test PTL FAILED\n");
        return;
    }
    printf("Test PTL passed\n");
}

void testIOL()
{
    // testing function intersectionOfLine and including cases where lines are parallel, coincident and vertical
    Line l1 = lineInit(1, 0);
    Line l2 = lineInit(-7, 6);
    Line l3 = lineInit(INFINITY, 2);
    Line l4 = lineInit(1, 6);
    Line l5 = lineInit(INFINITY, 0);
    Point check[15] = {{INFINITY, INFINITY}, pointInit(0.75, 0.75), pointInit(2, 2), {INFINITY, 0}, pointInit(0, 0), {INFINITY, INFINITY}, pointInit(2, -8), pointInit(0, 6), pointInit(0, 6), {INFINITY, INFINITY}, pointInit(2, 8), {INFINITY, 0}, {INFINITY, INFINITY}, pointInit(0, 6), {INFINITY, INFINITY}};
    Line lines[5] = {l1, l2, l3, l4, l5};
    int c = 0;
    for (int i = 0; i < 5; i++)
    {
        c += i;
        for (int j = i; j < 5; j++)
        {
            Point p = intersectionOfLine(lines[i], lines[j]);
            if (!isfinite(p.x) && !isfinite(check[i * 5 + j - c].x))
            {
                if(!isfinite(p.y) == !isfinite(check[i * 5 + j - c].y)){
                    continue;
                }
                printf("Test IOL FAILED\n");
                return;
                
            }
            if (p.x != check[i * 5 + j - c].x || p.y != check[i * 5 + j - c].y)
            {
                printf("Test IOL FAILED\n");
                return;
            }
        }
    }
    printf("Test IOL passed\n");
}

void testPeri()
{
    // testing function polyPeri
    // testing function polySortPoint
    // I have included polygons where collinear points are present
    Point points1[3] = {pointInit(0, 0), pointInit(0, 1), pointInit(1, 0)};
    Point points2[4] = {pointInit(0, 0), pointInit(-11, 1), pointInit(1, 1), pointInit(10, 0)};
    Point points3[5] = {pointInit(0, 0), pointInit(1, 1), pointInit(-10, -10), pointInit(1, 0), pointInit(2, 2)};
    Polygon poly1 = polyInit(points1, 3);
    Polygon poly2 = polyInit(points2, 4);
    Polygon poly3 = polyInit(points3, 5);
    int flag = 1;
    int fail[6] = {0};
    if (fabs(polyPeri(&poly1) - 3.4142) > 0.0001)
    {
        flag = 0;
        fail[0] = 1;
    }
    if (fabs(polyPeri(&poly2) - 42.1007) > 0.0001)
    {
        flag = 0;
        fail[1] = 1;
    }
    if (fabs(polyPeri(&poly3) - 34.0727) > 0.0001)
    {
        flag = 0;
        fail[2] = 1;
    }
    polySortPoint(&poly1);
    polySortPoint(&poly2);
    polySortPoint(&poly3);
    if (fabs(polyPeri(&poly1) - 3.4142) > 0.0001)
    {
        flag = 0;
        fail[3] = 1;
    }
    if (fabs(polyPeri(&poly2) - 44.4380) > 0.0001)
    {
        flag = 0;
        fail[4] = 1;
    }
    if (fabs(polyPeri(&poly3) - 18.9706) > 0.0001)
    {
        flag = 0;
        fail[5] = 1;
    }
    if (flag)
    {
        printf("Test Peri passed\n");
    }
    else
    {
        printf("Test Peri FAILED\n");
    }
    for(int i=0;i<6;i++){
        if(fail[i]==1){
            printf("Perimeter TC %d FAILED\n",i+1);
        }
    }
    return;
}

void testCent(){
    // testing function polyCentroid
    Point points1[3] = {pointInit(0, 0), pointInit(0, 1), pointInit(1, 0)};
    Point points2[4] = {pointInit(0, 0), pointInit(-11, 1), pointInit(1, 1), pointInit(10, 0)};
    Point points3[5] = {pointInit(0, 0), pointInit(1, 1), pointInit(-10, -10), pointInit(1, 0), pointInit(2, 2)};
    Polygon poly1 = polyInit(points1, 3);
    Polygon poly2 = polyInit(points2, 4);
    Polygon poly3 = polyInit(points3, 5);
    Point check[3] = {pointInit(1.0/3, 1.0/3), pointInit(0.0, 0.5), pointInit(-1.2, -1.4)};
    if(polyCentroid(&poly1).x != check[0].x || polyCentroid(&poly1).y != check[0].y){
        printf("Test Cent FAILED1\n");
        return;
    }
    if(polyCentroid(&poly2).x != check[1].x || polyCentroid(&poly2).y != check[1].y){
        printf("Test Cent FAILED2\n");
        return;
    }
    if(polyCentroid(&poly3).x != check[2].x || polyCentroid(&poly3).y != check[2].y){
        printf("Test Cent FAILED3\n");
        return;
    }
    printf("Test Cent passed\n");

}


int main()
{
    // I need to test all the functions in geometry.c
    testDist();
    testRef();
    testPTL();
    testAngle();
    testIOL();
    testPeri();
    testCent();
}
