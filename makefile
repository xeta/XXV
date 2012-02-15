TEST_DIR = ./test
SRC_DIR = ./src
BIN_DIR = ./bin

all: sorting_test clean

sorting_test: sorting.o sorting_test.o all_test.o
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -lpthread /usr/lib/libgtest.so $^ -o $(BIN_DIR)/$@
	
sorting.o: $(SRC_DIR)/sorting.cpp $(SRC_DIR)/sorting.h  
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $(SRC_DIR)/sorting.cpp
	
sorting_test.o: $(TEST_DIR)/sorting_test.cpp $(SRC_DIR)/sorting.h
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $(TEST_DIR)/sorting_test.cpp

all_test.o:
	$(CXX) $(CPPFLAGS) -c $(CXXFLAGS) $(TEST_DIR)/all_test.cpp
	
clean:
	rm -fr *.o