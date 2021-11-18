#include <iostream>
#include <memory>

int main()
{
    std::shared_ptr<int> shared1(new int);
    std::cout << "shared pointer count = " << shared1.use_count() << std::endl;

    {
        std::shared_ptr<int> shared2 = shared1;
        std::cout << "shared pointer count = " << shared1.use_count() << std::endl;
        std::shared_ptr<int> shared3 = shared1;
        std::cout << "shared pointer count = " << shared1.use_count() << std::endl;
        
    std::cout << "shared pointer count = " << shared2.use_count() << &shared1 << " " << &shared2 <<  " " << &shared3 << std::endl;

    }
    std::cout << "shared pointer count = " << shared1.use_count() <<" "  << &shared1 << std::endl;
    

    return 0;
}
