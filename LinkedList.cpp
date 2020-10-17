#include <iostream>
using namespace std;

class Node
{
public:
	int data = NULL;
	Node* next = nullptr;
	Node(int data)
	{
		this->data = data;
		this->next = nullptr;
    }
};

class Linkedlist
{
private:
	Node* head;
public:
	Linkedlist()
	{
		this->head = nullptr;
	}
	void Push(int data)
	{
		Node *NewNode = new Node(data);
		Node* temp;
		if (this->head == nullptr)
		{ 
			this->head = NewNode;
		}
		else
		{
			temp = this->head;
			while (temp->next != nullptr)
			{
				temp = temp->next;
			}

			temp->next = NewNode;
		}
	}
	void Display()
	{
		Node* temp = this->head;
		while (temp != nullptr)
		{
			cout << temp->data << "->";
			temp = temp->next;
		}
	}
};

int main()
{
	Linkedlist L1;
	L1.Push(3);
	L1.Push(4);
	L1.Display();
	return 1;
}

