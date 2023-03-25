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

set<char> vv = {'a', 'e', 'i', 'o', 'u'};

void solve() {
    string a, b;
    cin >> a >> b;
    map<char, char> ck;
    bool r = true;
    if (a.size() != b.size()) {
        r = false;
    } else {
        for (int i = 0; i < a.size(); i++) {
            char x = a[i];
            char y = b[i];
            if (vv.count(x) != vv.count(y)) {
                r = false;
            }
        }
    }
    cout << (r ? "Yes\n" : "No\n");
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}