class StockSpanner {
public:
    vector<int> v;
    stack<pair<int,int>> s;
    int count;
    StockSpanner() {
        count=0;
    }
    
    int next(int price) {
        if(s.empty()){
            v.push_back(-1);
            s.push({price,count});
            count++;
            return 1;
        }
        else{
            while(!s.empty() && s.top().first<=price){
                s.pop();
            }
            if(s.empty())
                v.push_back(-1);
            else
                v.push_back(s.top().second);
        }
        s.push({price,count});
        count++;
        return count-1-v[count-1];
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
