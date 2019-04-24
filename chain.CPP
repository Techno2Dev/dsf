#include<iostream>
using namespace std;

#define MAX 10
#define SIZE 10              /* size of the hash table*/
#define FALSE 0
#define TRUE 1
#define h(x) x%SIZE  
struct hashtable
{
	int chain;
	long int key;
	char name;
}s[MAX];
class hasht
{
	public:
		int hash(int telno);
		void insert( int data[],int flag[],int chain[],int x,char sname,char name1[]);
		void print(int data[],int flag[],int chain[], char name1[]);
};
	
int hasht::hash(int telno)
{
	int h;
	h=telno%MAX;
	return h;
}

void hasht::insert( int data[],int flag[],int chain[],int x,char sname,char name1[])
{
	int i=0,j,start;
	start=h(x); 
	if(flag[start]==0)
	{
		data[start]=x;
		name1[start]=sname;                                                 
		flag[start]=1;                                                                        
		return;
	}
	if(h(data[start])!=h(x))
	{ 
		i=0;j=start;
		while(flag[j] && i<SIZE)
		{
			j=(j+1)%SIZE;
			i++;
		}
		if(i==SIZE)
		{
			cout<<"\nTable is full ...";
			return;
		}
		i=data[start]%SIZE;
	
		while(chain[i] != start)
			i=chain[i];
	
		chain[i]=chain[start]; 
	
		while(chain[i]!=-1)
			i=chain[i];
	
		chain[i]=j;
		data[j]=data[start];
		name1[j]=name1[start];
	
		chain[start]=-1;
		flag[j]=1;
		chain[j]=-1;
	
		data[start]=x;
		name1[start]=sname;
		chain[start]=-1;
		return;
	}
	i=0;j=start;
	while(flag[j] && i<SIZE)
	{
		j=(j+1)%SIZE;
		i++;
	}
	if(i==SIZE)
	{
		cout<<"\nTable is full ...";
		return;
	}
	data[j]=x;
	name1[j]=sname;
	flag[j]=1;
	chain[j]=-1;
	i=start;
	while(chain[i] != -1)
		i=chain[i];
	chain[i]=j;
}

void hasht::print(int data[],int flag[],int chain[],char name1[])
{
	int i;
	cout<<"------------------------------------------------";
	cout<<"Index"<<"\t"<<"Telephone"<<"\t"<<"Name"<<"\t"<<"chain"<<"\n";
	for(i=0;i<SIZE;i++)
	{
		if(flag[i])
			cout<<"\n"<<i<<"\t"<<data[i]<<"\t"<<name1[i]<<"\t"<<chain[i];
		else
			cout<<"\n"<<i<<"\t"<<"\t"<<"\t"<<chain[i];
	}
	cout<<"\n------------------------------------------------";
}

int main(void)
{
	int i,flag1=0,ch,ch1,no1,h,c,index,k,temp,ch3;
	int data[SIZE],flag[SIZE],chain[SIZE],j,x,op,loc;
	char sname;
	char name1[SIZE];
	hasht t;
	for(i=0;i<MAX;i++)
	{
		s[i].key=-1;
		s[i].chain=-1;
		s[i].name='-';
	}	
	do
	{
		cout<<"\n----------------------------------";
		cout<<"\n1. Chaining without replacement";
		cout<<"\n2. Chaining with replacement";
		cout<<"\n----------------------------------";
		cout<<"\nEnter ur choice: ";
		cin>>ch;
		switch(ch)
		{
			case 1:
					do
					{
						for(j=0;j<MAX;j++)
						{
							if(s[j].key==-1)
								break;
						}
						if(j==MAX)
						{
							cout<<"\nHash Table is full:";
							break;
						}
						cout<<"\nEnter the Telephone number:";
						cin>>no1;
						cout<<"Enter the name:";
						cin>>sname;
						h=t.hash(no1);
						c=-1;
						index=h;
						do
						{
							if(s[h].key==-1)
							{
								flag1=1;
								s[h].key=no1;
								s[h].name=sname;
								if(c!=-1)
									s[c].chain=h;
							}
							else if(t.hash(s[h].key)==index)	
								c=h;
							h=t.hash(h+1);
						}while(flag1==0&&h<MAX);
						flag1=0;
						cout<<"------------------------------------------------";
						cout<<"\nIndex"<<"\t"<<"Telephone"<<"\t"<<"Name"<<"\t"<<"chain"<<"\n";
						for(i=0;i<MAX;i++)
								cout<<i<<"\t"<<s[i].key<<"\t\t"<<s[i].name<<"\t"<<s[i].chain<<"\n";
						cout<<"------------------------------------------------";
						cout<<"\nDo you want to continue [0/1]: ";
						cin>>ch;
					}while(ch==1);
				break;
				
				case 2:
					for(i=0;i<SIZE;i++) /* initialize */
					{
						flag[i]=FALSE;
						name1[i]='-';
						chain[i]=-1;
					}
					do
					{
						cout<<"\nEnter Telephone no: ";
						cin>>x;
						cout<<"Enter name: ";
						cin>>sname;
						t.insert(data,flag,chain,x,sname,name1);
						t.print(data,flag,chain,name1);
						cout<<"\nDo you want to continue[0/1]: ";
						cin>>ch3;
					}while(ch3==1);
				break;
		}
		cout<<"\nDo you want to continue[0/1]: ";
		cin>>ch1;
	}while(ch1==1);
	return 0;	
}
