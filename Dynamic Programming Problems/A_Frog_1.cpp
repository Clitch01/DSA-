/* https://atcoder.jp/contests/dp/tasks/dp_a */

#include <bits/stdc++.h>
using namespace std;
#define ll long long

int ans(int i, ll a[], ll cache[])
{
    if (i <= 0)
    {
        return 0;
    }
    if (cache[i] != -1 || i == 1)
    {
        return cache[i];
    }
    return cache[i] = min(abs(a[i] - a[i - 1]) + ans(i - 1, a, cache), abs(a[i] - a[i - 2]) + ans(i - 2, a, cache));
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;
    ll a[n];
    ll cache[n];
    memset(cache, -1, sizeof(cache));

    for (auto &i : a)
    {
        cin >> i;
    }

    cache[0] = 0;
    cache[1] = abs(a[1] - a[0]);

    cout << ans(n - 1, a, cache);

    return 0;
}
