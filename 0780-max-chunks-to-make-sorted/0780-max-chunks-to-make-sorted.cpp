class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int mxVal=-1;
        int n=arr.size();
        int chunkCount=0;
        for(int i=0;i<n;i++)
        {
            mxVal=max(arr[i],mxVal);
            if(mxVal==i){
                chunkCount+=1;
                mxVal=-1;
            }
        }
        return chunkCount;
    }
};