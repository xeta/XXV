TEST_DIR = ./test
SRC_DIR = ./src
BIN_DIR = ./bin

all: build_all build_tests clean

build_all: build_sorting build_other

build_sorting: $(SRC_DIR)/sorting/sorting.cpp $(SRC_DIR)/sorting/heap.cpp
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $^
	
build_other: $(SRC_DIR)/other/MouseHunter.cpp $(SRC_DIR)/other/determinant.cpp
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $^
	
build_tests: build_all test_helper sorting_tests mouse_hunter_test

test_helper: $(TEST_DIR)/test_helper.cpp $(TEST_DIR)/benchmark.cpp
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $^

sorting_tests: $(TEST_DIR)/sorting/sorting_test.cpp sorting.o heap.o test_helper.o benchmark.o
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -lgtest -lgtest_main $^ -o $(BIN_DIR)/$@
	
mouse_hunter_test: $(TEST_DIR)/other/mouse_hunter_test.cpp MouseHunter.o test_helper.o
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -lgtest -lgtest_main $^ -o $(BIN_DIR)/$@
	
clean:
	rm -fr *.o