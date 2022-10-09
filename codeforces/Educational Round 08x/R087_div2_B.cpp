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

void solve() {
    string s;
    vi c(3);
    cin >> s;
    queue<int> q;

    int r = 1 << 30;
    for (char x: s) {
        x -= '1';
        q.push(x);
        c[x]++;
        while (!q.empty() && c[q.front()] >= 2) c[q.front()]--, q.pop();
        if (c[0] > 0 && c[1] > 0 && c[2] > 0) {
            r = min(r, c[0] + c[1] + c[2]);
        }
    }
    if (r > 1 << 20)r = 0;
    cout << r << endl;
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
