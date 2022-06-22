class Solution {
public:
    double myPow(double x, int n) {
        double ans=1.0;
        double p;
        if(n<0) 
            p=abs(n);
        else
            p=n;
        for(int i=0 ; i<p ; i++){
            ans=ans*x;
        }
        if(n<0){
            ans=1/ans;
        }
        return ans;
    }
};
