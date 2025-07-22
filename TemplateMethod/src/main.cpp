#include "DataProcessor.hpp"
#include <iostream>
#include <memory>

void ClientCode(DataProcessor *client){
    client->execute();
}

int main()
{
    DataProcessor *json = new JSONProcessor("./Files/JSONFile.txt", "./Files/JSONProcessed.txt");
    DataProcessor *csv = new CSVProcessor("./Files/CSVFile.txt", "./Files/CSVProcessed.txt");   
    try{
        ClientCode(json);
        ClientCode(csv);
    }
    catch(const std::runtime_error& er){
        std::cout << er.what() << std::endl;
    }

    delete json;
    delete csv;
}