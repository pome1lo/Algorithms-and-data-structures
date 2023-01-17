#include <iostream>
#include <vector>
#include <conio.h>
#include <string>

using namespace std;

void LIS(vector<int> const& arr)
{
    int n = arr.size();

    if (n == 0)    return;

    vector<vector<int>> LIS(n, vector<int>{});

    LIS[0].push_back(arr[0]);

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (arr[j] < arr[i] && LIS[j].size() > LIS[i].size())
            {
                LIS[i] = LIS[j];
            }
        }
        LIS[i].push_back(arr[i]);
    }

    cout << "" << LIS[LIS.size() - 1].size() << endl;

    for (int i : LIS[LIS.size() - 1])
    {
        cout << i << " ";
    }
}

void main()
{
    setlocale(LC_ALL, "rus");
    vector<int> arr;
     //= { 5, 10, 6, 12, 3, 24, 7, 8 }
    
    cout << "Введите элементы последовательности: " << endl;
    
    string num;
    string temp = "q w e r t y u i o p a s d f g h j k l ; ' z x c v b n m , . / [ ]";
    while (true) 
    {
        cout << " : ";
        cin >> num;
        if (num == "exit") {
            break;
        }
        /*
        if (!temp.rfind(num[0])) {
            cout << "Вы сделали что-то не так " << endl; 
            num = " ";
            continue;
        } */
        else {
            arr.push_back(stoi(num));
            num = " ";
        }
    }

    cout << "Исходная последовательность: ";

    for (vector<int>::iterator it = arr.begin(); it != arr.end(); ++it)
    {
        cout << *it << " ";
    }
    cout << endl;

    LIS(arr);

    cout << endl << endl;
}

//int main()
//{
//    vector<int> arr = { 0, 8, 4, 12, 2, 10, 6, 14, 1, 9, 5, 13, 3, 11, 7, 15 };
//
//    cout << "The length of the LIS is " << LIS(arr);
//
//    return 0;
//}
//#include <iostream>
//#include <vector>
//#include <climits>
//using namespace std;
//
//// Итерационная функция для нахождения длины самой длинной возрастающей подпоследовательности
//// данного массива
//int LIS(vector<int> const& arr)
//{
//    int n = arr.size();
//
//    // базовый вариант
//    if (n == 0) {
//        return 0;
//    }
//
//    // массив для хранения решения подзадачи. `L[i]` хранит длину
//    // самой длинной возрастающей подпоследовательности, заканчивающейся на `arr[i]`
//    int *L = new int[n] {0};
//
//    // самая длинная возрастающая подпоследовательность, заканчивающаяся на `arr[0]`, имеет длину 1
//    L[0] = 1;
//
//    // начинаем со второго элемента массива
//    for (int i = 1; i < n; i++)
//    {
//        // делаем для каждого элемента подмассива `arr[0…i-1]`
//        for (int j = 0; j < i; j++)
//        {
//            // найти самую длинную возрастающую подпоследовательность, заканчивающуюся на `arr[j]`
//            // где `arr[j]` меньше, чем текущий элемент `arr[i]`
//
//            if (arr[j] < arr[i] && L[j] > L[i]) {
//                L[i] = L[j];
//            }
//        }
//
//        // включить `arr[i]` в ЛИС
//        L[i]++;
//    }
//
//    // найти самую длинную возрастающую подпоследовательность (имеющую максимальную длину)
//    int lis = INT_MIN;
//    for (int x : L) {
//        lis = max(lis, x);
//    }
//    return lis;
//}