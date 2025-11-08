#include<stdio.h>
main()

{
	int n,a[100],i,e=0,o=0;
	printf("enter no. of elements in array:");
	scanf("%d",&n);
	printf("enter elements of array:\n");
	for(i=1;i<=n;i++)
{
	scanf("%d",&a[i]);
	}
	for(i=1;i<=n;i++)
	{
		if(i%2==0)
		{
			e=e+a[i];
		}
		else
		{
			o=o+a[i];
		}
	}
	printf("the sum of even index elements is %d\n",e);
	printf("the sum of odd index elements is %d\n",o);
	
}
