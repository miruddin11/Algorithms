class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        unordered_set<string> bankSet(bank.begin(),bank.end());
        if(bankSet.count(endGene)==0){
            return -1;
        }
        string str="ACGT";
        queue<string> q;
        q.push(startGene);
        unordered_set<string> visited;
        visited.insert(startGene);
        int cnt=0;
        while(!q.empty()){
            int size=q.size();
            while(size--){
                string s=q.front();
                q.pop();
                if(s==endGene){
                    return cnt;
                }
                for(int i=0;i<8;i++){
                    if(s[i]==endGene[i]) continue;
                    int oldChar=s[i];
                    for(int j=0;j<4;j++){
                        if(oldChar==str[j]) continue;
                        s[i]=str[j];
                        if(bankSet.count(s)>0&&visited.count(s)==0){
                            q.push(s);
                            visited.insert(s);
                        }
                    }
                    s[i]=oldChar;
                }
            }
            cnt+=1;
        }
        return -1;
    }
};