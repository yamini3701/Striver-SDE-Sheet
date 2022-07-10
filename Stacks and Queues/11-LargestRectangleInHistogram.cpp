class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> left, right;
        stack<pair<int,int>> s; //stores element and its index
        int pseudoindex_left = -1;
        int pseudoindex_right = n;
        
        //NSL
        for(int i=0 ; i<n ; i++){
            if(s.size()==0)
                left.push_back(pseudoindex_left);
            else if(s.size()>0 && s.top().first<heights[i])
                left.push_back(s.top().second);
            else if(s.size()>0 && s.top().first>=heights[i]){
                while(s.size()>0 && s.top().first>=heights[i])
                    s.pop();
                if(s.size()==0)
                    left.push_back(pseudoindex_left);
                else
                    left.push_back(s.top().second);
            }
            s.push({heights[i],i});
        }
        
        while(!s.empty())
            s.pop();
        
        //NSR
        for(int i=n-1 ; i>=0 ; i--){
            if(s.size()==0)
                right.push_back(pseudoindex_right);
            else if(s.size()>0 && s.top().first<heights[i])
                right.push_back(s.top().second);
            else if(s.size()>0 && s.top().first>=heights[i]){
                while(s.size()>0 && s.top().first>=heights[i])
                    s.pop();
                if(s.size()==0)
                    right.push_back(pseudoindex_right);
                else
                    right.push_back(s.top().second);
            }
            s.push({heights[i],i});
        }
        reverse(right.begin(),right.end());
        
        int m=INT_MIN;
        for (int i=0;i<n;i++)
        {
          m = max(m,(right[i]-left[i]-1)*heights[i]); // taking max after finding area
        }
        return m;
    }
};
