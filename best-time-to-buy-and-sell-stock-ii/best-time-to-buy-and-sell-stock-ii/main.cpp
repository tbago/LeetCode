//
//  main.cpp
//  best-time-to-buy-and-sell-stock-ii
//
//  Created by tbago on 2018/8/21.
//  Copyright © 2018年 tbago. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int resultValue = 0;
        for (uint32_t i = 1; i < prices.size(); i++) {
            int buyValue = prices[i - 1];
            int saleValue= prices[i];
            int differValue = saleValue - buyValue;
            if (differValue > 0) {
                resultValue += differValue;
            }
        }
        return resultValue;
    }
};

int main(int argc, const char * argv[]) {
    vector<int> inputDemo = {7,1,5,3,6,4};
    Solution solution;
    cout<<"Solution is "<<solution.maxProfit(inputDemo)<<endl;
    return 0;
}
