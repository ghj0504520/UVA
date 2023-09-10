#include <iostream>
#include <queue>
 
using namespace std;
 
struct Task
{
	int id, feq, stamp;
	Task(int i, int f, int stp)
	{
		this->id =i;
		this->feq =f;
		this->stamp =stp;
	}
	bool operator<(const Task& a) const
    {
        return stamp > a.stamp || (stamp == a.stamp &&id > a.id);
    }
};
 
int main(int argc, char const *argv[])
{
	string cmd;
	int id,feq;
	priority_queue<Task> taskQueue;
	while(cin>>cmd)
	{
		if(cmd=="#")break;
		cin>>id>>feq;
		taskQueue.push(Task(id,feq,feq));
	}
 
	int num;
	cin>>num;
	while(num--)
	{
		Task cur = taskQueue.top();
		taskQueue.pop();
		cout<<cur.id<<"\n";
 
		cur.stamp+= cur.feq;
		taskQueue.push(cur);
	}
	return 0;
}