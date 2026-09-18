#include "SalesmanProblem.h"

#include <algorithm>
#include <random>

const int kInfinity = 2147483647;

int** AllocateMatrix(int num_cities) 
{
    int** matrix = new int* [num_cities];
    for (int i = 0; i < num_cities; ++i) 
    {
        matrix[i] = new int[num_cities];
        for (int j = 0; j < num_cities; ++j) 
        {
            matrix[i][j] = 0;
        }
    }
    return matrix;
}

void FreeMatrix(int** matrix, int num_cities) 
{
    if (matrix == nullptr) return;
    for (int i = 0; i < num_cities; ++i) 
    {
        delete[] matrix[i];
    }
    delete[] matrix;
}

void FillRandomMatrix(int** matrix, int num_cities, int min_cost, int max_cost) 
{
    std::random_device rd;
    std::mt19937 generator(rd());
    std::uniform_int_distribution<int> dist(min_cost, max_cost);

    for (int i = 0; i < num_cities; ++i) 
    {
        for (int j = 0; j < num_cities; ++j) 
        {
            if (i == j) {
                matrix[i][j] = 0;
            }
            else 
            {
                matrix[i][j] = dist(generator);
            }
        }
    }
}


ExactResult SolveExactTsp(int** matrix, int num_cities, int start_city) 
{
    int perm_size = num_cities - 1;
    int* perm = new int[perm_size];

    int index = 0;
    for (int i = 0; i < num_cities; ++i) 
    {
        if (i != start_city) 
        {
            perm[index++] = i;
        }
    }

    std::sort(perm, perm + perm_size);

    ExactResult res;
    res.best_cost = kInfinity;
    res.worst_cost = -1;
    res.path_size = num_cities + 1;
    res.best_path = new int[res.path_size];

    do 
    {
        int current_cost = matrix[start_city][perm[0]];
        for (int i = 0; i < perm_size - 1; ++i) 
        {
            current_cost += matrix[perm[i]][perm[i + 1]];
        }
        current_cost += matrix[perm[perm_size - 1]][start_city];

        if (current_cost < res.best_cost) 
        {
            res.best_cost = current_cost;
            res.best_path[0] = start_city;
            for (int i = 0; i < perm_size; ++i) 
            {
                res.best_path[i + 1] = perm[i];
            }
            res.best_path[res.path_size - 1] = start_city;
        }

        if (current_cost > res.worst_cost) 
        {
            res.worst_cost = current_cost;
        }
    } while (std::next_permutation(perm, perm + perm_size));

    delete[] perm;
    return res;
}

void FreeExactResult(ExactResult& result) 
{
    if (result.best_path != nullptr) 
    {
        delete[] result.best_path;
        result.best_path = nullptr;
    }
}