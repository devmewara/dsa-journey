#include<iostream>
#include<queue>
using namespace std;


class Solution {
  public:
    string firstNonRepeating(string &s) {
        string ans;
        queue<char> q;
        vector<int> v(26,0);
        for (int i=0;i<s.length();i++){
            v[s[i]-'a']++;
            if (v[s[i]-'a']==1){
                q.push(s[i]);
            }
            while (!q.empty() && v[q.front()-'a']!=1){
                    q.pop();
            }
            if (q.empty()){
                ans.push_back('#');
            }
            else{
                ans.push_back(q.front());
            }
        }
        return ans;
    }
};


// Driver code

int main(){
    Solution sol;
    string s;
    cin>>s;
    cout<<sol.firstNonRepeating(s)<<endl;
}