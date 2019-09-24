#include <bits/stdc++.h>
using namespace std;
 
#define rightn node*2+2
#define leftn node*2+1
#define cmid int mid = (left + right)/2
#define ll long long
 
#define MAXN 1000001
#define MAXN_4 3000004
 
int segtree[MAXN_4];
int source_array[MAXN];
int N;
int fibers[MAXN];
ll greater_left[MAXN];
ll smaller_right[MAXN];

 
void update(int node, int left, int right, int idx, int val) {
    if (left == right && left == idx) {
        segtree[node] = source_array[left] = val;
        return;
    }
 
    cmid;
 
    if (idx <= mid) {
        update(leftn, left, mid, idx, val);
    }
    else {
        update(rightn, mid+1, right, idx, val);
    }
 
    segtree[node] = segtree[leftn] + segtree[rightn];
}
 
int query(int node, int left, int right, int qleft, int qright) {
    if (left > qright || right < qleft) {
        return 0;
    }
 
    if (left >= qleft && right <= qright) {
        return segtree[node];
    }
 
    cmid;
 
    return query(leftn, left, mid, qleft, qright) + query(rightn, mid+1, right, qleft, qright);
}
 
void fill_smaller_right_and_greater_left() {
    memset(segtree, 0, MAXN_4* sizeof(int));
 
    for (int i = 0; i < N; ++i) {
        greater_left[i] = query(0, 0, MAXN-1, fibers[i], MAXN-1);
 
        update(0, 0, MAXN-1, fibers[i], 1);
    }
 
    memset(segtree, 0, MAXN_4* sizeof(int));
 
    for (int i = N - 1; i >= 0; --i) {
        smaller_right[i] = query(0, 0, MAXN-1, 0, fibers[i]);
 
        update(0, 0, MAXN-1, fibers[i], 1);
    }
}
 
int main() {
    while (scanf("%d", &N) != EOF) {
 
        for (int i = 0; i < N; ++i) {
            int a;
            scanf("%d", &a);
 
            fibers[i] = a;
        }
 
        fill_smaller_right_and_greater_left();
 
        ll valid_permutations = 0;
        for (int i = 0; i < N; ++i) {
            valid_permutations += greater_left[i] * smaller_right[i];
        }
 
		printf("%lld\n", valid_permutations);
    }
}
