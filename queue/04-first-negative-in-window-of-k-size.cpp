#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Solution {
  public:
    vector<int> firstNegInt(vector<int>& arr, int k) {
        deque<int> dq;
        vector<int> ans;
        for (int i=0;i<k;i++){
            if (arr[i]<0){
                dq.push_back(i);
            }
        }
        if (dq.size()>0){
            ans.push_back(arr[dq.front()]);
        }
        else{
            ans.push_back(0);
        }
        for (int i=k;i<arr.size();i++){
            if (!dq.empty() && i-dq.front()>=k){
                dq.pop_front();
            }
            if (arr[i]<0){
                dq.push_back(i);
            }
            if (dq.size()>0){
                ans.push_back(arr[dq.front()]);
            }
            else{
                ans.push_back(0);
            }
        }
        return ans;
    }
};


// Driver code
int main(){
    cout<<"Enter n and n elements: "<<endl;
    int n;
    cin>>n;
    vector<int> arr;
    for (int i=0;i<n;i++){
        int element;
        cin>>element;
        arr.push_back(element);
    }
    cout<<"Enter size of window: ";
    int k;
    cin>>k;

    Solution s;
    vector<int> ans=s.firstNegInt(arr,k);
    for (int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
}