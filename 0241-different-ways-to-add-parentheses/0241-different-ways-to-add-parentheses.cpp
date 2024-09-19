class Solution {
public:
    int find(int a,int b,char x)
    {
        if(x=='+') return a+b;
        else if(x=='-') return a-b;
        else return a*b;
    }
    vector<int> diffWaysToCompute(string expression) {
        bool flag=true;
        int n=expression.size();
        vector<int> ans;
        for(int i=0;i<n;i++)
        {
            if(!isdigit(expression[i])){
                flag=false;
                vector<int> left=diffWaysToCompute(expression.substr(0,i));
                vector<int> right=diffWaysToCompute(expression.substr(i+1));
                for(auto &x:left)
                {
                    for(auto &y:right)
                    {
                        int val=find(x,y,expression[i]);
                        ans.push_back(val);
                    }
                }
            }
        }
        if(flag) ans.push_back(stoi(expression));
        return ans;
    }
};