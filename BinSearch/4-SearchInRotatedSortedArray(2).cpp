class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low = 0;
        int high = nums.size()-1;
        while(low<=high){
            int mid = (low+high) >> 1;
            
            if(nums[mid]==target)
                return mid;
            
            if(nums[low]<=nums[mid]){    //check if left half is sorted
                //element is in left half
                if(target>=nums[low] && target<=nums[mid])
                    high = mid-1;
                
                //element is in right half
                else
                    low = mid+1;
            }
            //if left half isnt sorted we check in right half
            else{
                if(target>=nums[mid] &&  target<=nums[high])
                    low = mid+1;
                else
                    high = mid-1;
            }
        }
        return -1;
    }
};
