class Solution {
public:
    string countOfAtoms(string formula) {
        int n=formula.size();
        stack<unordered_map<string,int>> st;
        st.push(unordered_map<string,int>());
        int i=0;
        while(i<n)
        {
            if(formula[i]=='('){
                st.push(unordered_map<string,int>());
                i++;
            }
            else if(formula[i]==')'){
                unordered_map<string,int> curr=st.top();
                st.pop();
                i++;
                int currInteger=0;
                while(i<n&&isdigit(formula[i]))
                {
                    currInteger=currInteger*10+(formula[i]-'0');
                    i++;
                }
                if(currInteger>0){
                    for(auto &it:curr){
                        curr[it.first]=it.second*currInteger;
                    }
                }
                for(auto &it:curr)
                {
                    st.top()[it.first]+=it.second;
                }
            }
            else{
                string currElement;
                currElement.push_back(formula[i]);
                i++;
                while(i<n&&isalpha(formula[i])&&islower(formula[i]))
                {
                    currElement.push_back(formula[i]);
                    i++;
                }
                int currInteger=0;
                while(i<n&&isdigit(formula[i]))
                {
                    currInteger=currInteger*10+(formula[i]-'0');
                    i++;
                }
                st.top()[currElement]+=(currInteger==0)?1:currInteger;
            }
        }
        map<string,int> SortedMap(st.top().begin(),st.top().end());
        string ans;
        for(auto &it:SortedMap)
        {
            ans+=it.first;
            if(it.second>1){
                ans+=to_string(it.second);
            }
        }
        return ans;
    }
};