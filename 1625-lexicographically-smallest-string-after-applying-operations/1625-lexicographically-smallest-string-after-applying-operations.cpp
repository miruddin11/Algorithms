class Solution {
public:
    string findLexSmallestString(string s, int a, int b) {
        queue<string> q;
        q.push(s);
        unordered_set<string> vis;
        vis.insert(s);
        string smallest=s;
        auto rotate=[&](string &curr,int b){
            reverse(curr.begin(),curr.end());
            reverse(curr.begin(),curr.begin()+b);
            reverse(curr.begin()+b,curr.end());
        };
        while(!q.empty()){
            string curr=q.front();
            q.pop();
            if(curr<smallest){
                smallest=curr;
            }
            // add operation
            string temp=curr;
            for(int i=1;i<temp.size();i+=2){
                temp[i]=((temp[i]-'0'+a)%10)+'0';
            }
            if(vis.count(temp)==0){
                vis.insert(temp);
                q.push(temp);
            }
            // rotate operation
            rotate(curr,b);
            if(vis.count(curr)==0){
                vis.insert(curr);
                q.push(curr);
            }
        }
        return smallest;
    }
};