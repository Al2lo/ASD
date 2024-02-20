#include <iostream>

#define INFINITY INT_MAX
using namespace std;

void main()
{
	setlocale(LC_ALL, "Rus");

	int matrixOfWeight[6][6]
	{
		{0,28,21,59,12,27},
		{7, 0, 24, INFINITY, 21, 9},
		{9, 32, 0, 13, 11, INFINITY },
		{8, INFINITY, 5, 0, 16, INFINITY},
		{14, 13, 15, 10, 0, 22 },
		{15, 18, INFINITY, INFINITY, 6, 0}
	};

	int matrixOfVerhin[6][6]
	{
		{0,2,3,4,5,6},
		{1,0,3,4,5,6},
		{1,2,0,4,5,6},
		{1,2,3,0,5,6},
		{1,2,3,4,0,6},
		{1,2,3,4,5,0}
	};


	for (int m = 0; m < 6; m++)
	{
		for (int i = 0; i < 6; i++)
		{
			for (int j = 0; j < 6; j++)
			{
				if (matrixOfWeight[i][j] > matrixOfWeight[i][m] + matrixOfWeight[m][j])
				{
					matrixOfWeight[i][j] = matrixOfWeight[i][m] + matrixOfWeight[m][j];
					matrixOfVerhin[i][j] = m + 1;
				}
			}
		}
	}

	cout << "Матрица кратчайших путей" << endl;
	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 6; j++)
		{
			cout << matrixOfWeight[i][j] << '\t';
		}
		cout << endl;
	}

	cout << "Матрица связей" << endl;
	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 6; j++)
		{
			cout << matrixOfVerhin[i][j] << '\t';
		}
		cout << endl;
	}
}