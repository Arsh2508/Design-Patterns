#include "Shop.hpp"
#include "Product.hpp"
#include "Iterator.hpp"
#include <iostream>
#include <memory> 

int main() {
    ElectronicsShop shop;
    shop.addProduct(Product("TV", 1000));
    shop.addProduct(Product("Laptop", 900.25));
    shop.addProduct(Product("Phone", 499.50));

    std::unique_ptr<Iterator> it(shop.createIterator());

    while (it->hasMore()) {
        Product* p = it->getNext();
        if (p != nullptr) {
            std::cout << "Product: " << p->getType()
                      << ", Cost: $" << p->getCost() << '\n';
        } else {
            std::cout << "No more products.\n";
        }
    }

    return 0;
}
