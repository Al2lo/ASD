#include "iostream"

using namespace std;


void main()
{
	setlocale(LC_ALL, "Rus");
	srand(time(NULL));

	int kol = 8;
	int* arrZnachenie = new int[kol];
	int* arrCount = new int[kol];
	int* arrPerehod = new int[kol];

	
	for (int i = 0; i < kol; i++)
	{
		arrZnachenie[i] = rand()%20;
		arrCount[i] = 1;
		arrPerehod[i] = -1;
	}


	for (int i = 1; i < kol; i++)
	{
		for (int j = i-1; j > 0; j--)
		{
			if (arrZnachenie[i]>arrZnachenie[j])
			{
				if (arrCount[i]<=arrCount[j])
				{
					arrCount[i] = arrCount[j] + 1;
					arrPerehod[i] = j;
					
				}
			}
		}
	}

	int max = -1;
	int prev = 0;
	for (int i = 0; i < kol; i++)
	{
		if (max<arrCount[i])
		{
			max = arrCount[i];
			prev = i;
		}
	}


	int* arrVyvod = new int[max];

	for (int i = 0; prev != -1; i++)
	{
		arrVyvod[i] = arrZnachenie[prev];
		prev = arrPerehod[prev];
	}

	//--------------------Вывод------------------
	cout << "Последовательность:" << endl;
	for (int i = 0; i < kol; i++)
	{
		cout << arrZnachenie[i] << '\t';
	}

	cout << endl<<"количество элементов в подпоследовательности: "<<endl;

	for (int i = 0; i < kol; i++)
	{
		cout << arrCount[i] << '\t';
	}

	cout << endl<<"Переходы: "<<endl;

	for (int i = 0; i < kol; i++)
	{
		cout << arrPerehod[i] << '\t';
	}
	cout << endl;
	cout << "max: " << max << endl;

	cout << "Возрачтающая последовательеость: ";
	for (int i = max -1; i >= 0; i--)
	{
		cout << arrVyvod[i]<<'\t';
	}

	delete[]arrVyvod;
	delete[]arrZnachenie;
	delete[]arrCount;
	delete[]arrPerehod;

}