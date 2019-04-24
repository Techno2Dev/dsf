#include<iostream>
using namespace std;
struct node
{
	node *left;
	node *right;
	int data;
};

class btree
{
	node *root,*nn,*temp,*parent;
	public:
		btree()
		{
			root = NULL;
		}
		void create();
		void display();
		void find();
		void insert(node*,node*);
		void inorder(node*);
		void longestpath();
		int depth(node*);
		void leaf();
		void display_leaves(node *temp);
		node* copy(node *first);
		void copytree();
};

void btree::create()
{
	nn=new node;
	nn->left=NULL;
	nn->right=NULL;
	cout<<"Enter the element"<<endl;
	cin>>nn->data;
	if(root==NULL)
		root=nn;
	else
		insert(root,nn);
}

void btree::insert(node *root,node *nn)
{
	char ch;
	cout<<"Where to insert left/right of "<<root->data<<":";
	cin>>ch;
	if(ch=='r' || ch=='R')
	{
		if(root->right==NULL)
		{
			root->right=nn;
		}
		else
		{
			insert(root->right,nn);
		}
	}
	else
	{
		if(root->left==NULL)
		{
			root->left=nn;

		}
		else
		{
			insert(root->left,nn);
		}
	}	
}

void btree::display()
{
	if(root==NULL)
	{
		cout<<"Tree is not created..."<<endl;
	}
	else
	{
		cout<<"The tree is ";
		inorder(root);
	}
}

void btree::inorder(node *ptr)
{
	if(ptr!=NULL)
	{
		inorder(ptr->left);
		cout<<"  "<<ptr->data<<"  ";
		inorder(ptr->right);
	}
}

void btree::longestpath()
{
	if(root==NULL)
	{
		cout<<"Tree is empty.."<<endl;
	}
	else
	{
		int ldepth=depth(root);
		int rdepth=depth(root);
		if(ldepth>rdepth)
			cout<<"The depth of tree is = "<<ldepth<<endl;
		else
			cout<<"The depth of tree is = "<<rdepth<<endl;
	}
}

int btree::depth(node *root)
{
	if(root==NULL)
		return 0;
	else
	{
		int ldepth=depth(root->left);
		int rdepth=depth(root->right);
		if(ldepth>rdepth)
			return (ldepth+1);
		else
			return (rdepth+1);
	} 
}

void btree::leaf()
{
	display_leaves(root);
	
}

void btree::display_leaves(node *temp)
{
	if(root==NULL)
	{
		cout<<"Tree is not created..."<<endl;
	}
	if(temp!=NULL)
	{
		if((temp->left==NULL)&&(temp->right==NULL))
			cout<<"   "<<temp->data;
		else
		{
			display_leaves(temp->left);
			display_leaves(temp->right);
		}
	}
}

void btree::copytree()
{
	node *second;
	cout<<"The copied tree is = ";
	second=copy(root);
	inorder(second);

}

node *btree::copy(node *first)
{
	node *nn;
	if(first!=NULL)
	{
		nn=new node;
		if(nn==NULL)
		{
			cout<<"\nMemory not allocated..."<<endl;
		}
		nn->left=copy(first->left);
		nn->right=copy(first->right);
		nn->data=first->data;
		return (nn);
	}
	else
		return NULL;
}

int main()
{
	btree b;
	int ch,ans,ch1;
	do
	{
		cout<<"\n 1.Insert \n 2.Display \n 3.Display depth \n 4.Display leafnode \n 5.Create Copy";
		cout<<"\nEnter your choice: ";
		cin>>ch;
		switch(ch)
		{
			case 1: do
				{
					b.create();
					cout<<"Do you want to add more element?(press 1): "<<endl;
					cin>>ans;
				}while(ans==1);
				break;
			case 2:
				cout<<"inorder"<<endl;
				b.display();
				break;
			case 3:
				b.longestpath();
				break;
			case 4:
				b.leaf();
				break;
			case 5:
				b.copytree();
				break;
		}
		cout<<"\nDo you want to continue press 1: ";
		cin>>ch1;
	}while(ch1==1);
	return 0;
}
