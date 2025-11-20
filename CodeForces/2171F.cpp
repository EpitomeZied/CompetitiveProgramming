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

int n;
int mx[800000];

int mergeMx(int a, int b) {
    return max(a, b);
}

void buildMx(vector<int> &arr, int ni = 0, int ns = 1, int ne = n) {
    if (ns == ne) {
        mx[ni] = arr[ns];
        return;
    }
    int l = ni * 2 + 1, r = l + 1, mid = (ns + ne) / 2;
    buildMx(arr, l, ns, mid);
    buildMx(arr, r, mid + 1, ne);
    mx[ni] = mergeMx(mx[l], mx[r]);
}

void updateMx(int pos, int ni = 0, int ns = 1, int ne = n) {
    if (pos < ns || pos > ne) return;
    if (ns == ne) {
        mx[ni] = 0;
        return;
    }
    int l = ni * 2 + 1, r = l + 1, mid = (ns + ne) / 2;
    updateMx(pos, l, ns, mid);
    updateMx(pos, r, mid + 1, ne);
    mx[ni] = mergeMx(mx[l], mx[r]);
}

int hb(int ql, int qr, int x, int ni = 0, int ns = 1, int ne = n) {
    if (qr < ns || ql > ne || mx[ni] <= x) return -1;
    if (ns == ne) return ns;
    int mid = (ns + ne) / 2, l = ni * 2 + 1, r = l + 1;

    int left = hb(ql, qr, x, l, ns, mid);
    if (left != -1) return left;
    return hb(ql, qr, x, r, mid + 1, ne);
}


int mn[800000];

int mergeMn(int a, int b) { return min(a, b); }

void buildMn(vector<int> &arr, int ni = 0, int ns = 1, int ne = n) {
    if (ns == ne) {
        mn[ni] = arr[ns];
        return;
    }
    int l = ni * 2 + 1, r = l + 1, mid = (ns + ne) / 2;
    buildMn(arr, l, ns, mid);
    buildMn(arr, r, mid + 1, ne);
    mn[ni] = mergeMn(mn[l], mn[r]);
}

void updateMn(int pos, int ni = 0, int ns = 1, int ne = n) {
    if (pos < ns || pos > ne) return;
    if (ns == ne) {
        mn[ni] = OO;
        return;
    }
    int l = ni * 2 + 1, r = l + 1, mid = (ns + ne) / 2;
    updateMn(pos, l, ns, mid);
    updateMn(pos, r, mid + 1, ne);
    mn[ni] = mergeMn(mn[l], mn[r]);
}

int lb(int ql, int qr, int x, int ni = 0, int ns = 1, int ne = n) {
    if (qr < ns || ql > ne || mn[ni] >= x) return -1;
    if (ns == ne) return ns;

    int mid = (ns + ne) / 2, l = ni * 2 + 1, r = l + 1;

    int left = lb(ql, qr, x, l, ns, mid);
    if (left != -1) return left;
    return lb(ql, qr, x, r, mid + 1, ne);
}


auto Solve(const int &n) -> void {
    vi a(n + 1), pos(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        pos[a[i]] = i;
    }

    buildMx(a), buildMn(a);

    vector<pii> edges;
    vector<int> q;

    q.push_back(1);

    updateMx(pos[1]);
    updateMn(pos[1]);

    int seen = 1;
    vector<int> vis(n + 1, 0);
    vis[1] = 1;

    for (int qi = 0; qi < (int) q.size(); qi++) {
        int u = q[qi];
        int pu = pos[u];

        while (true) {
            int idx = hb(pu + 1, n, u);
            if (idx == -1) break;
            int v = a[idx];
            vis[v] = 1;
            seen++;
            edges.emplace_back(u, v);
            updateMx(idx), updateMn(idx);
            q.push_back(v);
        }

        while (true) {
            int idx = lb(1, pu - 1, u);
            if (idx == -1) break;
            int v = a[idx];
            vis[v] = 1;
            seen++;
            edges.emplace_back(u, v);
            updateMx(idx), updateMn(idx);
            q.push_back(v);
        }
    }
    if ((seen == n or edges.size() == n - 1)) {
        cout << "Yes" << endl;
        for (auto &[u ,v] : edges) {
            cout << u << " " << v << endl;
        }
    }else {
        cout << "NO" << endl;
    }
}

bool solve_test(const int test_number) {
    // int n = 1;
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
    cin >> test_cases;
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