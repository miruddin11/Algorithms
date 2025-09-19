class Spreadsheet {
public:
    unordered_map<string, int> sheet;
    Spreadsheet(int rows) {}

    void setCell(string cell, int value) { sheet[cell] = value; }

    void resetCell(string cell) { sheet.erase(cell); }
    bool containsAlphabet(string s) {
        for (auto& ch : s) {
            if (isalpha(ch)) {
                return true;
            }
        }
        return false;
    }
    int findVal(string x) {
        if (containsAlphabet(x)) {
            return (sheet.count(x) > 0) ? sheet[x] : 0;
        } else {
            return stoi(x);
        }
    }
    int getValue(string formula) {
        string x = "", y = "";
        bool yStart = false;
        for (int i = 1; i < formula.size(); i++) {
            if (yStart) {
                y += formula[i];
            } else if (formula[i] != '+') {
                x += formula[i];
            } else {
                yStart = true;
            }
        }
        int val1 = findVal(x);
        int val2 = findVal(y);
        return val1 + val2;
    }
};

/**
 * Your Spreadsheet object will be instantiated and called as such:
 * Spreadsheet* obj = new Spreadsheet(rows);
 * obj->setCell(cell,value);
 * obj->resetCell(cell);
 * int param_3 = obj->getValue(formula);
 */