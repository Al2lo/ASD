#include "iostream"
using namespace std;


int getVersh(char symbol)
{
	int beginn = 0;
	switch (symbol)
	{
	case 'A':
	{
		beginn = 0;
		break;
	}
	case 'B':
	{
		beginn = 1;
		break;
	}
	case 'C':
	{
		beginn = 2;
		break;
	}
	case 'D':
	{
		beginn = 3;
		break;
	}
	case 'E':
	{
		beginn = 4;
		break;
	}
	case 'F':
	{
		beginn = 5;
		break;
	}
	case 'G':
	{
		beginn = 6;
		break;
	}
	case 'H':
	{
		beginn = 7;
		break;
	}
	case 'I':
	{
		beginn = 8;
		break;
	}
	default:
		beginn = 1000;
		break;
	}
	return beginn;
}

void main() // a,b,c,d,e,f,g,h,i
{
	setlocale(LC_ALL, "RUS");

	int matrix[9][9] =
	{//  a  b  c   d  e  f  g  h   i
		{0, 7, 10, 0, 0, 0, 0, 0, 0},//a
		{7, 0, 0,  0, 0, 9, 27, 0, 0},//b
		{10, 0, 0, 0, 31, 8, 0, 0, 0},//c
		{0, 0, 0, 0, 32, 0, 0, 17, 21},//d
		{0, 0, 31, 32, 0, 0, 0, 0, 0},//e
		{0, 9, 8, 0, 0, 0, 0, 11, 0},//f
		{0, 27, 0, 0, 0, 0, 0, 0, 15},//g
		{0, 0, 0, 17, 0, 11, 0, 0, 15},//h
		{0, 0, 0, 21, 0, 0, 15, 15,0}//i
	};
	char vershin[] = {'A','B','C','D','E','F','G','H','I'};

	int visibleVersh[9];
	int minRast[9];
	int min;
	int begin = 0;
	int minIndex;
	int length = 0;
	char symbol;
	do
	{
		cout << "Введите начальную вершину('A','B','C','D','E','F','G','H','I'): ";
		cin >> symbol;
		begin = getVersh(symbol);
		if (begin>10)
		{
			cout << "Некорректные данные" << endl;
		}
	} while (begin > 10);


	for (int i = 0; i < 9; i++)
	{
		minRast[i] = 10000;
		visibleVersh[i] = 1;

	}

	minRast[begin] = 0;

	do
	{
		min = 10000;
		minIndex = 10000;


		for (int i = 0; i < 9; i++)
		{
			if (visibleVersh[i] == 1 && minRast[i]< min)
			{
				min = minRast[i];
				minIndex = i;
			}
		}


		if (minIndex != 10000)
		{
			for (int i = 0; i < 9; i++)
			{
				if (matrix[minIndex][i] > 0)
				{
					length = min + matrix[minIndex][i];

					if (length < minRast[i])
					{
						minRast[i] = length;

					}
				}
			}
			visibleVersh[minIndex] = 0;
		}
	} while (minIndex < 10000);
	for (int i = 0; i < 9; i++)
		cout << "Расстояние " << vershin[begin] << " -> " << vershin[i] << " : " << minRast[i] << endl;

}