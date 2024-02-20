#include <iostream>
using namespace std;
void main()
{
	setlocale(LC_ALL, "Rus");
	int n,n1,v[10], choice, count =0,z=0;
	unsigned int x = 0;
	cin >> n;
	x = n;
	do
	{
		n1 = n;
		n /= 2;
		z =(n1-n);
		count++;
		cout << "1.<" << endl;
		cout << "2.>" << endl;
		cout << "true" << endl;
		cout << x<< endl;
		cin >> choice;	
		if (choice ==1)
		{
			x = x-z;

		}
		else
		{
			x = x + z;
		}
		for (int i = count-1; ; i++) 
		{
			v[i] = x;
			break;
		}
		cout << endl;
	} while (choice!=3);
	cout << "Шаги бинарного поиска: ";
	for (int i = 0; i < count-1; i++)
	{
		cout << v[i] << '\t';
	}
	cout << endl;
	cout <<"Кол-во шагов: " << count - 1;
}