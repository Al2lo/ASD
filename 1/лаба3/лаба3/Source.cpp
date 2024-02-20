#include <iostream>
void quickSort(int* numbers, int left, int right);
using namespace std;


void main()
{
	setlocale(LC_ALL, "Rus");
	srand(time(NULL));
	int n,c;
	unsigned int time1;
	cout << "Введите кол-во элементов массива: "; cin >> n;

	int* A = new int[n];
	int* B = new int[n];
	int* C = new int[n];
	int* D = new int[n];
	int* E = new int[n];


	for (int i = 0; i < n; i++)
	{
		A[i] = rand() % 20;
	}


	for (int i = 0; i < n; i++)
	{
		cout << A[i] << '\t';
	}
	cout << endl<<endl;


	for (int i = 0; i < n; i++)
	{
		B[i] = A[i];
		C[i] = A[i];
		D[i] = A[i];
		E[i] = A[i];
	}
	cout << "пузырьковая сортировка." << endl;
	unsigned int start_timeB = clock();
	for (int j = 0; j < n-1; j++)
	{
		for (int i = 0; i < n - 1; i++)
		{
			if (B[i] > B[i + 1])
			{
				c = B[i];
				B[i] = B[i + 1];
				B[i + 1] = c;

			}
		}
	}
	unsigned int end_timeB = clock();
	time1 = end_timeB - start_timeB;
	for (int i = 0; i < n; i++)
	{
		cout << B[i] << '\t';
	}
	cout << endl << time1 << endl<<endl;
	cout << "метод Вставки." << endl;
	int i, j, step;
	unsigned int start_timeC = clock();
	for (step = n / 2; step > 0; step /= 2)
		for (i = step; i < n; i++)
		{
			c = C[i];
			for (j = i; j >= step; j -= step)
			{
				if (c < C[j - step])
					C[j] = C[j - step];
				else
					break;
			}
			C[j] = c;
		}
	unsigned int end_timeC = clock();
	unsigned int timeC = end_timeC - start_timeC;
	for (int i = 0; i < n; i++)
	{
		cout << C[i] << '\t';
	}
	cout << endl << timeC << endl<<endl;

	cout << "сортировка выбора." << endl;
	int key;
	unsigned int start_timeD = clock();
	for (i = 0; i < n - 1; i++)
	{
		c = D[i]; key = i;
		for (j = i + 1; j < n; j++)
		{
			if (D[j] < D[key])
			{
				key = j;
			}
		}
		if (key != i)
		{
			D[i] = D[key];
			D[key] = c;
		}
	}
	unsigned int end_timeD = clock();
	unsigned int timeD = end_timeD - start_timeD;
	for (int  i = 0; i < n; i++)
	{
		cout << D[i] << '\t';
	}
	cout << endl<<timeD << endl<<endl;


	cout << "Быстрая сортировка." << endl;
	unsigned int start_timeE = clock();
	quickSort(E,0,n-1);
	unsigned int end_timeE = clock();
	unsigned int timeE = end_timeE - start_timeE;
	for (int i = 0; i < n; i++)
	{
		cout << E[i] << '\t';
	}
	cout<<endl << timeE << endl;

	delete []A;
	delete []B;
	delete []C;
	delete []D;
	delete []E;
}


void quickSort(int* numbers, int left, int right)
{
	int pivot; 
	int l_hold = left; 
	int r_hold = right; 
	pivot = numbers[left];
	while (left < right)
	{
		while ((numbers[right] >= pivot) && (left < right))
			right--; 
		if (left != right) 
		{
			numbers[left] = numbers[right];
			left++; 
		}
		while ((numbers[left] <= pivot) && (left < right))
			left++;
		if (left != right) 
		{
			numbers[right] = numbers[left];
			right--; 
		}
	}
	numbers[left] = pivot;
	pivot = left;
	left = l_hold;
	right = r_hold;
	if (left < pivot) 
		quickSort(numbers, left, pivot - 1);
	if (right > pivot)
		quickSort(numbers, pivot + 1, right);
}