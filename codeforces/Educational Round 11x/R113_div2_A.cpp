#include <string.h>
#include <stdio.h>
#include <math.h>
#include <cassert>
#include <map>
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
    int n;
    string s;
    cin >> n >> s;

    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            int c = 0;
            for(int k=i;k<=j;k++){
                if(s[k] == 'a') c ++;
                else c --;
            }

            if(c == 0) {
                cout << i + 1 << " " << j + 1<< '\n';
                return;
            }
        }
    }
    cout << -1 << " " << -1 << '\n';
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
