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
const int N = 2e5 + 10, M = 998244353, OO = 0X3F3F3F3F3F3F3F3F;
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

struct DSU {
    int n, components, maxSize; // maximum component size
    vi parent, sz, mn;

    DSU(int n) : n(n), components(n), maxSize(1) {
        parent.resize(n);
        sz.resize(n, 1);
        mn.resize(n);

        for (int i = 0; i < n; ++i) {
            parent[i] = i;
            mn[i] = i;
        }
    }

    int find(int x) {
        if (parent[x] == x) return x;
        return parent[x] = find(parent[x]); // path compression
    }

    bool unite(int a, int b) {
        int rootA = find(a);
        int rootB = find(b);

        if (rootA == rootB) return false; // already same component

        // union by size
        if (sz[rootB] > sz[rootA])
            swap(rootA, rootB);

        parent[rootB] = rootA;
        sz[rootA] += sz[rootB];
        mn[rootA] = min(mn[rootA], mn[rootB]);
        maxSize = max(maxSize, sz[rootA]);
        components--;

        return true;
    }
};


auto Solve(const int &n) -> void {
    int m;
    cin >> m;
    DSU dsu(n);
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        dsu.unite(u, v);
        cout << dsu.components << " " << dsu.maxSize << endl;
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
QT_QPA_PLATFORM=xcb vlc
