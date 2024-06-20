#include<iostream>
using namespace std;

class Sparse
{
	int arr[50][50];
	int sp[50][3];
	int row,col,i,j;
	int k=1;
	public: 
	void read()
	{
		cout<<"Enter the number of rows and columns: ";
		cin>>row>>col;
		for(i=0;i<row;i++)
		{
			for(j=0;j<col;j++)
			{
				cout<<"Enter the element: ";
				cin>>arr[i][j];	
			}
		}
	
	
		cout<<"Array Elements are: "<<endl;
		for(i=0;i<row;i++)
		{
			for(j=0;j<col;j++)
			{
				cout<<arr[i][j]<<"\t";
			}
			cout<<endl;
		}
		cout<<endl;
	}
	void sparse()
	{
		
		for(i=0;i<row;i++)
		{
			for(j=0;j<col;j++)
			{
				if(arr[i][j]!=0)
				{
					sp[k][0]=i;
					sp[k][1]=j;
					sp[k][2]=arr[i][j];
					k++;
				}
			}
		}
		sp[0][0]=row;
		sp[0][1]=col;
		sp[0][2]=k-1;
	}
	void showsparse()
	{
		cout<<"Sparse Matrix is: "<<endl;
		for(i=0;i<k;i++)
		{
			for(j=0;j<3;j++)
			{
				cout<<sp[i][j]<<"\t";
			}
			cout<<endl;
		}
		cout<<endl;
	}
	void addsp(Sparse s2)
	{
		int m,n,k=1,i=1,j=1;
		int c[50][3];
		m=sp[0][2];
		n=s2.sp[0][2];
		c[0][0]=sp[0][0];
		c[0][1]=sp[0][1];
        while(i<=m && j<=n)
		{
			if(sp[i][0]==s2.sp[j][0])
			{	
				if(sp[i][1]==s2.sp[j][1])
				{
					c[k][0]=sp[i][0];
					c[k][1]=s2.sp[j][1];
					c[k][2]=sp[i][2]+s2.sp[j][2];
					i++;j++;k++;
				}
				else if(sp[i][1]<s2.sp[j][1])
				{
					c[k][0]=sp[i][0];
					c[k][1]=sp[i][1];
					c[k][2]=sp[i][2];
					i++;j++;k++;
				}
				else
				{
					c[k][0]=s2.sp[j][0];
					c[k][1]=s2.sp[j][1];
					c[k][2]=s2.sp[j][2];
					i++;j++;k++;
				}
			}
			else if(sp[i][0]<s2.sp[j][0])
			{	
				c[k][0]=sp[i][0];
				c[k][1]=sp[i][1];
				c[k][2]=sp[i][2];
				i++;j++;k++;
			}
			else
			{
				c[k][0]=s2.sp[j][0];
				c[k][1]=s2.sp[j][1];
				c[k][2]=s2.sp[j][2];
				i++;j++;k++;
			}
		}
		while(i<=m)
		{
			c[k][0]=sp[i][0];
			c[k][1]=sp[i][1];
			c[k][2]=sp[i][2];
			i++;k++;			
		}	
		while(j<=n)
		{
			c[k][0]=s2.sp[j][0];
			c[k][1]=s2.sp[j][1];
			c[k][2]=s2.sp[j][2];
			j++;k++;
		}
		c[0][2]=k;
		cout<<"Addition of the sparse matrix is: "<<endl;
		for(i=0;i<k;i++)
		{
			for(j=0;j<3;j++)
			{
				cout<<c[i][j]<<"\t";
			}
			cout<<endl;
		}
		cout<<endl;
		}
		
	void simtrans()
    {
    	int transpose[50][3],k=1;
    	for(int i=0;i<sp[0][1];i++)
    	{
    		for(int j=1;j<=sp[0][1];j++)
    		{
    			if(sp[j][1]==i)
    			{
    				transpose[k][0]=sp[j][1];
    				transpose[k][1]=sp[j][0];
    				transpose[k][2]=sp[j][2];
    				k++;
				}
			}
		}
		transpose[0][0]=sp[0][1];
		transpose[0][1]=sp[0][0];
		transpose[0][2]=sp[0][2];
		cout << "simple Transpose Matrix is: " << endl;
		for (int i = 0; i < k; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                cout << transpose[i][j] << "\t";
            }
            cout << endl;
        }
        cout << endl;
		        
	}
	
	void fastran()
    {
        int loc, i, col_no;
        int result[50][3];
        int total[sp[0][1]], index[sp[0][1] + 1];
        for (i = 0; i < sp[0][1]; i++)
        {
            total[i] = 0;
        }
        for (i = 1; i <= sp[0][2]; i++)
        {
            col_no = sp[i][1];
            total[col_no]++;
        }
        index[0] = 1;
        for (i = 1; i <= sp[0][1]; i++)
        {
            index[i] = index[i - 1] + total[i - 1];
        }
        result[0][0] = sp[0][1];
        result[0][1] = sp[0][0];
        result[0][2] = sp[0][2];
        
		for (i = 1; i <= sp[0][2]; i++)
		{
			col_no=sp[i][1];
			loc=index[col_no];
			result[loc][0]=sp[i][1];
			result[loc][1]=sp[i][0];
			result[loc][2]=sp[i][2];
			index[col_no]++;
		}
		
		cout<<"\n\t Fast transpose:";
		cout<<"\n\tRows cols vals";
		for(i=0;i<=result[0][2];i++)
		{
			cout<<"\n";
			for(int j=0;j<3;j++)
			{
				cout<<" \t "<<result[i][j];
			}
		}
		
    }
	
		
};

int main()
{
	Sparse s1,s2;
	s1.read();
	s1.sparse();
	s1.showsparse();
	s2.read();
	s2.sparse();
	s2.showsparse();
	cout<<endl;
	s1.showsparse();
	s2.showsparse();
	s1.addsp(s2);
	cout<<endl;
	s1.simtrans();
	cout<<endl;
	cout<<"Using Fast Transpose: "<<endl;
	s1.fastran();
	return 0;
}