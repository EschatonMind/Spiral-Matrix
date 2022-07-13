#include <iostream>
#include <vector>
using namespace std;
vector<int> spiralOrder(vector<vector<int>>& matrix) {
    vector<int> ans;
    int m = matrix.size();
    if (m == 0) return ans;
    int n = matrix[0].size();
    if (n == 0) return ans;

    int sr = 0, er = m - 1, sc = 0, ec = n - 1;
    int count = 0;

    while (sr <= er && sc <= ec) {

        /// print sr
        for (int i = sc; i <= ec; i++) {
            ans.push_back(matrix[sr][i]);
            count++;
        }
        sr++;
        if (count == m * n) return ans;

        /// print ec
        for (int i = sr; i <= er; i++) {
            ans.push_back(matrix[i][ec]);
            count++;
        }
        ec--;
        if (count == m * n) return ans;

        /// print er
        for (int i = ec; i >= sc; i--) {
            ans.push_back(matrix[er][i]);
            count++;
        }
        er--;
        if (count == m * n) return ans;

        /// print sc
        for (int i = er; i >= sr; i--) {
            ans.push_back(matrix[i][sc]);
            count++;
        }
        sc++;
        if (count == m * n) return ans;
    }
    return ans;

}

int main() {

    vector<vector<int>> Matrix;
    int R, C, a;
    cin >> R >> C;
    vector<int> z;
    for (int i = 0; i < R; i++) {
        
        Matrix.push_back(vector<int>());
        for (int j = 0; j < C; j++) {
            cin >> a;
            Matrix[i].push_back(a);

        }
    }
    cout << endl << "matrix is: " << endl << endl;
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cout << Matrix[i][j] << " ";
        }
        cout << endl;
    }

    z = spiralOrder(Matrix);
    cout << endl << "Spiral order is: ";
    for (vector<int>::iterator It = z.begin(); It != z.end(); It++) {

        cout << " | " << *It << " | ";
    }
    cout << endl;
    return 0;
}