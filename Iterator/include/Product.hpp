#ifndef PRODUCT_HPP
#define PRODUCT_HPP
#include <string>

class Product {
public:
    Product(const std::string& type, double cost);

    std::string getType() const;
    double getCost() const;
private:
    std::string m_type;
    double m_cost;

};

#endif