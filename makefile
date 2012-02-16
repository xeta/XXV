TEST_DIR = ./src/test
SRC_DIR = ./src
BIN_DIR = ./bin

all: test clean

test: heap.o sorting.o sorting_test.o heap_test.o benchmark.o test_helper.o
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -lgtest -lgtest_main $^ -o $(BIN_DIR)/$@
	
benchmark.o: $(SRC_DIR)/benchmark.cpp $(SRC_DIR)/benchmark.h
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $(SRC_DIR)/benchmark.cpp

sorting.o: $(SRC_DIR)/sorting.cpp $(SRC_DIR)/sorting.h
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $(SRC_DIR)/sorting.cpp

heap.o: $(SRC_DIR)/heap.cpp $(SRC_DIR)/heap.h
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $(SRC_DIR)/heap.cpp
	
sorting_test.o: $(TEST_DIR)/sorting_test.cpp $(SRC_DIR)/sorting.h
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $(TEST_DIR)/sorting_test.cpp

heap_test.o: $(TEST_DIR)/heap_test.cpp $(SRC_DIR)/heap.h
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $(TEST_DIR)/heap_test.cpp

test_helper.o: $(TEST_DIR)/test_helper.cpp $(TEST_DIR)/test_helper.h
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $(TEST_DIR)/test_helper.cpp
	
xxx: 
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) $(SRC_DIR)/determinant.cpp -o $(BIN_DIR)/det
	
clean:
	rm -fr *.o