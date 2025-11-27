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
#define sz(s) int64_t(s.size())
#define dbg(x) cout << #x << ": " << (x) << "\n";
// #define getline(s) getline(cin >> ws, s)
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


auto Solve(const int &n) -> string {
    int x = 0, o = 0;
    vector<vector<char> > a(3, vector<char>(3));
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> a[i][j];
            if (a[i][j] == 'X') x++;
            if (a[i][j] == '0') o++;
        }
    }
    auto valid = [&](char c) {
        // '\'
        if (a[0][0] == a[1][1] && a[1][1] == a[2][2] && a[0][0] == c) return true;
        // '/'
        if (a[0][2] == a[1][1] && a[1][1] == a[2][0] && a[0][2] == c) return true;
        // '|'
        for (int row = 0; row < 3; row++)
            if (a[row][0] == a[row][1] && a[row][0] == a[row][2] && a[row][0] == c) return true;
        // '-'
        for (int col = 0; col < 3; col++)
            if (a[0][col] == a[1][col] && a[1][col] == a[2][col] && a[0][col] == c) return true;
        return false;
    };
    bool f = valid('X');
    bool s = valid('0');
    if (o > x or x - o > 1 or (f && s) or (s && x > o) or (f && x == o))
        return "illegal";
    if (f)
        return "the first player won";
    if (s)
        return "the second player won";
    if (x + o == 9)
        return "draw";
    if (x == o)
        return "first";
    return "second";
}

bool solve_test(const int test_number) {
    int n = 1;
    // string n;
    // if (!(cin >> n))
    // return false;
    // Solve(n);
    auto ans = Solve(n);
    cout << ans << endl;
    return true;
}

void Stress() {
    // for (int n = 2; n <= 1; ++n)
    //     cerr << n << ' ' << Solve(n) << '\n';
}

int32_t main() {
    Zied();
    Stress();
    // freopen("ghanophobia.in", "r", stdin);
    // freopen("output.txt", "w", stdout);
    preprocessing();
    int test_cases = 1;
    // cin >> test_cases;
    for (int tc = 1; tc <= test_cases; tc++) {
        // cout << "Case " << tc << ": ";
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
