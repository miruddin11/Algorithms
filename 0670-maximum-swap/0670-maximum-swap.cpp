class Solution {
public:
    int maximumSwap(int num) {
        string s=to_string(num);
        int n=s.size();
        vector<int> rMax(10,-1);
        for(int i=0;i<n;i++)
        {
            rMax[s[i]-'0']=i;
        }
        for(int i=0;i<n;i++)
        {
            int currDigit=s[i]-'0';
            for(int digit=9;digit>currDigit;digit--)
            {
                if(rMax[digit]>i){
                    swap(s[i],s[rMax[digit]]);
                    return stoi(s);
                }
            }
        }
        return num;
    }
};