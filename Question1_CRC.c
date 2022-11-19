#include<stdio.h>
#include<string.h>
#define N strlen(divisor)
char data[28],temp[28],divisor[28];
int l,i,j;
void xorl()
{
        for(j=1;j<N;j++) 
                temp[j]=((temp[j]==divisor[j])?'0':'1');
}
void crc()
{
        for(i=0;i<N;i++)
                temp[i]=data[i];
        do{
                if(temp[0]=='1')
                        xorl();
                for(j=0;j<N-1;j++)
                        temp[j]=temp[j+1]; 
                temp[j]=data[i++]; 
        }while(i<=l+N-1);
}
int main()
{
        printf("Enter the data\n");
        scanf("%s",&data);
        char ch='y';
        printf("CRC-16?(y/n)");
        scanf(" %c",&ch);
        if(ch=='y')
                strncpy(divisor, "1100000000000101", 28); 
        else
        {       printf("Enter the divisor\n");
                scanf("%s",&divisor);
        }
        printf("\nGenerating polynomial:%s\n",divisor);
        l=strlen(data);
        for(i=l;i<l+N-1;i++)
                data[i]='0';
        printf("Modified data is:%s\n",data);
        crc();
        printf("Remainder is:%s\n",temp);
        for(i=l;i<l+N-1;i++)
                data[i]=temp[i-l];
        printf("\nFinal codeword is : %s\n",data);
}
