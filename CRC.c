#include<string.h>
#define N strlen(g)
char t[28],cs[28],g[28];
int a,e,c,b;
void xor()
{
        for(c=1;c<N;c++)
                cs[c]=((cs[c]==g[c])?'0':'1');
}
void crc()
{
        for(e=0;e<N;e++)
                cs[e]=t[e];
        do{
                if(cs[0]=='1')
                        xor();
                for(c=0;c<N-1;c++)
                        cs[c]=cs[c+1];
                cs[c]=t[e++];
        }while(e<=a+N-1);
}
int main()
{
        printf("Enter the data\n");
        scanf("%s",&t);
        char ch='y';
        printf("CRC-16?(y/n)");
        scanf(" %c",&ch);
        if(ch=='y')
                strncpy(g, "1100000000000101", 28);
        else
        {       printf("Enter the divisor\n");
                scanf("%s",&g);
        }
        printf("\nGenerating polynomial:%s\n",g);
        a=strlen(t);
        for(e=a;e<a+N-1;e++)
                t[e]='0';
        printf("Modified data is:%s\n",t);
        crc();
        printf("Remainder is:%s\n",cs);
        for(e=a;e<a+N-1;e++)
                t[e]=cs[e-a];
        printf("\nFinal codeword is : %s\n",t);
}
