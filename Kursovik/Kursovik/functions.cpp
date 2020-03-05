#include "functions.h"

void Hiring::greedy(int **mat, int size) {

	int sum1 = 0;

	int **res = new int*[size];
	for (int i = 0; i < size; i++) {
		res[i] = new int[size];
	}

	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			res[i][j] = 0;
		}
	}

	int *buff = new int[size];

	for (int i = 0; i < size; i++) {
		buff[i] = 0;
	}

	for (int i = 0; i < size; i++) {

		int l = 0;

		while (buff[l] != 0) {
			l++;
		}

		size_t min = mat[i][l];
		int minI = i;
		int minJ = l;

		for (int j = 0; j < size; j++) {
			if (mat[i][j] < min && buff[j] == 0) {
				min = mat[i][j];
				minI = i;
				minJ = j;
			}
		}
		res[minI][minJ] = 1;
		sum1 += mat[minI][minJ];
		buff[minJ] = 1;
	}

	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			cout << res[i][j] << " ";
		}
		cout << endl;
	}

	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			mat[i][j] = res[i][j];
		}
	}

	cout << endl;
	cout << "Sum: " << sum1 << endl;
	cout << "----------------------------" << endl;



	for (int i = 0; i < size; i++) {
		delete[] res[i];
	}

	delete[] buff;
}

void Hiring::polniy_perebor(int **mat, int size) {

	int **res = new int*[size];
	for (int i = 0; i < size; i++) {
		res[i] = new int[size];
	}

	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			res[i][j] = 0;
		}
	}

	int *buff = new int[size];

	for (int i = 0; i < size; i++) {
		buff[i] = 0;
	}

	int **per_res = new int*[size];
	for (int i = 0; i < size; i++) {
		per_res[i] = new int[size];
	}

	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			per_res[i][j] = 0;
		}
	}

	int min = 0;

	min = perebor(size, mat, res, buff, 0, 0, per_res, min);

	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			cout << per_res[i][j] << " ";
		}
		cout << endl;
	}

	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			mat[i][j] = per_res[i][j];
		}
	}

	cout << endl;
	cout << "Sum: " << min << endl;
	cout << "----------------------------" << endl;

	for (int i = 0; i < size; i++) {
		delete[] res[i];
	}

	for (int i = 0; i < size; i++) {
		delete[] per_res[i];
	}

	delete[] buff;
}

int Hiring::perebor(int size, int **mat, int **res, int *buff, int i, int sum, int **per_res, int min) {

	if (i == size) {
		if (min == 0) {
			min = sum;

			for (int i = 0; i < size; i++) {
				for (int j = 0; j < size; j++) {
					per_res[i][j] = res[i][j];
				}
			}
		}
		else {
			if (sum < min) {
				min = sum;

				for (int i = 0; i < size; i++) {
					for (int j = 0; j < size; j++) {
						per_res[i][j] = res[i][j];
					}
				}
			}
		}
	}

	else {
		for (int j = 0; j < size; j++) {
			if (buff[j] == 0) {
				res[i][j] = 1;
				buff[j] = 1;
				sum += mat[i][j];
				min = perebor(size, mat, res, buff, i + 1, sum, per_res, min);
				buff[j] = 0;
				res[i][j] = 0;
				sum -= mat[i][j];
			}
		}
	}

	return min;

}

void Hiring::load(const string& filename, int **matrix, int size) {

	ifstream fin;

	fin.open(filename);

	while (!fin.eof()) {
		for (int i = 0; i < size; i++) {
			for (int j = 0; j < size; j++) {
				fin >> matrix[i][j];
			}
		}
	}

	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++)
			cout << matrix[i][j] << " ";
		cout << endl;
	}
	cout << "----------------------------" << endl;

	fin.close();
}

void Hiring::save(const string& filename, int **matrix, int size) {

	ofstream fout;
	fout.open(filename);

	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			fout << matrix[i][j] << " ";
		}
		fout << endl;
	}

	cout << "Результат сохранен в файле " << filename << endl;
	cout << "----------------------------" << endl;

	fout.close();
}

int Hiring::check_size(const string& filename) {
	int count = 0;
	ifstream fin;

	fin.open(filename);
	if (!fin) {
		throw runtime_error("Файл не найден.\n");
	}

	while (!fin.eof()) {
		int c;
		fin >> c;
		
		if (c < 0) {
			throw runtime_error("Некорректные исходные данные: элементы матрицы должны быть неотрицательными.\n");
		}

		count++;
	}

	if (count < 4) {
		throw runtime_error("Некорректные исходные данные: недостаточно исходных данных.\n");
	}

	int size = sqrt(count);

	if (pow(size, 2) != count) {
		throw runtime_error("Некорректные исходные данные: матрица с исходным данными должна быть квадратной.\n");
	}

	fin.close();
	return size;
}

Hiring::Hiring() {
}