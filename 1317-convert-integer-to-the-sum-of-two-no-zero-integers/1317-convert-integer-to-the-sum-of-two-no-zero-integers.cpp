class Solution {
public:
    bool check(int x) 
    {
        while(x>0) 
        {
            if(x%10==0)
            {
                return false;
            }
            x/=10;
        }
        return true;
    }
    vector<int> getNoZeroIntegers(int n) {
        for (int i = 1; i < n; ++i) {
            int j = n - i;
            if (check(i) && check(j)) {
                return {i, j};
            }
        }
        return {};
    }
};