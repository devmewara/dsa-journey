#include<iostream>
#include<stack>
#include<vector>
using namespace std;


void nextSmallBothSides(vector<int> &left,vector<int> &right,vector<int> heights){
    stack<int> s1;
    s1.push(-1);
    for (int i=heights.size()-1;i>=0;i--){
        while (s1.top()!=-1 && heights[s1.top()]>=heights[i]){
            s1.pop();
        }
        right[i]=s1.top();
        s1.push(i);
    }
    stack<int> s2;
    s2.push(-1);
    for (int i=0;i<heights.size();i++){
        while (s2.top()!=-1 && heights[s2.top()]>=heights[i]){
            s2.pop();
        }
        left[i]=s2.top();
        s2.push(i);
    }
}

int largestRectangleArea(vector<int>& heights) {
    int maxi=0;
    vector<int> left(heights.size());
    vector<int> right(heights.size());
    nextSmallBothSides(left,right,heights);
    for (int i=0;i<heights.size();i++){
        if (right[i]==-1){
            right[i]=heights.size();
        }
        maxi=max(maxi,(right[i]-left[i]-1)*heights[i]);
    }
    return maxi;
}


// Driver code

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for (int i=0;i<n;i++){
        cin>>arr[i];
    }
    int ans=largestRectangleArea(arr);
    cout<<ans<<endl;
}