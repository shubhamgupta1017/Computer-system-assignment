#include <stdlib.h>
#include <stdio.h>
#include "geometry.h"
#include <math.h>

// Initalizes a point with given x and y coordinates
Point pointInit(float x, float y) {
    Point p;
    if(x == INFINITY || y == INFINITY || x == -INFINITY || y == -INFINITY){  //checking for infinity
        printf("Invalid input\n");
        p.x = INFINITY;
        p.y = INFINITY;
        return p;
    }
    p.x = x;
    p.y = y;
    return p;
}

// Initalizes a line with given slope and y-intercept
Line lineInit(float slope, float intercept) {
    Line l;
    if(intercept == INFINITY || slope == -INFINITY || intercept == -INFINITY){ //checking for infinity
        printf("Invalid input\n");
        l.slope = INFINITY;
        l.intercept = INFINITY;
        return l;
    }
    l.slope = slope;
    l.intercept = intercept;
    return l;
}

// Returns the distance between two points
float distance(Point p1, Point p2) {
    return sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2));
}

// Returns the point after reflection about a line
Point reflectionAboutLine(Point p, Line l) {  
    Point reflected_point;
    if(l.slope==INFINITY){ //if line is vertical
        reflected_point.x = 2*l.intercept - p.x;
        reflected_point.y = p.y; 
        return reflected_point;
    }
    float x1 = (p.x + l.slope * (p.y - l.intercept)) / (1 + pow(l.slope, 2));//formula for reflection
    float y1 = l.slope * x1 + l.intercept;//formula for reflection
    reflected_point.x = 2 * x1 - p.x;
    reflected_point.y = 2 * y1 - p.y;
    return reflected_point;
}

// Returns the angle between two lines
float angleBwLines(Line l1, Line l2) {
    float angle_deg;
    if (l1.slope == INFINITY && l2.slope == INFINITY) { //if both lines are vertical
        angle_deg = 0;
    } 
    else if (l1.slope == INFINITY || l2.slope == INFINITY) { //if one line is vertical
        if (l1.slope == INFINITY) {
            angle_deg = atan((l2.slope)) * 180 / M_PI;
            angle_deg = angle_deg -90;
        } 
        else {
            angle_deg = atan((l1.slope)) * 180 / M_PI;
            angle_deg = 90 - angle_deg ;
        }
    } 
    else {
        float angle_tan = (l2.slope - l1.slope) / (1 + l1.slope * l2.slope);//formula for angle between two lines
        float angle_rad = atan(angle_tan);
        angle_deg = angle_rad * 180 / M_PI;
    }
    if(angle_deg>90){
        angle_deg = 180 - angle_deg;
    }
    if(angle_deg<-90){
        angle_deg = -180 - angle_deg;
    }
    return angle_deg;
}

// Returns the line passing through two points
Line ptsToLine(Point p1, Point p2) {
    Line l;
    if(p1.x == p2.x){//if line is vertical
        l.slope = INFINITY;
        l.intercept = p1.x;
        if(p1.y == p2.y){
            printf("Points are coincident\n");
            l.intercept = INFINITY;
            l.slope = INFINITY;
            return l;
        }
    }
    else{
    l.slope = (p2.y - p1.y) / (p2.x - p1.x);//formula for slope
    l.intercept = p1.y - l.slope * p1.x;
    }
    return l;
}

Point intersectionOfLine(Line l1, Line l2)
{
    Point p;
    if (l1.slope == l2.slope)
    { // if lines are parallel
        if (l1.intercept == l2.intercept)
        {
            // printf("Lines are coincident\n");
            p.x = INFINITY;
            p.y = INFINITY;
        }
        else
        {
            // printf("Lines are parallel\n");
            p.x = INFINITY;
            p.y = 0;
        }
    }
    else if (l1.slope == INFINITY)
    { // if line 1 is vertical
        p.x = l1.intercept;
        p.y = l2.slope * p.x + l2.intercept;
    }
    else if (l2.slope == INFINITY)
    { // if line 2 is vertical
        p.x = l2.intercept;
        p.y = l1.slope * p.x + l1.intercept;
    }
    else
    {
        p.x = (l2.intercept - l1.intercept) / (l1.slope - l2.slope); // formula for intersection
        p.y = l1.slope * p.x + l1.intercept;
    }
    return p;
}



Polygon polyInit(Point p[],int num_points) {//initializing polygon
    Polygon poly;
    if(num_points<=2){
        printf("Invalid input\n");
        poly.num_points = -1;
        poly.points = NULL;
        return poly;
    }
    poly.points = (Point *) malloc(num_points * sizeof(Point));
    poly.num_points = num_points;
    for(int i=0;i<num_points;i++){
        poly.points[i] = p[i];
    }
    return poly;
}

void polyAddPoints(Polygon *poly, Point p[],int size) {//adding points to polygon
    if(poly->num_points + size <= 2){
        printf("Invalid input\n");
        return ;
    }
    poly->points = (Point *) realloc(poly->points, (poly->num_points + size) * sizeof(Point));
    for(int i=0;i<size;i++){
        poly->points[poly->num_points + i] = p[i];
    }
    poly->num_points += size;
    return ;
}

Point polyGetPoint(Polygon *poly, int idx) {//getting point from polygon
    if (idx < 0 || idx >= poly->num_points) {
        printf("Invalid index\n");
        Point Po = {INFINITY,INFINITY};
        return Po;
    }
    return poly->points[idx];
}

int compare(const void *a, const void *b) {//comparing two points
    Point *pointA = (Point *)a;
    Point *pointB = (Point *)b;
    if (pointA->y != pointB->y) {
        return pointA->y - pointB->y;
    } else {
        return pointA->x - pointB->x;
    }
}

void polySortPoint(Polygon *poly){//sorting points in polygon
    qsort(poly->points, poly->num_points, sizeof(Point), compare);
}

float polyPeri(Polygon *poly){//calculating perimeter of polygon
    float peri = 0;
    for(int i=0;i<poly->num_points-1;i++){
        peri += distance(poly->points[i],poly->points[i+1]);
    }
    peri += distance(poly->points[poly->num_points-1],poly->points[0]);
    return peri;
}

Point polyCentroid(Polygon *poly)
{ // calculating centroid of polygon
    float x = 0;
    float y = 0;
    for (int i = 0; i < poly->num_points; i++)
    {
        x += poly->points[i].x;
        y += poly->points[i].y;
    }
    x = x / poly->num_points;
    y = y / poly->num_points;
    Point centroid = {x, y};
    return centroid;
}

void polyPrint(Polygon *poly) {//printing polygon
    for (int i = 0; i < poly->num_points; i++) {
        printf("Point %d: (%f, %f)\n", i, poly->points[i].x, poly->points[i].y);
    }
}



