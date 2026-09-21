#include "SalesmanProblem.h"

#include <algorithm>
#include <random>

const int kInf = 2147483647;

int** NewMatrix(int n)
{
    int** matrix = new int* [n];
    for (int i = 0; i < n; ++i) 
    {
        matrix[i] = new int[n];
        for (int j = 0; j < n; ++j) 
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

void FillMatrix(int** matrix, int num_cities, int min_cost, int max_cost)
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


ExactRes SolveExact(int** matrix, int num_cities, int start_city)
{
    int perm_size = num_cities - 1;
    int* perm = new int[perm_size];

    int index = 0;
    for (int i = 0; i < num_cities && index < perm_size; ++i)
    {
        if (i != start_city) 
        {
            perm[index++] = i;
        }
    }

    std::sort(perm, perm + perm_size);

    ExactRes  res;
    res.best_cost = kInf;
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
            for (int i = 0; i < perm_size && (i + 1) < res.path_size; ++i)
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


HeurRes SolveNN(int** matrix, int num_cities, int start_city)
{
    bool* visited = new bool[num_cities];
    for (int i = 0; i < num_cities; ++i) 
    {
        visited[i] = false;
    }

    HeurRes res;
    res.path_size = num_cities + 1;
    res.path = new int[res.path_size];
    res.cost = 0;

    int current_city = start_city;
    visited[current_city] = true;
    res.path[0] = current_city;

    for (int step = 1; step < num_cities; ++step) 
    {
        int nearest_city = -1;
        int min_distance = kInf;

        for (int next_city = 0; next_city < num_cities; ++next_city) 
        {
            if (!visited[next_city] && matrix[current_city][next_city] < min_distance) 
            {
                min_distance = matrix[current_city][next_city];
                nearest_city = next_city;
            }
        }

        visited[nearest_city] = true;
        res.path[step] = nearest_city;
        res.cost += min_distance;
        current_city = nearest_city;
    }
    
    res.cost += matrix[current_city][start_city];
    res.path[res.path_size - 1] = start_city;

    delete[] visited;
    return res;
}


void FreeExact(ExactRes& res)
{
    if (res.best_path != nullptr) 
    {
        delete[] res.best_path;
        res.best_path = nullptr;
    }
}

void FreeHeur(HeurRes& res)
{
    if (res.path != nullptr) 
    {
        delete[] res.path;
        res.path = nullptr;
    }
}

double GetQuality(int best_cost, int worst_cost, int heur_cost)
{
    if (worst_cost == best_cost) 
    {
        return 100.0;
    }
    double quality = (static_cast<double>(worst_cost - heur_cost) /
        static_cast<double>(worst_cost - best_cost)) * 100.0;
    if (quality < 0.0) return 0.0;
    if (quality > 100.0) return 100.0;
    return quality;
}