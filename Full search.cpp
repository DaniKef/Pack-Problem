int knapSack(int W, int *wt, int *val, int n)
{
	int i, w;
	int** K = new int* [n + 1];
	for (int j = 0; j < n + 1; j++)
		K[j] = new int[W + 1];

	for (i = 0; i <= n; i++)
	{
		for (w = 0; w <= W; w++)
		{
			if (i == 0 || w == 0)
				K[i][w] = 0;
			else if (wt[i - 1] <= w)
				K[i][w]= max(val[i - 1] + K[i - 1][w - wt[i - 1]], K[i - 1][w]);
			else
				K[i][w] = K[i - 1][w];
		}
	}
	double result = K[n][W];
	for (int k = 0; k < n + 1; k++)
		delete[] K[k];

	delete[] K;
	return result;
}


n- number of items, *val – value, *wt- weight, W- capacity bag.
