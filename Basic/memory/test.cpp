#include <iostream>

class intArray {
    private:
	int size ;
	int* array ;
    public:
	intArray( int size_ ) {
	    size = size_ ;
	    array = new int[size] ;
	}

	intArray( intArray &source ) {
	    size = source.size ;
	    array = new int[size] ;
	    *array = *source.array ;
	}

	intArray &operator=( intArray &source ) {
	    if ( this == &source ) return source ;
	    this->size = source.size ;
	    this->array = new int[this->size] ;
	    *this->array = *source.array ;
	    return *this ;
	}

	~intArray() {
	    delete[] array ;
	}
} ;


int main() {
    intArray a1(5) ;
    intArray a2(a1) ;
    intArray a3(5) ;  
    a3 = a1 ;
}
