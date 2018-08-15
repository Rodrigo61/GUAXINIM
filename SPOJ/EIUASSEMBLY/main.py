N = 0
BUD = 0
P = []
M = []

def possible(T):
	global N
	global BUD
	global P
	global M
	curr_BUD = BUD

	for i in range(0, N):
		
		if P[i] < T:
			curr_BUD = curr_BUD - ((T - P[i]) * M[i])

		if curr_BUD < 0:
			return False

	return True


def solve():
	global N
	global BUD
	global P
	global M
	upper = 1000000000000000000000000000000
	lower = 0
	ans = 0	


	while lower <= upper:

		mid = lower + (upper - lower + 1) // 2

		if possible(mid):
			lower = mid + 1
			ans = mid
		else:
			upper = mid - 1

	return ans


T = int(input())

for q in range(0, T):
	
	args = input().split()
	N = int(args[0])
	BUD = int(args[1])

	P.clear()
	M.clear()

	for i in range(0, N):
		args = input().split()
		P.append(int(args[0]))
		M.append(int(args[1]))


	print(solve())
