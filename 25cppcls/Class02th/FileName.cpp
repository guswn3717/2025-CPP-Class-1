#include<iostream>

using namespace std;

template<typename T>
class DoubleLinkedList
{
private:
	struct  Node
	{
		T data;
		Node* previous;
		Node* next;
	};

	Node* head;
	Node* tail;

	int size;
public:

	DoubleLinkedList()
	{
		head = nullptr;
		tail = nullptr;
		size = 0;
	}

	void push_front(T data)
	{

	}
};

int main()
{
#pragma region 

#pragma endregion

	return 0;
}