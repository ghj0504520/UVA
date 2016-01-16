#include <iostream>

using namespace std;

bool table[10][7]=
{
{1,1,1,0,1,1,1},
{0,0,1,0,0,1,0},
{1,0,1,1,1,0,1},
{1,0,1,1,0,1,1},
{0,1,1,1,0,1,0},
{1,1,0,1,0,1,1},
{1,1,0,1,1,1,1},
{1,0,1,0,0,1,0},
{1,1,1,1,1,1,1},
{1,1,1,1,0,1,1}

};

int main()
{
	int Length;
	string query;
	while(cin>>Length>>query)
	{
		if(!Length&&query=="0")break;

		string data1=" ",data2="",data3=" ",data4="",data5=" ";

		for(int i=0 ; i<query.size() ; i++)
		{
			for(int j=0 ; j<Length ; j++)
				if(table[ query[i]-'0' ][0])data1+="-";
				else data1+=" ";
			data1+="   ";


			if(table[ query[i]-'0' ][1])data2+="|";
			else data2+=" ";
			for(int j=0 ; j<Length ; j++)data2+=" ";
			if(table[ query[i]-'0' ][2])data2+="|";
			else data2+=" ";
			data2+=" ";

			for(int j=0 ; j<Length ; j++)
				if(table[ query[i]-'0' ][3])data3+="-";
				else data3+=" ";
			data3+="   ";


			if(table[ query[i]-'0' ][4])data4+="|";
			else data4+=" ";
			for(int j=0 ; j<Length ; j++)data4+=" ";
			if(table[ query[i]-'0' ][5])data4+="|";
			else data4+=" ";
			data4+=" ";


			for(int j=0 ; j<Length ; j++)
				if(table[ query[i]-'0' ][6])data5+="-";
				else data5+=" ";
			data5+="   ";
		}
		data1.resize(data1.size()-2);
		data2.resize(data2.size()-1);
		data3.resize(data3.size()-2);
		data4.resize(data4.size()-1);
		data5.resize(data5.size()-2);
		cout<<data1<<"\n";
		for(int i=0 ; i<Length ; i++)cout<<data2<<"\n";
		cout<<data3<<"\n";
		for(int i=0 ; i<Length ; i++)cout<<data4<<"\n";
		cout<<data5<<"\n\n";
	}
	return 0;
}