class Solution {
public:
    string getSum(string str)
    {
        int sum=0;
        for(auto &ch:str){
            sum+=(ch-'0');
        }
        return to_string(sum);
    }
    string digitSum(string s, int k) {
        while(s.size()>k){
            string temp="";
            for(int i=0;i<s.size();i+=k){
                int sizeLeft=s.size()-i;
                int length=min(k,sizeLeft);
                string group=s.substr(i,length);
                temp+=getSum(group);
            }
            s=temp;
        }
        return s;
    }
};