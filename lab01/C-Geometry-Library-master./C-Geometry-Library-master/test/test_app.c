#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "geometry.h"

int orientation(Point a, Point b, Point c)
{
    int val = (b.y - a.y) * (c.x - b.x) - (b.x - a.x) * (c.y - b.y);
    return val;
}
Polygon ConvexHull(Polygon p) 
{
    Polygon dummy = polyInit(p.points, p.num_points);
    
    // Find the leftmost point
    int leftmost = 0;
    for (int i = 1; i < p.num_points; i++) {
        if (p.points[i].x < p.points[leftmost].x) {
            leftmost = i;
        } else if (p.points[i].x == p.points[leftmost].x) {
            if (p.points[i].y < p.points[leftmost].y) {
                leftmost = i;
            }
        }
    }
    int a = leftmost;
    int b;
    
    // Start wrapping around the points to find the convex hull
    do {
        Point point[] = {p.points[a]};
        // Add the current point to the convex hull
        polyAddPoints(&dummy, point, 1);

        // Search for a point 'b' such that orientation(p, b, r) is counterclockwise for all points 'r'
        b = (a + 1) % p.num_points;
        for (int i = 0; i < p.num_points; i++) {
            if (orientation(p.points[a], p.points[i], p.points[b])<0) {
                b = i;
            }
        }

        // Set p as b for the next iteration
        a = b;

    } while (a != leftmost); // While we don't come back to the first point

    Point points[dummy.num_points-p.num_points];

    for (int i = 0; i < dummy.num_points-p.num_points; i++)
    {
        points[i] = dummy.points[i+p.num_points];
    }
    
    Polygon convexHull = polyInit(points, dummy.num_points-p.num_points);

    // Print the convex hull
    polySortPoint(&convexHull);
    return convexHull;
}


void testConvexHull(){
    Point arr1[9]={pointInit(19,0),pointInit(-11,-51),pointInit(-61,8),pointInit(2,6),pointInit(0,0),pointInit(0,18.7),pointInit(-10,-20),pointInit(10,-10),pointInit(-20,0)};
    Point hull1[4]={pointInit(-11,-51),pointInit(19,0),pointInit(-61,8),pointInit(0,18.7)};
    Point arr2[6]={pointInit(6,-3),pointInit(5,5),pointInit(7,6),pointInit(3,4),pointInit(6,4),pointInit(10,8)};
    Point arr3[7]={pointInit(6,-3),pointInit(3,4),pointInit(4,3),pointInit(8,3),pointInit(5,1),pointInit(7,2),pointInit(10,8)};
    Point hull2[3]={pointInit(6,-3),pointInit(3,4),pointInit(10,8)};
    Point hull3[3]={pointInit(6,-3),pointInit(3,4),pointInit(10,8)};
    Point hull4[5]={pointInit(6,-2),pointInit(1,-1),pointInit(10,1),pointInit(2,3),pointInit(8,5)};
    Point arr4[15]={pointInit(6,-2),pointInit(1,-1),pointInit(10,1),pointInit(2,3),pointInit(8,5),pointInit(4,2),pointInit(5,3),pointInit(7,2),pointInit(3,1),pointInit(6,0),pointInit(4,-1),pointInit(5,1),pointInit(3,2),pointInit(7,1),pointInit(5,-0.5)};
    Point *points[4]={arr1,arr2,arr3,arr4};
    Point *hulls[4]={hull1,hull2,hull3,hull4};
    int sizes[4]={9,6,7,15};
    for(int i=0;i<4;i++){
        Polygon p = polyInit(points[i],sizes[i]);
        Polygon hull = ConvexHull(p);
        for(int j=0;j<hull.num_points;j++){
            if(hull.points[j].x!=hulls[i][j].x || hull.points[j].y!=hulls[i][j].y){
                printf("Test ConvexHull FAILED\n");
                return;
            }
        }
    }
    printf("Test ConvexHull passed\n");
}

int main(){
    
    testConvexHull();
    return 0;
}
