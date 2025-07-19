#include "Iterator.hpp"
#include "Shop.hpp"
#include "Product.hpp"


ElectoronicsIterator::ElectoronicsIterator(ElectronicsShop *shop)
    : m_shop{shop}
    , currentPosition{0}
{}

Product* ElectoronicsIterator::getNext()
{
    if(hasMore()) {
        return &m_shop->getProducts()[currentPosition++];    
    }
    return nullptr;
}

bool ElectoronicsIterator::hasMore()
{
    if(currentPosition < m_shop->getProducts().size()){
        return true;
    }
    return false;
}

SweetsIterator::SweetsIterator(SweetsShop *shop)
    : m_shop{shop}
    , currentPosition{0}
{}

Product *SweetsIterator::getNext()
{
    if(hasMore()){
        return &m_shop->getProducts()[currentPosition++];
    }
    return nullptr;
}

bool SweetsIterator::hasMore()
{
    if(currentPosition < m_shop->getProducts().size()){
        return true;
    }
    return false;
}
