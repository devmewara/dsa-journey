#include<iostream>
#include<string>
#include<stack>
using namespace std;


int findMinimumCost(string str) {
  //odd condition
  if ((str.length())%2==1){
    return -1;
  }
  stack<char> s;
  for (int i=0;i<str.length();i++){
    if (str[i]=='{'){
      s.push(str[i]);
    }
    else{
      if (!s.empty() && s.top()=='{'){
        s.pop();
      }
      else{
        s.push(str[i]);
      }
    }
  }
  //stack now contains invalid expresion
  int a=0,b=0;
  while (!s.empty()){
    if (s.top()=='{'){
      a++;
    }
    else{
      b++;
    }
    s.pop();
  }
  return (a+1)/2+(b+1)/2;
}


//Driver Code

int main(){
    string s;
    cin>>s;
    cout<<findMinimumCost(s)<<endl;
    return 0;
}