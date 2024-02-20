#include <iostream>


using namespace std;

void main()
{
	srand(time(NULL));
	setlocale(LC_ALL, "Rus");
	int kol,c=0,count = 3;
	cout << "Введите кол-во участников олимпиады: ", cin >> kol;
	int* arr = new int[kol];


	for (int i = 0; i < kol; i++)
	{
		arr[i] = rand() % 10 +1;
	}

	for (int i = 0; i < kol; i++)
	{
		cout << arr[i] << '\t';
	}

	cout << endl;

	for (int i = 0; i < kol; i++)
	{
		for (int j = 0; j < kol-1; j++)
		{
			if (arr[j]<arr[j+1])
			{
				c = arr[j+1];
				arr[j + 1] = arr[j];
				arr[j] = c;
			}
		}
	}


	for (int i = 0; i < count; i++)
	{
		if (arr[i] == arr[i+1])
		{
			count++;
		}
	}


	if (count>kol)
	{
		count -= 1;
	}


	cout <<endl<<"Кол-во выигравших участников: " << count;

	delete[]arr;
}
