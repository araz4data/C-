#include <iostream> 
#include <string>
#include <vector>
#include "car.h"


int main() {

    car car1 = car( "blue", 7, 10 ) ;
    car* carP1 = new car( "red", 0, 20 ) ;

    car1.increaseDis( 5 ) ;
    carP1->increaseDis( 5 ) ;

    car1.printInfo() ;
    carP1->printInfo() ;
///////////////////////////////////////////////////

    std::vector<car> cars ;
    cars = { car( "navy", 0, 1 ) , car( "green", 0, 2 ) } ;

    std::vector<car*> carsP ;
    car* carPR ;

    for ( int i = 0 ; i < 5 ; i++ ) {
	carPR = new car( "any color "+ std::to_string(i), 0, i ) ;
	carsP.push_back(carPR) ;
    }
    carPR = carsP[1] ;

    carPR->printInfo();


    for( car* carPR : carsP ) {
        carPR->printInfo();
    }


    return 0 ;
}
