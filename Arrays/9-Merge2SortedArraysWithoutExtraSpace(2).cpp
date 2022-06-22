class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        if(n==0) return;
        if(m==0){
            for(int i=0;i<nums2.size();i++){
                nums1[i] = nums2[i];
            }
            return;
        }
        int j = 0;
        for(int i=0;i<m;i++){
            if(nums1[i] > nums2[j]){
                swap(nums1[i],nums2[j]);
                if((j+1)<n) j++;
            }
        }
        j = 0;
        for(int i = m;i<nums1.size();i++){
            nums1[i] = nums2[j];
            j++;
        }
        sort(nums1.begin(),nums1.end());
    }
};
