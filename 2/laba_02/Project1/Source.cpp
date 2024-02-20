#include "iostream"
#include "queue"
using namespace std;

void main()
{
	int matrix[10][10] = { 
		{0,1,0,0,1,0,0,0,0,0},
		{1,0,0,0,0,0,1,1,0,0},
		{0,0,0,0,0,0,0,1,0,0},
		{0,0,0,0,0,1,0,0,1,0},
		{1,0,0,0,0,1,0,0,0,0},//5
		{1,0,0,1,1,1,0,0,1,0},
		{0,1,0,0,0,0,0,1,0,0},
		{0,1,1,0,0,0,1,0,0,0},
		{0,0,0,1,0,1,0,0,0,1},
		{0,0,0,0,0,0,0,0,1,0}
	};

	queue <int> Queue;
	int arr[10];
	int start = 0;
	int f = 0;

	Queue.push(start);

	while (!Queue.empty())
	{
		int number = Queue.front();
		Queue.pop();
		arr[f] = number;

		for (int j = 0; j < 10; j++)
		{
			if (matrix[number][j] == 1)
			{
				for (int k = 0; k <= f; k++)
				{
					if (j+1 != arr[k])
					{
						Queue.push(j);
					}
				}
			}
		}
		f++;
		cout << number+1;
	}

}