N = int(input())
vet = []
for i in range(N):
	vet.append(int(input()))

left = vet[0]
right = vet[N - 1]

total = 0
for i in range(1, N - 1):
	if vet[i] < left and vet[i] < right:
		total = total + 1
		
print(total)
