class Solution {
public:
    vector<string> getWordsInLongestSubsequence(vector<string>& words, vector<int>& groups) {
        int n=words.size();
        vector<int> arr2(n,1);
        vector<int> arr3(n,1);
        vector<vector<int> > arr1(n+2,vector<int> (n+2));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                int diff=0;
                if(words[i].size()==words[j].size()){
                    for(int k=0;k<words[i].size();k++)
                    {
                        diff+= (words[i][k]!=words[j][k]);
                    }
                    arr1[i][j]=diff;
                }
            }
        }
        for(int i=0;i<=n-1;i++)
        {
            arr3[i]=i;
            for(int pi=0;pi<=i-1;pi++){
                if((groups[pi]!=groups[i]&&words[i].size()==words[pi].size()&&arr1[i][pi]==1)&&1+arr2[pi]>arr2[i]){
                    arr2[i]=1+arr2[pi];
                    arr3[i]=pi;
                }
            }
        }
        int ans=-1;
        int li=-1;
        for(int i=0;i<=n-1;i++){
            if(arr2[i]>ans){
                ans=arr2[i];
                li=i;
            }
        }
        vector<string> ti;
        ti.push_back(words[li]);
        while(arr3[li]!=li){
            li=arr3[li];
            ti.push_back(words[li]);
        }
        reverse(ti.begin(),ti.end());
        return ti;
    }
};