TEST_DIR = ./test
SRC_DIR = ./src
BIN_DIR = ./bin
CXXFLAGS = -O3

all: build_all build_tests clean

build_all: build_sorting build_other build_nlp

build_sorting: $(SRC_DIR)/sorting/sorting.cpp $(SRC_DIR)/sorting/heap.cpp
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $^
	
build_other: $(SRC_DIR)/other/MouseHunter.cpp $(SRC_DIR)/other/determinant.cpp $(SRC_DIR)/other/HanoiTower.cpp $(SRC_DIR)/other/inversion.cpp
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $^
	
build_nlp: $(SRC_DIR)/nlp/distance.cpp
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $^
	
build_tests: build_all test_helper sorting_tests mouse_hunter_test tower_of_hanoi_test nlp_test inversion_test

test_helper: $(TEST_DIR)/test_helper.cpp $(TEST_DIR)/benchmark.cpp
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $^

sorting_tests: $(TEST_DIR)/sorting/sorting_test.cpp sorting.o heap.o test_helper.o benchmark.o
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -lgtest -lgtest_main $^ -o $(BIN_DIR)/$@
	
mouse_hunter_test: $(TEST_DIR)/other/mouse_hunter_test.cpp MouseHunter.o test_helper.o
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -lgtest -lgtest_main $^ -o $(BIN_DIR)/$@
	
nlp_test: $(TEST_DIR)/nlp/distance_test.cpp distance.o test_helper.o
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -lgtest -lgtest_main $^ -o $(BIN_DIR)/$@

tower_of_hanoi_test: $(TEST_DIR)/other/tower_of_hanoi_test.cpp HanoiTower.o test_helper.o
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -lgtest -lgtest_main $^ -o $(BIN_DIR)/$@

inversion_test: $(TEST_DIR)/other/inversion_test.cpp inversion.o test_helper.o
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -lgtest -lgtest_main $^ -o $(BIN_DIR)/$@

clean:
	rm -fr *.o