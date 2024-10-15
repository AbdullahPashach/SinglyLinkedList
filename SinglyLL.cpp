# include <iostream>
using namespace std;
template<typename T>
class Node
{
public:
	T info;
	Node<T>* next;
	Node()
	{
		next = nullptr;
	}
	Node(T value)
	{
		info = value;
		next = nullptr;
	}
};
template<typename T>
class LinkList
{
	Node<T>* head;
public:
	LinkList()
	{
		head = nullptr;
	}
	void insertAtHead(T value)
	{
		Node<T>* temp = new Node<T>(value);
		temp->next = head;
		head = temp;
	}
	void insertAtTail(T value)
	{
		Node<T>* temp = head;
		if (!head)
		{
			head = new Node<T>(value);
			return;
		}
		while (temp->next != nullptr)
		{
			temp = temp->next;
		}
		temp->next = new Node<T>(value);
	}
	void insertBefore(T key, T value)
	{
		if (!head)
		{
			return;
		}
		if (head->info == key)
		{
			insertAtHead(value);
		}
		Node<T>* prev = nullptr;
		Node<T>* curr = head;
		while (curr != nullptr && curr->info != key)
		{
			prev = curr;
			curr = curr->next;
		}
		if (curr)
		{
			Node<T>* newNode = new Node<T>(value);
			prev->next = newNode;
			newNode->next = curr;
		}
	}
	void insertAfter(T key, T value)
	{
		if (!head)
		{
			head = new Node<T>(value);
		}
		else
		{
			Node<T>* temp = head;
			while (temp != nullptr && temp->info != key)
			{
				temp = temp->next;
			}
			if (temp != nullptr)
			{
				Node<T>* newNode = new Node<T>(value);
				newNode->next = temp->next;
				temp->next = newNode;
			}
		}
	}
	void removeAtHead()
	{
		if (!head)
		{
			return;
		}
		Node<T>* temp = head;
		head = head->next;
		delete temp;
		temp = nullptr;
	}
	void removeAtTail()
	{
		if (!head)
		{
			return;
		}
		Node<T>* curr = head;
		Node<T>* prev = nullptr;
		while (curr->next != nullptr)
		{
			prev = curr;
			curr = curr->next;
		}
		if (prev)
		{
			prev->next = nullptr;
		}
		else
		{
			head = nullptr;
		}
		delete curr;
		curr = nullptr;
	}
	void show()
	{
		Node<T>* temp = head;
		while (temp != nullptr)
		{
			cout << temp->info << " ";
			temp = temp->next;
		}
	}
	void removeAfter(T key)
	{
		if (!head)
		{
			return;
		}
		Node<T>* curr = head;
		while (curr != nullptr && curr->info != key)
		{
			curr = curr->next;
		}
		if (curr != nullptr && curr->next != nullptr)
		{
			Node<T>* temp = curr->next;
			if (temp->next == nullptr)
			{
				curr->next = nullptr;
			}
			else
			{
				curr->next = temp->next;
			}
			delete temp;
			temp = nullptr;
		}
	}
	void removeBefore(T key)
	{
		if (!head)
		{
			return;
		}
		Node<T>* befPrev = nullptr;
		Node<T>* prev = nullptr;
		Node<T>* curr = head;
		while (curr != nullptr && curr->info != key)
		{
			befPrev = prev;
			prev = curr;
			curr = curr->next;
		}
		if (curr != nullptr && prev != nullptr && befPrev != nullptr)
		{
			befPrev->next = prev->next;
		}
		else
		{
			head = head->next;
		}
		delete prev;
		prev = nullptr;
	}

};
int main()
{
	LinkList<int> l1;
	/*l1.insertAtHead(6);
	l1.insertAtHead(8);
	l1.insertAtHead(10);
	l1.insertAtHead(34);
	l1.insertAtTail(12);
	l1.insertBefore(6,12);
	l1.insertAfter(34,56);*/
	l1.insertAtHead(24);
	l1.insertAtHead(35);
	l1.insertAtHead(12);
	l1.insertAtHead(16);
	l1.removeBefore(35);
	//	l1.insertAtTail(35);
		//l1.removeAtTail();
	l1.show();
}
