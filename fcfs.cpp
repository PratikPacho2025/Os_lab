#include<iostream>
#include<vector>
using namespace std;

struct Process{
           int pid;
           int at;
           int burstTime;
           int ct;
           int tat;
           int wt;
};
void Bubble_sort(vector<Process>& pro,int n){
           for(int i=0;i<n-1;i++){
                      for(int j=0;j<n-1-i;j++){
                                 if(pro[j].at>pro[j+1].at){
                                            swap(pro[j],pro[j+1]);
                                 }
                      }
           }
}
void Completion_Time(vector<Process> &pro, int n){
           pro[0].ct = pro[0].at + pro[0].burstTime;
           for(int i=1;i<n;i++){
                      if(pro[i].at>pro[i-1].ct){
                              pro[i].ct =pro[i].at+pro[i].burstTime;   
                      }else{
                              pro[i].ct =pro[i-1].ct+pro[i].burstTime;
                      }
                      
           }
}

void Turn_Around_Time(vector<Process> &pro, int n){
           for(int i=0;i<n;i++){
                      pro[i].tat = pro[i].ct - pro[i].at;
           }
}

void Waiting_Time(vector<Process> &pro, int n){
           for(int i=0;i<n;i++){
                      pro[i].wt = pro[i].tat - pro[i].burstTime;
           }
}

void Calculate_FCFS(vector<Process> &pro, int n){
           Bubble_sort(pro, n);
           Completion_Time(pro, n);
           Turn_Around_Time(pro, n);
           Waiting_Time(pro, n);
}
void Print_Data(vector<Process> &pro, int n){
           cout<<"FCFS Scheduling"<<endl;
           cout<<"pid\t"<<"Arrival Time\t"<<"Burst Time\t"<<"Comp Time\t"<<"TAT\t"<<"Waiting Time\t"<<endl;
           for(int i=0;i<n;i++){
                      cout<<pro[i].pid<<"\t\t"<<pro[i].at<<"\t\t"<<pro[i].burstTime<<"\t\t"<<pro[i].ct<<"\t\t"<<pro[i].tat<<"\t\t"<<pro[i].wt<<"\t\t"<<endl;
           }
}
int main(){
   int n;
   cout<<"Enter the number of processes: ";
   cin>>n;
   
   vector<Process> pro(n);
   for (int i = 0; i < n; i++) {
        pro[i].pid = i + 1;
        cout << "Process " << pro[i].pid << ":" << endl;
        cout << "Enter Arrival Time: ";
        cin >> pro[i].at;
        cout << "Enter Burst Time: ";
        cin >> pro[i].burstTime;
    }

    Calculate_FCFS(pro,n);
    Print_Data(pro,n);
    return 0;;
}

