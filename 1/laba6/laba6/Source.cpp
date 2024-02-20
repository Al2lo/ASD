#include <array>
#include <vector>
#include <Windows.h>
#include <iostream>
#include <string>
using namespace std;
const int sizeoft = 32, maxnum = 32767, sizeoft2 = 16;


struct Data
{
    int key;
    string name;
};

struct HashTable1
{
    array<vector<Data>, sizeoft> table;

    int hash_func(int key)
    {
        return key % sizeoft;
    }

    bool add(int key, string name)
    {
        if (key > maxnum)
        {
            cout << "максимальный номер 32767\n";
            return false;
        }
        int place = hash_func(key);
        Data t = { key, name };
        table[place].push_back(t);
        return true;
    }

    void search(int key)
    {
        int place = hash_func(key);
        bool check = false;
        for (auto i : table[place])
        {
            if (i.key == key)
            {
                cout << i.key << " --- " << i.name << endl;
                check = true;
            }
        }
        if (check == false)
            cout << "Такого телефона в книге нет\n";
    }

    void deleteEl(int key)
    {
        int place = hash_func(key);
        bool check = false;
        for (auto i : table[place])
        {
            if (i.key == key)
            {
                check = true;
            }
            if (check == true)
                table[place].erase(table[place].begin() + (i.key / sizeoft));
        }
        if (check == false)
        {
            cout << "Такого телефона в книге нет\n";
        }
    }

    void scan()
    {
        for (int j = 0; j < sizeoft; j++)
        {
            for (auto i : table[j])
                cout << i.key << " --- " << i.name << endl;
        }
    }
};

struct HashTable2
{
    array<vector<Data>, sizeoft2> table;

    int hash_func(int key)
    {
        return key % sizeoft2;
    }

    bool add(int key, string name)
    {
        if (key > maxnum)
        {
            cout << "максимальный номер 32767\n";
            return false;
        }
        int place = hash_func(key);
        for (auto i : table[place])
        {
            if (i.key == key)
            {
                i.key = key;
                i.name = name;
                return false;
            }
        }
        Data t = { key, name };
        table[place].push_back(t);
        return true;
    }

    void deleteEl(int key)
    {
        int place = hash_func(key);
        bool check = false;
        for (auto i : table[place])
        {
            if (i.key == key)
            {
                check = true;
            }
            if (check == true)
                table[place].erase(table[place].begin() + (i.key / sizeoft));
        }
        if (check == false)
        {
            cout << "Такого телефона в книге нет\n";
        }
    }

    void search(int key)
    {
        int place = hash_func(key);
        bool check = false;
        for (auto i : table[place])
        {
            if (i.key == key)
            {
                cout << i.key << " --- " << i.name << endl;
                check = true;
            }
        }
        if (check == false)
            cout << "Такого телефона в книге нет\n";
    }



    void scan()
    {
        for (int j = 0; j < sizeoft2; j++)
        {
            for (auto i : table[j])
                cout << i.key << " --- " << i.name << endl;
        }
    }
};

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    HashTable1 HT1;
    HashTable2 HT2;
    int choice, key; string name;
    HT1.add(32292, "Паша");
    HT1.add(31424, "Гена");
    HT1.add(12942, "Кто");
    HT1.add(21741, "Дима");
    HT2.add(32292, "Паша");
    HT2.add(31424, "Гена");
    HT2.add(12942, "Кто");
    HT2.add(21741, "Дима");
    do
    {
        cout << " l= 16\n";
        cout << "\n1 - вывести телефонную книгу на экран\n";
        cout << "2 - добавить элемент\n";
        cout << "3 - удалить элементы\n";
        cout << "4 - поиск\n";
        cout << "l = 32\n";
        cout << "\n5 - вывести телефонную книгу на экран\n";
        cout << "6 - добавить элемент\n";
        cout << "7 - удалить элементы\n";
        cout << "8 - поиск\n";
        cout << "9 - выход\n\n";
        cout << "Ваш выбор: "; cin >> choice;
        cout << endl;
        switch (choice)
        {
        case 1:system("cls"); HT1.scan(); break;
        case 2: cout << "\nвведите телефон (не более чем 32767): "; cin >> key;
            cout << "введите имя:"; cin >> name;
            HT1.add(key, name);
            break;
        case 3: cout << "Введите телефон: "; cin >> key;
            HT1.deleteEl(key);
            break;
        case 4: cout << "Введите телефон: "; cin >> key;
            HT1.search(key);
            break;
        case 5: system("cls");  HT2.scan(); break;
        case 6: cout << "\nвведите телефон (не более чем 32767): "; cin >> key;
            cout << "введите имя:"; cin >> name;
            HT2.add(key, name);
            break;
        case 7: cout << "Введите телефон: "; cin >> key;
            HT2.deleteEl(key);
            break;
        case 8: cout << "Введите телефон: "; cin >> key;
            HT2.search(key);
            break;
        }
    } while (choice != 9);
}