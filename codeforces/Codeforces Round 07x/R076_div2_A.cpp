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

string a, b;

void solve() {
    string s;
    vector<string> v(10);
    cin >> s;
    for (auto &x: v)cin >> x;
    for (int i = 0; i < 8; i++) {
        string t = s.substr(0, 10);
        s = s.substr(10);
        for (int j = 0; j < 10; j++) {
            if (t == v[j]) {
                cout << j;
                break;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
