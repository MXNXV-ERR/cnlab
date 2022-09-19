#include<stdio.h>
#include<string.h>
#define N strlen(divisor)
char data[28],temp[28],divisor[28];
int l,i,j;
void xorl()
{
        for(j=1;j<N;j++) //simple xor opration for all bits of divisor
                temp[j]=((temp[j]==divisor[j])?'0':'1');
}
void crc()
{
        for(i=0;i<N;i++)
                temp[i]=data[i];
        while(i<=l+N-1)//loop through len(data) + len(divisor) - 1
        {        if(temp[0]=='1')
                        xorl();//if one encountered xor
                for(j=0;j<N-1;j++)
                        temp[j]=temp[j+1]; //shift by a bit
                temp[j]=data[i++]; //take the next bit
        }
}
int main()
{
        printf("Enter the data\n");
        scanf("%s",&data);
        char ch='y';
        printf("CRC-16?(y/n)");
        scanf(" %c",&ch);//ask if crc-16 to be used
        if(ch=='y')
                strncpy(divisor, "1100000000000101", 28); //standard crc-16 divisor
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
        // for(i=l;i<l+N-1;i++)
        //         data[i]=temp[i-l];//fix that one extra shift
        printf("\nFinal codeword is : %s\n",data);
}
