#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>

void bubbleSort(int arr[], int n) {
    int i, j;
    for (i = 0; i < n-1; i++) {
        for (j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}
int main() {
    int arr[] = {12, 11, 10, 5, 6};
    int n = sizeof(arr) / sizeof(arr[0]);
    


    int pid = fork();

    if (pid == -1) {
        printf("Fork failed");
    } else if (pid == 0) { // Child process
        bubbleSort(arr, n);
        printf("\nChild process sorted the integers:\n");
        for (int i = 0; i < n; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n");
    } else { // Parent process
        wait(NULL);
        printf("\nParent process sorted the integers:\n");
        bubbleSort(arr, n);
        for (int i = 0; i < n; i++) {
            printf("%d ", arr[i]);
        }
       // printf("\n");
    }


    return 0;
}
