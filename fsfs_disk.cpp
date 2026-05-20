#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

int main() {
    int n;
    cout << "Enter number of requests: ";
    cin >> n;

    vector<int> requests(n);

    cout << "\nEnter disk requests\n";
    for(int i = 0; i < n; i++) {
        cout << "Request " << i + 1 << ": ";
        cin >> requests[i];
    }

    int current_head;
    cout << "Enter initial head position: ";
    cin >> current_head;

    int TTM = 0;

    cout << "\nMovement:\n";
    cout << current_head;

    for(int i = 0; i < n; i++) {
        int movement = abs(requests[i] - current_head);
        TTM += movement;
        current_head = requests[i];

        cout << " -> " << current_head;
    }

    cout << "\n\nTotal Track Movement: " << TTM;

    return 0;
}