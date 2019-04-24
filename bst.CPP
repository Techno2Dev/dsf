#include<iostream>
using namespace std;

typedef struct node
{
	int data;
	struct node *left,*right;
}root;

class tree
{
	root *nw;
	int key;

	public:
		void search(root *,int);
		void insert(root *,root *);
		void inorder(root *);
		void preorder(root *);
		void postorder(root *);
		root *mirror(root *);
		void level(root *);
		root *delt(root *,int);
};

root *tree::mirror(root *tree)
{
	root *temp;
	if(tree!=NULL)
	{
		temp=tree->left;
		tree->left=tree->right;
		tree->right=temp;

		if(tree->left!=NULL)
			mirror(tree->left);
		if(tree->right!=NULL)
			mirror(tree->right);
	}
	return tree;
}

void tree:: level(root *tree)
{
	static int front=0,rear=0;
	static root *queue[20];
	if(front<=rear)
	{
		cout<<" "<<tree->data;
		if(tree->left!=NULL)
			queue[rear++]=tree->left;
		if(tree->right!=NULL)
			queue[rear++]=tree->right;
		tree=queue[front++];
		level(tree);
	}

}


void tree:: search(root *root1,int key)
{
	if(root1!=NULL)
	{
		if(key==root1->data)
		{
			cout<<"key found: "<<key<<endl;
		}
		else if(key>root1->data)
		{
			search(root1->right,key);
		}
		else
		{
			search(root1->left,key);
		}
	}
	else
		cout<<"Key not found..."<<endl;
}

void tree:: insert(root *root1,root *nw1)
{
	if(nw1->data>=root1->data)
	{
		if(root1->right!=NULL)
		{
			insert(root1->right,nw1);
		}
		else
			root1->right=nw1;
	}
	else
	{
		if(root1->left!=NULL)
		{
			insert(root1->left,nw1);
		}
		else
			root1->left=nw1;
	}
}

void tree:: inorder(root *nw1)
{
	if(nw1!=NULL)
	{
		inorder(nw1->left);
		cout<<"\t"<<nw1->data;
		inorder(nw1->right);
	}
}

void tree:: preorder(root *nw1)
{
	if(nw1!=NULL)
	{
		cout<<"\t"<<nw1->data;
		preorder(nw1->left);
		preorder(nw1->right);
	}
}

void tree:: postorder(root *nw1)
{
	if(nw1!=NULL)
	{
		postorder(nw1->left);
		postorder(nw1->right);
		cout<<"\t"<<nw1->data;	
	}
}

int main()
{
	root *nw1,*root1=NULL,*nw,*nn;
	tree t;
	int data1,key,c,c1,ch;
	do
	{
		cout<<"\n1.Insert data\n2.Search data\n3.Inorder traversal\n4.Preorder traversal\n5.Postorder traversal\n6.Mirror image\n7.level wise tree\n8.delete node"<<endl;
		cout<<"\nEnter your choice: ";
		cin>>ch;
		switch(ch)
		{
			case 1:
				do
				{
					nw1=new  root();
					cout<<"\nEnter the data:";
					cin>>data1;
					nw1->data=data1;
					nw1->right=NULL;
					nw1->left=NULL;
					if(root1==NULL)
					{
						root1=nw1;
					}
					else
					{
						t.insert(root1,nw1);
					}
					cout<<"\nAdd more Data? if yes then press 1:";
					cin>>c;
				}while(c==1);
				break;
			case 2:
				cout<<"\nEnter key:";
				cin>>key;
				t.search(root1,key);
				break;
			case 3:
				t.inorder(root1);
				break;
			case 4:
				t.preorder(root1);
				break;
			case 5:
				t.postorder(root1);
				break;
			case 6:
				t.inorder(t.mirror(root1));
				break;
			case 7:
				t.level(root1);
				break;
			case 8:
				
				break;				
		}
		cout<<"\nDo you want to continue if yes then press 1:";
		cin>>c1;
	}while(c1==1);
	return 0;
}

