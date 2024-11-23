class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        int m=box.size();
        int n=box[0].size();
        for(int r=0;r<m;r++)
        {
            int prev=n-1;
            for(int c=n-1;c>=0;c--)
            {
                if(box[r][c]=='#'){
                    swap(box[r][c],box[r][prev]);
                    prev-=1;
                }
                else if(box[r][c]=='*'){
                    prev=c-1;
                }
            }
        }
        vector<vector<char>> ans(n,vector<char>(m));
        for(int i=0;i<m;i++) 
        {
            for(int j=0;j<n;j++)
            {
                ans[j][m-1-i]=box[i][j];
            }
        }
        return ans;
    }
};

auto init = []()
{ 
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();