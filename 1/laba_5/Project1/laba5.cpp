#include <iostream>
#include <stack>


using namespace std;


void main()
{
	setlocale(LC_ALL, "Rus");
	int count = 0;
	char strock[100];
	stack<char>st;
	cin.getline(strock, 100);
	for (int i = 0; i < strlen(strock); i++)
	{
		if (strock[i] == '{')
		{
			st.push('}');
		}
		if (strock[i] == '[')
		{
			st.push(']');
		}
		if (strock[i] == '(')
		{
			st.push(')');
		}
		if (strock[i] == '}')
		{
			if (st.empty())
			{
				count = 0;
				cout << "������ ����������� �� �����" << endl;
				break;
			}
			if (st.top() != '}')
			{
				count = 0;
				cout << "������ ����������� �� �����" << endl;
			}
			else
			{
				st.pop();
				count++;
			}
		}
		if (strock[i] == ']')
		{
			if (st.empty())
			{
				count = 0;
				cout << "������ ����������� �� �����" << endl;
				break;
			}
			if (st.top() != ']')
			{
				count = 0;
				cout << "������ ����������� �� �����" << endl;
				break;
			}
			else
			{
				st.pop();
				count++;
			}
		}
		if (strock[i] == ')')
		{
			if (st.empty())
			{
				count = 0;
				cout << "������ ����������� �� �����" << endl;
				break;
			}
			if (st.top() != ')')
			{
				count = 0;
				cout << "������ ����������� �� �����" << endl;
				break;
			}
			else
			{
				st.pop();
				count++;
			}
		}

	}
	if (count !=0)
	{
		cout << "������ ����������� �����" << endl;
	}	
}