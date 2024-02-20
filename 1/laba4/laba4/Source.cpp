#include <iostream>


using namespace std;


void main()
{
	setlocale(LC_ALL,"Rus");
	srand(time(NULL));
	int kol, sum =0;
	cout << "Введите кол-во покупок: ", cin >> kol;
	int* price = new int[kol];
	cout << "Начальные цены: ";
	for (int i = 0; i < kol; i++)
	{
		price[i] = rand() % 100 +1;
	}
	for (int i = 0; i < kol; i++)
	{
		cout << price[i] << '\t';
	}
	cout << endl;
	for (int i = 0; i < kol-1; i++)
	{
		if (i % 2 != 0)
		{
			int c = price[i]; int key = i;
			for (int j = i + 1; j < kol; j++)
			{
				if (price[key] > price[j])
				{
					key = j;
				}
			}
			if (key != i)
			{
				price[i] = price[key];
				price[key] = c;
			}

			
		}
		else
		{
			int c = price[i]; int key = i;
			for (int j = i + 1; j < kol; j++)
			{
				if (price[j] > price[key])
				{
					key = j;
				}
			}
			if (key != i)
			{
				price[i] = price[key];
				price[key] = c;
			}
		}
	}
	for (int i = 0; i < kol; i++)
	{
		if (i%2==0)
		{
			sum += price[i];
		}
	}
	cout << "Цены пробития в чеке:\t";
	for (int i = 0; i < kol; i++)
	{
		cout << price[i] << '\t';
	}
	cout << endl <<"Цена в чеке: " << sum << endl;


	delete [] price;
}