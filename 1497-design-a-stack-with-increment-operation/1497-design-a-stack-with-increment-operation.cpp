class CustomStack {
public:
    int size;
    vector<int> v;
    vector<int> increments;
    CustomStack(int maxSize) {
        size=maxSize;
    }
    
    void push(int x) {
        if(v.size()==size){
            return;
        }
        v.push_back(x);
        increments.push_back(0);
    }
    
    int pop() {
        if(v.size()==0){
            return -1;
        }
        int idx=v.size()-1;
        if(idx>0){
            increments[idx-1]+=increments[idx];
        }
        int top_val=v[idx]+increments[idx];
        v.pop_back();
        increments.pop_back();
        return top_val;
    }
    
    void increment(int k, int val) {
        int idx=min(k,(int) v.size())-1;
        if(idx>=0){
            increments[idx]+=val;
        }
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */