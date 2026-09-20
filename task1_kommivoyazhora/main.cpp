#include <iostream>
#include "SalesmanProblem.h"

int main()
{
    const int num_cities = 5;
    const int start_city = 0;

    int** matrix = NewMatrix(num_cities);
    FillMatrix(matrix, num_cities, 10, 99);

    std::cout << "Testing algorithm for " << num_cities << " cities:\n";
    ExactRes exact = SolveExact(matrix, num_cities, start_city);

    std::cout << "Best cost: " << exact.best_cost << "\n";
    std::cout << "Worst cost: " << exact.worst_cost << "\n";
    std::cout << "Optimal route: ";
    for (int i = 0; i < exact.path_size; ++i)
        std::cout << exact.best_path[i] << (i + 1 < exact.path_size ? " -> " : "\n");
    

    std::cout << "\nTesting Neighbor heuristic:\n";
    HeurRes heur = SolveNN(matrix, num_cities, start_city);

    std::cout << "Heuristic cost: " << heur.cost << "\n";
    std::cout << "Heuristic route: ";
    for (int i = 0; i < heur.path_size; ++i)
    {
        std::cout << heur.path[i]
            << (i + 1 < heur.path_size ? " -> " : "\n");
    }

    FreeExact(exact);
    FreeHeur(heur);
    FreeMatrix(matrix, num_cities);

    return 0;
}