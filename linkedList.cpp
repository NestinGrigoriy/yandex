#include <iostream>
using namespace std;
struct node {
	int value;
	struct node* link;
};
class linkedList {
private:
	node head;
	node tail;
public:
	linkedList() {
		head.value = NULL;
		tail.value = NULL;
		head.link = &tail;
		tail.link = nullptr;
	}
	node* getH() {
		return &head;
	}
	int& operator[](int number) {
		node* checkNode = &head;
		int count = 0;
		while (count!=number) {
			checkNode = checkNode->link;
			count++;
		}
		return checkNode->value;
	}
	bool operator==(linkedList list) {
		node* checkNode = &head;
		node* checkNode1 = list.getH();
		while (checkNode->link != nullptr) {
			if (checkNode->value != checkNode1->value) {
				return false;
			}
			checkNode = checkNode->link;
			checkNode1 = checkNode1->link;
		}
		return true;
	}
	void operator=(linkedList list) {
		node* checkNode = &head;
		node* checkNode1 = list.getH();
		while (checkNode1->link != nullptr) {
			if (checkNode->link == &tail) {
				node* pNode = new node;
				pNode->value = checkNode1->value;
				pNode->link = &tail;
				checkNode->link = pNode;
			}
			checkNode->value = checkNode1->value;
			checkNode = checkNode->link;
			checkNode1 = checkNode1->link;
		}
		checkNode->value = checkNode1->value;
		checkNode->link = nullptr;
	}
	void operator*(int number) {
		node* checkNode = &head;
		while (checkNode->link != nullptr) {
			checkNode->value = checkNode->value * number;
			checkNode = checkNode->link;
		}
		checkNode->value = checkNode->value * number;
	}
	void printList() {
		node* checkNode = &head;
		while (checkNode->link != nullptr) {
			cout << checkNode->value << " ";
			checkNode = checkNode->link;
		}
		cout << checkNode->value;
	}
	void Append(int number){
		if (head.value == NULL) {
			head.value = number;
			head.link = &tail;
			return;
		}
		if (tail.value == NULL) {
			if (head.value <= number) {
				tail.value = number;
			}
			else {
				int pValue = head.value;
				head.value = number;
				tail.value = pValue;
			}
			return;
		}
		node* checkNode1 = &head;
		node* checkNode2 = &tail;
		node* pNode = new node;
		while (checkNode1!=checkNode2) {
			if (number <= checkNode1->value) {
				pNode->value = checkNode1->value;
				pNode->link = checkNode1->link;
				checkNode1->value = number;
				checkNode1->link = pNode;
				break;
			}
			if (checkNode1->link == checkNode2) {
				if (checkNode2->value > number) {
					checkNode1->link = pNode;
					pNode->value = number;
					pNode->link = checkNode2;
					break;
				}
				else {
					pNode->value = checkNode2->value;
					pNode->link = checkNode2;
					checkNode2->value = number;
					checkNode1->link = pNode;
					break;
				}
			}
			checkNode1 = checkNode1->link;

		}
	}	
};
int main() {
	linkedList list;
	linkedList list1;
	list1.Append(5);
	list1.Append(6);
	list1.Append(10);
	list1.Append(55);
	list = list1;
	list1.printList();
	cout << endl;
	list.printList();
	if (list == list1) {
		cout << "wqewqewqewqewqe";
	}
}