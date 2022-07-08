class three{
    public:
        int val, idx, jdx;
};

struct cmp{
    bool operator()(three a, three b){
        return a.val < b.val;
    }
};

vector<int> Solution::solve(vector<int> &a, vector<int> &b, int c) {
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    priority_queue<three,vector<three>,cmp> pq;
    set<pair<int,int>> s;
    vector<int> ans;
    int n=a.size();
    pq.push({a[n-1]+b[n-1], n-1, n-1});
    s.insert({n-1,n-1});
    while(ans.size()!=c){
        three th = pq.top();
        pq.pop();
        int val = th.val, i=th.idx, j=th.jdx;
        ans.push_back(val);
        if(i>0 and s.count({i-1,j})==0){
            pq.push({a[i-1]+b[j], i-1, j});
            s.insert({i-1,j});
        }
        if(j>0 and s.count({i,j-1})==0){
            pq.push({a[i]+b[j-1], i, j-1});
            s.insert({i,j-1});
        }
    }
    return ans;
}
