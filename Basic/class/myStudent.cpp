#include <cassert>
#include <stdexcept>
#include <string>
#include <cstring>
#include <iostream>

// TODO: Define "Student" class
class Student {
 public:
    Student( std::string name_, int grade_, float gpa_){
        nameCPP = name_ ;
        grade = grade_ ;
        gpa = gpa_ ;
    }
    void setNameCPP( std::string name_) { 
        nameCPP = name_ ;
        if ( name_.length() == 0 ) {
            throw std::invalid_argument("No name is given") ;
            std::cout << "error " << "\n" ;
        }
    }
    void setNameC( std::string name_) {
        nameC = new char[ name_.length() + 1 ] ;
        strcpy( nameC, name_.c_str() ) ;
        nameCPP = name_ ;
        if ( name_.length() == 0 )
            throw std::invalid_argument("No name is given") ; 
    }
    void setGrade( int grade_ ) {
        grade = grade_ ;
        if ( grade <=0 || grade > 12 )
            throw std::invalid_argument("Grade must be between 1 to 12") ;
    }
    void setGPA( int gpa_ ) {
        gpa = gpa_ ;
        if ( gpa <=0 || gpa > 4.0 )
            throw std::invalid_argument("GPA must be between 0 to 4") ;
    }
    std::string getNameCPP() { return nameCPP ;}
    char* getNameC() { return nameC ;}
  // constructor
  // accessors
  // mutators

 private:
    char* nameC ;
    std::string nameCPP ;
    int grade ;
    float gpa ;
  // name
  // grade
  // GPA
};

// TODO: Test
int main() {
    Student student("Alex", 10, 4.0) ;
    //student.setNameCPP("");
    //student.setGrade( -2 ) ;
    
    try {
        student.setGrade( 2 ) ;
        student.setNameCPP("AB");
        student.setNameC("Cname");
    } catch (...) {
        assert(false) ;
    }
    std::cout << "Student name is "<< student.getNameCPP() << "\n" ;
    printf("Student C name is %s \n", student.getNameC() ) ;
}
