#include <iostream>
#include <cstdlib>
using namespace std;

struct que
{
	int w;
	bool pos;
	que *next;
	que ()
	{
		w=0;
		pos=0;
	}
};

void en(que **head,int num,bool p)
{
	que *ptr = new que;
	ptr->w=num;
	ptr->pos=p;
	ptr->next=NULL;
	
	if(*head==NULL)
	{
		*head = ptr;
	}
	else
	{
		que *pre,*cur= (*head);
		while(cur!=NULL)
		{	
			pre=cur;
			cur=cur->next;
		}
		pre->next=ptr;
	}
}

void de(que **head)
{
	que *tmp= new que;
	tmp=(*head);
	*head = (*head)->next;
	delete tmp;
}

void mv(que **head)
{
	que *tmp= new que,*cur= (*head),*pre;
	tmp=(*head);
	(*head) = (*head)->next;
	
	while(cur!=NULL)
	{
		pre=cur;
		cur = cur->next;
	}
	pre->next=tmp;
	tmp->next=NULL;
}

bool find(que *head,int weight)
{
	while(head!=NULL)
	{
		if(head->w > weight)
			return 1;
		head = head->next;
	}
	return 0;
}

void print(que *head)
{
	while(head!=NULL)
	{
		cout<<head->w;
		cout<<head->pos<<' ';
		head=head->next;
	}
	cout<<"NULL\n";
}

int main()
{
	int n;
	cin>>n;
	while(n--)
	{
		int jnum,pos;
		cin>>jnum>>pos;
		que *head=NULL;
		for(int i=0 ; i<jnum ; i++)
		{
			int num;
			cin>>num;
			en(&head,num,(i==pos));
		}
		int t=0;
		while(1)
		{
			if(!find(head->next,head->w))
			{
				if(head->pos)
					break;
				else
				{
					t++;
					de(&head);
				}
			}
			else
				mv(&head);
		}
		cout<<t+1<<'\n';
	}
	return 0;
} 
