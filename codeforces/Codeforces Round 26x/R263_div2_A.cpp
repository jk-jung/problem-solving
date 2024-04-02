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

char a[555][555];

void solve() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> a[i][j];
        }
    }
    bool r = true;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            int c =0 ;
            if(a[i-1][j] == 'o')c++;
            if(a[i+1][j] == 'o')c++;
            if(a[i][j-1] == 'o')c++;
            if(a[i][j+1] == 'o')c++;
            if(c % 2 == 1)r = false;
        }
    }
    cout << (r ? "YES" : "NO") << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
