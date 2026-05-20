#include <iostream>
#include <vector>
#include <climits> 
#include <cmath>
using namespace std;

int main() {
    int n, head;
    
    cout << "Enter number of requests: ";
    cin >> n;

    vector<int> req(n);
    vector<bool> visited(n, false);

    cout << "Enter request queue:\n";
    for(int i = 0; i < n; i++) {
        cin >> req[i];
    }

    cout << "Enter initial head position: ";
    cin >> head;

    int totalSeek = 0;

    cout << "\nSeek Sequence: " << head;

    for(int i = 0; i < n; i++) {
        int minDist = INT_MAX;
        int index = -1;

        for(int j = 0; j < n; j++) {
            if(!visited[j]) {
                int dist = abs(head - req[j]);

                if(dist < minDist) {
                    minDist = dist;
                    index = j;
                }
            }
        }

        visited[index] = true;
        totalSeek += minDist;
        head = req[index];

        cout << " -> " << head;
    }

    cout << "\nTotal Seek Time: " << totalSeek << endl;

    return 0;
}