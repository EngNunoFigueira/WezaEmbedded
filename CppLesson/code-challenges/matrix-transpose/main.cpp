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

int** transposeAgivenMatrix (int sudoku[3][3])
{
    int **resultMransPoseMatrix = new int*[3];
    for (int col{0}; col < 3;  col++)
    {
        resultMransPoseMatrix[col] = new int[col];
    }

    for (int row{0}; row < 3; row ++)
    {
        for (int col{0}; col < 3;  col++)
        {
            resultMransPoseMatrix[col][row] = sudoku[row][col];
        }
    }

    return resultMransPoseMatrix;
}

int main()
{
    std::cout << "The exercise received a matrix and transpose their values" << std::endl;
    int matrixA[3][3] = {{1, 2, 3}, {9, 7, 8}, {4, 5, 6}};
    int matrixB[3][3] = {{1, 1, 3}, {6, 5, 4}, {8, 7, 9}};
    int matrixC[3][3] = {{0, 1, 2}, {6, 4, 5}, {9, 8, 7}};
    int** valuesTranspose = transposeAgivenMatrix(matrixA);

    std::cout<<"{ ";
    for (int row{0}; row < 3; row++)
    {   std::cout<<"{ ";
        for (int col{0}; col < 3; col++)
        {
           std::cout<<valuesTranspose[row][col]<<",";
        }
        std::cout<<"},";
    }
    std::cout<<" }"<<std::endl;

    return 0;
}
