//source\repos\Kursovik\Debug\Kursovik.exe

#include "functions.h"

void main(int argc, char* argv[]) {

	setlocale(LC_ALL, "Russian");

	try {

		Hiring test;

		if (argc < 4) {
			throw runtime_error("Недостаточно данных.\n");
		}

		int size = test.check_size(argv[1]);

		int **matrix = new int*[size];

		for (int i = 0; i < size; i++) {
			matrix[i] = new int[size];
		}
		for (int i = 0; i < size; i++) {
			for (int j = 0; j < size; j++) {
				matrix[i][j] = 0;
			}
		}

		cout << "Матрица с исходным данными:" << endl;

		test.load(argv[1], matrix, size);

		string tmp = "greedy";
		string tmp1 = "perebor";

		if (argv[3] == tmp) {

			cout << "Результат работы жадного алгоритма:" << endl;

			auto start = chrono::high_resolution_clock::now();
			test.greedy(matrix, size);
			auto end = chrono::high_resolution_clock::now();

			chrono::duration<float> duration = end - start;
			cout << endl << "time: " << duration.count() << "s" << endl << endl;

			test.save(argv[2], matrix, size);
		}

		if (argv[3] == tmp1) {

			cout << "Результат полного перебора:" << endl;

			auto start = chrono::high_resolution_clock::now();
			test.polniy_perebor(matrix, size);
			auto end = chrono::high_resolution_clock::now();

			chrono::duration<float> duration = end - start;
			cout << endl << "time: " << duration.count() << "s" << endl << endl;

			test.save(argv[2], matrix, size);
		}

		for (int i = 0; i < size; i++) {
			delete[] matrix[i];
		}
	}
	catch (exception &e) {
		cerr << e.what();
		getch();
	}

	getch();
}





