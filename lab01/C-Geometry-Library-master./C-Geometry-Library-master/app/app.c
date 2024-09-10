#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "geometry.h"

Polygon ConvexHull(Polygon p);
int orientation(Point a, Point b, Point c);

int main()
{
    int n;
    printf("Enter the no. of points: ");
    scanf("%d", &n);
    
    Point points[n];
    for (int i = 0; i < n; i++)
    {
        printf("Enter Point %d: ", i+1);
        scanf("%f %f", &points[i].x, &points[i].y);
    }
    
    Polygon polygon = polyInit(points, n);
    ConvexHull(polygon);

    return 0;
}

// find convex hull using Jarvis' algorithm
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

int orientation(Point a, Point b, Point c)
{
    int val = (b.y - a.y) * (c.x - b.x) - (b.x - a.x) * (c.y - b.y);
    return val;
}
