#include <iostream> 
#include <string>

#ifndef CAR_H
#define CAR_H

    class car {
	private:
	    std::string color ;
	    int distance ;
	    int number ;

	public:

	    car ( std::string c, int d, int n ) {
		    color = c ;
		    distance = d ;
		    number = n ;
	    } ;


    	    void printInfo() ;
	    int getNum() ;  
	    int getDis() ;
	    void increaseDis( int ) ;

    } ;
			    
#endif
