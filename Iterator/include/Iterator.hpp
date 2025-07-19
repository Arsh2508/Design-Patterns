#ifndef ITERATOR_HPP
#define ITERATOR_HPP
#include <vector>

#include "Product.hpp"
#include "Shop.hpp"

class Iterator {
public:
    virtual Product* getNext() = 0;
    virtual bool hasMore() = 0;
    virtual ~Iterator() = default;  
};

class ElectoronicsIterator : public Iterator {
public:
    ElectoronicsIterator(ElectronicsShop* shop);
    Product *getNext() override;
    bool hasMore() override;

private:
    ElectronicsShop* m_shop;
    size_t currentPosition;
};



#endif