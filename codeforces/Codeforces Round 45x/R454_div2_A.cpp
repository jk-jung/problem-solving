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
    int a, b, c, d;
    cin >> a >> b >> c >> d;

    for (int x = 1; x <= 200; x++) {
        for (int y = x + 1; y <= 200; y++) {
            for (int z = y + 1; z <= 200; z++) {
                if(y <= d * 2)continue;
                if (!(c <= x && x <= c * 2))continue;
                if (!(d <= x && x <= d * 2))continue;
                if (!(b <= y && y <= b * 2))continue;
                if (!(a <= z && z <= a * 2))continue;
                cout << z << endl << y << endl << x << endl;
                return;
            }
        }
    }
    cout << "-1\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
