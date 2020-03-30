//dictionary

#include <iostream>
#include <stack>
#include <stdlib.h>
#include <string.h>
using namespace std;

class Node{
public:
	string word;
	Node* right;
	Node* left;
	string meaning;
	Node()
	{
		word = "";
		meaning = "";
		right=NULL;
		left=NULL;
	}
};

class Dictionary{
private:
	Node* root;
	int totalNodes;
public:
	Dictionary(){
		root=NULL;
	}
	void create();
	void insert();
	void inorder(Node* );
	void nonRecInorder();
	Node* getRoot(){
		return root;
	}
	Node* search(string);
	Node* deleteNode(Node*,string);
	void update(string);
};

void Dictionary::create(){
	if(root==NULL){
		root = new Node();
		cout<<"\nEnter word : ";
		cin>>root->word;
		cout<<"\nEnter meaning : ";
		cin>>root->meaning;
		return;
	}
}

void Dictionary::insert(){
	char choice;
	Node* temp,*curr;
	char cont;
	do{
		if(root==NULL)
			create();
		temp = root;
		curr = new Node;
		cout<<"\nWord : ";
		bool flag=false;
		cin>>curr->word;
		cout<<"\nMeaning : ";
		cin>>curr->meaning;
		do{
			if(temp->word > curr->word)
				choice = 'l';
			else if(temp->word < curr->word)
				choice = 'r';
			else{
				cout<<"\nSame value exists in tree."<<endl;
				cout<<"\nWord : ";
				cin>>curr->word;
				continue;
			}
			switch(choice){
				case 'l':
					if(temp->left!=NULL)
						temp = temp -> left;
					else{
						temp -> left = curr;
						flag=true;
					}
					break;
				case 'r':
					if(temp->right!=NULL)
						temp = temp -> right;
					else{
						temp -> right = curr;
						flag=true;
					}
					break;
			}
		}while(flag!=true);
		cout<<"\n Do you want to Continue ?(y/n) ";
		cin>>cont;
	}while(cont=='y');
}

void Dictionary::inorder(Node* temp){
	if(temp==NULL)
		return;
	inorder(temp->left);
	cout<<temp->word<<" "<<"\n";
	inorder(temp->right);
}
void Dictionary::nonRecInorder(){
	stack<Node *> s;
    Node *curr = root;
    if(root == NULL){
    	cout<<"\nTree is empty";
    	return;
    }
    while (curr != NULL || !s.empty())
    {
	    while (curr !=  NULL)
        {
            s.push(curr);
            curr = curr->left;
        }
        curr = s.top();
        s.pop();
        cout << curr->word << " "<<"\n";
        curr = curr->right;
    }
}

Node* Dictionary::search(string word){
	Node *temp=root;
	char choice;

	if(temp==NULL){
		cout<<"\nTree is not created.";
		return NULL;
	}
	do{
		if(temp->word > word)
			choice = 'l';
		else if(temp->word <word)
			choice = 'r';
		else{
			//cout<<"Meaning: "<<temp->meaning;
			return temp;
		}
		switch(choice){
			case 'l':
				if(temp->left!=NULL)
					temp = temp -> left;
				else{
					cout<<"\nNot Found\n";
					return NULL;
				}
				break;
			case 'r':
				if(temp->right!=NULL)
					temp = temp -> right;
				else{
					cout<<"\nNot Found";
					return NULL;
				}
				break;
		}
	}while(1);
}


Node * minValueNode(Node* node)
{
    Node* curr = node;
    while (curr->left != NULL)
        curr = curr->left;
    return curr;
}

Node* Dictionary :: deleteNode(Node* root, string key)
{

    if (root == NULL)
    		return root;

    if (key < root->word)
        root->left = deleteNode(root->left, key);
    else if (key > root->word)
        root->right = deleteNode(root->right, key);

    else
    {
        if (root->left == NULL)
        {
            Node *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            Node *temp = root->left;
            free(root);
            return temp;
        }
  	Node* temp = minValueNode(root->right);
        root->word = temp->word;
        root->right = deleteNode(root->right, temp->word);
    }
    return root;
}
void Dictionary::update(string word) {
	string newValue;
	Node* curr = search(word);
	cout<<"\nEnter new meaning: ";
	cin>>newValue;
	curr->meaning = newValue;
}

int main()
{
	Dictionary d1;
	int choice,ch;
	Node* temp;
	string value;
	do{
		cout<<"\n\tDictionary\n";
		cout<<"\n#1 Create";
		cout<<"\n#2 Insert";
		cout<<"\n#3 Inorder Traversal";
		cout<<"\n#4 Search a word";
		cout<<"\n#5 Update dictionary";
		cout<<"\n#6 Delete a word";
		cout<<"\n#7 Exit";
		cout<<"\nEnter your choice: ";
		cin>>choice;
		switch(choice){
			case 1:
				d1.create();
				break;
			case 2:
				d1.insert();
				break;
			case 3:
				cout<<"\n\t Inorder Traversal\n";
				cout<<"\n1. Recursive\n2. Non-Recursive\n";
				cout<<"\nEnter your choice : ";
				cin>>ch;
				switch(ch){
					case 1:
						d1.inorder(d1.getRoot());
						break;
					case 2:
						d1.nonRecInorder();
						break;
					default:
						cout<<"\nEnter a valid choice : ";
				}
				break;

			case 4:
				cout<<"\nEnter the value to search : ";
				cin>>value;
				temp=d1.search(value);
				if(temp!=NULL)
					cout<<"Meaning : "<<"\n"<<temp->meaning;
				break;
			case 5:
				cout<<"\nEnter word : ";
				cin>>value;
				d1.update(value);

				break;
			case 6:
				cout<<"\nEnter word to delete : ";
				cin>>value;
				d1.deleteNode(d1.getRoot(),value);
				break;

			case 7:
				break;
			}
	}while(choice!=7);
	return 0;
}
