#include <iostream>
#include <fstream>
#include <string>
using namespace std;


// Создать очередь.информационными полями который являются: фамилия и средний бал студента. Добавить в очередь сведения о новом студенте.
// Организовать просмотр данных очереди. БАЗОВЫЙ.
struct stek
{
    string surname;
    int average;
    stek* next;
};

int main()
{
    setlocale(0, "ru");
    int a, count=0;
    cout << "Введите количество студентов: ";
    cin >> a;
    stek *top, *p, *first;
    top = new stek;
    top->next = NULL;
    cout << "Input surname student: ";
    cin.ignore(std::cin.rdbuf()->in_avail());
    getline(cin, top->surname, '\n');
    cout << "Input mark: ";
    cin >> top->average;
    first = top;
    cout << endl;
    do
    {
        if (a == 1)
            break;
        p = new stek;
        p->next = NULL;
        cout << "Input surname student: ";
        cin.ignore(std::cin.rdbuf()->in_avail());
        getline(cin, p->surname, '\n');
        cout << "Input mark:";
        cin >> p->average;
        top->next = p;
        top = p;
        count++;
        cout << endl;

    } while (--a != count );
    int answer;
    cout << "Добавить информацию о новом студенте?(1 - да/нет - 0)" << endl;
    cin >> answer;
    cout << endl;
    if (answer == 1)
    {
        p = new stek;
        p->next = NULL;
        cout << "Input surname student: ";
        cin.ignore(std::cin.rdbuf()->in_avail());
        getline(cin, p->surname, '\n');
        cout << "Input mark:";
        cin >> p->average;
        top->next = p;
        top = p;
        cout << endl;
    }
    top = first;
    do
        {
            cout << "Surname: " << top->surname << " Average mark " << top->average << endl;
            top = top->next;

        } while (top);
   
    


 
}


#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
using namespace std;

// Создать очередь вещественных значений,для реализации используя односвязные списки. Реализовать операции добавления (enqueue) и удаления
// (deqeue) элемента из очереди. Добавьте в очередь числа 2.2, 3.2, 2.4, -3.2 и распечатйте содержимое очереди. Удалите 1 элемент из очереди,
// затем добавьте в очередь число 0.04 и распечатайте очередь ещё раз. *Найдите сумму чисел по модулю меньших 1,принадлежащих очереди.

struct queue
{
    double number;
    queue* next;

};

double info(queue* ptop , queue *pfirst)
{
    double sum = 0;
    ptop = pfirst;
    while (ptop)
    {
        if (abs(ptop->number) < 1)
            sum = sum + ptop->number;
        cout << ptop->number << "    ";
        ptop = ptop->next;

    } 
    return sum;
}
void info2(queue* pp , queue* ptop, queue* pfirst)
{
    ptop = pfirst;
    while (ptop)
    {
        cout << ptop->number << "    ";  
        if (!ptop->next->next)
        {
            free(ptop->next);
            ptop->next = NULL;
            break;
        }
        ptop = ptop->next;
    }
    pp = new queue;
    pp->next = NULL;
    pp->number = 0.04;
    ptop->next = pp;
    ptop = pp;

}
void filling(queue* pointer_p, queue* ptop2 , double *array)
{
    int count = 0;
    do
    {
        pointer_p = new queue;
        pointer_p->next = NULL;
        pointer_p->number = array[count];
        ptop2->next = pointer_p;
        ptop2 = pointer_p;
        count++;
    } while (count != 5);

}


int main()
{
    setlocale(0, "ru");
    int count = 0;
    double array[] = { 2.2 , 3.2, 2.4, -3.2 };
    queue *top, *p, *first;
    top = new queue;
    top->next = NULL;
    top->number =(rand() % 100 + 0.1)*0.1;
    first = top;
    do
    {
        p = new queue;
        p->next = NULL;
        p->number = (rand() % 100 + 1) * 0.1;
        top->next = p;
        top = p;
        count++;
    } while (count != 5);
    count = 0;
    cout << "Изначальная матрица"<<endl;
    info(top , first);
    filling(p, top, array);
    cout <<endl<< "Измененная матрица:"<<endl;
    info2(p,top, first);
    cout << endl;
    cout <<"Добавление 0.04"<< endl;
    double sum = info(top, first);
    cout << endl << "Сумма по модулю всех чисел меньше 1: " << sum  ;

}
