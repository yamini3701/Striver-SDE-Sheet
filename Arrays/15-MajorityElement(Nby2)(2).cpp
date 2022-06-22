class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int maxCount =((int)nums.size())/2;
        unordered_map <int,int> freq;
        for(int i:nums){
            if(++freq[i]>maxCount)
                return i;
        }
        return -1;
    }
};
