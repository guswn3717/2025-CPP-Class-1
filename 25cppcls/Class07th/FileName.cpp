#include <iostream>

using namespace std;

template<typename T>
class Vector
{
private:
	int size;
	int capacity;

	T* container;

public:
	Vector()
	{
		size = 0;
		capacity = 0;
		container = nullptr;
	}

	void resize(int newSize)
	{
		// 1. capacity�� ���ο� size���� �����մϴ�.
		capacity = newSize;

		// 2. ���ο� ���̳� ������ �����ؼ� ���Ӱ� �������
		//    �޸� ������ ����Ű���� �մϴ�
		T* newContainer = new T[capacity];

		// 3. ���ο� �޸� ������ ���� �ʱ�ȭ�մϴ�
		for (int i = 0; i < capacity; i++)
		{
			newContainer[i] = NULL;
		}

		// 4. ���� �迭�� �ִ� ���� �����ؼ� ���ο� �迭�� �־��ݴϴ�
		for (int i = 0; i < size; i++)
		{
			newContainer[i] = container[i];
		}

		// 5. ���� �迭�� �޸𸮸� �����մϴ�.
		if (container != nullptr)
		{
			delete[] container;
		}

		// 6. ������ �迭�� ����Ű�� ������ ������ ����
		//    ���ο� �迭�� ���� �ּҷ� ����ŵ�ϴ�
		container = newContainer;
	}

	void push_back(T data)
	{
		if (capacity <= 0)
		{
			resize(1);
		}
		else if (size >= capacity)
		{
			resize(capacity * 2);
		}
		
		container[size++] = data;
	}

	void pop_back()
	{
		if (size <= 0)
		{
			cout << "vector is empty" << endl;
		}
		else
		{
			container[--size] = NULL;
		}
	}

	const int& Size()
	{
		return size;
	}

	const T& operator [] (const int& index)
	{
		return container[index];
	}

	~Vector()
	{
		if(container)
	}
};

int main()
{
	Vector<int> vector;

	vector.push_back(10);
	vector.push_back(20);
	vector.push_back(30);
	vector.push_back(40);
	vector.push_back(50);

	for (int i = 0; i < vector.Size(); i++)
	{
		cout << vector[i] << " ";
	}

	return 0;
}