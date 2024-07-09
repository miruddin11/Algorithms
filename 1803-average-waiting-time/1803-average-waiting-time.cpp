class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        double ans=0;
        int n=customers.size();
        double curr_time=0;
        for(int i=0;i<n;i++)
        {
            double arrival_time=customers[i][0];
            double cook_time=customers[i][1];
            if(i==0) curr_time=arrival_time;
            if(curr_time<arrival_time) curr_time=arrival_time;
            double wait_time= (curr_time+cook_time) - arrival_time;
            ans = ans + wait_time;
            curr_time+= cook_time;
        }
        ans = ans / (double) n;
        return ans;
    }
};