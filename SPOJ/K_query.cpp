#include <bits/stdc++.h>

using namespace std;
const int N = 3e4 + 5,M=2e5+5;

int tree[N], n;
int ans[M];

int get(int i) {
    int res = 0;
    for (++i; i; i -= i & -i)
        res += tree[i - 1];
    return res;
}

void add(int i, int v) {
    for (++i; i <= n; i += i & -i)
        tree[i - 1] += v;
}

struct event {
    int v;
    bool isQuery;
    int i, s, e;
};

int main() {
    vector<event> events;
    int q;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        events.push_back({x, false, i, 0, 0});
    }
    scanf("%d", &q);
    for (int i = 0; i < q; i++) {
        int s, e, v;
        scanf("%d%d%d", &s, &e, &v);
        events.push_back({v, true, i, --s, --e});
    }
    sort(events.begin(), events.end(), [](const event &a,const event &b) {
        if (a.v != b.v)
            return a.v > b.v;
        return a.isQuery > b.isQuery;
    });
    for (auto &e: events)
        if (e.isQuery) {
            ans[e.i] = get(e.e) - get(e.s - 1);
        } else {
            add(e.i, 1);
        }
    for (int i = 0; i < q; i++)
        printf("%d\n", ans[i]);
}