#include <assert.h>

// TODO: Define Point class
class Point {
   public:
    int x ;
    int y ;
    Point( int x_ = 0 , int y_  = 0 ) { 
        x = x_ ; 
        y = y_ ;
    } ;
    //Point(int x = 0, int y = 0) : x(x), y(y) {}
    Point operator+( const Point& P1 ) {
        Point p ;
        p.x = P1.x + x ;
        p.y = P1.y + y ;
        
        return p ;
    }
    int operator() () { return x ; }
    int operator() (int x__) { return x+x__ ; }
} ;
  // TODO: Define public constructor
  // TODO: Define + operator overload
  // TODO: Declare attributes x and y
// Test in main()
int main()  {
  Point p1(10, 5), p2(2, 4);
  Point p3 = p1 + p2; // An example call to "operator +";
  assert(p3.x == p1.x + p2.x);
  assert(p3.y == p1.y + p2.y);

  assert( p1() == p1.x) ;
  assert( p1(5) == p1.x+5) ;
}
