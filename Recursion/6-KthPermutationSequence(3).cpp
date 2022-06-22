class Solution {
public:
    
    void solve(string s, int index, vector<string> &ans){
        if(index==s.size()){
            ans.push_back(s);
            return;
        }
        for(int i=index ; i<s.size() ; i++){
            swap(s[i], s[index]);
            solve(s, index+1, ans);
            swap(s[i], s[index]);
        }
    }
    
    string getPermutation(int n, int k) {
        string s;
        vector<string > ans;
        for(int i=1 ; i<=n ; i++){
            s.push_back(i+'0');
        }
        solve(s,0,ans);
        sort(ans.begin(), ans.end());
        auto res = ans.begin() + (k-1);
        return *res;
    }
};
