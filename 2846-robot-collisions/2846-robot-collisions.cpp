class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        int n=positions.size();
        vector<int> actual_index(n);
        for(int i=0;i<n;i++)
        {
            actual_index[i]=i;
        }
        auto comp=[&](int &i,int &j){
            return positions[i]<positions[j];
        };
        sort(actual_index.begin(),actual_index.end(),comp);
        vector<int> ans;
        stack<int> st;
        for(auto &currIdx:actual_index)
        {
            if(directions[currIdx]=='R'){
                st.push(currIdx);
            }
            else{
                while(!st.empty()&&healths[currIdx]>0)
                {
                    int top_idx=st.top();
                    st.pop();
                    if(healths[currIdx]<healths[top_idx]){
                        healths[currIdx]=0;
                        healths[top_idx]-=1;
                        st.push(top_idx);
                    }
                    else if(healths[currIdx]>healths[top_idx]){
                        healths[top_idx]=0;
                        healths[currIdx]-=1;
                    }
                    else{
                        healths[top_idx]=0;
                        healths[currIdx]=0;
                    }
                }
            }
        }
        for(auto &x:healths){
            if(x>0) ans.push_back(x);
        }
        return ans;
    }
};