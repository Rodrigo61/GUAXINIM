INF = 10000000000
N = int(input())
grid = []
for i in range(N):
	grid.append([int(x) for x in list(input().split())])


def get_col_sum(i, j):
	if i < 0 or i >= N or j < 0 or j >= N:
		return INF
	total = 0;
	for it in range(i, N):
		total = total + grid[it][j];
	return total;
	
	
############### MAIN #################
	
# Seleciona a melhor coluna para primeira linha
mini = INF
left = -1
right = -1
for col in range(N):
	col_sum = get_col_sum(0, col)
	if col_sum < mini:
		mini = col_sum;
		left = right = col;
	
# Logica para as demais linhas
total = mini;
for i in range(1, N):
	
	left_col = get_col_sum(i, left - 1)
	right_col = get_col_sum(i, right + 1)
	
	if left_col < right_col:
		left = left - 1
		total = total + left_col
	else:
		right = right + 1
		total = total + right_col
		
print(total)
