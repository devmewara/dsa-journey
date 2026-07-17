#include<iostream>
#include<string>
#include<stack>
using namespace std;


bool findRedundantBrackets(string &s)
{
    // Write your code here.
    stack<char> st;
    for (int i=0;i<s.length();i++){
        if (s[i]=='(' || s[i]=='+' || s[i]=='-' || s[i]=='*' || s[i]=='/'){
            st.push(s[i]);
        }
        else{
            if (s[i]==')'){
                bool isRedundant=1;
                while (st.top()!='('){
                    char top=st.top();
                    if (top=='+' || top=='-' || top=='*' || top=='/'){
                        isRedundant=0;
                        st.pop();
                    }
                }
                if (isRedundant){
                    return 1;
                }
                else{
                    st.pop();
                }
            }
        }
    }
    return 0;
}


//Driver Code

int main(){
    string s;
    cin>>s;
    if (findRedundantBrackets(s)){
        cout<<"YES"<<endl;
    }
    else{
        cout<<"NO"<<endl;
    }
    return 0;
}