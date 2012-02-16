TEST_DIR = ./src/test
SRC_DIR = ./src
BIN_DIR = ./bin

all: sorting_test clean

sorting_test: sorting.o sorting_test.o benchmark.o
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -lgtest -lgtest_main $^ -o $(BIN_DIR)/$@

benchmark.o: $(SRC_DIR)/benchmark.cpp $(SRC_DIR)/benchmark.h
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $(SRC_DIR)/benchmark.cpp

sorting.o: $(SRC_DIR)/sorting.cpp $(SRC_DIR)/sorting.h
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $(SRC_DIR)/sorting.cpp
	
sorting_test.o: $(TEST_DIR)/sorting_test.cpp $(SRC_DIR)/sorting.h
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $(TEST_DIR)/sorting_test.cpp

xxx: 
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) $(SRC_DIR)/determinant.cpp -o $(BIN_DIR)/det
	
clean:
	rm -fr *.o