class Solution {
public:
    int maximumGain(string s, int x, int y) {
        int n=s.size();
        int points=0;
        if(y>x)
        {
            vector<char> v;
            for(int i=0;i<n;i++)
            {
                char curr=s[i];
                if(!v.empty()&&v.back()=='b'&&curr=='a'){
                    points+=y;
                    v.pop_back();
                }
                else{
                    v.push_back(curr);
                }
            }
            vector<char> v1;
            for(int i=0;i<v.size();i++)
            {
                char curr=v[i];
                if(!v1.empty()&&v1.back()=='a'&&curr=='b'){
                    points+=x;
                    v1.pop_back();
                }
                else{
                    v1.push_back(curr);
                }
            }
        }
        else
        {
            vector<char> v;
            for(int i=0;i<n;i++)
            {
                char curr=s[i];
                if(!v.empty()&&v.back()=='a'&&curr=='b'){
                    points+=x;
                    v.pop_back();
                }
                else{
                    v.push_back(curr);
                }
            }
            vector<char> v1;
            for(int i=0;i<v.size();i++)
            {
                char curr=v[i];
                if(!v1.empty()&&v1.back()=='b'&&curr=='a'){
                    points+=y;
                    v1.pop_back();
                }
                else{
                    v1.push_back(curr);
                }
            }
        }
        return points;
    }
};