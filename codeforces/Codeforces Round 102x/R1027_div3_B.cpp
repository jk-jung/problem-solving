#include <algorithm>
#include <array>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <vector>

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;

#define mp make_pair
#define pb push_back
#define F first
#define S second
#define ab(x) (((x) < 0) ? -(x) : (x))

void solve() {
    int n, k;
    string s;
    cin >> n >> k >> s;
    int a = 0;
    for (int i = 0; i < n; i++)if (s[i] == '1')a++;
    int b = n - a;
    int m = (max(a, b) - min(a, b)) / 2;
    int M = a / 2 + b / 2;

    // 0000
    // 1111
    cout << (m <= k && k <= M && (m % 2 == k % 2) ? "YES" : "NO") << endl;

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int test_case;
    cin >> test_case;
    while (test_case--)
        solve();
}
