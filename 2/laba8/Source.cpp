#include <iostream>
using namespace std;

void main()
{
	setlocale(LC_ALL, "Rus");
	int weight = 8;
	int count = 3;
	int weights[3] = {3,6,4 };
	int price[3] = { 14,20,7 };
	string names[3] = { "Каштан","Малина","Сникерс" };
	//cout << "Введите вес рюкзака:";
	//cin >> weight;
	//cout << "Введите кол-во элементов:";
	//cin >> count;
	//int *price = new int[count];
	//int *weights = new int[count];
	//string* names = new string[count];
	//for (int i = 0; i < count; i++)
	//{
	//	cout << "Введите вес элемента: ";
	//	cin >> weights[i];
	//	cout << "Введите стоимость элемента: ";
	//	cin >> price[i];
	//	cout << "Введите имя элемента: ";
	//	cin >> names[i];
	//	
	//}

	int** arrWCoasts = new int* [count+1];
	for (int i = 0; i < count+1; i++)
	{
		arrWCoasts[i] = new int[weight+1];
	}

	for (int i = 0; i < count+1; i++)
	{
		for (int j = 0; j < weight+1; j++)
		{
			arrWCoasts[i][j] = 0;
		}
	}

	for (int i = 1; i < count+1; i++)
	{
		for (int j = 0; j <= weight; j++)
		{
			if (weights[i-1]>j)
			{
				arrWCoasts[i][j] = arrWCoasts[i - 1][j];
			}
			else
			{
				arrWCoasts[i][j] = max(arrWCoasts[i-1][j],arrWCoasts[i-1][j-weights[i-1]] + price[i-1]);
			}
		}
	}
	cout << endl;
	for (int i = 0; i < count + 1; i++)
	{
		for (int j = 0; j < weight + 1; j++)
		{
			cout << arrWCoasts[i][j] << '\t';
		}
		cout << endl;
	}

	int arrV[] = {0,0,0,0};

	int i = count;
	int j = weight;
	cout << "Стоимость рюкзака: " << arrWCoasts[i][j]<<endl;
	while (i>=1)
	{
		if (arrWCoasts[i][j] == arrWCoasts[i-1][j])
		{
			i--;
		}
		else
		{
			arrV[i-1] = 1;
			j -= weights[i-1];
			i--;
		}
	}
	cout << "Рюкзак: ";
	for (int i = 0; i < 4; i++)
	{
		if (arrV[i] == true)
		{
			cout << names[i]<<'\t';
		}
	}
}

