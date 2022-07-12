class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> res;
        int n=nums.size();
		for(int i=0;i<n-k+1;i++)
		{
			int mx = nums[i];
			for(int j=i+1 ; j<i+k ; j++) 
                mx=max(mx,nums[j]);
			res.push_back(mx);
		}
        return res;
    }
};
