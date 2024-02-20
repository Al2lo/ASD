#include "iostream"
#include <string>
#include <queue>
#include <unordered_map>


using namespace std;


struct Node
{
	char symbol;
	int freq;
	Node* left, *right;
};

Node* GetNode(char symbol, int freq, Node*left,Node*right)
{
	Node* node = new Node();

	node->freq = freq;
	node->symbol = symbol;
	node->left = left;
	node->right = right;

	return node;
}

struct comp
{
	bool operator()(const Node* l, const Node* r) const
	{
		// ������� � ��������� ����������� ����� ���������� �������
		return l->freq > r->freq;
	}
};

// ��������������� ������� ��� ��������, �������� �� ������ �������� ������ ���� ����
bool OnlyOneNode(Node*node)
{
	return node->left == nullptr && node->right == nullptr;
}


void Encode(Node* node, string str, unordered_map<char, string>& huffmanCode)
{
	if (node == nullptr)
	{
		return;
	}

	if (OnlyOneNode(node))
	{
		huffmanCode[node->symbol] = (str != "") ? str : "1";
	}

	Encode(node->left, str + "0", huffmanCode);
	Encode(node->right, str + "1", huffmanCode);
}


void Decode(Node* node, int& index, string str)
{
	if (node == nullptr)
	{
		return;
	}

	if (OnlyOneNode(node))
	{
		cout << node->symbol;
		return;
	}

	index++;

	if (str[index] == '0')
	{
		Decode(node->left, index, str);
	}
	else
	{
		Decode(node->right, index, str);
	}

}


void BuildHuffmanTree(string text)
{
	if (text == "")
	{
		return;
	}

	// ������������ ������� ��������� ������� �������  � ��������� ��� �� �����
	unordered_map<char, int> freq;
	
	for (char symbol : text)
	{
		freq[symbol]++;
	}


	// ������� ������������ ������� ��� �������� �������� ����� ������ ��������
	priority_queue<Node*, vector<Node*>, comp> pq;

	// ������� �������� ���� ��� ������� ������� � ��������� ��� � ������������ �������
	for (auto pair : freq) {
		pq.push(GetNode(pair.first, pair.second, nullptr, nullptr));
	}
	cout << "����� ������� ������������� �������� � ������ " << endl;
	for (auto pair : freq)
	{
		cout << pair.first << "---" << pair.second << endl;
	}

	while (pq.size() != 1)
	{
		// ������� ��� ���� � ��������� ����������� (����� ������ �������) �� queue
		Node* left = pq.top();
		pq.pop();
		Node* Right = pq.top();
		pq.pop();

		// ������� ����� ���������� ���� � ����� ����� ������ � �������� �������� �
			// � ��������, ������ ����� ������ ���� �����.
			// ��������� ����� ���� � ������������ �������.
		int sum = left->freq + Right->freq;
		pq.push(GetNode('\0', sum, left, Right));

	}

	// `pNode` ������ ��������� �� ������ ������ ��������
	Node* pNode = pq.top();

	// �������� �� ������ �������� � ��������� ���� ��������
	// �� �����. ����� ����, ������������ ��
	unordered_map<char, string> huffmanCode;
	Encode(pNode, "", huffmanCode);

	cout << "Huffman Codes are : \n";
	for (auto pair:huffmanCode)
	{
		cout << pair.first << "---" << pair.second << endl;
	}


	cout << "\nThe original string is:\n" << text << endl;


	string str;
	for (char symbol : text)
	{
		str += huffmanCode[symbol];
	}


	cout << "\nThe encoded string is:\n" << str << endl;
	cout << "\nThe decoded string is:\n";

	if (OnlyOneNode(pNode))
	{
		// ������ ������ : ��� ����� ���� a, aa, aaa � �.�.
		while (pNode->freq--)
		{
			cout << pNode->symbol;
		}
	}
	else
	{
		int index = -1;
		while (index < (int)str.size() - 1)
		{
			Decode(pNode,index,str);
		}
	}

}





void main()
{
	setlocale(LC_ALL,"Rus");
	string text = "aabcd";
	BuildHuffmanTree(text);
}