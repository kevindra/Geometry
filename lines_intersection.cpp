/**
  * @author: kevindra
  */

#include <iostream>
#include <math.h>
#include <vector>

using namespace std;

/**
  * point 
  * x,y coordinates
  */
struct point {
  double x,y;
};

/**
  * @func dot
  * @params p1,p2: two points
  * @returns dot product of vector p1 and p2
  */
double dot( point p1, point p2 ) {
  return p1.x*p2.x + p1.y*p2.y;
}

/**
  * @func cross
  * @params p1,p2: two points
  * @returns magnitude of cross product of p1 and p2.
  */
double cross( point p1, point p2 ) {
  return p1.x*p2.y - p1.y*p2.x;
}

/**
  * @func mag
  * @params p, vector
  * @desc magnitude of vector
  */
double mag( point p) {
  return sqrt(p.x*p.x + p.y*p.y);
}

/**
  * @func dist
  * @params p1,p2: two points
  * @returns distance between p1,p2
  */
double dist( point p1, point p2 ) {
  int a = p1.x - p2.x;
  int b = p1.y - p2.y;
  return sqrt( a*a + b*b );
}


/**
  * @func sdist
  * @params p1,p2: two points
  * @returns square of distance between p1,p2
  */
double sdist( point p1, point p2 ) {
  int a = p1.x - p2.x;
  int b = p1.y - p2.y;
  return ( a*a + b*b );
}

/**
  * @func getVector
  * @params a,b: two points.
  * @returns vector passing through points a,b.
  */
point getVector( point a, point b ) {
  point p;
  p.x = b.x - a.x;
  p.y = b.y - a.y;
  return p;
}

/**
  * @func linesIntersection
  * @params Two lines in the form of equation:
  * A1(x) + B1(y) = C1
  * A2(x) + B2(y) = C2
  * 
  * To use this function generate the line in the above form first then use it.
  * It is easy to generate the lines in above equation if atleast two points on the line are given
  *
  * If line passes through (x1,y1) and (x2,y2) points then A,B,C can be easily found out by:
  *
  * A = y2-y1
  * B = x2-x1
  * C = A*x1 + B*y1 (pretty easy huh!!) 
  *
  * @returns NULL if lines are parallel, object "point" which contains their intersection point otherwise.
  *
  */
point *linesIntersection( double A1, double B1, double C1, double A2, double B2, double C2 )  {
  double det = A1*B2 - A2*B1;
  if ( det == 0 ) {
    // infinite solution to the lines' equations
    // hence lines are parallel
    return NULL;
  }
  else {
    point *p = new point;
    p->x = (B2*C1 - B1*C2)/det;
    p->y = (A1*C2 - A2*C1)/det;
  
    // speacial case: if x or y == 0 ant det < 0
    // fixing x=-0, y=-0 case
    if( p->x == 0 ) p->x = fabs(p->x);
    if( p->y == 0 ) p->y = fabs(p->y);
    
    return p;
  }
}

int main () {
  //line1
  point p1 = {0,0};
  point p2 = {2,0};

  //line2
  point p3 = {1,2};
  point p4 = {1,1};


  // lets find A,B,C for the lines
  double A[2],B[2],C[2];

  A[0] = p2.y - p1.y;
  B[0] = p1.x - p2.x;
  C[0] = A[0]*p1.x + B[0]*p1.y;

  
  A[1] = p4.y - p3.y;
  B[1] = p3.x - p4.x;
  C[1] = A[1]*p3.x + B[1]*p3.y;
  
  //now use the function 
  point *p = linesIntersection(A[0], B[0], C[0], A[1], B[1], C[1]);

  if( p == NULL ) {
    cout<<"Lines are parallel\n";
  }
  else  {
    cout<<"Lines intersect at point ( "<<p->x<<", "<<p->y<<" ).\n";
  }
  return 0;
}
