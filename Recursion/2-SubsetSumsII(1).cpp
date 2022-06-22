class Solution {
public:
    
    void solve(vector<int>& nums, int index, vector<int> ds, set<vector<int>>& res){
        if(index==nums.size()){
            sort(ds.begin(), ds.end());
            res.insert(ds);
            return;
        }
        ds.push_back(nums[index]);
        solve(nums, index+1, ds, res);
        ds.pop_back();
        solve(nums, index+1, ds, res);
    }
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans; //unique combinations
        set<vector<int>> res; //all generated combinations
        vector<int> ds;
        solve(nums, 0, ds, res);
        for(auto it = res.begin() ; it != res.end() ; it++){
            ans.push_back( *it);
        }
        return ans;
    }
};
