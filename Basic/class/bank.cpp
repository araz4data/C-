#include <iostream>
#include <string>

class BankAccount
{
  private:
      // TODO: declare member variables
    int account ;
    std::string name ;
    float fund ;

  public:
      // TODO: declare setters
      BankAccount( int account, std::string name, float fund ) ;
      void setAccount(int account ) ;
      void setName( std::string name ) ;
      void setFund(float fund ) ;
      // TODO: declare getters
      int getAccount() const ;
      std::string getName() const ;
      float getFund() const ;
};

// TODO: implement setters
BankAccount::BankAccount( int account, std::string name, float fund ) {
    BankAccount::setAccount( account) ;
    BankAccount::setName( name ) ;
    BankAccount::setFund( fund ) ;
}
void BankAccount::setAccount( int account) {
    BankAccount::account = account ;
}
void BankAccount::setName( std::string name) {
    BankAccount::name = name ;
}
void BankAccount::setFund( float fund) {
    BankAccount::fund = fund ;
}
// TODO: implement getters

std::string BankAccount::getName() const { return BankAccount::name ;}
int BankAccount::getAccount() const { return BankAccount::account ;}
float BankAccount::getFund() const { return BankAccount::fund ;}


int main(){
    // TODO: instantiate and output a bank account
    
    BankAccount  bankAccount("a", 10,10.1) ;
//    bankAccount.setName( "Annoshe" ) ;
//    bankAccount.setAccount( 12345 ) ;
//    bankAccount.setFund( 100123.56 ) ;    
    
}
