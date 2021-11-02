// Main.cpp
// Лісничук Арсен
// Лабораторна робота № 6.4
// Опрацювання та впорядкування одновимірних динамічних масивів
// Варіант 13(Ітераційний спосіб)
#define NOMINMAX
#include <iostream>
#include <Windows.h>
using namespace std;

void InitArray(int arr[], const int size)
{
	for (size_t i = 0; i < size; i++)
	{
		arr[i] = -100 + rand() % 201;
	}
}

void PrintArray(const int* const arr, const int size)
{
	cout << "{";
	for (size_t i = 0; i < size; i++)
	{
		cout << arr[i];
		if (i != size - 1)
			cout << ", ";
	}
	cout << "}" << endl;
}

int CountElementArray(const int const arr[], const int size, const int A, const int B)
{
	int C = 0;
	for (size_t i = 0; i < size; i++)
		if (arr[i] >= A && arr[i] <= B)
			C++;
	return C;
}

int IndexMax(const int const arr[], const int size, const int A, const int B)
{
	for (size_t i = 0; i < size; i++)
	{
		if (arr[i] >= A && arr[i] <= B)
			return i;
	}
	return -1;
}

int SumElementArray(const int const arr[], const int size, const int A, const int B)
{
	int S = 0;
	for (size_t i = 1 + IndexMax(arr, size, A, B); i < size; i++)
		S += arr[i];
	return S;
}

void SortArray(int arr[], const int size)
{
	for (size_t i = 0, index = 0; i < size; i++)
	{
		int m = numeric_limits<int>::min();
		for (size_t j = i; j < size; j++)
		{
			if (abs(arr[j]) > abs(m)) {
				m = arr[j];
				index = j;
			}
		}
		arr[index] = arr[i];
		arr[i] = m;

	}
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	srand(time(0));
	int n, A, B;
	cout << "n = "; cin >> n;
	cout << "A = "; cin >> A;
	cout << "B = "; cin >> B;
	int* arr = new int[n];

	InitArray(arr, n);
	PrintArray(arr, n);
	cout << "Кількість елементів масиву, що лежать в діапазоні від [" << A << " до " << B << "] = "
		<< CountElementArray(arr, n, A, B) << endl;
	cout << "Суму елементів масиву, розташованих після максимального елементу [" << arr[IndexMax(arr, n, A, B)] << "] = "
		<< SumElementArray(arr, n, A, B) << endl;

	SortArray(arr, n);
	PrintArray(arr, n);

	delete[] arr;
	arr = nullptr;
	return 0;
}