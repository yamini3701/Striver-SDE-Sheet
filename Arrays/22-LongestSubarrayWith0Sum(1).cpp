class Solution{
    public:
    int maxLen(vector<int>&nums, int n)
    {   
        int maxLen=0;
        for(int i=0 ; i<n ; i++){
            int sum=0;
            for(int j=i ; j<n ; j++){
                sum += nums[j];
                if(sum==0){
                    maxLen=max(maxLen, j-i+1);
                }
            }
        }
        return maxLen;
    }
};
