#include<iostream>
#include<vector>
#include<stack>
using namespace std;


vector<int> nextSmallerElement(vector<int> &arr, int n)
{
    stack<int> s;
    vector<int> ans(arr.size(),-1);
    s.push(-1);
    for (int i=arr.size()-1;i>=0;i--){
        while (s.top()>=arr[i]){
            s.pop();
        }
        ans[i]=s.top();
        s.push(arr[i]);
    }
    return ans;
}


// Driver code

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for (int i=0;i<n;i++){
        cin>>arr[i];
    }
    vector<int> ans=nextSmallerElement(arr,n);
    for (int i=0;i<n;i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
}