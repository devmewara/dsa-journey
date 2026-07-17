#include<iostream>
#include<stack>
#include<string>
using namespace std;


bool isValidParenthesis(string s)
{
    stack<char> st;
    for (int i=0;i<s.length();i++){
        char ch=s[i];
        if (ch=='(' || ch=='{' || ch=='['){
            st.push(ch);
        }
        else{
            if (!st.empty()){
                char top=st.top();
                if ((ch==')' && top=='(') || (ch=='}' && top=='{') || (ch==']' && top=='[')){
                    st.pop();
                }
                else{
                    return 0;
                }
            }
            else{
                return 0;
            }
        }
    }
    if (st.empty()){
        return 1;
    }
    else{
        return 0;
    }
}


//Driver Code

int main(){
    string s;
    cin>>s;
    if (isValidParenthesis(s)){
        cout<<"YES"<<endl;
    }
    else{
        cout<<"NO"<<endl;
    }
    return 0;
}