// NAME : HARSHAL PATIL
// ROLL NO : 44

// Assignment 8 : Stack Operations

#include<iostream>
#include<stack>
#include<math.h>
#include<cstring>
#include<algorithm>
using namespace std;
int prec(char c)
{
    if(c=='^')
    {
        return 3;
    }
    else if(c=='*' || c=='/')
    {
        return 2;
    }
    else if(c=='+' || c=='-')
    {
        return 1;
    }
    else
    {
        return -1;
    }
}
class stackOperations
{
    private:
        stack<string> st;
        string res,res1,res2,a,b,c,temp;

    public:
        void infixOperations(string s)
        {
            stack<char> st;
            cout<<"\n Infix to Postfix : ";
            for(int i=0;i<s.length();i++)
            {
                if ((s[i]>='a' && s[i]<='z') || (s[i]>='A' && s[i]<='Z'))
                { 
                    res1+=s[i];  
                }
                else if(s[i]=='(')
                {
                    st.push(s[i]);
                }
                else if(s[i]==')')
                {
                    while (!st.empty() && st.top()!='(')
                    {
                        res1+=st.top();
                        st.pop();
                    }
                    if(!st.empty())
                    {
                        st.pop();
                    }
                }
                else
                {
                    while (!st.empty() && prec(st.top())>prec(s[i]))
                    {
                        res1+=st.top();
                        st.pop();
                    }
                    st.push(s[i]);
                } 
            }
            while (!st.empty())
            {
                res1+=st.top();
                st.pop();
            }
            cout<<res1;

            reverse(s.begin(),s.end());  
            cout<<"\n Infix to Prefix : ";
            for(int i=0;i<s.length();i++)
            {
                if ((s[i]>='a' && s[i]<='z') || (s[i]>='A' && s[i]<='Z'))
                { 
                    res2+=s[i];  
                }
                else if(s[i]==')')
                {
                    st.push(s[i]);
                }
                else if(s[i]=='(')
                {
                    while (!st.empty() && st.top()!=')')
                    {
                        res2+=st.top();
                        st.pop();
                    }
                    if(!st.empty())
                    {
                        st.pop();
                    }
                }
                else
                {
                    while (!st.empty() && prec(st.top())>prec(s[i]))
                    {
                        res2+=st.top();
                        st.pop();
                    }
                    st.push(s[i]);
                } 
            }
            while (!st.empty())
            {
                res2+=st.top();
                st.pop();
            }
            reverse(res2.begin(),res2.end());
            cout<<res2;
        }
        void prefixOperations(string s)
        {
            cout<<"\n Prefix to Infix : ";
            for (int i=s.length()-1;i>=0; i--)
            {
                if((s[i]>='a' && s[i]<='z') || (s[i]>='A' && s[i]<='Z'))
                {
                    temp=s[i];
                    st.push(temp);
                }
                else
                {
                    a=st.top();
                    st.pop();
                    b=st.top();
                    st.pop();
                    c='('+a+s[i]+b+')';
                    st.push(c);
                }
            }
            res=st.top();
            st.pop();
            cout<<res;

            cout<<"\n Prefix to Postfix : ";
            for (int i=s.length()-1;i>=0; i--)
            {
                if((s[i]>='a' && s[i]<='z') || (s[i]>='A' && s[i]<='Z'))
                {
                    temp=s[i];
                    st.push(temp);
                }
                else
                {
                    a=st.top();
                    st.pop();
                    b=st.top();
                    st.pop();
                    c=a+b+s[i];
                    st.push(c);
                }
            }
            res=st.top();
            st.pop();
            cout<<res;
        }
        void postfixOperaions(string s)
        {
            cout<<"\n Postfix to Infix : ";
            for (int i=0;i<s.length(); i++)
            {
                if((s[i]>='a' && s[i]<='z') || (s[i]>='A' && s[i]<='Z'))
                {
                    temp=s[i];
                    st.push(temp);
                }
                else
                {
                    a=st.top();
                    st.pop();
                    b=st.top();
                    st.pop();
                    c='('+b+s[i]+a+')';
                    st.push(c);
                } 
            }
            res=st.top();
            st.pop();
            cout<<res;

            cout<<"\n Postfix to Prefix : ";
            for (int i=0;i<s.length(); i++)
            {
                if((s[i]>='a' && s[i]<='z') || (s[i]>='A' && s[i]<='Z'))
                {
                    temp=s[i];
                    st.push(temp);
                }
                else
                {
                    a=st.top();
                    st.pop();
                    b=st.top();
                    st.pop();
                    c=s[i]+b+a;
                    st.push(c);
                } 
            }
            res=st.top();
            st.pop();
            cout<<res;
        }
};
int main()
{
    stackOperations obj;
    string expr;
    int ch;
    cout<<"\n Enter any Expression : ";
    cin>>expr;
    cout<<"\n ******* MENU *******";
    cout<<"\n 1. Infix Operations";
    cout<<"\n 2. Prefix Operations";
    cout<<"\n 3. Postfix Operations";
    cout<<"\n 4. Exit";

    cout<<"\n Enter your Choice : ";
    cin>>ch;

    switch(ch)
    {
        case 1:
            obj.infixOperations(expr);
            break;
        case 2:
            obj.prefixOperations(expr);
            break;
        case 3:
            obj.postfixOperaions(expr);
            break;
        case 4:
            cout<<"\n Exiting...";
            return 1;    
        default:
            cout<<"\n Invalid Choice";        
            break; 
    }
    
    return 0;
}
    