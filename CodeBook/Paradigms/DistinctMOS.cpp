int blocks;

struct Query{
    int L, R;
    int order;
};

bool queryComparator(Query &q1, Query &q2) {

    if (q1.L / blocks == q2.L / blocks) {
        return q1.R < q2.R;
    }

    return q1.L / blocks < q2.L / blocks;
}

void queryResults(int a[], int n, Query q[], int m, vi &results) {

    blocks = sqrt(n);

    sort(q, q + m, queryComparator);

    int currL = 0, currR = 0;
    vi freq(1000001, 0);

    int distinct_count = 1;
    freq[a[0]] = 1;

    results.resize(m);

    for (size_t i = 0; i < m; i++) {
        int L = q[i].L, R = q[i].R;


        while (currL > L) {
            if (freq[a[currL - 1]] == 0) {
                distinct_count++;
            }
            ++freq[a[currL - 1]];
            --currL;

        }

        while (currR < R) {
            if (freq[a[currR + 1]] == 0) {
                distinct_count++;
            }
            ++freq[a[currR + 1]];
            ++currR;
        }

        while (currR > R) {
            --freq[a[currR]];
            if (freq[a[currR]] == 0) {
                --distinct_count;
            }
            --currR;
        }

        while (currL < L) {
            --freq[a[currL]];
            if (freq[a[currL]] == 0) {
                --distinct_count;
            }
            ++currL;
        }

        results[q[i].order] = distinct_count;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m;

    cin >> n;
    int a[n];
    for (size_t i = 0; i < n; i++) {
        cin >> a[i];
    }

    cin >> m;
    Query q[m];
    for (size_t i = 0; i < m; i++) {
        Query new_query;
        cin >> new_query.L >> new_query.R;
        --new_query.L, --new_query.R;
        new_query.order = i;
        q[i] = new_query;
    }

    vi results;
    queryResults(a, n, q, m, results);

    for (auto &res : results) {
        printf("%d\n", res);
    }

    return 0;
}

