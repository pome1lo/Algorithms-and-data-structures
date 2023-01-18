#include<stdio.h>
#include<stdlib.h>
#include <iostream>
#include <vector>

using namespace std;

typedef struct items
{
    string name;
    unsigned int weight;
    float profit;
};

float max(float a, float b)
{
    return ((a > b) ? a : b);
}

float knapsack(unsigned int n, struct items object[], unsigned int capacity)
{
    float **table = new float *[n + 1];

    for (int i = 0; i <= n; i++)
    {
        table[i] = new float [capacity + 1];
        for (int j = 0; j <= capacity; j++)
        {
            if (i == 0 || j == 0)
            {
                table[i][j] = 0.0;
            }
            else if (object[i - 1].weight <= j)
            {
                table[i][j] = max((object[i - 1].profit + table[i - 1][j - object[i - 1].weight]), table[i - 1][j]);
            }
            else
            {
                table[i][j] = table[i - 1][j];
            }
        }
    }
    cout << "Таблица с предметами: " << endl;
    for (unsigned int i = 1; i <= n; i++)
    {
        for (unsigned int j = 1; j <= capacity; j++)
            printf("%.1f\t", table[i][j]);
        printf("\n");
    }

    return table[n][capacity];
}

void main()
{
    setlocale(LC_ALL, "rus");

    unsigned int capacity;
    cout << "Введите объем рюкзака:";
    cin >> capacity;

    unsigned int n;
    printf("Введите общее количество элементов: ");
    cin >> n;

    items* item = new items[n];

    printf("Введите запрашиваемые данные:\n");
    for (unsigned int i = 0; i < n; i++)
    {
        printf("==========Item No. %d ==========\n", i + 1);
        printf("Имя : ");
        cin >> item[i].name;
        printf("Вес : ");
        cin >> item[i].weight;
        printf("Цена: ");
        cin >> item[i].profit;
    }

    printf("Максимальная прибыль - это %.2f.", knapsack(n, item, capacity));
}