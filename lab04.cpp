#include <iostream>
#include <iomanip>

using namespace std;

void main()
{
    const int size = 6;
    const int I = INT32_MAX;
    int MatrixD[size][size] =
    {
     //   1   2ц   3   4   5   6   // 31
 /* 1 */{ 0 , 28, 21, 59, 12, 27},
 /* 2 */{ 7 , 0 , 24, I , 21, 9  },
 /* 3 */{ 9 , 32, 0 , 13, 11, I  },
 /* 4 */{ 8 , I , 5 , 0 , 16, I  },
 /* 5 */{ 14, 13, 15, 10, 0 , 22 },
 /* 6 */{ 15, 18, I , I , 6 , 0  }
    };                                     

    int MatrixS[size][size] =
    {
        { 0, 2, 3, 4, 5, 6 },
        { 1, 0, 3, 4, 5, 6 },
        { 1, 2, 0, 4, 5, 6 },
        { 1, 2, 3, 0, 5, 6 },
        { 1, 2, 3, 4, 0, 6 },
        { 1, 2, 3, 4, 5, 0 }
    };

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++) 
        {
            if ((j != i) || (MatrixD[j][i] != I))
            {
                for (int k = 0; k < size; k++) 
                {
                    if (MatrixD[j][k] > MatrixD[j][i] + MatrixD[i][k])
                    {
                        MatrixD[j][k] = MatrixD[j][i] + MatrixD[i][k];
                        MatrixS[j][k] = MatrixS[j][i];
                    }
                }
            }
        }
    }
    cout << "Matrix D:" << endl;

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++) 
        {
            cout << setw(4) << MatrixD[i][j];
        }
        cout << endl;
    }
    cout << "Matrix P:" << endl;

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++) 
        {
            cout << setw(4) << MatrixS[i][j];
        }
        cout << endl;
    }
    cout << endl;
}