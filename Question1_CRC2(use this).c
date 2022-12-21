// Write a program for implementing the error detection technique for data transfer in
// unreliable network code using CRC (16-bits) Technique.

#include<stdio.h>
#include<string.h>
char data[28],temp[28],divisor[28];
int l,i,j,N=16;
void xorl()
{   for(j=1;j<N;j++) //simple xor opration for all bits of divisor
                temp[j]=((temp[j]==divisor[j])?'0':'1');
}
void crc()
{   for(i=0;i<N;i++)
        temp[i]=data[i];
    do{
        if(temp[0]=='1')
            xorl();//if one encountered xor
        for(j=0;j<N-1;j++)
            temp[j]=temp[j+1]; //shift by a bit
        temp[j]=data[i++]; //take the next bit
    }while(i<=l+N-1);//loop through len(data) + len(divisor) - 1
}
void main()
{
	int choice,flag;char ch;
    repeat:
        printf("Enter new data\n");
    	scanf("%s",&data);
        //ask if crc-16 to be used or no
        printf("CRC-16?(y/n): ");
        scanf(" %c",&ch);
        //standard crc-16 divisor
        if(ch=='y')
            strncpy(divisor, "1100000000000101", 28); 
    	else
        {	printf("Enter the divisor: ");
            scanf("%s",&divisor);
            N=strlen(divisor);
        }
        l=strlen(data);
        while(1)
        {
            printf("\nMenu: \n1. Find final codeword(Sender's Side)\n");
        	printf("2. Check The Code word(Receiver's Side)\n");
            printf("3. Enter diffrenet values\n");
            printf("4. EXIT\n");
            printf("Enter your choice: ");
            scanf("%d",&choice);
            switch (choice)
            {
            case 1: for(i=l;i<l+N-1;i++)
                            data[i]='0';
                        printf("\nGenerating polynomial: %s\n",divisor);
                        printf("Modified data is: %s\n",data);
                        crc();
                        for(i=l;i<l+N-1;i++)
                            data[i]=temp[i-l];//fix that one extra shift
                        printf("Remainder is: %s\n",temp);
                        printf("Final codeword is : %s\n",data);
                        break;
            case 2:flag=0;
                        printf("Enter the recieved data on recievers side");
                        scanf("%s",&data);
                        crc();
    	                printf("\nRemainder is:%s\nTherefor,\n",temp);
    	                for(i=l;i<l+N-1;i++)
    	    	            if(temp[i-l]=='1')
                            {     flag=1;
    	    		            break;
    	    	            }
                        if(flag==0)
            	            printf("Data doesnt have any errors.\n");
                        else
            	            printf("Data has errors.\n");
                        break;
            case 3:goto repeat;
            case 4:exit(0);
            default:break;
            }    
        }
}
