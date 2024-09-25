#include<bits/stdc++.h>
using namespace std;
struct pr{
  int p_id;      //Process ID
  int burst_time;//CPU Burst Time
  int prior;     //Priority Of The Process
};
bool cmp(pr a, pr b)
{
    return a.prior>b.prior;
}
void prior_scheduling(pr process[],int n)
{
    sort(process,process+n,cmp);//sorting processes by priority
    cout<<"Order of the executed processes: ";
    for(int i=0;i<n;i++)
    {
        cout<<process[i].p_id<<" ";
    }
    cout<<endl;
}
void wait_time(pr process[],int n,int waiting_time[])
{
    waiting_time[0]=0;
    //calculating waiting time
    for(int i=1;i<n;i++)
    {
        waiting_time[i]=process[i-1].burst_time+waiting_time[i-1];
    }
}
void turn_around(pr process[],int n,int waiting_time[],int turn_around_time[])
{
    //calculating turn around time
    for(int i=0;i<n;i++)
    {
        turn_around_time[i]=process[i].burst_time+waiting_time[i];
    }
}
void average_time(pr process[],int n)//calculating average time
{
    int waiting_time[n],turn_around_time[n],total_wt=0,total_tat=0;
    wait_time(process,n,waiting_time);
    turn_around(process,n,waiting_time,turn_around_time);
    cout<<"________________________________________________________________"<<endl;
    cout<<"Processes\t"<<"Burst Time\t"<<"Waiting Time\t"<<"Turn Around Time"<<endl;
    cout<<"----------------------------------------------------------------"<<endl;
    //calculating total waiting and turn around time
    for(int i=0;i<n;i++)
    {
        total_wt+=waiting_time[i];
        total_tat+=turn_around_time[i];
        cout<<"    "<<process[i].p_id<<"\t\t  "<<process[i].burst_time<<"\t\t    "<<waiting_time[i]<<"\t\t    "<<turn_around_time[i]<<endl;
        cout<<"----------------------------------------------------------------"<<endl;
    }
    cout<<"Average Waiting Time: "<<(float)total_wt/n<<endl;
    cout<<"Average Turn Around Time: "<<(float)total_tat/n<<endl;

}
int main()
{
    pr process[100];
    int n;
    cout<<"Please Enter Process number: ";
    cin>>n;
    cout<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<"Process Number->"<<i+1<<endl;
        int x;
        cout<<"Enter P_ID: ";
        cin>>x;
        int y;
        cout<<"Enter Burst Time: ";
        cin>>y;
        int z;
        cout<<"Enter Priority: ";
        cin>>z;
        process[i]={x,y,z};
        cout<<endl;
    }
    prior_scheduling(process,n);
    average_time(process,n);
}
