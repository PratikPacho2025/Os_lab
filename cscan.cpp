#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;

int main(){
    int n;
    cout<<"Enter number of requests:: ";
    cin>>n;

    vector<int> requests(n);

    cout<<"\nEnter disk requests\n";
    for(int i=0;i<n;i++){
        cout<<"Request "<<i+1<<":: ";
        cin>>requests[i];
    }

    int current_head;
    cout<<"Enter initial head position:: ";
    cin>>current_head;

    int disk_size;
    cout<<"Enter disk size:: ";
    cin>>disk_size;

    int start_head = current_head;

    sort(requests.begin(), requests.end());

    int TTM = 0;

    cout<<"\nMovement:\n";
    cout<<current_head;

    // Move right
    for(int i=0;i<n;i++){
        if(requests[i] >= start_head){
            TTM += abs(requests[i]-current_head);
            current_head = requests[i];
            cout<<" -> "<<current_head;
        }
    }

    // Go to end
    if(current_head != disk_size-1){
        TTM += abs((disk_size-1)-current_head);
        current_head = disk_size-1;
        cout<<" -> "<<current_head;
    }

    // Jump to start
    TTM += current_head;
    current_head = 0;
    cout<<" -> "<<current_head;

    // Serve left side only
    for(int i=0;i<n;i++){
        if(requests[i] < start_head){
            TTM += abs(requests[i]-current_head);
            current_head = requests[i];
            cout<<" -> "<<current_head;
        }
    }

    cout<<"\n\nTotal Track Movement:: "<<TTM;

    return 0;
}