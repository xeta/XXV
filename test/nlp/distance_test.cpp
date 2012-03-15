#include "../test_helper.h"
#include "../../src/nlp/distance.h"

TEST(Distance,Test){
	string a_str = "aa";
	string b_str = "ab";
	unsigned  int result = edit_distance(a_str, b_str);
	cout << result << "\n";
	ASSERT_EQ(2, result);
}


TEST(Distance,Test2){
	string a_str = "aca";
	string b_str = "aba";
	int result = edit_distance(a_str, b_str);
	cout << result << "\n";
	ASSERT_EQ(2, result);
}


TEST(Distance,Test3){
	string a_str = "aa";
	string b_str = "aab";
	unsigned  int result = edit_distance(a_str, b_str);
	cout << result << "\n";
	ASSERT_EQ(1, result);
}

TEST(Distance,Test4){
	string a_str = "exclude";
	string b_str = "include";
	unsigned  int result = edit_distance(a_str, b_str);
	cout << result << "\n";
	ASSERT_EQ(4, result);
}


TEST(Distance,Test5){
	string a_str = "intention";
	string b_str = "execution";
	unsigned  int result = edit_distance(a_str, b_str);
	cout << result << "\n";
	ASSERT_EQ(8, result);
}
