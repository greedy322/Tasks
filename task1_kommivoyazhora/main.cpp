#include <chrono>
#include <iostream>
#include "SalesmanProblem.h"

int main() 
{
    const int dimensions[] = { 4, 6, 8, 10 };

    for (int d = 0; d < 4; ++d) 
    {
        int n = dimensions[d];
        std::cout << "Testing " << n << " cities\n";

        for (int run = 1; run <= 3; ++run) 
        {
            int** mat = NewMatrix(n);
            FillMatrix(mat, n, 10, 10000);

            auto t1 = std::chrono::high_resolution_clock::now();
            ExactRes exact = SolveExact(mat, n, 0);
            auto t2 = std::chrono::high_resolution_clock::now();
            auto exact_time =
                std::chrono::duration_cast<std::chrono::microseconds>(t2 - t1).count();

            auto t3 = std::chrono::high_resolution_clock::now();
            HeurRes heur = SolveNN(mat, n, 0);
            auto t4 = std::chrono::high_resolution_clock::now();
            auto heur_time =
                std::chrono::duration_cast<std::chrono::microseconds>(t4 - t3).count();

            double quality = GetQuality(exact.best_cost, exact.worst_cost, heur.cost);

            std::cout << "Run #" << run << ":\n";
            std::cout << "  Exact: best = " << exact.best_cost
                << ", worst = " << exact.worst_cost
                << ", time = " << exact_time << " mcs\n";
            std::cout << "  NN:    cost = " << heur.cost
                << ", time = " << heur_time << " mcs\n";
            std::cout << "  Quality: " << quality << "%\n";

            FreeExact(exact);
            FreeHeur(heur);
            FreeMatrix(mat, n);
        }
        std::cout << "\n";
    }

    return 0;
}