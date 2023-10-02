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

int dx[] = {1, 0, 1, 1};
int dy[] = {0, 1, 1, -1};

void solve() {
    vector<string> v(10);
    for (auto &x: v)cin >> x;
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {

            for (int t = 0; t < 4; t++) {
                map<char, int> c;
                for (int k = 0; k < 5; k++) {
                    int x = i + dx[t] * k;
                    int y = j + dy[t] * k;

                    if (x < 0 || x >= 10 || y < 0 || y >= 10)continue;
                    c[v[y][x]]++;
                }
                if (c['X'] == 5 || (c['X'] == 4 && c['.'] == 1)) {
                    cout << "YES\n";
                    return;
                }
            }

        }
    }
    cout << "NO\n";

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
