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
	/* The Method Append will add the elements at the End of the Linked List */
	void Append(int data)
	{
		Node *NewNode = new Node(data);
		Node* temp;

		/* check if the head is pointing to Null 
		* if Head is pointing to Null then point the head to the First Node of Linked List
		*/
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
	/* The Method Push is used to add the elements to the start of the Linked List*/
	void Push(int data)
	{
		Node* NewNode = new Node(data);
		 
		if (this->head == nullptr)
		{
			head = NewNode; // If head is Null Make New Node as Head,
		}
		else
		{
			NewNode->next = head; //If Head is not Null then Change the Head to New Node
			head = NewNode;
		}
	}
	/* The Method InsertAfter is used to insert New Node after a Node with the given NodeData*/
	void InsertAfter(int NodeData,int data)
	{
		Node *prevNode, *nextNode , *NewNode = new Node(data);
		prevNode = nextNode = this->head;
		if (this->head == nullptr)
		{
			cout << "This Function Cannot be Used when Given List is Empty" << endl;
			return;
		}
		else
		{
			while (prevNode != nullptr)
			{
				if (prevNode->data == NodeData)
				{
					nextNode = prevNode->next;
					prevNode->next = NewNode;
					NewNode->next = nextNode;
					return;
				}
				else
				{
					prevNode = prevNode->next;
				}

			}
			if (prevNode == nullptr)
			{
				cout << "Given Data was not found in the Linked List to Insert New Node" << endl;
			}

		}
		return;
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
	L1.InsertAfter(4, 9);
	L1.Append(3);
	L1.Append(4);
	L1.Push(10);
	L1.Push(12);
	L1.InsertAfter(10, 8);
	L1.InsertAfter(12, 7);
	L1.InsertAfter(4, 9);
	L1.InsertAfter(14, 11);
	L1.Display();
	return 1;
}

