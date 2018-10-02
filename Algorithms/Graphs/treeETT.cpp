/*
  Euler Tour Technique em árvore.
  [COMPLEX] O(E + V) // DFS
  [OUT]
  Nesse algoritmo o inteverlo (beg_time[x], end_time[x]) contem todos os vertices
  da subarvore enraizada por x.
  Além disso, um vértice x está na posicao end_time[x] = a no vetor linearizado.
  O vetor time2node permite recuperar qual é o vertice x com o tempo end_time = t em O(1)
  
 * */

int curr_time;
int beg_time[MAXN], end_time[MAXN];
int time2node[MAXN];

void ett(int u)
{
	beg_time[u] = curr_time;
	
	for (int v : tree[u])
	{
		ett(v);
	}
	
	end_time[u] = curr_time;
	time2node[curr_time] = u;
	++curr_time;
}
