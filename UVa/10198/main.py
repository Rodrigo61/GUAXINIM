import sys

target = 0
memo = []

def solve(sum):

	if sum > target:
		return 0

	if sum == target:
		return 1

	if memo[sum] != -1:
		print("memorizou")
		return memo[sum]

	res = 0
	res += solve(sum + 1)
	res += solve(sum + 1)
	res += solve(sum + 2)
	res += solve(sum + 3)

	memo[sum] = res

	return res


for line in sys.stdin:
	target = int(line)

	dp = [0] * (target + 1)
	dp[target] = 1	

	for i in range(target - 1, -1, -1):
		if i + 1 <= target:
			dp[i] += dp[i + 1]
			dp[i] += dp[i + 1]

		if i + 2 <= target:
			dp[i] += dp[i + 2]

		if i + 3 <= target:
			dp[i] += dp[i + 3]

	print(dp[0])
