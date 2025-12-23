class Solution {
public:
    int nextEvent(vector<vector<int>> &arr,int target,int low)
    {
        int high=arr.size()-1;
        int result=arr.size();
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            if(arr[mid][0]>target){
                result=mid;
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return result;
    }
    int maxTwoEvents(vector<vector<int>>& events) {
        int n=events.size();
        sort(events.begin(),events.end());
        vector<int> maxTillIndex(n,-1);
        maxTillIndex[n-1]=events[n-1][2];
        for(int i=n-2;i>=0;i--){
            maxTillIndex[i]=max(maxTillIndex[i+1],events[i][2]);
        }
        int maxSum=0;
        for(int i=0;i<n;i++){
            maxSum=max(maxSum,events[i][2]);
            int index=nextEvent(events,events[i][1],i+1);
            if(index<n){
                maxSum=max(maxSum,events[i][2]+maxTillIndex[index]);
            }
        }
        return maxSum;
    }
};