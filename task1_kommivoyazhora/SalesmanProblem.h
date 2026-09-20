#pragma once


struct ExactRes
{
	int best_cost;
	int worst_cost;
	int* best_path;
	int path_size;
};

struct HeurRes
{
	int cost;
	int* path;
	int path_size;
};


int** NewMatrix(int num_cities);
void FreeMatrix(int** matrix, int num_cities);
void FillMatrix(int** matrix, int num_cities, int min_cost, int max_cost);


ExactRes SolveExact(int** matrix, int num_cities, int start_city);
HeurRes SolveNN(int** matrix, int num_cities, int start_city);

void FreeExact(ExactRes& res);
void FreeHeur(HeurRes& res);