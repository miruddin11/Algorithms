class CustomStack {
public:
    int size;
    vector<int> v;
    CustomStack(int maxSize) {
        this->size=maxSize;
    }
    
    void push(int x) {
        if(v.size()==size){
            return;
        }
        v.push_back(x);
    }
    
    int pop() {
        if(v.size()==0){
            return -1;
        }
        int val=v.back();
        v.pop_back();
        return val;
    }
    
    void increment(int k, int val) {
        int n=v.size();
        int mn=min(k,n);
        for(int i=0;i<mn;i++){
            v[i]+=val;
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