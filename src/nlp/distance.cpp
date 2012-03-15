#include "distance.h"
//#include <iostream>
unsigned int edit_distance(string str1, string str2) {

	unsigned int result;
	size_t str1_l = str1.length();
	size_t str2_l = str2.length();
//	cout << "edit distance \"" << str1  << "\" and \""<< str2 << "\"\n";
	unsigned int matrix[str1_l][str2_l];
	size_t i, j;
	unsigned int s1, s2, s3;

	// Coast matrix population
	for (i = 0; i < str1.length(); i++) {
		for (j = 0; j < str2.length(); j++) {

			if (i == 0 && j == 0) {
				s1 = 1;
				s2 = 1;
				s3 = 0;
			} else if (i == 0) {
				s1 = matrix[0][j - 1];
				s2 = j + 1;
				s3 = j;
			} else if (j == 0) {
				s1 = i + 1;
				s2 = matrix[i-1][j];
				s3 = i;
			} else {
				s1 = matrix[i][j - 1];
				s2 = matrix[i - 1][j];
				s3 = matrix[i-1][j-1];
			}
//			cout << "s1=" << s1 << " s3=" << s3 << " s2=" << s2 << " || i=" << i
//					<< " j=" << j << "\n";
			s1++;
			s2++;
			if (str1[i] != str2[j]) {
				s3 += 2;
			}

			matrix[i][j] = min(min(s1, s2), s3);
//			cout << "matrix["<<i<<"]["<<j<<"] = " << matrix[i][j] << "\n";
		}
	}

	result = matrix[str1_l - 1][str2_l - 1];

//	cout << "!!! matrix !!!\n";
//	for (int x = str1_l-1; x >= 0; --x) {
//		for (unsigned int y = 0; y < str2_l; y++) {
//			cout << matrix[x][y] << " ";
//		}
//		cout << "\n";
//	}
//	cout << result << "\n";
	return result;
}

