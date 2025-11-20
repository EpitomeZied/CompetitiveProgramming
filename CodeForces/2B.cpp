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


auto Solve(const int &n) -> void {
    vector<vector<int> > twos(n, vector<int>(n));
    vector<vector<int> > fives(n, vector<int>(n));

    int x0 = -1, y0 = -1;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int x;
            cin >> x;
            if (x == 0) {
                twos[i][j] = fives[i][j] = 1;
                x0 = i, y0 = j;
                continue;
            }
            int pw = 0;
            while (x % 2 == 0) pw++, x /= 2;
            twos[i][j] = pw;

            pw = 0;
            while (x % 5 == 0) pw++, x /= 5;
            fives[i][j] = pw;
        }
    }

    vector<vector<int> > memo2(n, vector<int>(n, -1));
    vector<vector<int> > memo5(n, vector<int>(n, -1));

    function<int(int,int)> dp2 = [&](int i, int j) -> int {
        if (i == n - 1 && j == n - 1) return twos[i][j];
        if (memo2[i][j] != -1) return memo2[i][j];

        int res = OO;
        if (i + 1 < n) res = twos[i][j] + dp2(i + 1, j);
        if (j + 1 < n) res = min(res, twos[i][j] + dp2(i, j + 1));
        return memo2[i][j] = res;
    };

    function<int(int,int)> dp5 = [&](int i, int j) -> int {
        if (i == n - 1 && j == n - 1) return fives[i][j];
        if (memo5[i][j] != -1) return memo5[i][j];

        int res = OO;
        if (i + 1 < n) res = fives[i][j] + dp5(i + 1, j);
        if (j + 1 < n) res = min(res, fives[i][j] + dp5(i, j + 1));
        return memo5[i][j] = res;
    };

    string res;
    function<void(int,int)> path2 = [&](int i, int j) {
        if (i == n - 1 && j == n - 1) return;

        if (i + 1 < n &&
            dp2(i, j) == twos[i][j] + dp2(i + 1, j)) {
            res.push_back('D');
            path2(i + 1, j);
        } else {
            res.push_back('R');
            path2(i, j + 1);
        }
    };

    function<void(int,int)> path5 = [&](int i, int j) {
        if (i == n - 1 && j == n - 1) return;

        if (i + 1 < n &&
            dp5(i, j) == fives[i][j] + dp5(i + 1, j)) {
            res.push_back('D');
            path5(i + 1, j);
        } else {
            res.push_back('R');
            path5(i, j + 1);
        }
    };

    int ans = 0;

    if (x0 != -1 && y0 != -1 && min(dp2(0, 0), dp5(0, 0)) > 1) {
        ans = 1;

        int dx = y0, dy = x0;
        while (dx--) res.push_back('R');
        while (dy--) res.push_back('D');

        dx = n - 1 - y0;
        dy = n - 1 - x0;
        while (dx--) res.push_back('R');
        while (dy--) res.push_back('D');
    } else {
        ans = min(dp2(0, 0), dp5(0, 0));
        if (dp2(0, 0) < dp5(0, 0))
            path2(0, 0);
        else
            path5(0, 0);
    }

    cout << ans << endl << res;
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
