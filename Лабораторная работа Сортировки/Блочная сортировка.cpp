﻿// Блочная сортировка.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
using namespace std;

void BlockSort(int* A, int n) 
{
    int min = A[0];
    int max = A[0];

    for (int i = 0; i < n; i++)
    {
        if (A[i]<min)
        {
            min = A[i];
        }
        if (A[i] > max)
        {
            max = A[i];
        }
    }
    int count = max - min + 1;
    int** c = new int*[count];

    for (int i = 0; i < count; i++)
    {
        c[i] = new int[n];
    }
    for (int i = 0; i < n; i++)
    {
        int index = (A[i] - min) / count;
        c[index][i] = A[i];
    }
    for (int i = 0; i < count; i++)
    {
        for (int j = 0; j < n; j++)
        {
            for (int k = j+1; k < n; k++)
            {
                if (c[i][j]>c[i][k])
                {
                    int tmp = c[i][j];
                    c[i][j] = c[i][k];
                    c[i][k] = tmp;
                }
            }
        }
    }
    int index = 0;
    for (int i = 0; i < count; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (c[i][j] != 0)
            {
                A[index++] = c[i][j];
            }
        }
    }
    for (int i = 0; i < count; i++)
    {
        delete[] c[i];
    }
    delete c;
}

int main()
{
    setlocale(0, "");
    int n;
    int* A = new int[100];
    cout << "размер массива: ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cout << i + 1 << " Элемент: ";
        cin >> A[i];
    }
    BlockSort(A, n);
    cout << "Массив после сортировки: ";
    for (int i = 0; i < n; i++)
    {
        cout << A[i] << " ";
    }
    return 0;
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
