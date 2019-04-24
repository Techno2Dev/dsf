#include<iostream>
using namespace std;
int weight[10][10],nodes;
int visited[10];

class Prims
{
	private:
		int i,j,min,k,l,m,total_cost;
	public:
		Prims()
		{
			total_cost=0;
			for(i=0;i<nodes;i++)
			{
				visited[i]=0;
			}
		}
		void prims(int weight[10][10],int nodes);
		void read()
		{
			cout<<"Enter the no of vertices: ";
			cin>>nodes;
			cout<<"Enter the weight of edges: ";
			for(i=1;i<=nodes;i++)
			{
				for(j=1;j<=nodes;j++)
				{
					cin>>weight[i][j];
				}
			}
			min=9999;
			prims(weight,nodes);
		}
};

void Prims::prims(int weight[10][10],int nodes)
{
	for(i=1;i<=nodes;j++)
	{
		for(j=1;j<=nodes;j++)
		{
			if(weight[i][j]<min && weight[i][j]!=0)
			{
				min=weight[i][j];
				k=i;
				l=j;
			}
		}
	}
	cout<<"\n Edges "<<k<<"-"<<l<<"  Having weight "<<min;
	visited[k]=1;
	visited[l]=1;
	total_cost=min;

	for(m=1;m<=nodes-2;m++)
	{
		min=9999;
		for(i=1;i<=nodes;i++)
		{
			if(visited[i]==1)
			{
				for(j=1;j<=nodes;j++)
				{
					if(visited[j]!=1)
					{
						if(weight[i][j]<min && weight[i][j]!=0)
						{
							min=weight[i][j];
							k=i;
							
						}
					}
				}
			}
		}
		cout<<"\n Edges "<<k<<"-"<<l<<"  Having weight "<<min;
		visited[k]=1;
		visited[l]=1;
		total_cost=total_cost+min;
	}
	cout<<"\n Minimum cost is: "<<total_cost;
}

int main()
{
	Prims p;
	p.read();
	return 0;
}
