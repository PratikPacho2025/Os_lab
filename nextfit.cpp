#include<iostream>
#include<vector>
using namespace std;

int main(){
           int np;
           cout<<"Enter number of process:: ";
           cin>>np;
           int nb;
           cout<<"Enter number of blocks:: ";
           cin>>nb;
           vector<int> process(np);
           vector<int> block(nb);
           vector<int> allocation(np,-1);

           cout<<"Enter process sizes\n";
           for(int i=0;i<np;i++){
                      cout<<"process "<<i+1<<":: ";
                      cin>>process[i];
           }

           cout<<"Enter block sizes\n";
           for(int i=0;i<nb;i++){
                      cout<<"block "<<i+1<<":: ";
                      cin>>block[i];
           }
           int last = 0;
           for(int i=0;i<np;i++){
                      int count = 0;
                      int j = last;
                      while(count < nb){
                                 if(block[j]>=process[i]){
                                            allocation[i] = j;
                                            block[j]-=process[i];
                                            last = j;
                                            break;
                                 }
                                 j = (j+1)%nb;
                                 count++;
                      }
           }

           cout<<"\nProcess\tSize\tBlock\n";
           for(int i=0;i<np;i++){
                      cout<<i+1<<"\t"<<process[i]<<"\t";
                      if(allocation[i]!=-1){
                                 cout<<allocation[i]+1;
                      }else{
                                 cout<<"Not Allocated";
                      }
                      cout<<endl;
           }
}