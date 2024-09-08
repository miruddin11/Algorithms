class Solution {
public:
    string binary(int n)
    {
        string ans;
        while(n!=0)
        {
            int v=n&1;
            ans+=to_string(v);
            n=n>>1;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
    string convertDateToBinary(string date) {
        string ans;
        ans+=binary(stoi(date.substr(0,4)));
        ans+=date[4];
        ans+=binary(stoi(date.substr(5,2)));
        ans+=date[7];
        ans+=binary(stoi(date.substr(8,2)));
        return ans;
    }
};