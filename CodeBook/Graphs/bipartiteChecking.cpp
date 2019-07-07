/*
 * O (V + E)
 * Setar vet_adj e V.
 *Esse algoritmo apenas conta (minimizando) o LeftSide de um grafo bipartido (se for possivel, possible = false).
*/

vi color(V, -1);
bool possible = true;
int res = 0;

for (int i = 0; possible && i < V; ++i) {

    if (color[i] == -1) {
        int one_count = 0, zero_count = 0;

        queue<int> q;

        color[i] = 0;
        zero_count = 1;
        q.push(i);

        while (!q.empty()) {
            int u = q.front();
            q.pop();


            for (auto &v : vet_adj[u]) {
                if (color[v] == color[u]) {
                    possible = false;
                    break;
                } else if (color[v] == -1) {
                    color[v] = !(bool)color[u];

                    if (color[v] == 0) {
                        ++zero_count;
                    } else {
                        ++one_count;
                    }

                    q.push(v);
                }
            }

            if (!possible) { break; }
        }

        res += min(one_count, zero_count);

        if (min(one_count, zero_count) == 0) {
            res += max(one_count, zero_count);
        }
    }

}
