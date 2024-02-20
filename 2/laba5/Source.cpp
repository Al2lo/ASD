#include <iostream>

using namespace std;

void Kraskl();
int find_set(int i);
int interconnected(int i);
void unionCompos(int i, int j);
int graph[8][8] = {
         {0,2,0,8,2,0,0,0},
         {2,0,3,10,5,0,0,0},
         {0,3,0,12,0,0,7},
         {8,10,0,0,14,3,1,0},
         {2,5,12,14,0,11,4,8},
         {0,0,0,3,11,0,6,0},
         {0,0,0,1,4,6,0,9},
         {0,0,7,0,8,0,9}
};


const int Y = 8;
int infCost = 10000;
int visited[Y];
int main() {
    setlocale(LC_ALL, "Rus");



    int arrProverka[] = { 0,0,0,0,0,0,0,0 };

    int min = INT_MAX;
    int l, t;

    for (int i = 0; i < 8; ++i)
    {
        for (int j = i; j < 8; ++j)
            if (graph[i][j] < min && graph[i][j] != 0)
            {
                min = graph[i][j];
                l = i;
                t = j;
            }
    }
    cout << "Алгоритм Прима: [" << l + 1 << ", " << t + 1 << " ];  ";
    arrProverka[l] = 1;
    arrProverka[t] = 1;
    int count = 0;


    while (count != 7)
    {
        min = INT_MAX;
        l = t = 0;
        for (int i = 0; i < 8; i++)
        {
            if (arrProverka[i] != 0)
            {
                continue;
            }
            for (int j = 0; j < 8; j++)
                if (arrProverka[j] == 1)
                {
                    if (graph[i][j] < min && graph[i][j] != 0)
                    {
                        min = graph[i][j];
                        l = i;
                        t = j;
                    }
                }
        }
        arrProverka[l] = 1;
        arrProverka[t] = 1;
        for (int i = 0; i < 8; i++)
        {
            if (arrProverka[i] == 1)
            {
                count = i;
            }
            else
            {
                count = 0;
                break;
            }
        }
        cout << "[" << l + 1 << ", " << t + 1 << " ];  ";
    }
    cout << "\n";



    cout << "Крускала: ";
    Kraskl();
}


void Kraskl()
{
    int min;
    int edgesCount = 0;
    for (int i = 0; i < Y; i++)
    {
        visited[i] = i;
    }
    while (edgesCount < Y - 1)
    {
        min = INT_MAX;
        int a = infCost, b = infCost;
        for (int i = 0; i < Y; i++)
        {
            for (int j = 0; j < Y; j++)
            {
                if (find_set(i) != find_set(j) && graph[i][j] < min && graph[i][j] != 0)
                {
                    min = graph[i][j];
                    a = i;
                    b = j;
                }
            }
        }
        unionCompos(a, b);
        edgesCount++;
        cout << "["<<a + 1 << "," << b + 1 << "]; ";

    }
}



void unionCompos(int i, int j)
{
    int a = find_set(i);
    int b = find_set(j);
    visited[a] = b;
}

int find_set(int i) {
    if (i == visited[i])
        return i;
    else
        return find_set(visited[i]);
}
   


