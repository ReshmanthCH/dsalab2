//Finding the strength of input numbers
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> s(n);
        for (int i = 0; i < n; ++i) {
            cin >> s[i];
        }

        // Find the two maximum elements
        int max1 = -1, max2 = -1;
        for (int i = 0; i < n; ++i) {
            if (s[i] > max1) {
                max2 = max1;
                max1 = s[i];
            } else if (s[i] > max2) {
                max2 = s[i];
            }
        }

        // Calculate the result for each participant
        for (int i = 0; i < n; ++i) {
            if (s[i] == max1) {
                cout << s[i] - max2 << " ";
            } else {
                cout << s[i] - max1 << " ";
            }
        }
        cout << endl;
    }

    return 0;
}