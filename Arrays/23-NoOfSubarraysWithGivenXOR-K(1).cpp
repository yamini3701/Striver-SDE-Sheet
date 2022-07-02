int Solution::solve(vector<int> &A, int B) {
    long long count=0;
    for(int i=0 ; i<A.size() ; i++){
        int curr_xor=0;
        for(int j=i ; j<A.size() ; j++){
            curr_xor ^= A[j];
            if(curr_xor==B){
                count++;
            }
        }
    }
    return count;
}
