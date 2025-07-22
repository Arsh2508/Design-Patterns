#include "DataProcessor.hpp"
#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <exception>

void DataProcessor::execute()
{
    readData();
    processData();
    saveData();
}

CSVProcessor::CSVProcessor(const std::string &input, const std::string &output)
    : inputFile{input}
    , outputFile{output}
{}

void CSVProcessor::readData()
{
    std::ifstream file(inputFile);

    if(!file.is_open()){
        throw std::runtime_error("Failed to open the file: " + inputFile);
    }

    std::string line;
    while(std::getline(file, line)){
        data.push_back(line);
    }

    std::cout<<"CSV read "<<data.size()<<" lines:\n";
}

void CSVProcessor::processData()
{
    for(size_t i = 0; i < data.size(); ++i){
        data[i] += "[Processed]";
    }
}

void CSVProcessor::saveData()
{
    std::ofstream file(outputFile);
    if(!file.is_open()){
        throw std::runtime_error("Failed to open the file: " + outputFile);
    }
    for(size_t i = 0; i < data.size(); ++i){
        file << data[i] << '\n';
    }
    std::cout<<"CSV saved to "<<outputFile<<std::endl;
}

JSONProcessor::JSONProcessor(const std::string &input, const std::string &output)
    : inputFile{input}
    , outputFile{output}
{}

void JSONProcessor::readData()
{
   std::ifstream file(inputFile);
   if(!file.is_open()){
        throw std::runtime_error("Failed to open the file: " + inputFile);
   } 

   std::string line;
   while(std::getline(file, line)) {
        data.push_back(line);
   }
   std::cout<<"JSON read "<<data.size() <<" lines:\n";
}

void JSONProcessor::processData()
{
    for(size_t i = 0; i < data.size(); ++i){
        data[i] += " //processed:";
    }
}

void JSONProcessor::saveData()
{
    std::ofstream file(outputFile);
    if(!file.is_open()) {
        throw std::runtime_error("Failed to open the file " + outputFile);
    }

    for(size_t i = 0; i < data.size(); ++i) {
        file << data[i] << '\n';
    }

    std::cout<< "JSON saved to " << outputFile <<std::endl;
}  
