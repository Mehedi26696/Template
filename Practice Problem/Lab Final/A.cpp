//13
//13
//13
// //13



#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
    // Input reading
    int n, m;
    cin >> n;

    unordered_map<int, int> frequency; // Map to store frequencies of numbers
    int num;

    // Read the numbers and store their frequencies
    for (int i = 0; i < n; i++) {
        cin >> num;
        frequency[num]++;
    }

    cin >> m;
    
    int queries[m];

    // Read the queries
  
    for (int i = 0; i < m; i++) {
        cin >> queries[i];
    }

    // Output the frequency for each query
    for (int i = 0; i < m; i++) {
        cout << frequency[queries[i]] << endl; // Default is 0 for keys not in the map
    }

    return 0;
}
