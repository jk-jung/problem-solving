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

set<char> t = {'A', 'E', 'I', 'O', 'U', 'Y'};

void solve() {
    string s;
    cin >> s;
    s = "A" + s + "A";
    int r = 0, x = 0;
    for (int i = 0; i < s.size(); i++) {
        if (t.count(s[i])) {
            r = max(r, i - x);
            x = i;
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
