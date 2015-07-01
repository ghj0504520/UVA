		#include <iostream>  
		#include<stack>
		#include<cstring>
		#include<stdio.h>
		#include<cstdlib>
		using namespace std;  
		  
		int main (int argc, char *argv[])  
		{  
		    int in;
		    
		    cin>>in;
		    getchar();
		     	for(int i=0;i<in;i++)
		     	{
		      		char c[200];
		      		cin.getline(c,200,'\n');
                
                    bool j=1;
		    		int d=strlen(c);
		    		stack<char> a,b;
		    		for(int i=0;i<d;i++)
		    		{
		    			if(c[i]=='(')
		    			{
		    				a.push('(');
		    			}
		    			else if(c[i]=='[')
		    			{
		    				a.push('[');
		    			}
		    			else if(c[i]==')')
		    			{
		    				if(a.empty())
		    				{
		    					j=0;
		    					break;
		    				}
		    				else
		    				{
		    					if(a.top()=='(')a.pop();
		    					else if(a.top()=='[')
		    		 			{
		    		 				 j=0;
		    		 				 break;
		    		 			}
		 					}  	
		    			}
		    			else if(c[i]==']')
		    			{
		    				if(a.empty())
		    				{
		    					j=0;
		    					break;
		    				}
		    				else
		    				{
		    					if(a.top()=='[')a.pop();
		    					else if(a.top()=='(')
		    		 			{
		    		  				j=0;
		    		  				break;
		    		 			}
		 					}  	
		    			}
		    	
		    		}
		    
		   		 a.empty()*j==1?cout<<"Yes\n":cout<<"No\n";
		    
		     }
		  
		      
		    return 0;  
		}  
