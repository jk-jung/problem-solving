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

int r[100005];

void solve() {
    int n;
    cin >> n;

    int k = 1;
    for (int i = 2; i <= n + 1; i++) {
        if (!r[i]) {
            for (int j = i + i; j <= n + 1; j += i)r[j] = 1, k =2;
        }
    }
    cout << k << endl;
    for(int i=2;i<=n+1;i++)cout << r[i] + 1 << " ";

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
