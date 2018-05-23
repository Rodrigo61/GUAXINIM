/* Retorna apenas o tamanho da LCS */
int lcs(string &str1, string &str2) {

	int sz1 = str1.size();
	int sz2 = str2.size();

	int dp[sz1+1][sz2+1];
	memset(dp, 0, sizeof(dp));

	for (int i = 1; i<=m; i++) {
		for (int j = 1; j<=n; j++) {

			if (X[i - 1] == Y[j - 1]) {
				dp[i][j] = dp[i - 1][j - 1] + 1;
			} else {
				dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
			}

		}
	}

   return dp[sz1][sz2];
}
