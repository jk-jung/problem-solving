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


int f(string &x) {
    int r = 0;
    for (int i = 1; i < x.size(); i++)if (x[i - 1] == 'V' && x[i] == 'K') r++;
    return r;
}

void solve() {
    string s;
    cin >> s;
    int r = f(s);
    for (int i = 0; i < s.size(); i++) {
        s[i] = s[i] == 'V' ? 'K' : 'V';
        r = max(r, f(s));
        s[i] = s[i] == 'V' ? 'K' : 'V';
    }
    cout << r << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
