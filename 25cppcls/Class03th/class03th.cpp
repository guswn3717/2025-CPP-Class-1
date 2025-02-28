#include<iostream>

using namespace std;

template <typename T>
class CircleLinkedList
{
private:
	struct Node
	{
		T data;
		Node* next;
	};

	int size;
	Node* head;

public:
	CircleLinkedList()
	{
		size = 0;
		head = nullptr;
	}

	void pop_fornt()
	{
		if (head == nullptr)
		{
			cout << "Linked List is Empty" << endl;
		}

		Node* deleteNode = head->next;

		if (head == head->next)
		{
			head = nullptr;
		}
		else
		{
			head->next = deleteNode->next;
		}

		delete deleteNode;

		size--;
	}

	void pop_back()
	{
		if (head == nullptr)
		{
			cout << "Linked List is Empty" << endl;
		}

		Node* currentNode = head->next;
		Node* previousNode = head;

		if (head == head->next)
		{
			delete head;

			head = nullptr;
		}
		else
		{
			while (currentNode != head)
			{
				previousNode = currentNode;

				currentNode = currentNode->next;
			}

			previousNode->next = head->next;

			delete head;

			head = previousNode;
		}

		size--;
	}

	void push_fornt(T data)
	{
		Node* newNode = new Node;

		newNode->data = data;

		if (head == nullptr)
		{
			head = newNode;

			head->next = head;
		}
		else
		{
			newNode->next = head->next;
			head->next = newNode;
		}

		size++;
	}

	void push_back(T data)
	{
		Node* newNode = new Node;

		newNode->data = data;

		if (head == nullptr)
		{
			head = new Node;

			newNode->next = head;
		}
		else
		{
			newNode->next = head->next;

			head->next = newNode;
			head = newNode;
		}

		size++;
	}

	const int& Size()
	{
		return size;
	}

	~CircleLinkedList()
	{
		while(head != nullptr)
		{
			pop_fornt();
		}
	}

	void show()
	{
		if (head != nullptr)
		{
			Node* currentNode = head->next;

			for (int i = 0; i < size; i++)
			{
				cout << currentNode->data << " ";

				currentNode = currentNode->next;
			}
		}
	}
};

int main()
{
	CircleLinkedList<int> circleLinkedList;

	circleLinkedList.push_back(10);
	circleLinkedList.push_back(20);
	circleLinkedList.push_back(30);

	circleLinkedList.pop_fornt();

	circleLinkedList.push_fornt(5);
	circleLinkedList.push_fornt(10);

	circleLinkedList.pop_back();

	circleLinkedList.show();

	return 0;
}