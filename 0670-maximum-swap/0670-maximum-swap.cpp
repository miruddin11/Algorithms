class Solution {
public:
    int maximumSwap(int num) {
        string s=to_string(num);
        int n=s.size();
        vector<int> maxR(n);
        maxR[n-1]=n-1;
        for(int i=n-2;i>=0;i--)
        {
            if(s[maxR[i+1]]<s[i]){
                maxR[i]=i;
            }
            else{
                maxR[i]=maxR[i+1];
            }
        }
        for(int i=0;i<n;i++)
        {
            if(s[i]<s[maxR[i]]){
                swap(s[i],s[maxR[i]]);
                return stoi(s);
            }
        }
        return stoi(s);
    }
};