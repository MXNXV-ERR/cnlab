#include <bits/stdc++.h>
using namespace std;
string addBinaryUtil(string a, string b)
{
	string result = ""; 
	int s = 0;
	int i = a.size() - 1, j = b.size() - 1;
	while (i >= 0 || j >= 0 || s == 1) 
    {   
		s += ((i >= 0) ? a[i] - '0' : 0);
		s += ((j >= 0) ? b[j] - '0' : 0);
		result = char(s % 2 + '0') + result;
		s /= 2;    
        i--;  j--;  
	}
	return result;
}
string checkSum(string arr[], int n,int x)
{
	string result = "";
	for (int i = 0; i < n; i++)
		result = addBinaryUtil(result, arr[i]);
    if(result.length()==x)
        return result; 
    else
    {   arr[0]=result.substr(0,result.length()-x);
        arr[1]=result.substr(result.length()-x,x);
        return checkSum(arr,2,x);
    }
}

int main()
{
    int n,x;
    cout<<"Enter number of bits:";
    cin>>x;
    cout<<"Enter number of numbers:";
    cin>>n;  
	string arr[n] ;
    cout<<"Enter the numbers\n";
    for(int i=0;i<n;i++)
        cin>>arr[i];
    string ans=checkSum(arr,n,x);
    cout<<"Ans:";
    for (int i = 0; i < x; i++)
        ans[i]=='0'?cout<<'1':cout<<'0';
	return 0;
}

