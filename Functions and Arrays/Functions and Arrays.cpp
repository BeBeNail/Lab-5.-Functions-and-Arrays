#include <iostream>
#include <clocale>

using namespace std;

int restore_2d_array(int rows, int columns, int flat_array[])
{
    int array_2d[2][3] {};
    int s;
    
    for (int i = 0; i < rows * columns; i += columns) // номер элемента строки
        for (int j = rows * columns; j < rows * columns * 2; j++) // номер элемента столбца
        {
            if (flat_array[i] == flat_array[j])
            {
                s = (j - rows * columns) % rows; // номер строки
                for (int z = 0; z < columns; z++) // номер элемента строки 
                    array_2d[s][z] = flat_array[z + i]; // заполняем строку 
            }
        }

    cout << "Исходный массив: " << endl;
    for (int i = 0; i < rows; i++) // выводим двумерный массив 
    {
        for (int j = 0; j < columns; j++)
            cout << array_2d[i][j] << ' ';
        cout << endl;
    }
        
    return 0;
}

void main()
{
    setlocale(LC_ALL, "Russian");
    const int rows = 2, columns = 3; // переменные, отвечающие за количество строк и столбцов в исходном массиве

    int flat_array[rows * columns * 2] = {1, 2, 3, 4, 5, 6, 1, 4, 3, 6, 2, 5}; 
    restore_2d_array(rows, columns, flat_array);
}






