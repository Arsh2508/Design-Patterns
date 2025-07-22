#include <iostream>
#include "Logger.hpp"

int main() 
{
    Logger* logger = Logger::getInstance();

    logger->log("Hello World");

    delete logger;
    
    return 0;   
}