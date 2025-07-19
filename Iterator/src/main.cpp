#include "Shop.hpp"
#include "Product.hpp"
#include "Iterator.hpp"
#include <iostream>
#include <memory> 

int main() {
    ElectronicsShop shop1;
    shop1.addProduct(Product("TV", 1000));
    shop1.addProduct(Product("Laptop", 900.25));
    shop1.addProduct(Product("Phone", 499.50));

    SweetsShop shop2;
    shop2.addProduct(Product("Cake", 10));
    shop2.addProduct(Product("Candy", 5));
    shop2.addProduct(Product("IceCream", 5.4));


    std::unique_ptr<Iterator> it(shop1.createIterator());

    std::unique_ptr<Iterator> it2(shop2.createIterator());

    while(it->hasMore()) {
        Product* p = it->getNext();
        if (p != nullptr) {
            std::cout << "Electronics Product: " << p->getType()
                      << ", Cost: $" << p->getCost() << std::endl;
        }
    }

    while(it2->hasMore()) {
        Product* p = it2->getNext();
        if(p != nullptr) {
            std::cout << "Sweets Product: " <<p->getType()
                      << ", Cost: $" <<p->getCost() << std::endl; 
        }
    }

    return 0;
}
