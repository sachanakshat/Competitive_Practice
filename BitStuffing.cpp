// #include<iostream>

// #include<stdio.h>
// #include<string.h>

// using namespace std;

// void main() {
// 	int i, j,count=0,nl;
// 	char str[100];
// 	printf("enter the bit string:  ");
// 	fgets(str);
// 	for (i=0;i<strlen(str);i++) {
// 		count=0;
// 		//the following code search the six ones in given string
// 		for (j=i;j<=(i+5);j++) {
// 			if(str[j]=='1') {
// 				count++;
// 			}
// 		}
// 		//if there is six ones then folling code execute to bit stuffing after five ones
// 		if(count==6) {
// 			nl=strlen(str)+2;
// 			for (;nl>=(i+5);nl--) {
// 				str[nl]=str[nl-1];
// 			}
// 			str[i+5]='0';
// 			i=i+7;
// 		}
// 	}
// 	puts(str);
// 	getch();
// }


#include<stdio.h>
#include<string.h>
int main()
{
int a[20],b[30],i,j,k,count,n;
printf("Enter frame length:");
scanf("%d",&n);
printf("Enter input frame (0's & 1's only):");
for(i=0;i<n;i++)
    scanf("%d",&a[i]);
i=0; count=1; j=0;
while(i<n)
{
    if(a[i]==1)
    {
        b[j]=a[i];
        for(k=i+1;a[k]==1 && k<n && count<5;k++)
        {
            j++;
            b[j]=a[k];
            count++;
            if(count==5)
            {
                j++;
                b[j]=0;
            }
            i=k;
        }
    }
    else
    {
        b[j]=a[i];
    }
    i++;
    j++;
}
printf("After stuffing the frame is:");
for(i=0;i<j;i++)
    printf("%d",b[i]);
printf("\n");
return 0;
}