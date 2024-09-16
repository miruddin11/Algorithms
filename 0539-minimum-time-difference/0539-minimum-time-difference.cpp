class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        int n=timePoints.size();
        vector<int> times(n);
        for(int i=0;i<n;i++)
        {
            string s=timePoints[i];
            int h=(s[0]-'0')*10+(s[1]-'0');
            int m=(s[3]-'0')*10+(s[4]-'0');
            int total_minutes=h*60+m;
            times[i]=total_minutes;
        }
        sort(times.begin(),times.end());
        int mnTime=INT_MAX;
        for(int i=1;i<n;i++)
        {
            mnTime=min(mnTime,times[i]-times[i-1]);
        }
        mnTime=min(mnTime,(24*60-times[n-1])+times[0]);
        return mnTime;
    }
};