#include <iostream>
#include <memory>

class intVec {
    private:
	int size ;
    public:
	int* vec ;
	intVec( int size_ ) {
	    size = size_ ;
	    //std::unique_ptr<int> vec( new int(size) ) ;
	    vec = new int(size) ;
	}
	void setValue( int id, int value ) { vec[id] = value ; }	
	~intVec(){
	    //delete vec ;
	    std::cout << "deleted" << std::endl ;
	}
} ;

int main() {
	/*
	for( int i = 0 ; i < 10 ; i++ ) {
	   std::unique_ptr<intVec> myIntVec(new intVec(5)) ;
	   for( int j = 0 ; j < 5 ; j++ ) myIntVec->vec[j] = j+1 ;
	   //intVec myIntVec(100000000) ;
	   std::unique_ptr<int> vec2( new int(10) ) ;
	   for( int j = 0 ; j < 5 ; j++ ) vec2.get()[j] = j+1 ;
	std::cout << "vec2" <<vec2.get()[3] <<std::endl ;
	}
	*/
	//std::unique_ptr<intVec> myIntVec = std::make_unique<intVec>(10000) ;
	intVec myIntVec(10000);
	myIntVec.setValue(0,100);
	std::cout << "done" << std::endl ;

	int*    vec = new int(10000) ;
	return 0 ;
}

