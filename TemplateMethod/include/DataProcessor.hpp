#ifndef DATAPROCESSOR_HPP
#define DATAPROCESSOR_HPP
#include <string>
#include <vector>

class DataProcessor {
public:
    void execute();
    virtual ~DataProcessor() = default;
protected:
    virtual void readData() = 0;
    virtual void processData() = 0;
    virtual void saveData() = 0;
};

class CSVProcessor : public DataProcessor {
public:
    CSVProcessor(const std::string& input, const std::string& output);

private:
    std::string inputFile;
    std::string outputFile;
    std::vector<std::string> data;

    void readData() override;
    void processData() override;
    void saveData() override;
};

class JSONProcessor : public DataProcessor {
public:
    JSONProcessor(const std::string& input, const std::string& output);
private:
    std::string inputFile;
    std::string outputFile;
    std::vector<std::string> data;

    void readData() override;
    void processData() override;
    void saveData() override; 
};

#endif 