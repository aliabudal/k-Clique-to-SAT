#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
	if (argc < 2)
	{
		printf("Correct usage: ./kCliqueBKT input_file\n");
		return 1;
	}
	FILE *fin = fopen(argv[1], "r");

	if (!fin)
	{
		printf("could not open input file\n");
		return 2;
	}

	int K;
	fscanf(fin, "%d", &K);
	int N;
	fscanf(fin, "%d", &N);
	int M;
	fscanf(fin, "%d", &M);

	int **G;
	G = (int**)calloc(N, sizeof(int*));
	for (int i = 0; i < N; i++)
   		G[i] = (int*)calloc(N, sizeof(int));

	for (int i = 0; i < M; i++)
	{
		int lin, col;
		fscanf(fin, "%d%d", &lin, &col);
		// le adjustam din numerotarea umana in cea din implementarea in C		
		lin--;
		col--;
		// graful este neorientat
		G[lin][col] = 1;
		G[col][lin] = 1;
	}
	fclose(fin);

	// intai generam clauzele care arata daca exista un al i-lea element
	// v in clica
	for (int i = 0; i < K; i++)
	{
		if (i == 0)
			printf("(");
		else
			printf("^(");
		
		for (int v = 0; v < N; v++)
			if (v == 0)			
				printf("x_%d_%d", i + 1, v + 1);
			else
				printf("Vx_%d_%d", i + 1, v + 1);
		
		printf(")");
	}
	// apoi clauzele care arata daca pentru doi indici diferiti i, j
	// varfurile sunt diferite
	for (int i = 0; i < K; i++)
		for (int j = i + 1; j < K; j++)
			for (int v = 0; v < N; v++)
				printf("^(~x_%d_%dV~x_%d_%d)", i + 1, v + 1, j + 1, v + 1);
			
	// pentru fiecare pereche de varfuri neconectate, u, v, nu pot apartine
	// unei clici. Adica pentru fiecare i, j ~x_i_uV~x_j_v
	for (int u = 0; u < N; u++)
		for (int v = 0; v < N; v++)
			if (u != v && G[u][v] == 0)
			{
				for (int i = 0; i < K; i++)
					for (int j = 0; j < K; j++)
						if (i != j)
							printf("^(~x_%d_%dV~x_%d_%d)", i + 1, u + 1, j + 1, v + 1);
			}

	for (int i = 0; i < N; i++)
    	free(G[i]);
	free(G);

	return 0;
}
