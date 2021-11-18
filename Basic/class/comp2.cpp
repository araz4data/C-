#include <iostream>
#include <cmath>
#include <assert.h>

// Define pi
float pi = 3.1415 ;

// Define Line Class
class LineSegment {
//struct LineSegment {
    // Define protected attribute length
    public:
      LineSegment( double length_) ;   
      double length ;
//        length = length_ ;
//      }
//   private:
//    double length ;
} ;

LineSegment::LineSegment( double length_) {
	length = length_ ;
} ;

// Define Circle subclass
class Circle {
    // Define public setRadius() and getArea()
    public:
    LineSegment myRadi( double r ) ;
     //Circle( double radius_) {
     //Circle( LineSegment radius_) {
     Circle( LineSegment myRadi ) {
         radius = myRadi ;
     } 
     
//     float Area() { return pi*radius.length*radius.length ;}
    private:
     LineSegment radius ;
//     double radius ;
     
} ;

    
// Test in main()
int main() 
{
//    LineSegment radius {3.} ;
//    double radius = 3;
//    Circle circle(radius);
//    assert(int(circle.Area()) == 28);
}
