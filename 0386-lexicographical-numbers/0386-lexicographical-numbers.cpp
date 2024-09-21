class Solution {
public:
    vector<int> ans;
    void solve(int Currnum,int n)
    {
        if(Currnum>n) return;
        ans.push_back(Currnum);
        for(int d=0;d<=9;d++)
        {
            int nextNum=Currnum*10+d;
            if(nextNum>n) return;
            solve(nextNum,n);
        }
    }
    vector<int> lexicalOrder(int n) {
        ans.clear();
        for(int num=1;num<=9;num++)
        {
            solve(num,n);
        }
        return ans;
    }
};