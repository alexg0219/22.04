#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
using namespace std;

void main()
{
    int n, m, comp = 0;
    cin >> n;
    vector<int> a;

    for (int i = 0; i < n; i++) 
    {
        int temp;
        cin >> temp;
        a.push_back(temp);
    }

    vector<vector<int>> b(n, vector<int>(n, 1e9));
    cin >> m;

    for (int i = 0; i < m; i++) 
    {
        int x, y;
        cin >> x >> y;
        b[x - 1][y - 1] = a[x - 1];
        b[y - 1][x - 1] = a[y - 1];
    }

    for (int k = 0; k < n; k++) 
    {
        for (int i = 0; i < n; i++) 
        {
            for (int j = 0; j < n; j++) 
            {
                if (b[i][k] < 1e9 && b[k][j] < 1e9)
                {
                    b[i][j] = min(b[i][j], b[i][k] + b[k][j]);
                }
            }
        }
    }

    for (int i = 0; i < n; i++) 
    {
        for (int j = 0; j < n; j++) 
        {
            if (b[i][j] > comp && b[i][j] != 1) 
            {
                comp = b[i][j];
            }
        }
    }

    for (int i = 0; i < n; i++) 
    {
        b[i][i] = 0;
    }

    int ans = b[0][n - 1];

    if (ans == 1e9) 
        ans = -1;
    cout << ans << endl;
}