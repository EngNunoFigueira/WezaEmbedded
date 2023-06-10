#include <iostream>
#include <stdio.h>
#include <map>
#include <vector>
#include <thread>
#include <future>
#include <utility>
#include <memory>
#include <iterator>
#include <numeric>
#include <algorithm>
#include <unordered_map>
#include <functional>
#include <initializer_list>
#include <cstddef>
#include <cerrno>
#include <cfenv>
#include <cmath>
#include <fstream>
#include <cstring>
#include <iomanip>
#include <list>
#include <sstream>
#include <regex>

bool isSudoku(int sudoku[][3])
{
    int sudokuComplet {0};
    for (int i{0}; i < 3; i ++)
    {
        int repeated {0};
        for (int ii{0}; ii < 3; ii ++)
        {
            if (sudoku[i][ii] == 0 | sudoku[i][ii] > 9 | repeated == sudoku[i][ii])
            {
                std::cout << "Sorry this time you don't complet a sudoku" << std::endl;
                return false;
            }
            repeated = sudoku[i][ii];
            sudokuComplet += sudoku[i][ii];
        }
    }

    if (sudokuComplet == 45)
    {
        std::cout << "Congratulation you have a sudoku" << std::endl;
        return true;
    }

    std::cout << "Sorry this time you don't complet a sudoku" << std::endl;
    return false;
}

int main()
{
    std::cout << "The exercise received a input parameter and we need to create the function" << std::endl;
    int sudoku1[3][3] = {{1, 2, 3}, {9, 7, 8}, {4, 5, 6}};
    int sudoku2[3][3] = {{1, 1, 3}, {6, 5, 4}, {8, 7, 9}};
    int sudoku3[3][3] = {{0, 1, 2}, {6, 4, 5}, {9, 8, 7}};
    isSudoku(sudoku1);
    isSudoku(sudoku2);
    isSudoku(sudoku3);

    return 0;
}
