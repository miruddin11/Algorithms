class Spreadsheet {
public:
    vector<vector<int>> sheet;
    Spreadsheet(int rows) {
        sheet.resize(rows,vector<int>(26,0));
    }
    
    void setCell(string cell, int value) {
        int col=cell[0]-'A';
        int row=stoi(cell.substr(1))-1;
        sheet[row][col]=value;
    }
    
    void resetCell(string cell) {
        setCell(cell,0);
    }
    bool containsAlphabet(string s) {
        for(auto &ch:s){
            if(isalpha(ch)){
                return true;
            }
        }
        return false;
    }
    int findVal(string x) {
        if(containsAlphabet(x)){
            int col=x[0]-'A';
            int row=stoi(x.substr(1))-1;
            return sheet[row][col];
        }
        else{
            return stoi(x);
        }
    }
    int getValue(string formula) {
        string x="",y="";
        bool yStart=false;
        for(int i=1;i<formula.size();i++){
            if(yStart){
                y+=formula[i];
            }
            else if(formula[i]!='+'){
                x+=formula[i];
            }
            else{
                yStart=true;
            }
        }
        int val1=findVal(x);
        int val2=findVal(y);
        return val1+val2;
    }
};

/**
 * Your Spreadsheet object will be instantiated and called as such:
 * Spreadsheet* obj = new Spreadsheet(rows);
 * obj->setCell(cell,value);
 * obj->resetCell(cell);
 * int param_3 = obj->getValue(formula);
 */