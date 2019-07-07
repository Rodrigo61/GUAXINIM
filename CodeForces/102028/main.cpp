#include <bits/stdc++.h>

using namespace std;

#define START 0
#define all(x) x.begin(), x.end()
#define pb push_back
#define db(x) //cerr << #x << " = " << x << endl;

struct rect{
	int Xl, Xr, Yl, Yr;
	rect(){}
	rect(int a, int b, int c, int d)
	{
		Yl = a;
		Xl = b;
		Yr = c;
		Xr = d;
	}
	
	bool operator<(const rect &other) const
	{
		return Xr < other.Xr;
	}
	
	bool operator==(const rect &other) const
	{
		return Yl == other.Yl &&
			   Xl == other.Xl &&
			   Yr == other.Yr &&
			   Xr == other.Xr;
	}
	
	void print()
	{
		//~ printf("Yl = %d  Xl = %d  Yr = %d  Xr = %d\n", Yl, Xl, Yr, Xr);
	}
};

struct Event{
	int X, Y;
	int type;
	rect rec;
	
	Event(int y, int x, int type, rect &rec)
	{
		this->Y = y;
		this->X = x;
		this->type = type;
		this->rec = rec;
	}
	
	bool operator<(const Event &other) const
	{
		if (this->X != other.X)
		{
			return this->X < other.X;;
		}
		
		return this->type < other.type;
	}
	
	void print()
	{
		//~ printf("Y = %d, X = %d, type = %d\n", Y, X, type);
	}
};

int num_carpet, M;
int sqr;

vector<int> ind_sum;
vector<int> block_sum;
vector<vector<rect>> ind_list;
vector<vector<rect>> block_list;
vector<vector<int>> grid_val;
vector<vector<int>> grid_sum1;
vector<vector<int>> grid_sum2;
vector<vector<vector<rect>>> own_grid;
vector<rect> vet_rect;
vector<Event> events;

void update_list(vector<rect> &list, rect rec)
{
	if (list.size() < 2)
	{
		list.pb(rec);
	}
	else if (list[0].Xr < list[1].Xr)
	{
		list[0] = rec;
	}
	else
	{
		list[1] = rec;
	}
}

void remove_list(vector<rect> &list, rect rec)
{
	//~ auto it = find(all(list), rec);
	//~ if (it != list.end())
	//~ {
		//~ list.erase(it);
	//~ }
}

void add (rect rec)
{
	int l = rec.Yl;
	int r = rec.Yr;
	
	int b_l = l/sqr;
	int b_r = r/sqr;

	if (b_l == b_r)
	{
		for (int i = l; i <= r; ++i)
		{
			ind_sum[i]++;
			update_list(ind_list[i], rec);
		}
	}
	else
	{
		for (int i = l; i/sqr == b_l; ++i)
		{
			ind_sum[i]++;
			update_list(ind_list[i], rec);
		}
		for (int i = r; i/sqr == b_r; --i)
		{
			ind_sum[i]++;
			update_list(ind_list[i], rec);
		}
		for(int i = b_l + 1; i < b_r; ++i)
		{
			block_sum[i]++;
			update_list(block_list[i], rec);
		}
	}
}

void remove (rect rec)
{
	int l = rec.Yl;
	int r = rec.Yr;
	
	int b_l = l/sqr;
	int b_r = r/sqr;
	
	if (b_l == b_r)
	{
		for (int i = l; i <= r; ++i)
		{
			ind_sum[i]--;
			remove_list(ind_list[i], rec);
		}
	}
	else
	{
		for (int i = l; i/sqr == b_l; ++i)
		{
			ind_sum[i]--;
			remove_list(ind_list[i], rec);
		}
		for (int i = r; i/sqr == b_r; --i)
		{
			ind_sum[i]--;
			remove_list(ind_list[i], rec);
		}
		
		for(int i = b_l + 1; i < b_r; ++i)
		{
			block_sum[i]--;
			remove_list(block_list[i], rec);
		}
	}
}

void calc_sum(vector<vector<int>> &grid, int target)
{
	int acu = 0;
	for (int i = 0; i < M; i++)
	{
		if (grid_val[i][0] == target)
		{
			++acu;
		}
		grid[i][0] = acu;
	}
	acu = 0;
	for (int j = 0; j < M; j++)
	{
		if (grid_val[0][j] == target)
		{
			++acu;
		}
		grid[0][j] = acu;
	}
	for (int i = 1; i < M; i++)
	{
		for (int j = 1; j < M; j++)
		{
			grid[i][j] = grid[i - 1][j] 
					   + grid[i][j - 1] 
					   - grid[i - 1][j - 1] 
					   + (int)(grid_val[i][j] == target);
		}
	}
}

int sum(vector<vector<int>> &grid, rect rec)
{
	int il = rec.Yl;
	int ir = rec.Yr;
	int jl = rec.Xl;
	int jr = rec.Xr;
	
	int res = grid[ir][jr];
	
	if (il - 1 >= 0)
	{
		res -= grid[il - 1][jr];
	}
	
	if (jl - 1 >= 0)
	{
		res -= grid[ir][jl - 1];
	}
	
	if (il - 1 >= 0 && jl - 1 >= 0)
	{
		res += grid[il - 1][jl - 1];
	}
	 
	return res;
}

int val(int pos)
{
	return ind_sum[pos] + block_sum[pos/sqr];
}

void owner(int pos, vector<rect> &list)
{
	list.insert(list.end(), all(ind_list[pos]));
	list.insert(list.end(), all(block_list[pos/sqr]));
	
	sort(all(list));
	while (list.size() > 2)
	{
		list.erase(list.begin());
	}
	
}

rect overlap(rect a, rect b)
{
	int Xl = max(a.Xl, b.Xl);
	int Yl = max(a.Yl, b.Yl);
	int Xr = min(a.Xr, b.Xr);
	int Yr = min(a.Yr, b.Yr);
	return rect(Yl, Xl, Yr, Xr);
}

void generate_events()
{
	for (rect &rec : vet_rect)
	{
		Event start(rec.Yl, rec.Xl, START, rec);
		Event end(rec.Yr, rec.Xr, !START, rec);
		events.pb(start);
		events.pb(end);
	}
	sort(all(events));
}

void init_sqr()
{
	sqr = (int) sqrt(M + 0.1) + 1;
	ind_sum.clear();
	ind_sum.resize(M + 5);
	ind_list.clear();
	ind_list.resize(M + 5);
	block_sum.clear();
	block_sum.resize(M/sqr + 5);
	block_list.clear();
	block_list.resize(M/sqr + 5);	
}

void init()
{
	init_sqr();
	grid_val.clear();
	grid_val.resize(M + 5, vector<int>(M + 5));
	grid_sum1.clear();
	grid_sum1.resize(M + 5, vector<int>(M + 5));
	grid_sum2.clear();
	grid_sum2.resize(M + 5, vector<int>(M + 5));
	own_grid.clear();
	own_grid.resize(M + 5, vector<vector<rect>>(M + 5));
	vet_rect.clear();
	events.clear();
}

void print_grid(vector<vector<int>> &grid)
{
	//~ for (int i = 0; i < (int)grid.size(); i++)
	//~ {
		//~ for (int j = 0; j < (int)grid[i].size(); j++)
		//~ {
			//~ printf("%d ", grid[i][j]);
		//~ }
		//~ printf("\n");
	//~ }
	//~ printf("\n");
}


int main()
{
	int T;
	scanf("%d", &T);
	
	while (T--)
	{
		scanf("%d%d", &num_carpet, &M);
		init();
		
		int a, b, c, d;
		for (int i = 0; i < num_carpet; i++)
		{					   
			scanf("%d%d%d%d", &a, &b, &c, &d);
			vet_rect.pb({c - 1, a - 1, d - 1, b - 1});
			vet_rect.back().print();
		}
		db("d1");
		
		generate_events();
		
		db("d2");
		auto it = events.begin();
		for (int j = 0; j < M; j++)
		{
			db(j);
			while (it!= events.end() && it->X == j && it->type == START)
			{
				it->print();
				add(it->rec);
				++it;
			}
			
			for (int i = 0; i < M; i++)
			{
				grid_val[i][j] = val(i);
				if (grid_val[i][j] == 2)
				{
					owner(i, own_grid[i][j]);
				}
			}
			while (it!= events.end() && it->X == j && it->type != START)
			{
				it->print();
				remove(it->rec);
				++it;
			}
		}
		
		print_grid(grid_val);
		
		db("d6");
		calc_sum(grid_sum1, 1);
		calc_sum(grid_sum2, 2);
		db("d7");
		
		print_grid(grid_sum1);
		print_grid(grid_sum2);
		
		int res = 0;
		int not_zero = 0;
		for (int i = 0; i < M; i++)
		{
			for (int j = 0; j < M; j++)
			{
				if (grid_val[i][j] != 0) 
					++not_zero;
				
				if (grid_val[i][j] == 2)
				{
					db(i);
					db(j);
					
					if (own_grid[i][j].size() != 2)
					{
						exit(own_grid[i][j].size());
					}
					
					
					auto rectA = own_grid[i][j][0];
					auto rectB = own_grid[i][j][1];
					
					auto olap = overlap(rectA, rectB);
					
					rectA.print();
					rectB.print();
					olap.print();
					
					db(sum(grid_sum2, olap));
					
					int total = sum(grid_sum2, olap);
					total += sum(grid_sum1, rectA);
					total += sum(grid_sum1, rectB);
					
					db(total);
					res = max(res, total);
				}
			}
		}
		
		vector<int> vet_sum1;
		for (rect rec : vet_rect)
		{
			vet_sum1.pb(sum(grid_sum1, rec));
		}
		sort(all(vet_sum1));
		res = max(res, vet_sum1[num_carpet - 1] + vet_sum1[num_carpet - 2]);
		
		printf("%d\n", not_zero - res);
		
	}
	
}
