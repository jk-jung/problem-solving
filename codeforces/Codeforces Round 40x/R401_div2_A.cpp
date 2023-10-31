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
//         0  1  0  1  0  1  0
int a[] = {0, 1, 2, 2, 1, 0};
int b[] = {1, 0, 0, 1, 2, 2};
int c[] = {2, 2, 1, 0, 0, 1};
void solve() {
    int n, x;
    cin >> n >> x;

    if(a[n % 6] == x)cout << 0 << endl;
    else if(b[n % 6] == x)cout << 1 << endl;
    else cout << 2 << endl;

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
