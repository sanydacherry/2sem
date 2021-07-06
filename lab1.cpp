#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
struct Name
{
	char Name[50];
	char Surname[50];
	char Patronymic[50];
};
struct Date
{
	short day;
	short month;
	short year;
	bool isCorrect();
};

bool Date::isCorrect()
{
	bool result = false;

	if (month > 0 && month <= 12 && year <= 2021)
	{
		switch (month)
		{
		case 1:
		case 3:
		case 5:
		case 7:
		case 8:
		case 10:
		case 12:
		{
			if ((day <= 31) && (day > 0))
				result = true;
			break;
		}

		case 4:
		case 6:
		case 9:
		case 11:
		{
			if ((day <= 30) && (day > 0))
				result = true;
			break;
		}

		case 2:
		{
			if (year % 4 != 0)
			{
				if ((day <= 28) && (day > 0))
					result = true;
			}
			else
				if (year % 400 == 0)
				{
					if ((day <= 29) && (day > 0))
						result = true;
				}
				else
					if ((year % 100 == 0) && (year % 400 != 0))
					{
						if ((day == 28) && (day > 0))
							result = true;
					}
					else
						if ((year % 4 == 0) && (year % 100 != 0))
							if ((day <= 29) && (day > 0))
								result = true;
			break;
		}

		default:
			result = false;
		}
	}
	return result;
}
struct NOTE1
{
	Name NAME;
	int TELE;
	Date DATE;
};

struct Worker       //Создаем структуру!
{
	char F[50];       //familiya
	int Y;        //god rojd
	char D[50];       //doljnost
	int zarplata;       //zp
	char O[10];         //obrazovanie
	void printInfo();
	void readInfo();
};
void Worker::printInfo()
{

	cout << "\nSurname: " << Worker::F << endl;
	cout << "Year of birth: " << Worker::Y << endl;
	cout << "Doljnost: " << Worker::D << endl;
	cout << "zarplata: " << Worker::zarplata << endl;
	cout << "obrazovanie: " << Worker::O << endl;
}
void Worker::readInfo()
{
	cout << "\nInput worker surname: ";
	cin.ignore(std::cin.rdbuf()->in_avail());
	cin.getline(F, sizeof(F));

	cout << "\nInput year of birth: ";
	cin >> Y;

	cout << "\nInput Doljnost: ";
	cin.ignore(std::cin.rdbuf()->in_avail());
	cin.getline(D, sizeof(D));

	cout << "\nInput zarplata: ";
	cin >> zarplata;

	cout << "\nInput obrazovanie: ";
	cin.ignore(std::cin.rdbuf()->in_avail());
	cin.getline(O, sizeof(O));
}
void task19() {

	cout << "\n 19. Определить самого младшего работника и напечатать сведения о нем.\n";

	const int N = 3;
	Worker stat[N];

	for (size_t i = 0; i < N; i++)
	{
		stat[i].readInfo();
	}

	for (size_t i = 0; i < N; i++)
	{
		stat[i].printInfo();
	}

	int youngest = 0;
	for (size_t i = 1; i < N; i++)
	{
		if (stat[i].Y > stat[youngest].Y)
			youngest = i;

	}
	cout << endl << "The youngest worker is: ";
	stat[youngest].printInfo();
}
struct Player
{
	char Family[50];
	Date birthday;
	char Klub[50];
	int Role;
	int Kolvoigr;
	char Birthplace[50];

};
void task19_2()
{
	cout << "\n 19_2. Вывести сведения о защитниках,младше 20-лет и сыгравших за свой клуб более 40-ка матчей.\n";
	const int N = 1;
	Player group[N];
	int player_counter = 1;

	for (int i = 0; i < N; i++)
	{
		cout << "\n\n\nPlayer #" << player_counter << " \n\n\n";
		cout << "\nInput Family: ";
		cin.ignore(std::cin.rdbuf()->in_avail());
		cin.getline(group[i].Family, 50);

		cout << "\nInput Club: ";
		cin.ignore(std::cin.rdbuf()->in_avail());
		cin.getline(group[i].Klub, 50);

		cout << "\n 1 - Defender \n 2 - Attacker \n 3 - Goalkeeper\n";

		cout << "\nInput Amplua number: ";
		cin >> group[i].Role;
		do
		{
			cout << "\nInput birthday year(Not more then 2021): ";
			cin.ignore(std::cin.rdbuf()->in_avail());
			cin >> group[i].birthday.year;
			cout << "\nInput birthday month(1-12): ";
			cin >> group[i].birthday.month;
			cout << "\nInput birthday day(1-31): ";
			cin >> group[i].birthday.day;

		} while (!group[i].birthday.isCorrect());

		cout << "\nInput quantity of games: ";
		cin >> group[i].Kolvoigr;

		cout << "\nInput Birthplace: ";
		cin.ignore(std::cin.rdbuf()->in_avail());
		cin.getline(group[i].Birthplace, 50);
		player_counter++;

	}
	for (int i = 0; i < N; i++)
	{
		if (group[i].Role == 1)
		{
			if (group[i].Kolvoigr > 40)
			{
				if ((2021 - group[i].birthday.year) < 20)
				{
					cout << "\nFamily: " << group[i].Family;
					cout << "\nClub: " << group[i].Klub;
					cout << "\nAmlua: Defender";
					cout << "\nBirthday: " << group[i].birthday.day << "." << group[i].birthday.month << "." << group[i].birthday.year;
					cout << "\nQuantity of games: " << group[i].Kolvoigr;
					cout << "\nBirthplace: " << group[i].Birthplace;



				}
				else
				{
					if ((2021 - group[i].birthday.year) == 20 && (3 - group[i].birthday.month) < 0)
					{
						cout << "\nFamily: " << group[i].Family;
						cout << "\nClub: " << group[i].Klub;
						cout << "\nAmlua: Defender";
						cout << "\nBirthday: " << group[i].birthday.day << "." << group[i].birthday.month << "." << group[i].birthday.year;
						cout << "\nQuantity of games: " << group[i].Kolvoigr;
						cout << "\nBirthplace: " << group[i].Birthplace;
					}
					else
					{

						if ((2021 - group[i].birthday.year) == 20 && (3 - group[i].birthday.month) == 0 && (8 - group[i].birthday.day) <= 0)
						{
							cout << "\nFamily: " << group[i].Family;
							cout << "\nClub: " << group[i].Klub;
							cout << "\nAmlua: Defender";
							cout << "\nBirthday: " << group[i].birthday.day << "." << group[i].birthday.month << "." << group[i].birthday.year;
							cout << "\nQuantity of games: " << group[i].Kolvoigr;
							cout << "\nBirthplace: " << group[i].Birthplace;
						}
						else
						{
							break;
						}
					}
				}
			}
			else
			{
				break;
			}
		}
		else
		{
			break;
		}
	}
}
void task19_3()
{
	cout << "\n 19_3. Ввод с клавиатуры данных в массив BLOCK,состоящийиз 9 элементов типа note1,записи должны быть упорядочены по инициалам,вывод на экран информации о людях чьи дни рождения приходятся на месяц,значение которого введено с клавиатуры,если такого человека нет - выдать сообщение\n";
	const int N = 2;
	NOTE1 BLOCK[N];

	for (int i = 0; i < N; i++)
	{
		cout << "\nInput Name: ";
		cin.ignore(std::cin.rdbuf()->in_avail());
		cin.getline(BLOCK[i].NAME.Name, 50);
		cout << "\nInput Patronymic: ";
		cin.ignore(std::cin.rdbuf()->in_avail());
		cin.getline(BLOCK[i].NAME.Patronymic, 50);
		cout << "\nInput Surname: ";
		cin.ignore(std::cin.rdbuf()->in_avail());
		cin.getline(BLOCK[i].NAME.Surname, 50);
		do
		{
			cin.ignore(std::cin.rdbuf()->in_avail());
			BLOCK[i].DATE.year = rand() % 22 + 2000;
			BLOCK[i].DATE.month = rand() % 13;
			BLOCK[i].DATE.day = rand() % 32;

		} while (!BLOCK[i].DATE.isCorrect());
		BLOCK[i].TELE = rand()%100000000;

	};
	NOTE1 person;
	for (int i = 0; i < N; i++)
	{
		
		if (strcmp(BLOCK[i].NAME.Name, BLOCK[i + 1].NAME.Name) > 0 && strcmp(BLOCK[i].NAME.Patronymic, BLOCK[i + 1].NAME.Patronymic)>0)
		{
			swap(BLOCK[i], BLOCK[i + 1]);
		}
	}
	int Month = 0;
	for (int i = 0; i < N; i++)
	{
		cout << "\n Name: " << BLOCK[i].NAME.Name << " " << BLOCK[i].NAME.Patronymic << " " << BLOCK[i].NAME.Surname;
		cout << "\nBirthday: " << BLOCK[i].DATE.day << "." << BLOCK[i].DATE.month << "." << BLOCK[i].DATE.year;
		cout << "\n Phone number:" << BLOCK[i].TELE;
	}
	cout << "\nInput month number (1-12)\n";
	cin >> Month;
	for (int i = 0; i < N; i++)
	{
		if (BLOCK[i].DATE.month == Month)
		{
			cout << "\n Name: " << BLOCK[i].NAME.Name << " " << BLOCK[i].NAME.Patronymic << " " << BLOCK[i].NAME.Surname;
			cout << "\nBirthday: " << BLOCK[i].DATE.day << "." << BLOCK[i].DATE.month << "." << BLOCK[i].DATE.year;
			cout << "\n Phone number:" << BLOCK[i].TELE;
		}
	}
}


int main()
{
	setlocale(LC_ALL, "rus");
	//task19();
	//task19_2();
	task19_3();
}
