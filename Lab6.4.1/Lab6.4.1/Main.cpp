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
		arr[i] = -10 + rand() % 21;
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

int IndexMax(int arr[], const int size)
{
	int index = 0;
	int max = arr[0];
	for (int i = 0; i < size; i++)
		if (arr[i] > max)
		{
			index = i;
			max = arr[i];
		}
	return index;
}

int SumElementArray(int arr[], const int size)
{
	int S = 0;
	for (size_t i = 1 + IndexMax(arr, size); i < size; i++)
		S += arr[i];
	return S;
}

int FindIndexMin(const int const arr[], const int size, int start)
{
	int min = arr[start];
	int index = start;
	for (int i = start; i < size; i++)
	{
		if (abs(arr[i]) > abs(min)) {
			min = arr[i];
			index = i;
		}
	}
	return index;
}

void SortArray(int arr[], const int size)
{
	for (size_t i = 0; i < size; i++)
	{
		int index = FindIndexMin(arr, size, i);
		int tmp = arr[index];
		arr[index] = arr[i];
		arr[i] = tmp;
	}
}

int main()
{
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
	cout << "Суму елементів масиву, розташованих після максимального елементу [" << IndexMax(arr, n) << "] = "
			<< SumElementArray(arr, n) << endl;
	SortArray(arr, n);
	PrintArray(arr, n);

	delete[] arr;
	arr = nullptr;
	return 0;
}