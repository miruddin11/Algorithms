class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) {
        vector<vector<int>> direction={{0,1},{1,0},{0,-1},{-1,0}};
        int steps=0;
        int dir=0;
        vector<vector<int>> result;
        result.push_back({rStart,cStart});
        while(result.size()<rows*cols)
        {
            if(dir==0||dir==2) steps++;

            for(int c=0;c<steps;c++)
            {
                rStart+=direction[dir][0];
                cStart+=direction[dir][1];
                if(cStart<=cols-1&&rStart<=rows-1&&cStart>=0&&rStart>=0){
                    result.push_back({rStart,cStart});
                }
            }
            dir=(dir+1)%4;
        }

        return result;
    }
};