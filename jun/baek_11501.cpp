#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void solution() {
    int t, n;
    //input
    cin >> t;

    for (int i = 0;i < t;i++) {
        cin >> n;
        int tmp;
        long long result = 0;
        vector<int> stock_price;
        for (int j = 0;j < n;j++) {
            cin >> tmp;
            stock_price.push_back(tmp);
        }

        long long pole = stock_price[n-1];
        long long stock_num = 0;
        for (int k = stock_price.size() - 2;k >= 0;k--) {
            if (stock_price[k] > pole) {
                result += (pole * stock_num);
                pole = stock_price[k];
                stock_num = 0;
            }
            else {
                result -= stock_price[k];
                stock_num++;
            }
        }
        result += (pole * stock_num);


        //print result
        cout << result << '\n';
    }
}
int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    solution();
}
