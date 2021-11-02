// Main.cpp
// ˳������ �����
// ����������� ������ � 6.4
// ����������� �� ������������� ����������� ��������� ������
// ������ 13(����������� �����)
#define NOMINMAX
#include <iostream>
#include <Windows.h>
using namespace std;

void InitArray(int arr[], const int size, int i)
{
	if (i < size)
	{
		arr[i] = -100 + rand() % 201;
		InitArray(arr, size, i + 1);
		return;
	}
}

void PrintArray(const int* const arr, const int size, int i)
{
	if (i < size)
	{
		if (i == 0)
			cout << "{";
		cout << arr[i];
		if (i != size - 1)
			cout << ", ";
		else cout << "}" << endl;
		PrintArray(arr, size, i + 1);
		return;
	}
}

int CountElementArray(const int const arr[], const int size, const int A, const int B, int i)
{
	if (i < size)
	{
		if (arr[i] >= A && arr[i] <= B)
			return 1 + CountElementArray(arr, size, A, B, i + 1);
		else
			return CountElementArray(arr, size, A, B, i + 1);
	}
	else return 0;
}

int IndexMax(const int const arr[], const int size, const int A, const int B, int i, int m = numeric_limits<int>::min())
{
	if (arr[i] > m && arr[i] >= A && arr[i] <= B)
	{
		m = arr[i];
		return i;
	}
	if (i < size-1)
		return IndexMax(arr, size, A, B, i + 1, m);
	else return -1;
}

int SumElementArray(const int const arr[], const int size, const int A, const int B, int i)
{
	if (i < size)
	{
		return arr[i] + SumElementArray(arr, size, A, B, i + 1);
	}
	else return 0;
}

int Max(const int const arr[], int size, int& index, int i)
{
	index = 0;
	if (i < size)
	{
		if (abs(arr[i]) > abs(Max(arr, size, index, i + 1))) 
		{
			index = i;
			return arr[i];
		}
		else
			return Max(arr, size, index, i + 1);
	}
	else return numeric_limits<int>::min();
}

void SortArray(int arr[], const int size, int i)
{
	if (i < size)
	{
		int index;
		int m = Max(arr, size, index, i);
		arr[index] = arr[i];
		arr[i] = m;
		SortArray(arr, size, i + 1);
		return;
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

	InitArray(arr, n, 0);
	PrintArray(arr, n, 0);
	cout << "ʳ������ �������� ������, �� ������ � ������� �� [" << A << " �� " << B << "] = "
		<< CountElementArray(arr, n, A, B, 0) << endl;
	cout << "���� �������� ������, ������������ ���� ������������� �������� [" << arr[IndexMax(arr, n, A, B, 0)] << "] = "
		<< SumElementArray(arr, n, A, B, IndexMax(arr, n, A, B, 0) + 1) << endl;
	SortArray(arr, n, 0);
	PrintArray(arr, n, 0);

	delete[] arr;
	arr = nullptr;
	return 0;
}