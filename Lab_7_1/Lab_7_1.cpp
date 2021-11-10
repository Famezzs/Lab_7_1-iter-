// Lab_7_1.cpp
// Козубенко Андрій
// Лабораторна робота № 7.1
// Пошук заданих елементів та впорядкування рядків / стовпчиків матриці.
// Варіант 10
#include <iostream>
#include <iomanip>
#include <time.h>

void Create(int **a, const int rowCount, const int colCount, const int Low, const int High);
void Print(int **a, const int rowCount, const int colCount);
void Sort(int **a, const int rowCount, const int colCount);
void Change(int **a, const int col1, const int col2, const int rowCount);
void Calc(int **a, const int rowCount, const int colCount, int &Sum, int &Amount);

using std::cout;
using std::endl;
using std::setw;

int main()
{
	srand((unsigned)time(NULL));

	const int Low = -26;
	const int High = 23;

	const int rowCount = 8;
	const int colCount = 6;

	int **Q = new int *[rowCount];
	for (int i = 0; i < rowCount; i++)
		Q[i] = new int[colCount];

	Create(Q, rowCount, colCount, Low, High);
	Print(Q, rowCount, colCount);
	Sort(Q, rowCount, colCount);
	Print(Q, rowCount, colCount);

	int S = 0;
	int n = 0;
	Calc(Q, rowCount, colCount, S, n);
	cout << "Sum of replaced elements: " << S << endl;
	cout << "Number of replaced elements: " << n << endl;
	Print(Q, rowCount, colCount);

	for (int i = 0; i < rowCount; i++)
		delete[] Q[i];
	delete[] Q;

	return 0;
}

void Create(int **a, const int rowCount, const int colCount, const int Low, const int High)
{
	for (int i = 0; i < rowCount; i++)
		for (int j = 0; j < colCount; j++)
			a[i][j] = Low + rand() % (High - Low + 1);
}

void Print(int **a, const int rowCount, const int colCount)
{
	cout << endl;
	for (int i = 0; i < rowCount; i++)
	{
		for (int j = 0; j < colCount; j++)
			cout << setw(5) << a[i][j];
		cout << endl;
	}
	cout << endl;
}

void Sort(int **a, const int rowCount, const int colCount)
{
	for (int i0 = 0; i0 < colCount - 1; i0++)
		for (int i1 = 0; i1 < colCount - i0 - 1; i1++)
			if ((a[0][i1] > a[0][i1 + 1])
				||
				(a[0][i1] == a[0][i1 + 1] &&
					a[1][i1] < a[1][i1 + 1])
				||
				(a[0][i1] == a[0][i1 + 1] &&
					a[1][i1] == a[1][i1 + 1] &&
					a[2][i1] > a[2][i1 + 1]))
				Change(a, i1, i1 + 1, rowCount);
}

void Change(int **a, const int col1, const int col2, const int rowCount)
{
	int tmp;
	for (int j = 0; j < rowCount; j++)
	{
		tmp = a[j][col1];
		a[j][col1] = a[j][col2];
		a[j][col2] = tmp;
	}
}

void Calc(int **a, const int rowCount, const int colCount, int &Sum, int &Amount) 
{
	Sum = 0;
	Amount = 0;
	for (int i = 0; i < rowCount; i++)
		for (int j = 0; j < colCount; j++)
			if (!(a[i][j] > 0 && a[i][j] % 2 == 0))
			{
				Sum += a[i][j];
				Amount++;
				a[i][j] = 0;
			}
}