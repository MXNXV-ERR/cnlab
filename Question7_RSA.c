// Write a program for simple RSA algorithm to encrypt and decrypt the data.

#include<stdio.h>
#include<math.h>
int gcd(int a, int h)
{   while(1)
    {   int temp = a%h;
        if(temp==0)
            return h;
        a = h;
        h = temp;
    }
}
 int main()
{   //e for encrypts(public key),d for decrypts(private key)
    int p,q,msg,e=2,d=e;
    printf("Enter two prime numbers:");
    scanf("%d%d",&p,&q);
    printf("Enter the messsage:");
    scanf("%d",&msg);
    int n=p*q,phi_of_n = (p-1)*(q-1);
    //for checking co-prime which satisfies e>1
    while(e<phi_of_n)
    {
        if(gcd(e,phi_of_n)==1)
            break;
        else
            e++;
    }
    //choosing d such that it satisfies d*e mod phi_of_n= 1 
    while(1)
    {
        if(fmod(d*e,phi_of_n)==1)
            break;
        else
            d++; 
    }
    //encrpyt and decrypt data and print
    long long encrpted =fmod(pow(msg,e),n);
    long long decrypted = fmod(pow(encrpted,d),n);
    printf("Message data =%d ",msg);
    printf("\np = %d",p);
    printf("\nq = %d",q);
    printf("\nn = pq = %d",n);
    printf("\nphi(n) = %d",phi_of_n);
    printf("\ne = %d",e);
    printf("\nd = %d ",d);
    printf("\nEncrypted data = %d",encrpted);
    printf("\nDecrypted data (from encrypted)=%d\n",decrypted);
}