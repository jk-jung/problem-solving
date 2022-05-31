#include <string.h>
#include <stdio.h>
#include <math.h>
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

void solve() {
    int n, m;
    string s;
    cin >> n >> m >> s;

    vi r(n * m), ck(m);
    queue<int> q;
    for (int i = 0; i < n * m; i++) {
        if (s[i] == '1') q.push(i);
        if (!q.empty() && q.front() <= i - m) q.pop();
        if (!q.empty()) r[i]++;
        if (i - m >= 0)r[i] += r[i - m];
    }

    for (int i = 0, c = 0; i < n * m; i++) {
        if (s[i] == '1' && ck[i % m] == 0) c++, ck[i % m] = 1;
        r[i] += c;
    }


    for (int x: r)cout << x << " ";
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int test_case;
    cin >> test_case;
    while (test_case--)
        solve();
}
