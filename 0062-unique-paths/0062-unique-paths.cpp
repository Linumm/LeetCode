class Solution {
public:
    int uniquePaths(int m, int n) {
        // We can think how to combinate the way (right, down)
        // So now it becomes the problem of combination (m-1, n-1) -> m-1+n-1Cm-1

        long long ans = 1;
        for (int i = 1; i <= m - 1; i++) {
            ans = ans * (n-1+i) / i;
        }
        return (int)ans;
    }
};
/*
28 21 15 10 6  3  1
7  6  5  4  3  2  1
1  1  1  1  1  1  1
*/

/* Normal DP sol
int uniquePaths(int m, int n) {
        int arr[m][n];
        for (int i=0; i<n; i++) {
            arr[m-1][i] = 1;
        }
        for (int i=m-2; i>=0; i--) {
            arr[i][n-1] = 1;
            for (int j=n-2; j>=0; j--) {
                arr[i][j] = arr[i+1][j] + arr[i][j+1];
            }
        }
        return arr[0][0];
    }
*/