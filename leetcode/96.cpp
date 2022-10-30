class Solution {
public:
    int numTrees(int n) {
	  if (n <= 1) return 1;
        vector<int> dp(n + 1);
	  dp[0] = dp[1] = 1;
	  for (int m = 2; m <= n; m++) { // the number of nodes (n - 1)
	 	int sum = 0;
for (int j = 0; j < m; j++) { // how many nodes are there in the left subtree (m times)
			sum += dp[j] * dp[m - 1 - j];
		}
		dp[m] = sum;
	  }
	  return dp[n];
    }
};
