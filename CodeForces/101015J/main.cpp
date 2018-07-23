#include <bits/stdc++.h>

#define all(x) x.begin(), x.end()
using namespace std;

typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;

int N;
vi vet_in, vet_out;
vector<vi> vet_cycles;
vii most_right_rep;
vi value_pos;
int cycle_id;

vi visited;

void dfs(int u, int cycle_id) 
{
	visited[u] = 1;
	vet_cycles[cycle_id].push_back(u);
	
	if (value_pos[u] >= 0 && value_pos[u] > most_right_rep[cycle_id].first)
	{
		most_right_rep[cycle_id].first = value_pos[u];
		most_right_rep[cycle_id].second = vet_cycles[cycle_id].size() - 1;
	}
	
	if (!visited[vet_in[u]])
		dfs(vet_in[u], cycle_id);
	
}

bool parse_in_cycles()	
{
	
	visited.assign(N, 0);
	most_right_rep.assign(N, make_pair(-1, -1));
	vet_cycles.resize(N);
	cycle_id = 0;
	

	for (int i = 0; i < N; i++)
	{
		if (!visited[i])
		{
			dfs(i, cycle_id);
			
			if (most_right_rep[cycle_id].first == -1)
			{
				return false;
			}
			
			++cycle_id;
		}
	}
	
	return true;
}

int main() 
{
	scanf("%d", &N);
	
	vet_in.resize(N);
	vet_out.resize(N);
	value_pos.resize(N, -1);
	
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &vet_in[i]);
		--vet_in[i];
	}
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &vet_out[i]);
		--vet_out[i];
		
		if (vet_out[i] >= 0)
		{
			value_pos[vet_out[i]] = i;
		}

	}
	
	
	if (parse_in_cycles()) 
	{
		
		vii sorted_cycle_id;
		for (int i = 0; i < N; i++)
		{
			if (most_right_rep[i].first != -1)
			{
				sorted_cycle_id.push_back(make_pair(most_right_rep[i].first, i));
			}
			
		}
		sort(all(sorted_cycle_id));
		
		
		visited.assign(N, 0);
		
		for (auto aux : sorted_cycle_id)
		{
			int i = aux.second;
			auto &cycle = vet_cycles[i];
			
			int it_out = most_right_rep[i].first;
			int it_cycle = most_right_rep[i].second;
			
			// fill left
			while (!visited[cycle[it_cycle]] && (vet_out[it_out] == -1 || vet_out[it_out] == cycle[it_cycle])) {
				
				visited[cycle[it_cycle]] = 1;
				
				vet_out[it_out] = cycle[it_cycle];
				--it_out, --it_cycle;
				
				if (it_cycle == - 1)
				{
					it_cycle = cycle.size() - 1;
				}
				
				if (it_out == - 1)
				{
					break;
				}
				
			}
			
			//fill right
			it_out = most_right_rep[i].first + 1;
			it_cycle = (most_right_rep[i].second + 1) % cycle.size();
			
			while (!visited[cycle[it_cycle]])
			{
				visited[cycle[it_cycle]] = 1;
				vet_out[it_out] = cycle[it_cycle];
				it_cycle = (it_cycle + 1) % cycle.size();
				it_out++;
			}
		}
		
		
		for (auto e : vet_out)
		{
			printf("%d ", e + 1);
		}
		printf("\n");
		
	} 
	else 
	{
		printf("-1\n");
	} 
	
	
	return 0;
}
