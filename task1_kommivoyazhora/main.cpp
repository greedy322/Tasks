#include <iostream>
#include <locale.h>
#include "SalesmanProblem.h"

using namespace std;

int main() 
{
    setlocale(LC_ALL, "rus");
    const int num_cities = 5;
    const int start_city = 0;

    int** matrix = AllocateMatrix(num_cities);
    FillRandomMatrix(matrix, num_cities, 10, 99);

    cout << "Выполнение алгоритма для " << num_cities << " городов:\n";
    ExactResult result = SolveExactTsp(matrix, num_cities, start_city);

    cout << "Лучшая стоимость: " << result.best_cost << "\n";
    cout << "Худшая стоимость: " << result.worst_cost << "\n";
    cout << "Оптимальный маршрут: ";

    for (int i = 0; i < result.path_size; ++i)
        cout << result.best_path[i] << (i + 1 < result.path_size ? " -> " : "\n");
    

    FreeExactResult(result);
    FreeMatrix(matrix, num_cities);

    return 0;
}