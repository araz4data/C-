#include <iostream>
#include <memory>
#include <vector>
class MyClass
{
private:
    int _member;
public:
    int* _member2 ;
    MyClass(int val) : _member{val} {}
    void printVal() { std::cout << ", managed object " << this << " with val = " << _member << std::endl; }
    void changeVal(int new_) { _member = new_ ; } ;
    void allocate(int size_, int value_) { 
	    if ( _member2 != NULL )
	    _member2 = new int(size_) ; 
	    _member2[size_-1] = value_ ; 
	    std::cout << "allocated  " << _member2 << std::endl; 
    } 
};

void f(std::unique_ptr<MyClass> ptr)
{
    std::cout << "unique_ptr " << &ptr;
    ptr->printVal();
}

void f1(std::shared_ptr<MyClass>& ptr, int value_)
{
   std::cout << "shared_ptr (ref_cnt= " << ptr.use_count() << ") " << &ptr;
   ptr->changeVal(value_);
   ptr->printVal();
//   ptr->allocate(15,10) ;
}

int main()
{
    /*
    MyClass myClass0(2) ;
    MyClass* myClass1 = new MyClass(2) ;
    std::vector<MyClass> myClassVec ;
    myClassVec.push_back(MyClass(1)) ;
    myClassVec.push_back(*myClass1);
    std::unique_ptr<MyClass> uniquePtr(new    MyClass(23)) ;
   */
    //std::unique_ptr<MyClass> uniquePtr = std::make_unique<MyClass>(23);
    std::unique_ptr<MyClass> uniquePtr ;
    uniquePtr = std::make_unique<MyClass>(23);
    std::cout << "unique_ptr " << &uniquePtr;
    uniquePtr->printVal();

    f(std::move(uniquePtr));

    if (uniquePtr)
        uniquePtr->printVal();

    std::cout << "starting shared " << std::endl ;

    std::shared_ptr<MyClass> sharedPtr = std::make_shared<MyClass>(23);
    std::cout << "shared_ptr (ref_cnt= " << sharedPtr.use_count() << ") " << &sharedPtr;
    sharedPtr->printVal();
//    sharedPtr->allocate(2,20) ;
//    delete sharedPtr->_member2 ;

//    for(int i = 0 ; i < 100000000 ; i++ ) {
    f1( sharedPtr,24);
//    std::cout << sharedPtr->_member2[1] << std::endl;
//    }
    std::cout << "shared_ptr (ref_cnt= " << sharedPtr.use_count() << ") " << &sharedPtr;
    sharedPtr->printVal();

//    delete sharedPtr->_member2 ;

    return 0;
}
