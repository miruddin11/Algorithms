class Solution {
public:
    long long maximumSumOfHeights(vector<int>& maxHeights) {
        int n = maxHeights.size();
        vector<long long> prefix(n, 0), suffix(n, 0);
        stack<int> st;
        st.push(0);    
        prefix[0] = maxHeights[0];
        for (int i = 1; i < n; i++) {
            while(!st.empty() && maxHeights[st.top()] > maxHeights[i])
                st.pop();
            if(st.empty()){
                prefix[i] = 1ll* (i+1) * maxHeights[i];
                st.push(i);
                continue;
            }
            int it = st.top();
            prefix[i] = prefix[it] + (long long)(i-it) * maxHeights[i];
            st.push(i);
        }
        while(!st.empty()) st.pop();
        st.push(n-1);    
        suffix[n-1] = maxHeights[n-1];
        for (int i = n - 2; i >= 0; i--) {
        while(!st.empty() && maxHeights[st.top()] > maxHeights[i])
                st.pop();
            
            if(st.empty()){
                suffix[i] = 1ll * (n-i) * maxHeights[i];
                st.push(i);
                continue;
            }
            int it = st.top();
            suffix[i] = suffix[it] + (long long)(it-i) * maxHeights[i];
            st.push(i);
        }
        long long maxSum = 0;
        for (int i = 0; i < n; i++) {
            maxSum = max(maxSum, prefix[i] + suffix[i] - maxHeights[i]);
        }
        return maxSum;
    }
};