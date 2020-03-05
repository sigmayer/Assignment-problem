#include <stdio.h>
#include <conio.h>
#include <cmath>
#include <string>
#include <chrono>
#include <iostream>
#include <fstream>

using namespace std;

class Hiring {

	public:

		Hiring();
		void greedy(int **mat, int size);
		void polniy_perebor(int **mat, int size);
		int perebor(int size, int **mat, int **res, int *buff, int i, int sum, int **per_res, int min);
		void load(const string& filename, int **matrix, int size);
		void save(const string& filename, int **matrix, int size);
		int check_size(const string& filename);

};