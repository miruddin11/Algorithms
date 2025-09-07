class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int> result(n);
        int i = 0;
        int x = -(n/2);
        if(n%2)
        {
            result[i++] = 0;
        }
        for(;i<n; i++) 
        {
            if(x == 0) x++;
            result[i] = x++;
        }
        return result;
    }
};