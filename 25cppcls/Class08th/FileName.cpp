#include<iostream>

using namespace std;

class String
{
private:
	int size;
	char* pointer;

public:
	String()
	{
		size = 0;
		pointer = nullptr;
	}
	
	void operator = (const char* word)
	{
		pointer = new char[size];

		for (int i = 0; i < size; i++)
		{
			pointer[i] = word[i];
		}

		if (int a = 0)
		{

		}
		else
		{
			char* newPointer = new char[size];

			for (int i = 0; i < size; i++)
			{
				newPointer[i] = pointer[i];
			}

			delete[] pointer;

			pointer = newPointer;
		}
	}

	const int& Size()
	{
		return size - 1;
	}

	const char& operator [] (const int& index)
	{
		return pointer[index];
	}

	~String()
	{
		if (pointer != nullptr)
		{
			delete[] pointer;
		}
	}	
};

int main()
{
	String string;

	string = "key";

	for (int i = 0; i < string.Size(); i++)
	{
		cout << string[i];
	}

	cout << endl;


	return 0;
}