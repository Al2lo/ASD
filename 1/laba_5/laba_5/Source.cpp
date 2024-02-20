#include <iostream>
#include <stack>


using namespace std;


void main()
{
	setlocale(LC_ALL,"Rus");
	int k =0, count1 =0, count2 =0;
	stack<char>st;
	while (k!=7)
	{
		cout << "1.{" << '\t';
		cout << "2.[" << '\t';
		cout << "3.(" << '\t';
		cout << "4.}" << '\t';
		cout << "5.]" << '\t';
		cout << "6.)" << '\t';
		cout << "7.END" << endl;
		cin >> k;
		switch (k)
		{
		case 1:
		{
			st.push('}');
			count1++;
			break;
		}
		case 2:
		{
			st.push(']');
			count1++;
			break;
		}
		case 3:
		{
			st.push(')');
			count1++;
			break;
		}
		case 4:
		{
			if (st.top() == '}')
			{
				st.pop();
				count2++;
				break;
			}
			else
			{
				cout << "скобки расставлены не верно" << endl;
				k = 7;
				break;
			}
		}
		case 5:
		{
			if (st.top() == ']')
			{
				st.pop();
				count2++;
				break;
			}
			else
			{
				cout << "скобки расставлены не верно" << endl;
				k = 7;
				break;
			}
		}
		case 6:
		{
			if (st.top() == ')')
			{
				st.pop();
				count2++;
				break;
			}
			else
			{
				cout << "скобки расставлены не верно" << endl;
				k = 7;
				break;
			}
		}
		case 7:
		{
			if (count1 == count2)
			{
				cout << "скобки расставлены верно" << endl;
				break;
			}
			else
			{
				cout << "скобки расставлены не верно" << endl;
				break;
			}
		}

		}
		cout << endl;
	}
}