#include <cstring>
#include <cstdio>
#include <cmath>
#include <cassert>
#include <set>
#include <map>
#include <array>
#include <stack>
#include <queue>
#include <vector>
#include <numeric>
#include <iostream>
#include <algorithm>

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;

#define mp    make_pair
#define pb    push_back
#define F     first
#define S     second
#define ab(x) (((x)<0)?-(x):(x))

int a[5005], b[5005];

void solve() {
    string s;
    cin >> s;

    int n = s.size();
    for (int i = 1; i <= n; i++) {
        a[i] = a[i - 1] + (s[i - 1] == 'a');
        b[i] = b[i - 1] + (s[i - 1] == 'b');
    }
    int r = a[n];
    for (int i = 1; i <= n; i++) {
        for (int j = i; j <= n; j++) {
            r = max(r, a[i - 1] + b[j] - b[i - 1] + a[n] - a[j]);
        }
    }
    cout << r << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
