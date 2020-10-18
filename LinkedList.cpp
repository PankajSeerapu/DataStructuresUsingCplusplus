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
/* The Method DeleteNode is used to Delete a Node with Given Data for a Linked List Object*/
	void DeleteNode(int data)
	{
		Node* currNode = this->head;
		Node* prevNode = nullptr;
		if (this->head != nullptr)
		{
			if (this->head->data == data) //check if Node to be deleted is the Head Node
			{
				head = head->next;
				free(currNode);
				return;
			}
			else
			{
				while (currNode->next != nullptr && currNode->next->data != data)
				{
					currNode = currNode->next;  //Run the Loop Untill the Data is Found till the end of List
				}
				if (currNode->next != nullptr)
				{
					prevNode = currNode;
					currNode = currNode->next;
					prevNode->next = prevNode->next->next;
					free(currNode);
				}
				else
				{
					cout << "Given data is not found in the Linked List for Deletion" << endl;
				}
			}
		}
		else
		{
			cout << "This Function cannot be used on a Empty Linked List" << endl;
		}

	}
	/* Method DeleteNodeN is used to Delete a Node at the Nth Position*/
	void DeleteNodeN(int Position)
	{
		Node* currNode = this->head;
		Node* prevNode = nullptr;
		if (this->head != nullptr) //Check if the Linked List is Empty
		{
			if (Position == 0)  //check if the Position to be deleted is Head
			{
				this->head = currNode->next;
				free(currNode);
				return;
			}
			else
			{
				while (currNode != nullptr && Position != 0)
				{
					prevNode = currNode;        // Run the Loop Until the Position is Found
					currNode = currNode->next;  // OR till the end Linked List 
					Position--;
				}
				if (currNode != nullptr && Position == 0)
				{
					prevNode->next = currNode->next; 
					free(currNode);
				}
				else
				{
					cout << "Node with that Position is not present in the Linked List" << endl;
				}
			}

		}
		else
		{
			cout << "This Function cannot be used on a empty Linked List" << endl;
		}
		
	}

/* The Method Display can be used to Display the created Linked List*/
	void Display()
	{
		Node* temp = this->head;
		while (temp != nullptr)
		{
			cout << temp->data << "->";
			temp = temp->next;
		}
		cout << endl;
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
	L1.DeleteNode(12);
	L1.DeleteNode(9);
	L1.DeleteNode(8);
	L1.DeleteNode(18);
	L1.Display();
	L1.Push(17);
	L1.Push(19);
	L1.Display();
	L1.DeleteNodeN(0);
	L1.DeleteNodeN(4);
	L1.DeleteNodeN(5);
	L1.DeleteNodeN(2);
	L1.Display();
	return 1;
}

