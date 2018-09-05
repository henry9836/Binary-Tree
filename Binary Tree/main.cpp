
/*

Needs:

Insertion [x]
Deletion  [x]
Searching [x]

*/

#include<iostream>

using namespace std;

class BST
{
	struct node
	{
		int myData;
		node* childLeft;
		node* childRight;
	};

	node* root;

	node* makeEmpty(node* node)
	{
		delete node;
		return NULL;
	}

	node* insert(int x, node* n)
	{
		if (n == NULL)
		{
			n = new node;
			n->myData = x;
			n->childLeft = NULL;
			n->childRight = NULL;
		}
		
		//If value is less than data put on left otherwise put on right

		else if (x < n->myData) 
		{
			n->childLeft = insert(x, n->childLeft);
		}
		else if (x > n->myData)
		{
			n->childRight = insert(x, n->childRight);
		}
		return n;
	}

	node* findMin(node* n)
	{
		if (n == NULL)
		{
			return NULL;
		}
		else if (n->childLeft == NULL)
		{
			return n;
		}
		return findMin(n->childLeft);
	}

	node* _remove(int x, node* n)
	{
		node* temp;
		if (n == NULL) //can't have nulls being deleted now can we?
		{
			return NULL;
		}
		else if (x < n->myData) //go left
		{
			n->childLeft = _remove(x, n->childLeft);
		}
		else if (x > n->myData) //go right
		{
			n->childRight = _remove(x, n->childRight);
		}
		else
		{
			temp = n;
			if (n->childLeft == NULL)
				n = n->childRight;
			else if (n->childRight == NULL)
				n = n->childLeft;
			delete temp;
		}

		return n;
	}

	void inorder(node* n, int output)
	{
		if (n == NULL) 
		{
			return;
		}
		inorder(n->childLeft, output);
		if (output == 1) {
			cout << n->myData << " ";
		}
		inorder(n->childRight, output);
	}

	node* search(node* n, int x)
	{
		node* temp;
		if (n == NULL)
		{
			cout << "Value was not found :(" << endl;
			system("pause");
			return NULL;
		}
		else if (x < n->myData)
		{
			//temp = search(n->childLeft, x);
			//return temp;
			return search(n->childLeft, x);
		}
		else if (x > n->myData)
		{
			//temp = search(n->childRight, x);
			//return temp;
			return search(n->childRight, x);
			
		}
		else
		{
			cout << "Value Found!" << endl;
			system("pause");
			return n;
		}

	}

public:
	BST()
	{
		root = NULL;
	}

	~BST()
	{
		makeEmpty(root);
	}

	void _insert(int x)
	{
		root = insert(x, root);
		inorder(root, 0);
	}

	void _delete(int x)
	{
		root = _remove(x, root);
		inorder(root, 0);
	}

	void _display()
	{
		inorder(root, 1);
		cout << endl;
	}

	void _search(int x)
	{
		search(root, x);
	}
};

int main()
{
	BST tree;
	int c, tmp;

	while (true) {
		system("cls");
		c = 0;
		tmp = 0;
		cout << "Main Menu" << endl;
		cout << "1. Insert in tree" << endl;
		cout << "2. Delete Node in tree" << endl;
		cout << "3. In-order sorted Tree" << endl;
		cout << "4. Search Tree" << endl;
		cout << "99. Exit" << endl;
		cout << "Enter Selection: ";
		cin >> c;
		if (c == 1) {
			cout << "Data to insert: ";
			cin >> tmp;
			tree._insert(tmp);
		}
		if (c == 2) {
			cout << "Data to delete: ";
			cin >> tmp;
			tree._delete(tmp);
		}
		if (c == 3) {
			tree._display();
			system("pause");
		}
		if (c == 4) {
			cout << "Data to search for: ";
			cin >> tmp;
			tree._search(tmp);
			system("pause");
		}
		if (c == 99) {
			break;
		}
	}

	return 0;
}