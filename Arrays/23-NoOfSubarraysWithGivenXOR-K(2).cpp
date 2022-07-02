int Solution::solve(vector<int> &A, int B) {
    map<int,int>freq;
    int xorr = 0;
    long long c=0;
    for(int i=0;i<A.size();i++){
        xorr^=A[i];
        if(xorr==B) c++;
        int y = xorr^B;
        if(freq.find(y)!=freq.end()){
            c=c+freq[y];
        }
        freq[xorr]++;
    }
    return c;
}
