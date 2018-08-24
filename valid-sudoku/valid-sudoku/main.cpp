//
//  main.cpp
//  valid-sudoku
//
//  Created by tbago on 2018/8/23.
//  Copyright © 2018年 tbago. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        const int sudokuLine = 9;
        ///< 水平方向校验
//        for (uint32_t i = 0; i < sudokuLine; i++) {
//            for (uint32_t j = 0; j < sudokuLine; j++) {
//                if (board[i][j] == '.') {
//                    continue;
//                }
//                for (uint32_t k = j + 1; k < sudokuLine; k++) {
//                    if (board[i][k] == '.') {
//                        continue;
//                    }
//                    if (board[i][k] == board[i][j]) {
//                        return false;
//                    }
//                }
//            }
//        }
//        ///< 垂直方向校验
//        for (uint32_t i = 0; i < sudokuLine; i++) {
//            for (uint32_t j = 0; j < sudokuLine; j++) {
//                if (board[j][i] == '.') {
//                    continue;
//                }
//                for (uint32_t k = j + 1; k < sudokuLine; k++) {
//                    if (board[k][i] == '.') {
//                        continue;
//                    }
//                    if (board[k][i] == board[j][i]) {
//                        return false;
//                    }
//                }
//            }
//        }
        ///<3*3校验
        for (uint32_t i = 0; i < sudokuLine; i++) {
            for (uint32_t j = 0; j < sudokuLine; j++) {
                cout<<"compare index:"<<i/3*3 + j/3<<","<<j%3<<endl;
            }
            cout<<"counter"<<endl;
        }
        return true;
    }
};

int main(int argc, const char * argv[]) {
    vector<vector<char>> inputDemo;
    vector<char> lineOne    = {'5','3','.','.','7','.','.','.','.'};
    vector<char> lineTwo    = {'6','.','.','1','9','5','.','.','.'};
    vector<char> lineThree  = {'.','9','8','.','.','.','.','6','.'};
    vector<char> lineFour   = {'8','.','.','.','6','.','.','.','3'};
    vector<char> lineFive   = {'4','.','.','8','.','3','.','.','1'};
    vector<char> lineSix    = {'7','.','.','.','2','.','.','.','6'};
    vector<char> lineSeven  = {'.','6','.','.','.','.','2','8','.'};
    vector<char> lineEight  = {'.','.','.','4','1','9','.','.','5'};
    vector<char> lineNine   = {'.','.','.','.','8','.','.','7','9'};
    inputDemo.push_back(lineOne);
    inputDemo.push_back(lineTwo);
    inputDemo.push_back(lineThree);
    inputDemo.push_back(lineFour);
    inputDemo.push_back(lineFive);
    inputDemo.push_back(lineSix);
    inputDemo.push_back(lineSeven);
    inputDemo.push_back(lineEight);
    inputDemo.push_back(lineNine);
    Solution solution;
    cout<<"solution is "<<solution.isValidSudoku(inputDemo)<<endl;
    return 0;
}
