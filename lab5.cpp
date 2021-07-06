
void task1() {
	ofstream five("D:\\Scientists.txt");//заполнение файла
	five << "Scientists:\nSurname, name, phone number, city, district, EducationType:\nSergeev Ivan 0634576862 Kiev Petrogradskii technic";
	five << "\nPetrov Egor 0894351726 Kiev Tatarovskii technic\nBobulev Dmitry 0456756123 Odessa Primorsky Gumanitariy";
	five << "\nPavlov Vladimir 0765432353 Peterburg Northern technic\nIvanova Yana 0345261783 Odessa Kievsky Gumanitariy";
	five.close();
}
void task1_1()
{
	string line, th="technic";
	int a = 0;
	ifstream five("D:\\Scientists.txt"); // окрываем файл для чтения
	ofstream out("D:\\Scientists2.txt");
	out << "\nTehniks:\nSurname, name, phone number, city, district, EducationType :" << std::endl;
	if (five.is_open())
	{
		while (getline(five, line))
		{
			cout << "\n" << line;
			for(int i=0;i< line.length();i++)
			{
				for (int o = 0; o < th.length()-1; o++) 
				{                                      //поиск слова technic
					if (line[i] == th[o] && line[i+1] == th[o+1] && a < th.length()-1) 
					{
							a++;
					}
					else 
						if (a ==th.length()-1 && line[i + 1] == th[o + 1]) 
					{
						out <<  line << std::endl;
						a = 0;
					}
				}
			}

		}
	}
	out.close();
	five.close();     // закрываем файл
}
void task1_2() {
	ifstream out("D:\\Scientists2.txt");
	string line;
	if (out.is_open())
	{
		while (getline(out, line))
		{
			cout << line<<std::endl;
		}
	}
	out.close();
}

void task2() 
{
    ofstream five("D:\\number.txt");
    five << "\n7 9 15 1 2 9 4 7 6 14 10";
    five.close();
} 

void task2_1() {
    string o;
    float oddd=0,evenn=0;
    int chislo;
    ifstream five("D:\\number.txt");
    ofstream odd("D:\\number2(nechetnie).txt");
    ofstream even("D:\\number3(chetnie).txt");

    if (five.is_open())
    {
        while (getline(five, o, ' '))
        {
            cout << " " << o;
            chislo = stof(o);
            if (chislo%2==1)
            {
                oddd = chislo;
                odd << oddd << " ";
            }
            else
            {
                if (chislo % 2 == 0)
                {
                    evenn = chislo;
                    even << evenn << " ";
                }
            }
        }

    }
    even.close();
    odd.close();
    five.close();
}
void task2_2() {
    ifstream odd("D:\\number2(nechetnie).txt");
    string line;
    cout << endl << "Не чётные" << endl;
    if (odd.is_open())
    {
        while (getline(odd, line))
        {
            cout << line << std::endl;
        }
    }
    odd.close();

    ifstream even("D:\\number3(chetnie).txt");
    string line2;
    cout << endl << "Чётные" << endl;
    if (even.is_open())
    {
        while (getline(even, line2))
        {
            cout << line2 << std::endl;
        }
    }
   even.close();
  
} 

int main() {
	setlocale(LC_ALL, "Russian");
	task1();
	task1_1();
	task1_2();
	 task2();
	task2_1();
	task2_2();
}
