#include<iostream>
#include <malloc.h>
#include<string.h>

using namespace std;

struct tree
{
	char data;
	struct tree *left,*right;

	tree(char c)
	{
		data=c;
		left=right=NULL;
	}
};

class stack
{
	tree *stk[20];
	int top;
	public:
		stack()
		{
			top=-1;
		}
		int isempty();
		int isfull();
		void push(tree*);
		tree* pop();
			

};

int stack::isempty()
{
	if (top==-1)
		return 1;
	return 0;
}

int stack::isfull()
{
	if(top==19)
		return 1;
	return 0;
}

void stack::push(tree *d)
{
	if (!isfull())
		stk[++top]=d;
}

tree* stack::pop()
{
	tree *temp=stk[top];
	top--;
	return temp;
}

tree *create()
{
	char estr[25];
	int i=0;
	stack s;
	cout<<"Enter the postfix expression "<<endl;
	cin>>estr;
	while(estr[i]!='\0')
	{
		tree *node=new tree(estr[i]);
		if(isalnum(estr[i]))
			s.push(node);
		else
		{
			node->right=s.pop();
			node->left=s.pop();
			s.push(node);
		}
		i++;
	}
	return s.pop();
}

void intrav(tree *root)
{
	if(root!=NULL)
	{
		intrav(root->left);
		cout<<root->data;
		intrav(root->right);

	}
}
void pretrav(tree *root)
{
	if(root!=NULL)
	{
		cout<<root->data;
		pretrav(root->left);
		pretrav(root->right);
	}
}
void posttrav(tree *root)
{
	if(root!=NULL)
	{
		posttrav(root->left);
		posttrav(root->right);
		cout<<root->data;
	}
}

void nonpre(tree *root)
{
	stack s;
	while(!s.isempty()||root!=NULL)
	{
		while(root!=NULL)
		{
			cout<<root->data;
			s.push(root);
			root=root->left;
		}
		root=s.pop();
		root=root->right;
	}
}

void nonrin(tree *root)
{
	stack s;
	while(!s.isempty()||root!=NULL)	
	{
		while(root!=NULL)
		{
			s.push(root);
			root=root->left;
		}
		root=s.pop();
		cout<<root->data;
		root=root->right;
	}
}

void nonpost(tree *root)
{
	stack s;
	int i=0;
	char str[20];
	while(!s.isempty()||root!=NULL)
	{
		while(root!=NULL)
		{
			str[i++]=root->data;
			s.push(root);
			root=root->right;
		}
		root=s.pop();
		root=root->left;
	}
	while(--i>=0)
	cout<<str[i];
}

int main()
{
	struct tree *root=NULL;
	char ch='y';
	int choice;
	root=create();
	do
	{
		cout<<"\n1. Preorder\n2. Inorder\n3. Postorder";
		cout<<"\nEnter your choice: ";
		cin>>choice;
		switch(choice)
		{
			case 1:
				cout<<"\n Recursive preorder: ";
				pretrav(root);
				cout<<"\n Non Recursive peorder: ";
				nonpre(root);
			break;
			
			case 2:
				cout<<"\nRecursive inorder: ";
				intrav(root);
				cout<<"\nNon Recursive inorder: ";
				nonrin(root);
			break;

			case 3:
				cout<<"\nRecursive postorder: ";
				posttrav(root);
				cout<<"\nNon Recursive postorder: ";
				nonpost(root);
				break;
		}
		cout<<"\n\nDo u want to continue(y/n): ";
		cin>>ch;
	}while(ch=='y'||ch=='Y');
	return 1;
}

