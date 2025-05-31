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

map<int, pi> t;
void solve() {
    string s;
    cin >> s;
    if(t.count(stoi(s))) {
        pi p = t[stoi(s)];
        cout << p.F << " " << p.S << endl;
        return;
    }
    cout << -1 << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);


    for (int i = 0; i < 100; i++) {
        for (int j = i; j < 100; j++) {
            t[(i + j) * (i + j)] = {i, j};
        }
    }

    int test_case;
    cin >> test_case;
    while (test_case--)
        solve();
}
