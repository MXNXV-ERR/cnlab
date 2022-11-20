// Write a program to archive Traffic management at Flow level by implementing Leaky
// Bucket Algorithm.

#include<stdio.h>
int main(){
    int incoming, outgoing, buck_size, n, store = 0;
    printf("Enter bucket size, outgoing rate and no of inputs: ");
    scanf("%d %d %d", &buck_size, &outgoing, &n);
    //While throught number of inputs
    while (n != 0) 
    {   printf("\n\nEnter the incoming packet size : ");
        scanf("%d", &incoming);
        printf("Incoming packet size %d\n", incoming);
        if (incoming <= (buck_size - store))
        {   store += incoming;//Add to bucket
            printf("Bucket buffer size %d out of %d\n", store, buck_size);
        } 
        else 
        {   printf("DROPPED %d no of packets\n", incoming - (buck_size - store));
            printf("Bucket buffer size %d out of %d\n", store, buck_size);
            store = buck_size;//Drop extra packets
        }
        store = store - outgoing;
        printf("After outgoing %d packets left out of %d in buffer\n", store, buck_size);
        n--;//Remove outgoing packet from full size of bucket
    }
}