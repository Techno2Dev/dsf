#include<iostream>

using namespace std;

int visited[10];

class graph
{
	int i,j,min,u,v,mincost,cost[10][10],edges,a,b,n;
	public:
		graph():edges(1),mincost(0){}
		void kruskal(int cost[10][10],int n);
		void read();
};

void graph::read()
{
	cout<<"\nEnter the no of vertices: ";
	cin>>n;
	cout<<"\nEnter weight of edges in the form of adjecency matrix: ";
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			cin>>cost[i][j];
			if(cost[i][j]==0)
				cost[i][j]=9999;
		}
	}
	kruskal(cost,n);
}

void graph::kruskal(int cost[10][10],int n)
{
	while(edges<n)
	{
		min=9999;
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=n;j++)
			{
				if(cost[i][j]<min)
				{
					min=cost[i][j];
					a=u=i;
					b=v=j;
				}
			}
		}
		while(visited[u])
			u=visited[u];
		while(visited[v])
			v=visited[v];

		if(u!=v)
		{
			edges++;
			cout<<"\nEdges: \n "<<a<<"->"<<b<<"\t weight= "<<min;
			mincost=mincost+min;
			v=visited[v];
		}
		cost[a][b]=cost[b][a]=9999;
	}
	cout<<"\nMinimun cost= "<<mincost<<endl;
}

int main()
{
	graph g;
	g.read();
	return 0;
}
