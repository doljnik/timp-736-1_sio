#include <stdio.h>
int main()
{
	int n,count=0,i,x;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&x);
		if (x>=0)
		{
			count++;
		};
	};
	printf("%d\n",count);
	return 0;
}
