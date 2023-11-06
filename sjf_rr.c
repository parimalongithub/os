#include<stdio.h>

typedef struct Process{
    int pid;
    int Arrival_time;
    int Burst_rate;
    int Remaning_burst_rate;
    int waiting_time;
    int Turn_Around_time;
    int completion_time;
}Process;




void round_robin(Process p[],int n,int quantum){
    int completed_precoess=0;
    int current_time=0;

    while(completed_precoess<n){
        for(int i =0;i<n;i++){
            if(p[i].Remaning_burst_rate<=quantum && p[i].Remaning_burst_rate>0){
                current_time+=p[i].Remaning_burst_rate;
                p[i].completion_time=current_time;
                p[i].Remaning_burst_rate=0;
                p[i].Turn_Around_time=p[i].completion_time-p[i].Arrival_time;
                p[i].waiting_time=p[i].Turn_Around_time-p[i].Burst_rate;
                completed_precoess++;
            }
            else if (p[i].Remaning_burst_rate>0){ 
                current_time+=quantum;
                p[i].Remaning_burst_rate-=quantum;
            }

        }
    }
}

void sjf(Process p[],int n){
    int completed_process=0;
    int selected_process=-1;
    int min_burst_rate=9999;
    int cureent_time=0;
    while(completed_process<n){
        for(int i=0;i<n;i++){
            if(p[i].Arrival_time<=cureent_time && p[i].Burst_rate<min_burst_rate && p[i].Remaning_burst_rate>0){
                min_burst_rate=p[i].Remaning_burst_rate;
                selected_process=i;
            }
        }


        p[selected_process].Remaning_burst_rate--;
        min_burst_rate=p[selected_process].Remaning_burst_rate;
        cureent_time++;

        if(min_burst_rate==0){
            p[selected_process].completion_time=cureent_time;
            p[selected_process].Turn_Around_time=p[selected_process].completion_time-p[selected_process].Arrival_time;
            p[selected_process].waiting_time=p[selected_process].Turn_Around_time-p[selected_process].Burst_rate;
            min_burst_rate=9999;
            selected_process=-1;
            completed_process++;
        }
    }

    



}

int main(){

    int n;
    printf("Enter The total number of proecess:");
    scanf("%d",&n);
    Process p[n];

    for(int i=0;i<n;i++){
        printf("Enter the PID: ");
        scanf("%d",&p[i].pid);

        printf("Enter the Arrival Time: ");
        scanf("%d",&p[i].Arrival_time);

        printf("Enter the Burst Rate: ");
        scanf("%d",&p[i].Burst_rate);

        p[i].Remaning_burst_rate=p[i].Burst_rate;

    }
    sjf(p,n);

   // round_robin(p,n,2);


    printf("Process ID\tCompletion time\tTAT\tWT\n");
    for(int i=0;i<n;i++){
        printf("%d\t\t%d\t\t%d\t%d\n",p[i].pid,p[i].completion_time,p[i].Turn_Around_time,p[i].waiting_time);

    }

    return 0;
}
