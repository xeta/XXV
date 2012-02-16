#include <vector>
#include <iostream>

using namespace std;

typedef int Element;
typedef vector<Element> Row;
typedef vector<Row> Matrix;

void printMatrix(Matrix m, int size) {
	int i, j;
	for (i = 0; i < size; i++) {
		for (j = 0; j < size; j++) {
			cout << m[i][j] << " ";
		}
		cout << endl;
	}
}

Element determinant(Matrix matrix, int m_size);

Matrix down_matrix(Matrix matrix, int size, int row, int column);

Matrix createMatrix(int size);

Element determinant(Matrix matrix, int m_size) {
	if (m_size == 1)
		return matrix[0][0];

	Element value = 0;
	int j;
	int new_size = m_size - 1;
	for (j = 0; j < m_size; j++) {
		Matrix new_matrix = down_matrix(matrix, m_size, 0, j);
		Element x = determinant(new_matrix, new_size);
		if((j+1)%2==0)
			value -= matrix[0][j] * x;
		else
			value += matrix[0][j] * x;
	}
	return value;
}

Matrix down_matrix(Matrix matrix, int size, int row, int column) {
	Matrix new_matrix = createMatrix(size - 1);
	int i, j;
	int x = 0;
	for (i = 0; i < size; i++) {
		if (i == row)
			continue;
		int y = 0;
		for (j = 0; j < size; j++) {
			if (j == column)
				continue;

			new_matrix[x][y] = matrix[i][j];
			y++;
		}
		x++;
	}
	return new_matrix;
}

Matrix createMatrix(int size) {
	Matrix matrix(size);
	int i, j = 0;
	for (i = 0; i < size; i++) {
		matrix[i] = Row(size);
		for (j = 0; j < size; j++) {
			matrix[i][j] = 0;
		}
	}
	return matrix;
}

int main(int argc, char **argv) {
	const int size = 3;
	Matrix m = createMatrix(size);

	m[0][0] = 3;
	m[0][1] = 1;
	m[0][2] = 8;
	m[1][0] = 2;
	m[1][1] = -5;
	m[1][2] = 4;
	m[2][0] = -1;
	m[2][1] = 6;
	m[2][2] = -2;
	printMatrix(m,size);
	cout << "Determinant = " << determinant(m, size) << endl;
	return 0;
}

