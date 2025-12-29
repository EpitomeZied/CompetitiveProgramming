#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define ll long long
#define int long long
typedef unsigned long long ull;
#define endl '\n'
typedef pair<int, int> pii;
#define elif else if
#define endd(s) return void(cout << s << "\n")
#define Ceil(n, m) (((n) / (m)) + ((n) % (m) ? 1 : 0))
#define X first
#define Y second
#define fixed(n) fixed << setprecision(n)
#define sz(s) int32_t(s.size())
#define dbg(x) cout << #x << ": " << (x) << "\n";
#define getline(s) getline(cin >> ws, s)
#define Time cerr << "Time Taken: " << (float)clock() / CLOCKS_PER_SEC << " Secs" << "\n";
#define all(vec) vec.begin(), vec.end()
#define rall(v) v.rbegin(),v.rend()
#define mul_mod(a, b) (((a % M) * (b % M)) % M)
#define add_mod(a, b) (((a % M) + (b % M)) % M)
#define sub_mod(a, b) (((a % M) - (b % M) + M) % M)
const int N = 2e5 + 10, M = 1'000'000'007, OO = 0X3F3F3F3F3F3F3F3F;
const double EPS = 1e-9, pi = 3.141592653589793;
#define kill return 0
typedef vector<int> vi;
typedef vector<vi> vvi;
#define pb push_back
vector<string> RET = {"NO", "YES"};
#define IO(NAME) \
cin.tie(0)->sync_with_stdio(0); \
if(fopen(NAME ".in","r")) freopen(NAME ".in","r",stdin), \
freopen(NAME ".out","w",stdout);
template<class T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

void Zied() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout);
#endif
}

template<typename T = int>
istream &operator >>(istream &in, vector<T> &v) {
    for (auto &x: v) in >> x;
    return in;
}

template<typename T = int>
ostream &operator <<(ostream &out, const vector<T> &v) {
    for (const T &x: v) out << x << ' ';
    return out;
}

template<typename A, typename B>
istream &operator>>(istream &fin, pair<A, B> &p) {
    fin >> p.X >> p.Y;
    return fin;
}

template<typename A, typename B>
std::ostream &operator<<(std::ostream &fout, const std::pair<A, B> &p) {
    fout << p.first << " " << p.second;
    return fout;
}

enum dir { d, r, u, l, ul, dr, ur, dl };

int dx[8] = {1, 0, -1, 0, -1, 1, -1, 1};
int dy[8] = {0, 1, 0, -1, -1, 1, 1, -1};


void preprocessing() {
}

vector<vector<int> > grid;

struct LCA {
    int n, lg, timer;
    vector<int> tin, tout, depth, par, sz;
    vector<vector<int> > up;

    void dfs(int v, int p) {
        tin[v] = timer++;            // 0-based timer is easiest
        up[v][0] = p;
        depth[v] = (v == p ? 0 : depth[p] + 1);

        for (int i = 1; i <= lg; ++i)
            up[v][i] = up[ up[v][i - 1] ][i - 1];

        for (int u : grid[v]) {
            if (u == p) continue;
            dfs(u, v);
        }
        tout[v] = timer - 1;         // max tin in subtree
    }

    bool is_ancestor(int u, int v) {
        return tin[u] <= tin[v] && tout[u] >= tout[v];
    }


    int get_distance(int u, int v) {
        return depth[u] + depth[v] - 2 * depth[lca(u, v)];
    }

    int lca(int u, int v) {
        if (is_ancestor(u, v))
            return u;
        if (is_ancestor(v, u))
            return v;
        for (int i = lg; i >= 0; --i) {
            if (!is_ancestor(up[u][i], v))
                u = up[u][i];
        }
        return up[u][0];
    }


    int kth_parent(int u, int k) {
        for (int i = 0; i <= lg; ++i) {
            if (k & (1LL << i)) u = up[u][i];
        }
        return u;
    }


    void init(int root) {
        n = (int) grid.size(), timer = 0, lg = ceil(log2(n));
        tin = tout = par = sz = depth = vector<int>(n);
        up.assign(n, vector<int>(lg + 1, 0));
        dfs(root, root);
    }
};


auto Solve(const int &n) -> void {
    grid.assign(n + 1, {});
    for (int i = 1; i <= n; ++i) {
        int p;
        cin >> p;
        grid[p].push_back(i);
    }

    LCA lca;
    lca.init(0);

    vvi d(n + 1);
    for (int v = 0; v <= n; ++v) {
        d[lca.depth[v]].push_back(lca.tin[v]);
    }
    for (auto &vec : d) sort(all(vec));


    int q;
    cin >> q;
    while (q--) {
        int v, p;
        cin >> v >> p;

        int k = lca.kth_parent(v, p);
        if (k == 0 or k == -1) {
            cout << 0 << " ";
            continue;
        }

        int targetDepth = lca.depth[v];
        auto &vec = d[targetDepth];

        int L = lca.tin[k];
        int R = lca.tout[k];

        int ans = upper_bound(vec.begin(), vec.end(), R) -
                  lower_bound(vec.begin(), vec.end(), L);

        cout << ans - 1 << " ";
    }
}

bool solve_test(const int test_number) {
    int n = 1;
    // string n;
    if (!(cin >> n))
        return false;
    Solve(n);
    // auto ans = Solve(n);
    // cout << ans << endl;
    return true;
}

void Stress() {
    // for (int n = 2; n <= 1; ++n)
    //     cerr << n << ' ' << Solve(n) << '\n';
}

int32_t main() {
    Zied();
    Stress();
    // freopen("document.in", "r", stdin);
    // freopen("document.out", "w", stdout);
    preprocessing();
    int test_cases = 1;
    // cin >> test_cases;
    for (int tc = 1; tc <= test_cases; tc++) {
        // cout << "Case " << tc << ": " << endl;
        // cout << "Case #" << tc << ": ";
        if (!solve_test(tc))break;
        // cout << endl;
    }
    kill;
    //    Time
}

/*
  _____       _ _                      _______
 |  ___|     (_) |                    |___  (_)        | |
 | |__ _ __  _| |_ ___  _ __ ___   ___   / / _  ___  __| |
 |  __| '_ \| | __/ _ \| '_ ` _ \ / _ \ / / | |/ _ \/ _` |
 | |__| |_) | | || (_) | | | | | |  __/  /__| |  __/ (_| |
 \____/ .__/|_|\__\___/|_| |_| |_|\___ \_____/_|\___|\__,_|
      | |
      |_|
*/