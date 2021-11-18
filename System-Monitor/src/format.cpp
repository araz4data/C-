#include <string>

#include "format.h"

using std::string;

// TODO: Complete this helper function
// INPUT: Long int measuring seconds
// OUTPUT: HH:MM:SS
// REMOVE: [[maybe_unused]] once you define the function

string Format::ElapsedTime(long seconds) { 

 int hours = (int) (seconds / 3600.0 ) ;	
 int mins = (int) ( ( seconds - hours*3600 ) / 60.0 ) ;	
 int secs = (int) (seconds - hours*3600 - mins*60 ) ;
 string retStr = std::to_string(hours) + ":" + std::to_string(mins) + ":" + std::to_string(secs) ;

 return retStr; 

}
