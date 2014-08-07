#include<stdio.h>
#define number_of_bits 8
int main()
{
char *meow_string;
int meow_input, meow_args;
int meow_bytes=100;
short meow_short, meow_bit;
int meow_idx;
short meow_mask=0X80;
meow_args=0;
meow_input=-1;
while((meow_args!=1) || (meow_input<0) || (meow_input>128))
{
puts("enter an integer from 0 to 128");
meow_string=(char *) malloc(meow_bytes+1);
getline(&meow_string, &meow_bytes, stdin);
meow_args=sscanf(meow_string, "%d", &meow_input);
if((meow_args!=1) || (meow_input<0) || (meow_input>128))
puts("\n invalid");
}
meow_short=(short) meow_input;
printf("binary value= ");
for(meow_idx=0;meow_idx<number_of_bits;meow_idx++)
{
meow_bit=meow_short & meow_mask;
printf("%d",meow_bit/meow_mask);
meow_short<<=1;
}
printf("\n");
return 0;
}
