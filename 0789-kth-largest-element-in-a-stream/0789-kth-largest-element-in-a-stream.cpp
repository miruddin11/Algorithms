class KthLargest {
public:
    priority_queue<int,vector<int>,greater<int>> pq;
    int pos;
    KthLargest(int k, vector<int>& nums) {
        for(auto &x:nums){
            pq.push(x);
        }
        pos=k;
    }
    int add(int val) {
        pq.push(val);
        int x=pos;
        while(pq.size()>x)
        {
            pq.pop();
        }
        return pq.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */