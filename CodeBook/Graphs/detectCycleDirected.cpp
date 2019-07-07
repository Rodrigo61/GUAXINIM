vi visited;
vi in_stack;

bool dfs(int u)
{
    if(!visited[u])
	{
        visited[u] = true;
        in_stack[u] = true;
 
		for (auto &v : out_adj[u]) 
		{	
			if (in_stack[v])
				return true;
				
			if (dfs(v))
				return true;
		}
    }
    in_stack[u] = false;  
    return false;
}
 
bool has_cycle()
{
	visited.assign(N, 0);
	in_stack.assign(N, 0);

    for(int i = 0; i < N; i++)
        if (dfs(i))
            return true;
 
    return false;
}
