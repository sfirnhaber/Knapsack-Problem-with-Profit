#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    //Input
    int c, n;
    cin >> c >> n;
    int weights[n], points[n];
    for (int i = 0; i < n; i++) {
        cin >> weights[i];
        cin >> points[i];
    }
    
    //Algorithms
    unsigned short **chart = new unsigned short* [n + 1];
    for (int i = 0; i <= n; i++)
        chart[i] = new unsigned short[c + 1];
    for (int i = 0; i <= n; i++)
        chart[i][0] = 0;
    for (int j = 0; j <= c; j++)
        chart[0][j] = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= c; j++) {
            if (j < weights[i - 1])
                chart[i][j] = chart[i - 1][j];
            else
                chart[i][j] = max((int)(points[i - 1] + chart[i - 1][j - weights[i - 1]]), (int)chart[i - 1][j]);
        }
    }
    
    cout << chart[n][c] << endl;
    
    //Testing
    /*cout << endl;
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= c; j++)
            cout << chart[i][j] << " ";
        cout << endl;
    }*/
    
    return 0;
}
