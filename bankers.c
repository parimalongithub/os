#include <stdio.h>


void main(){
    int resources,process,instance,count=0,temp=0,k=0;
    printf("Enter the No of Process: ");
    scanf("%d",&process);
    printf("Enter the No of Resources: ");
    scanf("%d",&resources);


    int available[resources],max[process][resources],allocated[process][resources],need[process][resources],completed[process];
    for(int i=0;i<process;i++){
        completed[i]=0;
    }

    printf("Enter the Availble resources\n");
    for(int i=0;i<resources;i++){
        printf("Resources[%d]: ",i);
        scanf("%d",&instance);
        available[i]=instance;
    }


    printf("\n----------------------------------------------------------->\n");
    printf("\nEnter Max Matrix for the process \n");
    for(int i=0;i<process;i++){
        printf("For process[%d]\n",i);
        for(int j=0;j<resources;j++){
            printf("Resources[%d]: ",j);
            scanf("%d",&instance);
            max[i][j]=instance;
        }
    }

    printf("\n------------------------------------------------------------>\n");
    printf("\nEnter Allocation Matrix for the process \n");
    for(int i=0;i<process;i++){
        printf("For the Process[%d]\n",i);
            for(int j=0;j<resources;j++){
                printf("Resources[%d]\n",j);
                scanf("%d",&instance);
                allocated[i][j]=instance;
                need[i][j]=max[i][j]-allocated[i][j];

            }
        }
    printf("\n------------------------------------------------------------>\n");
    printf("\nSafe sequnce  is: ");

    while(count!=process){

        for(int i=0;i<process;i++){
            for(int j=0;j<resources;j++){
                if(need[i][j]<=available[j]){
                    k++;
                }
            }
            if(k==resources&&completed[i]==0){
                printf(">p[%d]",i);
                completed[i]=1;
                for(int j=0;j<resources;j++){
                    available[j]=available[j]+allocated[i][j];
                }       

                  count++;
            }
            k=0;
        }
    

    }
   for(int i=0; i<process; i++)
  {
    if(completed[i] != 1)
    {
      printf("\n\n P[%d] not able to allocate", i);
    }
  }
    printf("\n");

    

}











