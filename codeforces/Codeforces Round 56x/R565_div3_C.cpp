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

map<int, int> ck = {{4,  0},
                    {8,  1},
                    {15, 2},
                    {16, 3},
                    {23, 4},
                    {42, 5}};

void solve() {
    int n;
    cin >> n;
    map<int, int> r;
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        x = ck[x];
        if (x == 0)r[x]++;
        else {
            if (r[x - 1] == 0)cnt++;
            else r[x - 1]--, r[x]++;
        }
    }
    for (int i = 0; i < 5; i++)cnt += (i + 1) * r[i];
    cout << cnt << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
