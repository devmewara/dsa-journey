#include<iostream>
#include<vector>
#include<stack>
using namespace std;

// Copied from "largest rectanlge area in a histogram"
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

// Main function
int maxArea(vector<vector<int>> &mat) {
    int n=mat.size();
    int m=mat[0].size();
    int maxi=0;
    vector<int> arr(m,0);
    for (int i=0;i<n;i++){
        for (int j=0;j<m;j++){
            if (mat[i][j]!=0){
                arr[j]+=mat[i][j];
            }
            else{
                arr[j]=0;
            }
        }
        maxi=max(maxi,largestRectangleArea(arr));
    }
    return maxi;
}


// Driver Code

int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>> matrix(n,vector<int>(m));
    for (int i=0;i<n;i++){
        for (int j=0;j<m;j++){
            cin>>matrix[i][j];
        }
    }
    int ans=maxArea(matrix);
    cout<<ans<<endl;
}

