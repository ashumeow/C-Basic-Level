/* Two dimensional arrays */
#include<stdio.h>
int main(void)
{
	int t, i, num[3][4];
	for(i=0;i<4;++i)
		for(t=0;t<4;++t)
		num[i][t]=(i*4)+t+1;
	for(i=0;i<4;++i)
	{
		for(t=0;t<4;++t)
			printf("%3d",num[i][t]);
		printf("\n");
	}
	return 0;
}
