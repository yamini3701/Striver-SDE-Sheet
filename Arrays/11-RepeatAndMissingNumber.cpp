class Solution{
public:
    int *findTwoElement(int *arr, int n) {
        vector<int> substitute(n+1,0);
        for (int i = 0; i < n; i++)
        {
            substitute[arr[i]]++;
        }
        int *ans = new int[2];
        for (int i = 1; i <= n; i++)
        {
            if (substitute[i] == 0)
            {
                ans[1]=i;
            }
            if (substitute[i] > 1)
            {
                ans[0]=i;
            }
        }
        return ans;
    }
};
