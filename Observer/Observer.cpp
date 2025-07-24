#include "Observer.hpp"
#include <iostream>

void PhoneDisplay::update(double temp)
{
    std::cout<<"[Phone display] Temperature is "<< temp <<"°C\n";
}

void LEDDisplay::update(double temp)
{
    std::cout<<"[LED display] Temperature is "<< temp <<"°C\n";
}
