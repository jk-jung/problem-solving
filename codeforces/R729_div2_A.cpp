#include <stdio.h>
#include <map>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

typedef long long ll;

#define mp make_pair
#define pb push_back
#define ab(x) (((x)<0)?-(x):(x))


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n;
        int c[2];
        c[0] = c[1] = 0;

        for (int i = 0; i < n*2; i++) {
            cin >> k;
            c[k % 2]++;
        }
        if (c[0] == c[1]) cout << "Yes" <<endl;
        else cout <<"No"<<endl;

    }

}
