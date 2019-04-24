#include<iostream>
#define MAX_NODE 50
using namespace std;

struct node
{
	int vertex;
	node *next;
};

class graph
{
	public:
		node *adj[MAX_NODE];
		int totnodes;
		int queue[MAX_NODE],f,r;
		graph()
		{
			f=-1;
			r=-1;
		}
		void q_insert(int item)
		{
			r=r+1;
			queue[r]=item;
			if(f==-1)
			f=0;
					
		}
		int q_delete()
		{
			int delitem=queue[f];
			if(f==r)
			f=r=-1;
			else
			f=f+1;
			return(delitem);		
		}
		int is_q_empty()
		{
			if(f==-1)
			return(1);
			else
			return(0);
		}
		void creategraph()
		{
			node *new1,*last;
			int neighbours,neighbour_value;
			cout<<"\n\n-----graph creation------\n\n";
			cout<<"enter total nodes in graph";
			cin>>totnodes;
			for(int i=1;i<=totnodes;i++)
			{
				last=NULL;
				cout<<"\nenter no. of nodes in the adujuscemcy list of node"<<i<<"\n";
				cout<<"-->that is total neighbours of "<<i<<":";
				cin>>neighbours;
				for(int j=1;j<=neighbours;j++)
				{
					cout<<"enter neighbour#"<<j<<":";
					cin>>neighbour_value;
					new1=new node;
					new1->vertex=neighbour_value;
					new1->next=NULL;
					if(adj[i]==NULL)
					adj[i]=last=new1;
					else
					{
						last->next=new1;
						last=new1;
											
					}
				}
			}			
		}	
		void BFS_traversal()
		{
			node *tmp;
			int N,v,start_node,status[MAX_NODE];
			int ready=1,wait=2,processed=3;
			cout<<"enter starting node";		
			cin>>start_node;

			for(int i=1;i<=totnodes;i++)
			{
				status[i]=ready;				
			}
			q_insert(start_node);
			status[start_node]=wait;
			while(is_q_empty()!=1)
			{
				N=q_delete();
				status[N]=processed;
				cout<<"    "<<N;
				tmp=adj[N];
				while(tmp!=NULL)
				{
					v = tmp->vertex;
					if(status[v]==ready)
        				{
						q_insert(v);
						status[v]=wait;
	    				}
					tmp=tmp->next;
				}
    			}
		}	
};

int main()
{
	graph g=graph();
	g.creategraph();//Create Graph
	cout<<"\n===BFS traversal is as under===\n";
	g.BFS_traversal();//BFS Traversal

}

