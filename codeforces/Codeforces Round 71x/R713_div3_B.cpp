#include <string.h>
#include <stdio.h>
#include <math.h>
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

string a[405];

void solve() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)cin >> a[i];
    map<int, int> xx, yy;
    for (int i = 0; i < n; i++)for (int j = 0; j < n; j++)if (a[i][j] == '*') xx[j] = 1, yy[i] = 1;
    if(xx.size() == 1)for(int i=0;i<n;i++)if(!xx.count(i)){xx[i]=1; break; }
    if(yy.size() == 1)for(int i=0;i<n;i++)if(!yy.count(i)){yy[i]=1; break; }
    for (int i = 0; i < n; i++)for (int j = 0; j < n; j++)if (xx.count(j) && yy.count(i)) a[i][j] = '*';
    for (int i = 0; i < n; i++)cout << a[i] << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int test_case;
    cin >> test_case;
    while (test_case--)
        solve();
}
