// NAME : HARSHAL PATIL
// ROLL NO : 44

// Assignment 1 : Set operations

#include<iostream>
using namespace std;
class Array
{
	private : 
		int a[100],b[100],c[100],d[100],m[100],i,j,n,w,x,y,z,p=0,q=0;
	public : 
		void getdata()
		{
			cout<<"\n Enter Total Number of Students : ";
			cin>>n;
			for(i=0;i<n;i++)
			{
				m[i]=i+1;
			}
			cout<<"\n Roll Numbers are : ";
			for(i=0;i<n;i++)
			{
				cout<<m[i]<<",";
			}
			cout<<"\n Enter Number of Students participated In Coding Contest : ";
			cin>>w;
			cout<<"\n Enter Roll no : ";
			for(i=0;i<w;i++)
			{
				cin>>a[i];
			}
			cout<<"\n Enter Number of Students participated In Project Competition : ";
			cin>>x;
			cout<<"\n Enter Roll no : ";
			for(i=0;i<x;i++)
			{
				cin>>b[i];
			}
			cout<<"\n Enter Number of Students participated In Paper Presentation : ";
			cin>>y;
			cout<<"\n Enter Roll no : ";
			for(i=0;i<y;i++)
			{
				cin>>c[i];
			}
			cout<<"\n Enter Number of Students participated In Mastermind : ";
			cin>>z;
			cout<<"\n Enter Roll no : ";
			for(i=0;i<z;i++)
			{
				cin>>d[i];
			}
		}	
		void first()
		{	
			cout<<"\n Students Participated in both Coding and Project are : ";
			for(i=0;i<w;i++)
			{
				for(j=0;j<x;j++)
				{
					if(a[i]==b[j])
					{
						cout<<" "<<b[j];
					}
				}
			}	
		}
		void second()
		{
			int res[w+x+z],k=0,i=0,j=0,p=0;
			cout<<"\n Students Participated in Coding or Project or Mastermind are : ";
			while(i<w && j<x && p<z)
			{
				if(a[i]<b[j] && a[i]<d[p])
				{
					res[k++]=a[i++];
				}
				else if(a[i]>b[j] && b[j]<d[p])
				{
					res[k++]=b[j++];
				}
				else if(d[p]<b[j] && d[p]<a[i])
				{
					res[k++]=d[p++];
				}
				else
				{
					res[k++]=a[i++];
					j++;
					p++;
				}
			}
			while(i<w)
			{
				res[k++]=a[i++];
			}
			while(j<x)
			{
				res[k++]=b[j++];
			}
			while(p<z)
			{
				res[k++]=d[p++];
			}
			for(i=0;i<k;i++)
			{
				cout<<res[i]<<" ";
			}
			
		}
	    void third()
		{
			int f;		
			cout<<"\n Students Participated in Coding but not in Mastermind are : ";
			for(i=0;i<w;i++)
			{
				f=0;
				for(j=0;j<z;j++)
				{
					if(a[i]==d[j])
					{
						f=1;
						break;				
					}
				}	
				if(f==0)
				{
					   cout<<a[i]<<", ";
				}    
			}
		}
		void fourth()
		{	
			cout<<"\n Students Participated in All Events are : ";
			for(i=0;i<w;i++)
			{
				for(j=0;j<x;j++)
				{
				    for(p=0;p<y;p++)
				    {
				        for(q=0;q<z;q++)
				        {      
					        if(a[i]==b[j] && b[j]==c[p] && c[p]==d[q])
					        {
						        cout<<""<<a[i]; 
						        break;
					        }
				        }	 
			        }
	            }
	        }        
		}
		void fifth()
		{
			cout<<"\n Students Participated in Atleast one Competition are : ";
			for(i=0;i<n;i++)
			{
				int roll=m[i];
				bool coding=false;
				bool project=false;
				bool paper=false;
				bool mastermind=false;
				for(j=0;j<w;j++)
				{
					if(roll==a[j])
					{
						coding=true;
					}
					if(roll==b[j])
					{
						project=true;
					}
					if(roll==c[j])
					{
						paper=true;
					}
					if(roll==d[j])
					{
						mastermind=true;
					}
					if(coding || project || paper || mastermind)
					{
						cout<<roll<<", ";
						break;
					}
				}
			}	
		}
		void sixth()
		{
			int temp[100],l=0;
			cout<<"\n Students Participated in None of the Competition : ";

			for(i=0;i<n;i++)
			{
				int roll=m[i];
				bool coding=false;
				bool project=false;
				bool paper=false;
				bool mastermind=false;
				for(j=0;j<w;j++)
				{
					if(roll==a[j])
					{
						coding=true;
					}
					if(roll==b[j])
					{
						project=true;
					}
					if(roll==c[j])
					{
						paper=true;
					}
					if(roll==d[j])
					{
						mastermind=true;
					}
					if(coding || project || paper || mastermind)
					{
						temp[l]=roll;
						l++;
						break;
					}
				}
			}	
			for(i=0;i<n;i++) 
			{
        	bool found=false;
        		for(j=0;j<l;j++) 
				{
            		if(m[i]==temp[j]) 
					{
                		found = true;
                		break;
            		}
        		}
        		if (!found) 
				{
            		cout<<m[i]<<", ";
        		}
    		}
		}
};
int main()
{
	Array obj;
	int ch,ch1;
	cout<<"\n PROGRAM TO UNDERSTAND SET OPERATIONS ON ARRAY ";
	cout<<"\n **************** EVENT EQUINOX **************";
	obj.getdata();
	do
	{
		cout<<"\n ******************** MENU *******************";
		cout<<"\n 1. Students Participated in both Coding and Project";
		cout<<"\n 2. Students Participated in Coding or Project or Mastermind";
		cout<<"\n 3. Students Participated in Coding but not in Mastermind";
		cout<<"\n 4. Students Participated in All Events";
		cout<<"\n 5. Students Participated in Atleast one Competition";
		cout<<"\n 6. Students Participated in None of the Competition";
		cout<<"\n Choose Operation to perform : ";
		cin>>ch;
		switch (ch)
		{
		case 1:
			obj.first();
			break;
		case 2:
			obj.second();
			break;
		case 3:
			obj.third();
			break;
		case 4:
			obj.fourth();
			break;
		case 5:
			obj.fifth();
			break;		
		case 6:
			obj.sixth();
			break;			
		default:
			cout<<"\n Invalid Option";
			break;
		}
		cout<<"\n Do you want to continue(1.Y/2.N) : ";
		cin>>ch1;

	}while(ch1==1);
	return 0;
}