typedef struct {
    float x;
    float y;
} Point;

typedef struct {
    float slope;
    float intercept;
} Line;

typedef struct{
    Point *points;
    int num_points;
} Polygon;

Point pointInit(float x, float y);
Line lineInit(float slope, float intercept);
Polygon polyInit(Point p[],int num_points);
void polyAddPoints(Polygon *poly, Point p[],int size);
Point polyGetPoint(Polygon *poly, int idx);
void polySortPoint(Polygon *poly); 
void polyPrint(Polygon *library);
float angleBwLines(Line l1, Line l2);
float polyPeri(Polygon *poly);
float distance(Point p1, Point p2);
Point reflectionAboutLine(Point p, Line l);
Line ptsToLine(Point p1, Point p2);
Point intersectionOfLine(Line l1, Line l2);
Point polyCentroid(Polygon *poly);
