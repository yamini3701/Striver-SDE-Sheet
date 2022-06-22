class Solution {
public:
    void sortColors(vector<int>& nums) {
        int cnt0=0;
        int cnt1=0;
        int cnt2=0;
        
        for(int i=0 ; i<nums.size() ; i++){
            if(nums[i]==0) cnt0++;
            if(nums[i]==1) cnt1++;
            if(nums[i]==2) cnt2++;
        }
        
        for(int i=0 ; i<nums.size() ; i++){
            while(cnt0>0){
                nums[i++]=0;
                cnt0--;
            }

            while(cnt1>0){
                nums[i++]=1;
                cnt1--;
            }

            while(cnt2>0){
                nums[i++]=2;
                cnt2--;
            }
        }
    }
};s
