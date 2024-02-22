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
    cin >> s;
    vi r;
    while (true) {
        int t = 0;
        for (int i = 0; i < s.size(); i++) {
            t = t * 10;
            if (s[i] > '0')s[i]--, t++;
        }
        if (!t)break;
        r.pb(t);
    }
    cout << r.size() << endl;
    for (int i = 0; i < r.size(); i++) cout << r[i] << " ";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
