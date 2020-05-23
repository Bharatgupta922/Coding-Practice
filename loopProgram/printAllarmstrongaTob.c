/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
C#, VB, Perl, Swift, Prolog, Javascript, Pascal, HTML, CSS, JS
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include<math.h>

int main()
{
	int a,n,sum,noOfDigits,b;
		scanf("%d",&n);
		for(int i =1;i<=n;i++) {
			a=i;
			sum=0;
			noOfDigits=0;
		noOfDigits=(int)log10(a)+1;
		a=i;
		while(a>0){
			b=a%10;
			sum+=pow(b,noOfDigits);
			a/=10;
		}
		if(sum==i) 
		printf("%d\n",i);
		
		
		}




    return 0;
}


