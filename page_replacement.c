#include <stdio.h>

#define FRAME_SIZE 3

int frames[FRAME_SIZE];
int pages[] = {7, 0, 1, 2, 0, 3, 0, 4, 2, 3,  0, 3, 2};

void initializeFrames() {
    for (int i = 0; i < FRAME_SIZE; i++) {
        frames[i] = -1;
    }
}

int isPageInFrames(int page) {
    for (int i = 0; i < FRAME_SIZE; i++) {
        if (frames[i] == page) {
            return 1;
        }
    }
    return 0;
}

void displayFrames() {
    for (int i = 0; i < FRAME_SIZE; i++) {
        if (frames[i] != -1) {
            printf("%d ", frames[i]);
        } else {
            printf("- ");
        }
    }
    printf("\n");
}

void FCFS() {
    initializeFrames();   
    int pageFaults = 0;

    for (int i = 0; i < sizeof(pages) / sizeof(pages[0]); i++) {
        if (!isPageInFrames(pages[i])) {
            frames[pageFaults % FRAME_SIZE] = pages[i];
            pageFaults++; 
        }
        displayFrames();
    }

    printf("Total Page Faults (FCFS): %d\n", pageFaults);
}

void lru(){
    initializeFrames();
    int fault_pages = 0;

    for(int i = 0; i < sizeof(pages) / sizeof(pages[0]); i++){
        if(!isPageInFrames(pages[i])){
            int replace_index = 0;
            int least_recently_used =100;

            for(int j = 0; j < FRAME_SIZE; j++){
                int k;
                for(k = i-1; k >= 0; k--){
                    if(frames[j] == pages[k]){
                        break;
                    }
                }

                if(k < least_recently_used){
                    least_recently_used = k;
                    replace_index = j;
                }
            }

            frames[replace_index] = pages[i];
            fault_pages++;
        }

        displayFrames();
    }

    printf("Total pages in the fault is %d\n", fault_pages);
}


void Optimal() {
    initializeFrames();
    int pageFaults = 0;

    for (int i = 0; i < sizeof(pages) / sizeof(pages[0]); i++) {
        if (!isPageInFrames(pages[i])) {
            int replaceIdx = -1;
            for (int j = 0; j < FRAME_SIZE; j++) {
                int k;
                for (k = i ; k < sizeof(pages) / sizeof(pages[0]); k++) {
                    if (frames[j] == pages[k]) {
                        break;
                    }
                }
                if (k == sizeof(pages) / sizeof(pages[0])) {
                    replaceIdx = j;
                    break;
                }
            }


            frames[replaceIdx] = pages[i];
            pageFaults++;
        }
        displayFrames();
    }

    printf("Total Page Faults (Optimal): %d\n", pageFaults);
}

int main() {
  //  printf("FCFS Page Replacement Algorithm\n");
   // FCFS();
    //printf("\n");

   //printf("LRU Page Replacement Algorithm\n");
    //lru();
    //printf("\n");

  //  printf("Optimal Page Replacement Algorithm\n");
   Optimal();
   // printf("\n");

    return 0;
}
