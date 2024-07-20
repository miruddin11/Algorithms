class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        unordered_map<string,int> mp;
        for(auto &s:words){
            mp[s]+=1;
        }
        int ans=0;
        bool centreUsed=false;
        for(auto &s:words){
            string rev=s;
            reverse(rev.begin(),rev.end());
            if(s!=rev){
                if(mp[s]>0&&mp[rev]>0){
                    mp[s]-=1;
                    mp[rev]-=1;
                    ans+=4;
                }
            }
            else{
                if(mp[s]>=2){
                    mp[s]-=2;
                    ans+=4;
                }else if(mp[s]==1&&centreUsed==false){
                    ans+=2;
                    mp[s]-=1;
                    centreUsed=true;
                }
            }
        }
        return ans;
    }
};