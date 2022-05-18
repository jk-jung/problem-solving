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
    int n, c = 0;
    string s;
    cin >> n >> s;
    vi r(n);
    queue<int> q[2];

    for (int i = 0; i < n; i++) {
        int x = (s[i] - '0');
        int y = x ^ 1;
        if(q[y].empty())r[i] = ++ c;
        else {
            r[i] = r[q[y].front()];
            q[y].pop();
        }
        q[x].push(i);
    }

    cout << c << endl;
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
