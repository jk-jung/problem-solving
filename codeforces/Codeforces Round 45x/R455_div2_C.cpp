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

int d[5005];

void solve() {
    int n;
    cin >> n;
    d[0] = 1;
    char y = 's';
    while (n--) {
        char x;
        cin >> x;
        if (y == 'f') {
            for (int i = 5000; i >= 1; i--)
                d[i] = d[i - 1];
            d[0] = 0;
        }else {
            for(int i=5000;i>=0;i--){
                d[i] = (d[i] + d[i + 1]) % 1000000007;
            }
        }
        y = x;
    }
    int r = 0;
    for (int i = 0; i <= 5000; i++)r = (r + d[i]) % 1000000007;
    cout << r << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
