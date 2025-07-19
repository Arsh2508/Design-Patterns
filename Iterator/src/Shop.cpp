#include "Shop.hpp"
#include "Product.hpp"
#include "Iterator.hpp"

void ElectronicsShop::addProduct(const Product &product)
{
    products.push_back(product);
}

Iterator *ElectronicsShop::createIterator()
{
    return new ElectoronicsIterator(this);
}

std::vector<Product>& ElectronicsShop::getProducts()
{
    return products;
}

void SweetsShop::addProduct(const Product &product)
{
    products.push_back(product);
}

Iterator *SweetsShop::createIterator()
{
    return new SweetsIterator(this);
}

std::vector<Product>& SweetsShop::getProducts()
{
    return products;
}




