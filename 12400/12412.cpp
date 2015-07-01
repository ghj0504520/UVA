#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>
#include <map>
#include <algorithm>
#define eps 1e-5                              //figure to modify point number
using namespace std;

class student
{
	public:
		string stuID,name;
		int clasID,score[4];
		student(int clas,int data[],string stu = "",string n = "")
		{
				stuID = stu;
				name = n;
				clasID = clas;
				for(int i=0 ; i<4 ; i++)score[i]=data[i];
		}
		int total()
		{
			return score[0]+score[1]+score[2]+score[3];
		}
		double avg()
		{
			return (double)total()/4.0+eps;
		}
		void print_stu()
		{
			cout<<stuID<<' '<<clasID<<' '<<name<<' ';
			for(int i=0;i<4;i++)cout<<score[i]<<' ';
			cout<<total()<<' ';
			printf("%.2lf\n",avg());
		}
};

class SPMS
{
	public:
		map<string, int> dupli;
		vector<student> students;
		void message()
		{
			printf("Welcome to Student Performance Management System (SPMS).\n\n");
			printf("1 - Add\n2 - Remove\n3 - Query\n4 - Show ranking\n5 - Show Statistics\n0 - Exit\n\n");
		}
		void add()
		{
			char stuID[100],name[100];
			int clasID,score[4];
			while(1)
			{
				printf("Please enter the SID, CID, name and four scores. Enter 0 to finish.\n");
				scanf("%s",stuID);
				if(!strcmp(stuID,"0"))return ;
				scanf("%d %s",&clasID,name);
				for(int i=0;i<4;i++)scanf("%d",&score[i]);
				map<string, int>::iterator it;
				it=dupli.find(stuID);
				if(it!=dupli.end() && dupli[stuID])                     //BUG !! figure out
				{
					printf("Duplicated SID.\n");
				}
				else
				{
					dupli.insert(pair<string,int>(stuID,1));
					student child(clasID,score,stuID,name);
					students.push_back(child);
				}
			}
		}
		void remove()
		{
			char del[100];
			while(1)
			{
				printf("Please enter SID or name. Enter 0 to finish.\n");
				scanf("%s",del);
				if(!strcmp(del,"0"))return ;		
				int count=0;
				vector<student>::iterator it;
				for(it=students.begin();it!=students.end();)            //figure out        
				{
					if(it->stuID==del || it->name==del)
					{
						count++;
						dupli[it->stuID]=0;
						it=students.erase(it);      //vector use erase will return current position
					}
					else
					{
						it++;
					}
					
				}printf("%d student(s) removed.\n",count);
			}
		}
		int rank(student q)
		{
			vector<student>::iterator it;
			int count=1;
			for(it=students.begin();it!=students.end();it++)            //figure out
			{
				if(it->total() > q.total())
				count++;
			}
			return count;
		}
		void query()
		{
			char q[100];
			while(1)
			{
				printf("Please enter SID or name. Enter 0 to finish.\n");
				scanf("%s",q);
				if(!strcmp(q,"0"))return ;		
				vector<student>::iterator it;
				for(it=students.begin();it!=students.end();it++)
				{
					if(it->stuID==q || it->name==q)
					{
						printf("%d ",rank(*it));
						it->print_stu();
					}
				}
			}
		}
		void print_rank()
		{
			printf("Showing the ranklist hurts students' self-esteem. Don't do that.\n");
		}
		void print_static()
		{
			int q;
			printf("Please enter class ID, 0 for the whole statistics.\n");
			scanf("%d",&q);		
			int pass[4]={0},fail[4]={0};
			int count=0,sum[4]={0};
			int overall[5]={0};
			vector<int> personal;
			personal.resize(students.size(), 0);                     //figure out
			for(int i=0;i<students.size();i++)
			{
				if(q && q!=students[i].clasID)
				{
					continue;
				}
				else
				{
					count++;
					for(int j=0;j<4;j++)
					{
						sum[j]+=students[i].score[j];
						if(students[i].score[j]>=60)
						{
							pass[j]++;
							personal[i]++;
						}
						else
						{
							fail[j]++;
						}
					}
					overall[personal[i]]++;
				}
			}
			for(int i=4;i>=2;i--)
			{
				overall[i-1]+=overall[i];
			}
			printf("Chinese\nAverage Score: %.2lf\nNumber of passed students: %d\nNumber of failed students: %d\n\n",
					(double)sum[0]/count+eps,pass[0],fail[0]);
			printf("Mathematics\nAverage Score: %.2lf\nNumber of passed students: %d\nNumber of failed students: %d\n\n",
					(double)sum[1]/count+eps,pass[1],fail[1]);
			printf("English\nAverage Score: %.2lf\nNumber of passed students: %d\nNumber of failed students: %d\n\n",
					(double)sum[2]/count+eps,pass[2],fail[2]);
			printf("Programming\nAverage Score: %.2lf\nNumber of passed students: %d\nNumber of failed students: %d\n\n",
					(double)sum[3]/count+eps,pass[3],fail[3]);
			printf("Overall:\nNumber of students who passed all subjects: %d\nNumber of students who passed 3 or more subjects: %d\nNumber of students who passed 2 or more subjects: %d\nNumber of students who passed 1 or more subjects: %d\nNumber of students who failed all subjects: %d\n\n",
					overall[4],overall[3],overall[2],overall[1],overall[0]);					
		}
}spms;

int main()
{
	//freopen("in","r",stdin);
	//freopen("out","w",stdout);
	int cmd;
	while(1)
	{
		spms.message();
		scanf("%d",&cmd);
		if(!cmd)break;
		if(cmd==1)
			spms.add();
		else if(cmd==2)
			spms.remove();
		else if(cmd==3)
			spms.query();
		else if(cmd==4)
			spms.print_rank();
		else if(cmd==5)
			spms.print_static();
	}
}
