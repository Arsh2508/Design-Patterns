#include "Product.hpp"

Product::Product(const std::string &type, double cost)
    : m_type{type}
    , m_cost{cost}
{}

std::string Product::getType() const
{
    return m_type;
}

double Product::getCost() const
{
    return m_cost;
}
