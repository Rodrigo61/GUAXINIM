dp = [[[0 for x in range(22)] for y in range(22)] for z in range(22)]

def solve(c, A, B):

	if c == 0:
		return 1

	
	if dp[c][A][B] != -1:
		return dp[c][A][B]

	res = 0

	i = 0
	j = 0

	while A - i >= 0:
		j = 0
		while B - j >= 0:
			c1 = c - 1
			a1 = A - i
			b1 = B - j
			res = res + solve(c1, a1, b1)
			j = j + 1
		i = i + 1

	
	dp[c][A][B] = res;

	return res


line = input()
args = line.split()
N = int(args[0])
Aa = int(args[1])
Bb = int(args[2])

for i in range(0, N + 1):
	for j in range(0, Aa + 1):
		for k in range(0, Bb + 1):
			dp[i][j][k] = -1

print(solve(N, Aa, Bb))
