long long getInversions(long long *nums, int n){
        int pairs = 0;
        for(int i=0 ; i<n ; i++){
            for(int j=i+1 ; j<n ; j++){
                if(nums[i]>nums[j])
                    pairs++;
            }
        }
        return pairs;
}
