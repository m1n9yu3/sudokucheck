// 数独check.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

char matrix[] = {
    0,0,0,0,0,0,7,3,1,
    0,0,7,0,5,0,0,0,0,
    0,6,1,0,0,8,0,2,9,

    8,0,6,5,7,1,0,9,0,
    1,2,0,0,8,3,4,0,0,
    0,0,0,6,2,4,8,0,5,

    5,0,4,0,6,2,9,7,3,
    7,9,3,4,1,0,2,0,6,
    0,8,0,3,9,0,0,5,4
};

int check() {
    int flag = 0;
    int flag1 = 1;
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {

            // 判断竖行
            flag = 0;
            for (int i1 = 0; i1 < 9; i1++) {
                flag = flag | (flag1 << matrix[i1 * 9 + j]);
            }

            // 判断横行
            for (int j1 = 0; j1 < 9; j1++) {
                flag = flag ^ (flag1 << matrix[i * 9 + j1]);
            }

            if (flag != 0) {
                return 0;
            }

        }
    }

    // 判断九宫 是否重复
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {

            // 遍历九宫
            flag = 0;
            for (int i1 = 0; i1 < 3; i1++) {
                for (int j1 = 0; j1 < 3; j1++) {
                    flag = flag | (flag1 << matrix[((i * 3) + i1) * 9 + ((j * 3) + j1)]);
                }
            }
            if (flag != 0x3fe) {
                return 0;
            }

        }
    }

    return 1;
}

int init() {
    char flag[255] = { 0 };
    
    scanf_s("%s", flag, 255);
    //puts(flag);
    if (strlen(flag) != 36) {
        exit(0);
    }

    for (int i = 0; i < 36; i++) {
        if (flag[i] > '9' || flag[i] <= '0') {
            exit(0);
        }
    }

    // 初始化 矩阵
    int index = 0;
    for (int i = 0; i < 81; i++) {
        if (matrix[i] == 0) {
            matrix[i] = flag[index] - 48;
            index++;
        }
    }

}

int main()
{
    //std::cout << "Hello World!\n";

    init();
    if (check()) {
        printf("Sucess!!\n");
    }
    else {
        printf("Wrong!!\n");
    }
}


/*****************
Trail:
 [[9 5 8 2 4 6 7 3 1]
 [2 3 7 1 5 9 6 4 8]
 [4 6 1 7 3 8 5 2 9]
 [8 4 6 5 7 1 3 9 2]
 [1 2 5 9 8 3 4 6 7]
 [3 7 9 6 2 4 8 1 5]
 [5 1 4 8 6 2 9 7 3]
 [7 9 3 4 1 5 2 8 6]
 [6 8 2 3 9 7 1 5 4]]

958246231964847354325967379118586271

***********************/