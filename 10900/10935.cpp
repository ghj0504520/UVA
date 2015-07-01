#include <iostream>
#include <queue>
#include <stdio.h>
using namespace std;

int main()
{
	int query;
	while(cin>>query,query)
	{
		queue<int> card;
		for(int i=0;i<query;i++)
		{
			card.push(i+1);
		}
		printf("Discarded cards:");
		if(query!=1)cout<<' ';
		int discard,t=0;
		while(1)
		{
			
			discard=card.front();
			card.pop();
			if(card.empty())break;
			if(t)printf(", ");
			t++;
			printf("%d",discard);
			discard=card.front();
			card.pop();
			card.push(discard);
		}
		printf("\nRemaining card: %d\n",discard);
	}
	return 0;
}
