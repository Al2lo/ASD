//#include "iostream"
//#include "stack"
//#include "queue"
//
//
//using namespace std;
//
//void obxod(int* spisokSme[]);
//
//void main()
//{
//	setlocale(LC_ALL,"Rus");
//	//список смежности
//	int mass1[] = { 2,5 };
//	int mass2[] = {1,7,8};
//	int mass3[] = { 8 };
//	int mass4[] = { 6,9 };
//	int mass5[] = { 1,6 };
//	int mass6[] = { 4,5,9 };
//	int mass7[] = { 2,8 };
//	int mass8[] = { 2,3,7 };
//	int mass9[] = { 4,6,10 };
//	int mass10[] = { 10};
//	int *spisokSme[] = {mass1, mass2,mass3,mass4,mass5,mass6,mass7,mass8,mass9,mass10};
//
//	cout << size(*spisokSme[1]);
//	cout << "Порядок обхода: ";
//	obxod(spisokSme);
//}
//
//void obxod(int* spisokSme[])
//{
//	queue <int> queues;
//	int arr[10];
//	int i = 0;
//	int f = 0;
//	int z = 1;
//	do
//	{
//		cout << z << '\t';
//		arr[f] = z;
//		f++;
//		for (int j = 0; j < ; j++)
//		{
//			for (int k = 0; k <= f; k++)
//			{
//				if (arr[k] != spisokSme[i][j])
//				{
//					queues.push(spisokSme[i][j]);
//				}
//
//			}
//		}
//		i = queues.front();
//		queues.pop();
//		z = i ;
//		i = i - 1;
//	} while (f!=10);
//
//}
//
#include <iostream>
#include <queue>
#include <stack>

using namespace std;

void BFS(queue<int> Queue, int arr[], int connectionsArray[][10]);
void DFS(stack<int> Stack, int arr[], int connectionsArray[][10]);

int main()
{
	setlocale(LC_ALL, "rus");

	int matrix[10][10] =
	{
		{0, 1, 0, 0, 1, 0, 0, 0, 0, 0},
		{1, 0, 0, 0, 0, 0, 1, 1, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 1, 0, 0},
		{0, 0, 0, 0, 0, 1, 0, 0, 1, 0},
		{1, 0, 0, 0, 0, 1, 0, 0, 0, 0},
		{0, 0, 0, 1, 0, 0, 0, 0, 1, 0},
		{0, 1, 0, 0, 0, 0, 0, 1, 0, 0},
		{0, 1, 1, 0, 0, 0, 1, 0, 0, 0},
		{0, 0, 0, 1, 0, 1, 0, 0, 0, 1},
		{0, 0, 0, 0, 0, 0, 0, 0, 1, 0}
	};
	int arrpPoverka[10] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };

	int mass1[] = { 2,5 };
	int mass2[] = {1,7,8};
	int mass3[] = { 8 };
	int mass4[] = { 6,9 };
	int mass5[] = { 1,6 };
	int mass6[] = { 4,5,9 };
	int mass7[] = { 2,8 };
	int mass8[] = { 2,3,7 };
	int mass9[] = { 4,6,10 };
	int mass10[] = { 10};
	int* spisokSmethnodti[] = { mass1, mass2,mass3,mass4,mass5,mass6,mass7,mass8,mass9,mass10 };

	int connectionsRibs[][2] = {
		{1,2},{2,1},
		{1,5},{5,1},
		{2,7},{7,2},
		{2,8},{8,2},
		{7,8},{8,7},
		{8,3},{3,8},
		{5,6},{6,5},
		{6,4},{4,6},
		{6,9},{9,6},
		{4,9},{9,4},
		{9,10},{10,9}
	};

	queue<int> Queue;
	stack<int> Stack;


	BFS(Queue, arrpPoverka, matrix);

	for (int i = 0; i < 10; i++) {
		arrpPoverka[i] = 0;
	}
	cout << endl;
	DFS(Stack, arrpPoverka, matrix);

	cout << "Сложность алгоритма матрицы смежности: O(100)";
	cout << "Сложность алгоритма списка смежности и списка ребер: O(19)";
}

void BFS(queue<int> Queue, int arrpPoverka[], int matrix[][10]) 
{
	Queue.push(0);

	while (!Queue.empty())
	{
		int numb = Queue.front();
		Queue.pop();

		arrpPoverka[numb] = 1;

		for (int i = 0; i < 10; i++) {
			if (matrix[numb][i] == 1 && arrpPoverka[i] == 0) {
				Queue.push(i);
				arrpPoverka[i] = i;
			}
		}
		cout << numb + 1;
	}
}

void DFS(stack<int> Stack, int arrpPoverka[], int matrix[][10]) 
{
	Stack.push(0);

	while (!Stack.empty())
	{
		int numb = Stack.top();
		Stack.pop();

		arrpPoverka[numb] = 1;

		for (int i = 9; i >0; i--) {
			if (matrix[numb][i] == 1 && arrpPoverka[i] == 0) {
				Stack.push(i);
				arrpPoverka[i] = i;
			}
		}
		cout << numb + 1;
	}
}
