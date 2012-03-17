#include "../test_helper.h"
#include "../../src/other/inversion.h"

TEST(InversionTest, NoInversions) {
	unsigned int test_data[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	ASSERT_EQ(0, count_inversions(test_data,10));
}

TEST(InversionTest, MaxInversions) {
	unsigned int test_data[] = { 9, 8, 7, 6, 5, 4, 3, 2, 1, 0 };
	ASSERT_EQ(45, count_inversions(test_data,10));
}

TEST(InversionTest, RideInversion) {
	unsigned int test_data[] = { 0, 1, 3, 2 };
	ASSERT_EQ(1, count_inversions(test_data,4));
}

TEST(InversionTest, SwitchInversion) {
	unsigned int test_data[] = { 0, 2, 1, 3 };
	ASSERT_EQ(1, count_inversions(test_data,4));
}

#include <fstream>
TEST(Inversion, LoadFromFile) {
	ifstream file("/home/xeta/projects/Algoritms/test/data/IntegerArray.txt");
	string line;
	unsigned int array[100000];
	int i = 0;
	while (file >> line) {
		istringstream int_iss(line);
		unsigned int x;
		int_iss >> x;
		array[i++] = x;
	}
	unsigned int inversions_count = count_inversions(array, 100000);
	cout << "[Inversions] " << inversions_count << endl;
	ASSERT_EQ(2407905288, inversions_count);

}
