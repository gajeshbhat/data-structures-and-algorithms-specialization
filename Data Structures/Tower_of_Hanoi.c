#include "stdio.h"
#include "stdlib.h"

int Tower_of_Hanoi(int n,char frompeg,char topeg,char interpeg)
{
  if(n==1)
  {
    printf("\nMove Disk 1 from %c to %c\n",frompeg,topeg);
    return 0;
  }

Tower_of_Hanoi(n-1,frompeg,interpeg,topeg);


printf("\nMove Disk %d from %c to %c \n",n,frompeg,topeg);


Tower_of_Hanoi(n-1,interpeg,topeg,frompeg);

}

int main(int argc, char const *argv[]) {
int n;
printf("\nEnter Number of Disks\n");
scanf("%d",&n);
printf("\nMove of Tower of Hanhoi involve\n" );
Tower_of_Hanoi(n,'A','B','C');
printf("\n");
  return 0;
}
