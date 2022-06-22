class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        int temp[m+n];
        int i = 0,j = 0,k = 0;
        while(i<m && j<n)
        {
            if(nums1[i] <= nums2[j])
                temp[k++] = nums1[i++];
            else 
                temp[k++] = nums2[j++];
        }
        
        while(i<m)
            temp[k++] = nums1[i++];
        
        while(j<n)
            temp[k++] = nums2[j++];
        
        if((m+n)%2 != 0)
            return (double)temp[(m+n)/2];
        else 
            return (double)(temp[((m+n) - 1) / 2] + temp[(m+n) / 2]) / 2.0;
    }
};
