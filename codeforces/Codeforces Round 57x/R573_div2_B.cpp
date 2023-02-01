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
    vector<string> v(3);
    for (auto &s: v)cin >> s;
    sort(v.begin(), v.end());
    int c = 0;
    if (v[0] == v[1]) c++;
    if (v[1] == v[2]) c++;
    if (c == 2)cout << 0 << endl;
    else if (c == 1)cout << 1 << endl;
    else {
        c = 0;
        for (int i = 0; i < 2; i++) {
            for (int j = i + 1; j < 3; j++) {
                if (v[i][0] + 1 == v[j][0] && v[i][1] == v[j][1]) c++;
            }
        }
        if (c == 2)cout << 0 << endl;
        else if (c == 1)cout << 1 << endl;
        else {
            c = 0;
            if (v[0][0] + 2 == v[1][0] && v[0][1] == v[1][1]) c = 1;
            if (v[0][0] + 2 == v[2][0] && v[0][1] == v[2][1]) c = 1;
            if (v[1][0] + 2 == v[2][0] && v[1][1] == v[2][1]) c = 1;
            cout << 2 - c << endl;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
