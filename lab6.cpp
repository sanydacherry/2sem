
#include <stdio.h>
#include <iostream>
#include <conio.h>
#include <io.h>
#include <time.h>
#include <fcntl.h>
#include <sys\stat.h>
#include <fstream>
#include <string>
#include "math.h"
#pragma warning(disable : 4996)


using namespace std;


void tasksredn()
{
	const int N = 5;
	double arr[N];
	FILE* f1, * f2;
	char arr1[] = "LR6.bin";
	for (int i = 0; i < N; i++)
	{
		cout << "Input number:" << endl;
		cin >> arr[i];
	}
	cout << "Before:" << endl;
	for (int i = 0; i < N; i++)
	{
		cout << arr[i] << " ";
	}
	f1 = fopen(arr1, "wb");
	fwrite(arr, sizeof(arr), 1, f1);
	fclose(f1);
	
	double sredznach = 0;

	for (size_t i = 0; i < N; i++)
	{
		sredznach += arr[i];
	}
	sredznach = sredznach / N;

	for (size_t i = 0; i < N; i++)
	{
		if (arr[i] < 0)
		{
			arr[i] = arr[i] + sredznach;
		}
		else
		{
			if (arr[i] > 0)
		{
			arr[i] = arr[i] - sredznach;
		}

		}
	}
	f1 = fopen(arr1, "wb");
	fwrite(arr, sizeof(arr), 1, f1);
	fclose(f1);
	f2 = fopen(arr1, "rb");
	fread(arr, sizeof(arr), 1, f2);
	fclose(f2);
	cout << endl << "After:" << endl;
	for (int i = 0; i < N; i++)
	{
		cout << arr[i] << " ";
	}


}

int main()
{
	tasksredn();
}
