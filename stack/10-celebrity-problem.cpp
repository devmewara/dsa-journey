#include<iostream>
#include<vector>
#include<stack>
using namespace std;


// brute force 

/*
int celebrity(vector<vector<int>>& mat) {
    int n=mat.size();
    int column=0;
    for (int i=0;i<n;i++){
        int c=0;
        for (int j=0;j<n;j++){
            if (mat[i][j]==1){
                c++;
            }
        }
        if (c==1){
            column=i;
            int a=0;
            for (int i=0;i<n;i++){
                if (mat[i][column]==1){
                    a++;
                }
            }
            if (a==n){
                return column;
            }
            break;
        }
    }
    return -1;
}
*/

// Using stack

int celebrity(vector<vector<int>>& mat) {
    stack<int> s;
    int n=mat.size();
    for (int i=0;i<n;i++){
        s.push(i);
    }
    while (s.size()!=1){
        int a=s.top();
        s.pop();
        int b=s.top();
        s.pop();
        if (mat[a][b]==1){
            s.push(b);
        }
        else{
            s.push(a);
        }
    }
    int check=s.top();
    for (int i=0;i<n;i++){
        if (i !=check && mat[check][i]==1){
            return -1;
        }
    }
    for (int i=0;i<n;i++){
        if (i !=check && mat[i][check]==0){
            return -1;
        }
    }
    return check;
}


//Driver code

int main(){
    int n;
    cin>>n;
    vector<vector<int>> matrix(n,vector<int>(n));
    for (int i=0;i<n;i++){
        for (int j=0;j<n;j++){
            cin>>matrix[i][j];
        }
    }
    int ans=celebrity(matrix);
    cout<<ans<<endl;
}