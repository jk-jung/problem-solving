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
    int n;
    cin >> n;
    vector<string> v[3];
    map<string, int> ck;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < n; j++) {
            string s;
            cin >> s;
            v[i].pb(s);
            ck[s]++;
        }
    }
    for (int i = 0; i < 3; i++) {
        int r = 0;
        for (auto s: v[i]) {
            if (ck[s] == 1)r += 3;
            else if (ck[s] == 2)r += 1;
        }
        cout << r << " ";
    }
    cout << endl;
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
