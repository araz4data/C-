#include <vector>
#include<iostream>

class Wheel {
	public:
	  float diam ;
	  float thick ;
	  Wheel() : diam(13.) , thick(2.5) {} 
} ;

class Car {
	public:
	std::vector<Wheel> wheels[4] ;
} ;

int main() {
	Wheel wheel ;
	Car car ;
	std::vector<Wheel> wheel1 = car.wheels[0]  ;
	std::cout << wheel1[].diam << "\n" ;
}
