//Not working for negative numbers

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int max_sum=0;
        
        if(nums.size()==1){
            return nums[0];
        }
        
        for(int i=0 ; i<nums.size() ; i++){
            for(int j=i ; j<nums.size() ; j++){
                int sum=0;
                
                for(int k=i ; k<=j ; k++){
                    sum=sum+nums[k];
                }
                
                if(sum>max_sum){
                    max_sum=sum;
                }
            }
        }
        return max_sum;
    }
};
