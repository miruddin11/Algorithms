class Solution {
public:
    int n,m;
    vector<vector<int>> dir={{0,1},{0,-1},{1,0},{-1,0}};
    bool isPossible(vector<vector<int>> &cells,int day){
        vector<vector<int>> grid(n+1,vector<int>(m+1,0));
        for(int i=0;i<day;i++){
            int ri=cells[i][0],ci=cells[i][1];
            grid[ri][ci]=1;
        }
        queue<pair<int,int>> q;
        for(int i=1;i<=m;i++){
            if(grid[1][i]==0){
                q.push({1,i});
                grid[1][i]=1;
            }
        }
        while(!q.empty()){
            auto p=q.front();
            q.pop();
            int r=p.first,c=p.second;
            for(int i=0;i<4;i++){
                int nr=r+dir[i][0],nc=c+dir[i][1];
                if(nr>0&&nc>0&&nr<=n&&nc<=m&&grid[nr][nc]==0){
                    grid[nr][nc]=1;
                    if(nr==n){
                        return true;
                    }
                    q.push({nr,nc});
                }
            }
        }
        return false;
    }
    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        n=row;
        m=col;
        int left=0,right=row*col;
        int ans=0;
        while(left<right-1){
            int mid=left+ (right-left)/2;
            if(isPossible(cells,mid)){
                ans=mid;
                left=mid;
            }
            else{
                right=mid;
            }
        }
        return ans;
    }
};