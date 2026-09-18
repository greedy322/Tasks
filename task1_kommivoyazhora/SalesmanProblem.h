#pragma once


struct ExactResult 
{
	int best_cost;
	int worst_cost;
	int* best_path;
	int path_size;
};


int** AllocateMatrix(int num_cities);
void FreeMatrix(int** matrix, int num_cities);


void FillRandomMatrix(int** matrix, int num_cities, int min_cost, int max_cost);


ExactResult SolveExactTsp(int** matrix, int num_cities, int start_city);


void FreeExactResult(ExactResult& result);