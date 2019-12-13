#include <stdexcept>
#include <string>
#include <iostream>
using namespace std;
// The Node class is provided to you.
// NOTE: you **MAY** alter this class if you wish
class Node
{
public:
	Node(int value, Node* left, Node* right)
	{
		this->value = value;
		this->left = left;
		this->right = right;
	}
	//It returns an integer by value.
	int getValue() const
	{
		return value;
	}

	Node* getLC() const
	{
		return left;
	}

	Node* getRC() const
	{
		return right;
	}
	void setValue(int value) {
		this->value = value;
	}
	void setLC(Node* left) {
		this->left = left;
	}
	void setRC(Node* right) {
		this->right = right;
	}

private:
	int value;
	Node* left;
	Node* right;
};

class BinaryTreeAdd
{
public:

	//OPTIONAL -- see the description for cpNode in the Notes section
	static Node* cpNode(Node* t) {
		if (t == NULL) {
			return NULL;
		}
		//OPTIONAL -- Implement your deep copy here
	}

	static Node* add(Node *t1, Node *t2)
	{
		while (t1 != NULL && t2 != NULL) {
			if ((t1 != NULL) && (t2 == NULL)) {
				
				return t1;
			}
			else if ((t1== NULL) && (t2 != NULL)) {
				return t2;
			}
			else{
				int temp;
				temp= t1->getValue() + t2->getValue();
				t1->setValue(temp);			
				while (t1->getLC() != NULL|| t2->getLC()!=NULL|| t1->getRC() != NULL || t2->getRC() != NULL)
				{
					add(t1->getLC(), t2->getLC());
					add(t1->getRC(), t2->getRC());
					return t1;
				}
			}
			return 0;	
		}

	}
	void display(Node * node)
	{
		while (node != NULL) {
			cout << node->getValue() << endl;
				display(node->getLC());
			
				display(node->getRC());
			
			return;
		}
	}
};

#ifndef RunTests
int main()
{
	
	Node root1(3, NULL, NULL);
	Node root2(1, NULL, &root1);
	Node root3(3, NULL, NULL);
	Node root4(5, &root2, &root3);

	Node root5(3, NULL, NULL);
	Node root6(6, NULL, &root5);
	Node root7(5, NULL, NULL);
	Node root8(2, &root6, &root7);

	//Node root9(0, NULL, NULL);
	Node *root9 = BinaryTreeAdd::add(&root4, &root8);
	//It seems that member function display() is a non - static member function.
	//You have to call it with using an instance of the class as for example


	BinaryTreeAdd bt;
	bt.display(root9);
	
	return 0;
}
#endif
