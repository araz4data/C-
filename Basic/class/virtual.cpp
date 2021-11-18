// Example solution for Shape inheritance
#include <assert.h>
#include <cmath>

// TODO: Define pi
double const pi = 3.1415 ;

// TODO: Define the abstract class Shape
class Shape {
   public:
    virtual double Area() = 0 ;
    virtual double Perimeter() = 0;
} ;
  // TODO: Define public virtual functions Area() and Perimeter()
  // TODO: Append the declarations with = 0 to specify pure virtual functions

class Rectangle : public Shape {
public:
   Rectangle(double w_ = 0.0, double h_ = 0.0) { w = w_ ; h = h_ ;}
    double Area() { return h*w ; } 
    double Perimeter() { return 2*h+2*w ; }
private:
    double w ;
    double h ;
} ;
// TODO: Define Rectangle to inherit publicly from Shape
  // TODO: Declare public constructor
  // TODO: Override virtual base class functions Area() and Perimeter()
  // TODO: Declare private attributes width and height

// TODO: Define Circle to inherit from Shape
  // TODO: Declare public constructor
  // TODO: Override virtual base class functions Area() and Perimeter()
  // TODO: Declare private member variable radius
class Circle : public Shape {
    public:
     Circle( double radius_ = 0 ) { radius = radius_ ; }
     double Area() { return pi*radius*radius ; } 
     double Perimeter() { return 2*pi*radius ; }     
    private:
     double radius ;
} ;
// Test in main()
int main() {
  double epsilon = 0.1; // useful for floating point equality

  // Test circle
  Circle circle(12.31);
  assert(abs(circle.Perimeter() - 77.35) < epsilon);
  assert(abs(circle.Area() - 476.06) < epsilon);

  // Test rectangle
  Rectangle rectangle(10, 6);
  assert(rectangle.Perimeter() == 32);
  assert(rectangle.Area() == 60);
}
