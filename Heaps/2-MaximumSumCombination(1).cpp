vector<int> Solution::solve(vector<int> &A, vector<int> &B, int k) {
    priority_queue<int> pq;
    vector<int> ans;
    for(int i=0 ; i<A.size() ; i++){
        for(int j=0 ; j<B.size() ; j++){
            pq.push(A[i]+B[j]);
            if(pq.size()>k){
                pq.pop();
            }
        }
    }
    while(!pq.empty()){
        ans.push_back(pq.top());
        pq.pop();
    }
    sort(ans.begin(), ans.end());
}

