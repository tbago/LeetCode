//
//  main.cpp
//  best-time-to-buy-and-sell-stock
//
//  Created by tbago on 2018/8/20.
//  Copyright © 2018年 tbago. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxValue = 0;
        for (uint32_t i = 0; i < prices.size(); i++) {
            int buyValue = prices[i];
            for (uint32_t j = i + 1; j < prices.size(); j++) {
                int saleValue = prices[j];
                if (saleValue - buyValue > maxValue) {
                    maxValue = saleValue -buyValue;
                }
            }
        }
        return maxValue;
    }
};

int main(int argc, const char * argv[]) {
    vector<int> inputDemo = {7,1,5,3,6,4};
    Solution solution;
    cout<<"max value:"<<solution.maxProfit(inputDemo)<<endl;
    return 0;
}
