#include <iostream>
#include <vector>
#include <stack>
using namespace std;

struct card
{
	char color,point;
	card(char c, char p)
	{
		this->color = c;
		this->point = p;
	}
	card()
	{
		this->color = 0;
		this->point = 0;
	}
	bool operator==(const card& a) const
	{
    	return ((a.color==color) || (a.point== point));
	}
	card& operator =(const card& a)
	{
    	color = a.color;
    	point = a.point;
    	return *this;
	}
};
int main()
{
	string str;
	while (cin>>str)
	{
		if(str=="#")break;
		vector< stack<card> > game;
		vector<card> sequence;
		
		sequence.push_back(card(str[0],str[1])); 
		for(int i=1 ; i<52 ; i++)
		{
			cin>>str;
			sequence.push_back(card(str[0],str[1])); 
		}

		// play the game
		for(int i=0 ; i<52 ; i++)
		{
			stack<card> pile;
			pile.push(sequence[i]);
			game.push_back(pile);

			card tmp;
			for(int p=game.size()-1 ; p<game.size() ; p++)
			{
				tmp = game[p].top();
				if(p>=3)
				{
					if(tmp == game[p-3].top())
					{
						game[p-3].push(tmp);
						game[p].pop();
						if(game[p].empty())
							game.erase(game.begin()+p);
						p = p -4; // next round will plus 1 and goto p-3
					}
					else if(tmp == game[p-1].top())
					{
						game[p-1].push(tmp);
						game[p].pop();
						if(game[p].empty())
							game.erase(game.begin()+p);
						p = p -2; // next round will plus 1 and goto p-1
					}
				}else if(p>0&&p<3)
				{
					if(tmp == game[p-1].top())
					{
						game[p-1].push(tmp);
						game[p].pop();
						if(game[p].empty())
							game.erase(game.begin()+p);
						p = p -2; // next round will plus 1 and goto p-1
					}
				}
			}
		}

		// output
		int len = game.size();
		if(len==1)
			cout<<"1 pile remaining:";
		else cout<<len<<" piles remaining:";
		for(int i=0 ; i<len ; i++)
			cout<<" "<< game[i].size();
		cout<<"\n";
	}

}