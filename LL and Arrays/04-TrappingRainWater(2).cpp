class Solution {
public:
    int trap(vector<int>& height) {
        int size=height.size();
        
        int maxL[size];
        int maxR[size];
        
        //Max on left
        maxL[0]=height[0];
        for(int i=1 ; i<size ; i++){
            maxL[i]=max(maxL[i-1],height[i]);
        }
        
        //Max to right
        maxR[size-1]=height[size-1];
        for(int i=size-2 ; i>=0 ; i--){
            maxR[i]=max(maxR[i+1],height[i]);
        }
        
        int water = 0;
        for (int i = 0; i < size; i++) {
            water += min(maxL[i], maxR[i]) - height[i];
        }
        return water;
    }
};
