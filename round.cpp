#include<iostream>
#include<queue>
#include<vector>
using namespace std;

struct Process{
    int pid;
    int at;
    int bt;
    int ct;
    int tat;
    int rem_bt;
    int wt;
};

void Bubble_sort(vector<Process>& pro,int n){
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if(pro[j].at > pro[j+1].at){
                swap(pro[j],pro[j+1]);
            }
        }
    }
}

void Turn_Around_Time(vector<Process> &pro,int n){
    for(int i=0;i<n;i++){
        pro[i].tat = pro[i].ct - pro[i].at;
    }
}

void Waiting_Time(vector<Process> &pro,int n){
    for(int i=0;i<n;i++){
        pro[i].wt = pro[i].tat - pro[i].bt;
    }
}

void Calculate_Robin(vector<Process> &pro,int n,int tq){
    Bubble_sort(pro,n);

    for(int i=0;i<n;i++){
        pro[i].rem_bt = pro[i].bt;
    }

    vector<bool> in_queue(n,false);
    queue<int> q;

    int curr_time = 0;
    int completed = 0;

    if(pro[0].at > 0){
        curr_time = pro[0].at;
    }

    q.push(0);
    in_queue[0] = true;

    while(completed < n){
        int idx = q.front();
        q.pop();

        if(pro[idx].rem_bt > tq){
            pro[idx].rem_bt -= tq;
            curr_time += tq;
        }
        else{
            curr_time += pro[idx].rem_bt;
            pro[idx].rem_bt = 0;
            pro[idx].ct = curr_time;
            completed++;
        }

        for(int i=0;i<n;i++){
            if(!in_queue[i] && pro[i].at <= curr_time && pro[i].rem_bt > 0){
                q.push(i);
                in_queue[i] = true;
            }
        }

        if(pro[idx].rem_bt > 0){
            q.push(idx);
        }

        if(q.empty()){
            for(int i=0;i<n;i++){
                if(pro[i].rem_bt > 0){
                    curr_time = pro[i].at;
                    q.push(i);
                    in_queue[i] = true;
                    break;
                }
            }
        }
    }

    Turn_Around_Time(pro,n);
    Waiting_Time(pro,n);
}

void Print_Data(vector<Process> &pro,int n){
    cout<<"\t\tRound Robin\t\t"<<endl;
    cout<<"PID\tAT\tBT\tCT\tTAT\tWT"<<endl;

    for(int i=0;i<n;i++){
        cout<<pro[i].pid<<"\t"
            <<pro[i].at<<"\t"
            <<pro[i].bt<<"\t"
            <<pro[i].ct<<"\t"
            <<pro[i].tat<<"\t"
            <<pro[i].wt<<endl;
    }
}

int main(){
    int n,tq;

    cout<<"Enter number of processes :: ";
    cin>>n;

    cout<<"Enter time quantum :: ";
    cin>>tq;

    vector<Process> pro(n);

    for(int i=0;i<n;i++){
        pro[i].pid = i+1;

        cout<<"Process "<<pro[i].pid<<":"<<endl;

        cout<<"Enter Arrival time :: ";
        cin>>pro[i].at;

        cout<<"Enter Burst time :: ";
        cin>>pro[i].bt;
    }

    Calculate_Robin(pro,n,tq);
    Print_Data(pro,n);

    return 0;
}
