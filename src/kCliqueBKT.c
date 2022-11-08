#include <stdlib.h>
#include <stdio.h>

int contains(int* v, int n, int val)
{
	for (int i = 0; i < n; i++)
		if (v[i] == val)
			return 1;
	return 0;
}

// n se refera la numarul de elemente din set
int checkGraf(int** G, int* set, int n)
{
	//printf("Intra in checkGraf pentru %d elemente\n", n);
	if (G == NULL || *G == NULL || set == NULL)
		return 0;
	if (n == 0)
		return 1;
	
	// pentru fiecare nod vedem daca are muchie cu toate nodurile celelalte
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if (i != j && G[set[i]][set[j]] == 0)
				return 0;
	return 1;
}

int isKClique(int** G, int n, int k, int pas, int* set)
{
	//printf("Intra in isKClique cu n = %d, k = %d, pas = %d\n", n, k, pas);

	if (G == NULL || *G == NULL || n == 0 || set == NULL)
		return 0;

	if (pas == k)
		return 1;

	for (int i = 0; i < n; i++)
	{
		// daca nodul nostru nu este deja in multimea selectata
		if (!contains(set, pas, i))
		{
			//printf("Il putem adauga pe %d la pasul %d\n", i, pas);
			set[pas] = i;
			// pentru pasul mai mare ca 1, vedem daca graful nostru partial
			// este complet
			if (checkGraf(G, set, pas + 1))
			{
				int ret = isKClique(G, n, k, pas + 1, set);
				// daca selectarea nodului duce la o solutie nu mai are rost
				// sa continuam
				if (ret == 1)
				{
					//printf("Am dat de 1\n");
					return 1;
				}
			}
			
		}
		
	}

	return 0;
}

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

	int k;
	fscanf(fin, "%d", &k);
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
	
	int* set = (int*)calloc(k, sizeof(int));
	int val = isKClique(G, N, k, 0, set);
	free(set);
	if (val)
		printf("True");
	else
		printf("False");

	for (int i = 0; i < N; i++)
    	free(G[i]);
	free(G);

	return 0;
}
