#include <iostream>

#define SIZE 10

using namespace std;

template<typename T>
class AdjacencyMatrix
{
private:
    int size; // ������ ����
    T vertex[SIZE]; // ������ ����
    int matrix[SIZE][SIZE]; // ���� ���

public:
    AdjacencyMatrix()
    {
        size = 0;

        for (int i = 0; i < SIZE; i++)
        {
            vertex[i] = NULL;

            for (int j = 0; j < SIZE; j++)
            {
                matrix[i][j] = 0;
            }
        }
    }

    void push(T data)
    {
        if (size >= SIZE)
        {
            cout << "Adjacency Matrix Overflow" << endl;
        }
        else
        {
            vertex[size++] = data;
        }
    }

    void edge(int i, int j)
    {
        if (size <= 0)
        {
            cout << "Ajancency Matrix is Empty" << endl;
        }
        else if (i >= size || j >= size)
        {
            cout << "Index Out of Range" << endl;
        }
        else
        {
            matrix[i][j] = 1;
            matrix[j][i] = 1;
        }
    }
};

int main()
{


    return 0;
}




//���� ���̽ÿ� ���� ���� �츮�ʽÿ�!!!!!!
