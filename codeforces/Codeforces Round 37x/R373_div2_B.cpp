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

string s;
int n;

int f(char a, char b) {
    int aa = 0, bb = 0;
    for (int i = 0; i < n; i++) {
        if (i % 2 == 1 && s[i] != a) aa++;
        if (i % 2 == 0 && s[i] != b) bb++;
    }
    return max(aa, bb);
}

void solve() {
    cin >> n >> s;
    cout << min(f('r', 'b'), f('b', 'r')) << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
