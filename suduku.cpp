#include <iostream>
#include <vector>
#include <unordered_set>
//#include <string>

using namespace std;


class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_set<string> seen;
        for(int i=0; i<9; i++){
            for(int j=0; j<9; j++){
                char number = board[i][j];
                if(number != '.'){
                    string row = rowString(number, i);
                    string col = colString(number, j);
                    string block = blockString(number, i, j);
                    
					//Using property of insertion in unordered_set explained above.
                    if(!seen.insert(row).second || 
                        !seen.insert(col).second ||
                        !seen.insert(block).second
                        ){
                            return false;
                        }
                }
            }
        }
        return true;
    }
	
	private:
	string rowString(char number, int row){
        string stringToInsert = "";
        stringToInsert += to_string(number-'0') + " in row " + to_string(row);
        return stringToInsert;
    }
    
    string colString(char number, int col){
        string stringToInsert = "";
        stringToInsert += to_string(number-'0') + " in col " + to_string(col);
        return stringToInsert;
    }
    
    string blockString(char number, int row, int col){
        string stringToInsert = "";
        stringToInsert += to_string(number-'0') + " in block " + to_string(row/3 * 3 + col/3);
        return stringToInsert;
    }
};

int main()
{

    return 0;
}