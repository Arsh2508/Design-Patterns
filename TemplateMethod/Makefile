CXX = g++
CXXFLAGS = -std=c++17 -Wall -I./include

SRC_DIR = src
INC_DIR = include
OBJ_DIR = obj
FILES_DIR = Files

SOURCES = $(SRC_DIR)/main.cpp $(SRC_DIR)/DataProcessor.cpp
OBJECTS = $(patsubst $(SRC_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(SOURCES))

TARGET = DataProcessor

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) $^ -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp | $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

clean:
	rm -rf $(OBJ_DIR)
	rm -f $(FILES_DIR)/*Processed.txt
	rm -f $(TARGET)

prepare:
	@mkdir -p $(FILES_DIR)
	@echo "name,age\nAlice,30\nBob,25" > $(FILES_DIR)/CSVFile.txt
	@echo "{\"people\": [{\"name\": \"Alice\"}, {\"name\": \"Bob\"}]}" > $(FILES_DIR)/JSONFile.txt
