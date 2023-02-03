#include<stdio.h>
#include<stdlib.h>

void fastsort(int arr[], int count){
    //printf("check 1\n");
    int pmin = arr[0], pmax = arr[0], nmax = arr[0], nmin = arr[0];

    for(int i=0;i<count;i++){
        if(arr[i] < 0){
            if(arr[i] *-1 > -1 * nmax)
                nmax = arr[i] * -1;
            else if(arr[i] *-1 < -1 * nmin)
                nmin = arr[i] * -1;
        }
        else if(arr[i] < pmin)
            pmin = arr[i];
        if(arr[i] > pmax)
            pmax = arr[i];
    }
//printf("check 2\n");
    int arrmax = nmax;
    int arrmin = nmin;

    int freqneg[arrmax-arrmin+1];
    for(int i=0; i < arrmax-arrmin+1; i++){
        freqneg[i]=0;
    }

    int ncount=0, pcount=0;
//printf("check 3\n");
    for(int i=0;i<count;i++){
        if(arr[i] < 0){
            freqneg[(-1*arr[i])-arrmin]+=1;
            ncount+=1;
        }
    }
//printf("check 4\n");
    arrmax = pmax;
    arrmin = pmin;

    int freqpos[arrmax-arrmin+1];
    for(int i=0; i < arrmax-arrmin+1; i++){
        freqpos[i]=0;
    }
//printf("check 5\n");
    for(int i=0;i<count;i++){
        if(arr[i] > -1){
            freqpos[arr[i]-arrmin]+=1;
            pcount+=1;
        }
    }
//printf("check 6\n");
    int iter=0;
    int niter=0;
    int j = 0;
    while(niter < ncount){
        while(freqneg[j]){
            arr[ncount-1-iter++] = (j + nmin)* -1;
            freqneg[j]--;
            niter++;
        }
        j++;
    }
//printf("check 7\n");
    int piter=0;
    j = 0;
    while(piter < pcount){
        while(freqpos[j]){
            arr[iter++] = j + pmin;
            freqpos[j]--;
            piter++;
            //printf("%d ",freqpos[j]);
            //printf("%d %d\n",piter,pcount);
            //printf("%d\n",arr[iter-1]);
        }
        j++;
    }

//printf("check 8\n");
}

int main(){
    int count;
    printf("Enter the number of elements\n");
    scanf("%d",&count);
    int arr[count];
    printf("Enter the elements\n");
    for(int i=0;i<count;i++){
        scanf("%d",&arr[i]);
    }

    fastsort(arr,count);

    printf("Sorted elements:\n");

    for(int i=0;i<count;i++){
        printf("%d ",arr[i]);
    }

    return 0;
}