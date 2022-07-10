class MedianFinder {
public:
    priority_queue<int> left;
    priority_queue<int, vector<int>, greater<int>> right;
    int size=0;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        size++;
        if(left.size()==right.size()){
            if(!left.empty() && left.top()>num){
                right.push(left.top());
                left.pop();
                left.push(num);
            }
            else{
                right.push(num);
            }
        }
        else{
            if(right.top()<num){
                left.push(right.top());
                right.pop();
                right.push(num);
            }
            else{
                left.push(num);
            }
        }
    }
    
    double findMedian() {
        if(size%2)
            return right.top();
        double ans = right.top()+left.top();
        return ans/2;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
