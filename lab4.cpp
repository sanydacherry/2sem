
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <string>
#include <sstream>
#include <iterator>
using namespace std;


void task4_1()
{
	// Для заданной строки определить входил ли в нее хотя бы одна латинская буква
	char S[1000];
	cin.getline(S, 1000);
	bool found = false;
	int i = 0;
	while (!found && i < strlen(S))
		if (S[i] >= 'a' && S[i] <= 'z' || S[i] >= 'A' && S[i] <= 'Z') // Сравнивает значение с буквами латинского алфавита, находит = выдаёт Yes 
			found = true;
		else
			i++;
	if (found)
		cout << "YES";
	else
		cout << "NO";
}
void task4_2()
{
	//Разрядить пробелами заданную строку
	char s1[50];
	char s2[50];
	int a;
	cin.getline(s1, 50);
	(cin >> a).get();
	cin.getline(s2, 50);

	// Не совсем понял формулировку задания, есть строка, которую я задаю, и она принимает значения с пробелами, так?
}
bool allLower(const std::string&);
void task4_3()
{
	//В заданной строке посчитать количество слов, содержащих только строчные латинские буквы. Разделителями слов считаются пробелы

		std::cout << "Введите слова, содержащие только строчные латинские буквы. Разделителями слов считаются пробелы:" << std::endl;
		std::string s, word;
		std::getline(std::cin, s);
		std::istringstream instr(s);
		std::istream_iterator<std::string> it(instr), eof;
		std::size_t count = std::count_if(it, eof, allLower);
		std::cout << "Количество слов: " << count << std::endl;

	
}
bool allLower(const std::string& word)
{
	for (auto const& ch : word)
		if (ch < 'a' || ch>'z')
			return false;
	return true;
}
int main()
{
	setlocale(LC_ALL, "Russian");
	//task4_1();
	//task4_2();
	task4_3();



}
