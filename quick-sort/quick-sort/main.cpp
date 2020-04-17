//
//  main.cpp
//  quick-sort
//
//  Created by tbago on 2020/4/16.
//  Copyright © 2020 tbago. All rights reserved.
//

#include <iostream>

void displayArray(int array[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

class Solution {
public:
    void QuickSort(int array[], int start, int end) {
        if (start < end) {
            int middleIndex = InnerSort(array, start, end);

            QuickSort(array, start, middleIndex - 1);
            QuickSort(array, middleIndex+1, end);
        }
    }
private:
    int InnerSort(int array[], int start, int end) {
        int key = array[start];
        while (start < end) {
            while (start < end && array[end] > key) {
                end--;
            }

            if (start < end) {
                array[start] = array[end];
            }

            while (start < end && array[start] <= key) {
                start++;
            }

            if (start < end) {
                array[end] = array[start];
            }
        }
        array[start] = key;
        return start;
    }
};

int main(int argc, const char * argv[]) {

    int size = 25;                            //数组大小
    int array[25] = { 0 };                    //数组初始化
    for (int j = 0; j < size; j++) {
        array[j] = rand() % 1000;        //随机生成数组 0~999
    }
    printf("origin array:\n");
    displayArray(array, size);

    Solution solution;
    solution.QuickSort(array, 0, size-1);
    printf("sort array:\n");
    displayArray(array, size);
    return 0;
}
