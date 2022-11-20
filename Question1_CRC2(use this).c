#include<stdio.h>
#include<string.h>
char data[28],temp[28],divisor[28],q[28];
int l,i,j,N=16;
void xorl()
{   for(j=1;j<N;j++) //simple xor opration for all bits of divisor
                temp[j]=((temp[j]==divisor[j])?'0':'1');
}
void crc()
{   for(i=0;i<N;i++)
        temp[i]=data[i];
    int w=0;    
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
	int choice,flag;char ch='y';
while(1)
{   printf("\n\nEnter the data\n");
	scanf("%s",&data);
    
    printf("CRC-16?(y/n): ");
    scanf(" %c",&ch);//ask if crc-16 to be used or no
    
    if(ch=='y')
        strncpy(divisor, "1100000000000101", 28); //standard crc-16 divisor
	else{       
		printf("Enter the divisor: ");
        scanf("%s",&divisor);
        N=strlen(divisor);
    }
    
    printf("Menu: \n1. Find final codeword(Sender's side\')\n");
	printf("2. Check The Code word(Receiver's Side)\n");
    printf("Enter your choice: ");
    scanf("%d",&choice);
    if(choice==2)
    	goto there;
    
	printf("\nGenerating polynomial: %s\n",divisor);
    l=strlen(data);
    for(i=l;i<l+N-1;i++)
        data[i]='0';
    printf("Modified data is: %s\n",data);
    crc();
    printf("Remainder is: %s\n",temp);
    for(i=l;i<l+N-1;i++)
        data[i]=temp[i-l];//fix that one extra shift
    printf("\nFinal codeword is : %s\n",data);
    goto final;
    
there:
	flag=0;
	crc();
	printf("\nRemainder is:%s\nTherefor,\n",temp);
	for(i=l;i<l+N-1;i++)
		if(temp[i-l]=='1'){
			flag=1;
			break;
		}
			        	
    if(flag==0)
    	printf("Data doesnt have any errors.\n");
    else
    	printf("Data has errors.\n");
		  
final:
	 printf("Enter the values again?(y/n): ");
    scanf(" %c",&ch);//ask user to restart or not
    if(ch=='y')
       break;
}
}
