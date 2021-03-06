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
  * @func distLinePoint
  * @params a,b two points on the line
  * @params c point from which distance is being calculated
  */
double distLinePoint( point a, point b, point c, bool isSegment) {
  point AB,AC;
  AB  = getVector(a,b);
  AC  = getVector(a,c);

  if( isSegment ) {
    point BA = getVector(b,a);
    int dot1  = dot(BA,AC);
    point BC = getVector(b,c);
    int dot2  = dot(AB,BC);

    if( dot1 > 0 ) return dist(b,c);  //if point is in rightside of segment
    if( dot2 > 0 ) return dist(c,a);  //if point is in leftside of segment
  }

  //in all other cases.
  return cross(AB,AC) / mag(AB);
}

int main () {
  point p1 = {0,0};
  point p2 = {2,0};
  point p3 = {2,2};

  vector<point> p(3);
  p[0] = p1, p[1] = p2, p[2] = p3;

  //cout << distLinePoint(p1,p2,p3,true) <<endl;
  cout << distLinePoint(p[0], p[1], p[2],true) <<endl;
  return 0;
}
