#include<iostream>
#include<malloc.h>
#include<string.h>

using namespace std;
typedef struct node
{
    	  int data;
  	  struct node *next;
}node;

class stack
{
	private:
	struct node *top;
	public:
	int  isoper(char x);
	int  priority(char x);
	void init(node **top);
	int  empty(node *top);
	int  pop(node **top);
	void push(node **top,int x);
	int  top1(node *top);
	void intopr(char in[],char pr[]);
	void intopo(char in[],char po[]);
	void evpo(char po[]);
	void evpr(char pr[]);

	int  posteva(char x,int op1,int op2);
};	

void stack::init(node **top)
{
	    *top=NULL;
}


int stack::empty(node *top)
{
	    if(top==NULL)
    		return(1);
	    return(0);
}


void stack::push(node **top,int x)
{
	    node *p;
	    p=(node*)malloc(sizeof(node));
	    p->data=x;
	    p->next=*top;
	    *top=p;
}


int stack::pop(node **top)
{
	    int x;
	    node *p;
	    p=*top;
	    *top=p->next;
	    x=p->data;
	    free(p);
	    return(x);
}

int stack::top1(node *top)
{
	    return(top->data);
}


void stack::intopr(char in[],char pr[])
{
	    int l,j;    
	    char temp,in1[30];
	    for(l=strlen(in)-1,j=0;l>=0;l--,j++)
	        in1[j]=in[l];
	        in1[j]='\0';
	    for(l=0;in1[l]!='\0';l++)
	    {
	        if(in1[l]=='(')
	            in1[l]=')';
	        else
	        if(in1[l]==')')
	            in1[l]='(';
	    }
	    intopo(in1,pr);
	    for(l=0,j=strlen(pr)-1;l<j;l++,j--)
	    {
	        temp=pr[l];
	        pr[l]=pr[j];
	        pr[j]=temp;
	    }
}


void stack::intopo(char in[],char po[])
{
	    node *top;
	    char x;
	    int i,j;
	    char ch;

	    init(&top);
		
	    j=0;
	    for(i=0;in[i]!='\0';i++)
	    {
	        ch=in[i];
	        if(isalnum(ch))
			{
	       		     po[j]=ch;
				j++;
			}
	       else
	        if(ch == '(')
	            push(&top,ch);
	        else
	        if(ch == ')')
	            while((x=pop(&top))!='(')
		{
	            po[j]=x;	
			j++;
		}
	        else
	        {        
		        while(priority(ch)<=priority(top1(top)) && !empty(top))
		        {
			            x=pop(&top);
			            po[j]=x;
					j++;
		        }
		        push(&top,ch);
	       }
}

while(!empty(top))
{
    	x=pop(&top);
    	po[j]=x;
	j++;
}
    	po[j]='\0';
}


void stack::evpo(char po[])
{
	    node *top;
	    char ch;
	    int op1,op2,val,i;
	    init(&top);
	    for(i=0;po[i]!='\0';i++)
	    {
		        ch=po[i];
        		if(isalpha(ch))
        		{
			    cout<<"\nEnter the value of "<<ch<<"=";
			    cin>>val;
			    push(&top,val);
			}
			else
			{
			    op2=pop(&top);
			    op1=pop(&top);
			    val=posteva(ch,op1,op2);
			    push(&top,val);
			}
    	}
    	val=pop(&top);
    	cout<<"\nvalue of expression= "<<val ;
}

void stack::evpr(char pr[])
{

            node *top;
	    char ch,temp;
	    int op1,op2,val,i,l,j;
	    init(&top);
	     for(l=0,j=strlen(pr)-1;l<j;l++,j--)
	    {
	        temp=pr[l];
	        pr[l]=pr[j];
	        pr[j]=temp;
	    }
	    for(i=0;pr[i]!='\0';i++)
	    {
		        ch=pr[i];
        		if(isalpha(ch))
        		{
			    cout<<"\nEnter the value of "<<ch<<"=";
			    cin>>val;
			    push(&top,val);
			}
			else
			{
			    op2=pop(&top);
			    op1=pop(&top);
			    val=posteva(ch,op1,op2);
			    push(&top,val);
			}
    	}
    	val=pop(&top);
    	cout<<"\nvalue of expression= "<<val ;
}
int stack::posteva(char x,int op1,int op2)
{
	    if(x=='+')
	    return(op1+op2);

	    if(x=='-')
	    return(op1-op2);
	
	    if(x=='*')
	    return(op1*op2);
	
	    if(x=='/')
	    return(op1/op2);
	
	    if(x=='%')
	    return(op1%op2);
	
	    else
	    return(0);
}

int stack::isoper(char x)
{
if(x=='+'||x=='-'||x=='*'||x=='*'||x=='^')
return 1;
return 0;
}
int stack::priority(char x)
{
    if(x == '(')
    return(0);

    if(x == '+' || x == '-')
    return(1);

    if(x == '*' || x == '/' || x == '%')
    return(2);

    else
    return(3);
}

int main()
{
char in[30],po[30],pr[30];
int ch;
stack s;
cout<<"\nEnter an Infix Expression: ";
cin>>in;
do
    {
    cout<<"\n******* MENU*******\n";
    cout<<"\n1.Infix To Postfix Conversion\n2.Infix To Prefix Conversion\n3.Evaluation of postfix\n4.Evaluation of prefix \n";
    cout<<"\n\nEnter your choice : ";
    cin>>ch;

    switch(ch)
    {
    case 1:
	
        s.intopo(in,po);
	cout<<"\nPostfix :  "<<po ;
	break;
    case 2:
	s.intopr(in,pr);
	cout<<"\nPrefix:  "<<pr ;
        break;
    case 3:
	cout<<"\nPostfix evaluation : ";
        s.evpo(po);
	break;
    case 4:
	cout<<"\n Prefix:";
	s.evpr(pr);
        break;
        }    
}while(ch<5);
return 0;
}
