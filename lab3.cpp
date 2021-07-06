#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <string>
using namespace std;


void task3_1()
{
	//Дан массив символов. Проверить,одинаковое ли число открывающихся и закрывающихся квадратных скобок в данной строке
	int counter = 0;
	char stroka[7] = { '[', '[', ']', ']', '[', ']', '[' };
	for (int i = 0; i < 7; i++)
	{
		cout << stroka[i] << " ";
		if (stroka[i] == '[')
		{
			counter++;
		}
		if (stroka[i] == ']')
		{
			counter--;
		}
	}
	if (counter == 0)
	{
		cout << endl << " [ and ] have same count ";
	}
	else
	{
		cout << endl << " [ and ] have not same count ";
	}
}
void task3_2()
{
	// Введите массив символов из 14 элементов. Расположить слова в алфавитном порядке по первой букве слова
	struct Surname // Взял за основу фамилии, просто так, текст можно писать по факту любой
	{
		char Surname[50];
	};
	const int N = 14;
	Surname Surname[N];

	for (int i = 0; i < N; i++)
	{
		cout << "\nInput Surname: ";
		cin.ignore(std::cin.rdbuf()->in_avail());
		cin.getline(Surname[i].Surname, 50); // Заполнение массивов данными
	}
	for (int i = 0; i < N; i++)
	{
		for (int c = 0; c < N; c++)
		{

			if (strcmp(Surname[i].Surname, Surname[c].Surname) > 0)
			{
				swap(Surname[i].Surname, Surname[c].Surname);
				// Выстраивание по алфавиту в обратном порядке
			}
		}
	}
	for (int i = N-1; i > -1; i--) // Разворот, и уже вывод в алфавитном порядке всех значений массива
	{
		cout << Surname[i].Surname << " ";
	}
}
void task3_3()
{
	//Дан массив символов,содержащий текст. Слова зашифрованы - каждое из них записано наоборот. Расшифровать сообщение.
	string input = {"?drah ti sI"}; 
	cout << input<< endl;
	reverse(input.begin(), input.end());
	cout << input << endl;
	// Серьёзно, к этому нужны какие-то комментарии?
}
int main()
{
	//task3_1();
	//task3_2();
	//task3_3();



}
