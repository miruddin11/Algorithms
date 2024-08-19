class Solution {
public:
    int subarrayBitwiseORs(vector<int>& arr) {
        unordered_set<int> ans;
        unordered_set<int> prev;
        prev.insert(arr[0]);
        for(int i=0;i<arr.size();i++)
        {
            unordered_set<int> curr;
            ans.insert(arr[i]);
            curr.insert(arr[i]);
            for(auto &x:prev){
                ans.insert(x|arr[i]);
                curr.insert(x|arr[i]);
            }
            prev=curr;
        }
        return ans.size();
    }
};