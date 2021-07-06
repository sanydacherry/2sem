#include <iostream>
#include <list>
#include <cstdlib>
using namespace std;
void task19_1()
{
    cout << "Создать линейный однонаправленный список из целых чисел. Определить среднее арифметическое значений элементов списка, кратных 4.\n";
    int n;
    cout << "\nВведите количество чисел\n";
    cin >> n;
    int counter = 1;

    list<int> l(n);
    for (auto& i : l)
    {
        cout << "\nВведите число № " << counter << " \n";
        cin >> i;
        counter++;
    }

    int sum = 0, k = 0;
    for (const auto i : l)
    {
        if (i % 4 == 0)
        {
            sum += i;
            k++;
        }
    }

    cout << "\nСреднее арифметическое чисел кратных 4 = " << double(sum / k);
}
void task19_2()
{
    cout << "Создать линейный однонаправленный список из вещественных чисел. Вставить в список число 13.5 после первого элемента со значением большим 2.\n";



list<double> Li;
        for (int i = 0; i < 10; i++)
            Li.push_back(rand() % 100 - 50);

list<double>::iterator p = Li.begin();
        for (; p != Li.end(); ++p)
cout << *p << ' ';
cout << std::endl;

        for (p = Li.begin(); p != Li.end();)
        {
            if (*p > 2)
            {
                Li.insert(++p, 13.5);
                break;
            }
            else
                ++p;
        }

cout << endl;
        for (p = Li.begin(); p != Li.end(); ++p)
cout << *p << ' ';
cout <<endl;


    }
    

int main()
{
    setlocale(LC_ALL, "Russian");
    //task19_1();
    task19_2();
}
