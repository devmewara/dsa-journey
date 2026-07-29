#include<iostream>
#include<vector>
using namespace std;

class Solution {
  public:
    int startStation(vector<int> &gas, vector<int> &cost) {
        int deficit=0;
        int balance=0;
        int start=0;
        int n=gas.size();
        for (int i=0;i<n;i++){
            balance+=(gas[i]-cost[i]);
            if (balance<0){
                deficit+=balance;
                balance=0;
                start=i+1;
            }
        }
        if (deficit+balance>=0){
            return start;
        }
        return -1;
        
    }
};


// Driver code
int main(){
    cout<<"Enter n and n pairs of elements: "<<endl;
    int n;
    cin>>n;
    vector<int> gas;
    vector<int> cost;
    for (int i=0;i<n;i++){
        int x,y;
        cin>>x>>y;
        gas.push_back(x);
        cost.push_back(y);
    }

    Solution s;
    cout<<s.startStation(gas,cost);
}
