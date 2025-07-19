#ifndef SHOP_HPP
#define SHOP_HPP

#include <vector>
class Iterator;
class Product;

class Shop {
public:
    virtual Iterator* createIterator() = 0;

    virtual ~Shop() = default;

};

class ElectronicsShop : public Shop {
public:
    ElectronicsShop() = default;

    void addProduct(const Product& product);
    Iterator* createIterator() override;
    std::vector<Product>& getProducts();
private:
    std::vector<Product> products;
};

class SweetsShop : public Shop{
public:
    SweetsShop() = default; 

    void addProduct(const Product& product);

    Iterator* createIterator() override;
    std::vector<Product>& getProducts();
private:
    std::vector<Product> products;
};

#endif