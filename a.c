#include <stdio.h>
#include <stdlib.h>
//in this function we compare two number on the basis of lexicographically but from reverse
int compare(int a,int b)
{
   int r1=0,r2=0,temp=1;
   while(a&&b&&temp!=0)
{
int rem1=a%10;
int rem2=b%10;
a /= 10;
b/=10;
if(rem1<rem2)
   {
       temp=0;
       r1=1;

   }
if(rem1>rem2)
   {
       r2=1;
       temp=0;
   }
if(rem1==rem2)
   ;
}
return (r1>r2&&r1!=r2?1:(r2>r1&&r1!=r2?0:(a==0&&b==0?1:(a!=0?0:1))));

}

// in this function takes a integer value return reverse number of this integer
int reverseF(int n)
{
   int reverse = 0;



while (n != 0)
{
reverse = reverse * 10;
reverse = reverse + n%10;
n = n/10;
}

return reverse;

}
//this function swap two element
void swap( int *a,int pos1,int pos2)
{ int temp;
   temp=*(a+pos1);
   *(a+pos1)=*(a+pos2);
   *(a+pos2)=temp;
}
//this partition1 used for simple sorting in quicksort1
int partition1(int *a,int p,int r)
{
   int left,right,i;
   int x;
   x=*(a+r);
   left=p-1;
   right=p;
   for(;right<=r-1;right++)
   {
       if(*(a+right)<=x)
       {
           left++;
           swap(a,left,right);
          

       }
      
   }
   left++;
   swap(a,r,left);
   return left;
}
//this partion function used for lexicographically sorting in quicksort function
int partition(int *a,int p,int r)
{
   int left,right,i;
   int x;
   x=*(a+r);
   left=p-1;
   right=p;
   for(;right<=r-1;right++)
   {
       if(compare(reverseF(*(a+right)),reverseF(x)))
       {
           left++;
           swap(a,left,right);
          

       }
      
   }
   left++;
   swap(a,r,left);
   return left;
}
//this sorting used for lexicographically sorting
void quickSort( int *a,int p,int r)
{
   int t;
   if(p<r)
   {
      
       t=partition(a,p,r);
       quickSort(a,p,t-1);
       quickSort(a,t+1,r);

   }
}
//this sorting used for simple sorting
void quickSort1( int *a,int p,int r)
{
   int t;
   if(p<r)
   {
      
       t=partition1(a,p,r);
       quickSort1(a,p,t-1);
       quickSort1(a,t+1,r);

   }
}
void lexigoraphicalSort()
{int a[20],i;
   printf("enter 20 positive integer values: ");
   for(i=0;i<20;i++)
       scanf("%d",a+i);
   quickSort(a,0,19);
   printf("results of data sorted in lexicographically order:\n");
   for(i=0;i<20;i++)
       {
          
           printf("%d\t",a[i]);
           if((i+1)%5==0)
               printf("\n");
       }


}
void simpleSort()
{
   int a[20],i;
   printf("enter 20 positive integer values: ");
   for(i=0;i<20;i++)
       scanf("%d",a+i);
   quickSort1(a,0,19);
   printf("results of data sorted by number of digits:\n");
   for(i=0;i<20;i++)
       {
           printf("%d\t",a[i]);
           if((i+1)%5==0)
               printf("\n");
          
       }

}
int main()
{
   int p;
   printf("sorting options\n");
   printf("1.Lexicographical order\n");
   printf("2.Number of digits\n");
   printf("Enter your selection now: ");
   scanf("%d",&p);
   if(p==1)
       lexigoraphicalSort();
   else if(p==2)
      
       simpleSort();
   else
       printf("you have enterd wrong choice\n");
   return 0;
}

/*

output:-
sorting options
1.Lexicographical order
2.Number of digits
Enter your selection now: 1
enter 20 positive integer values :
1 10001 100012 2 4 5 6 60 601 41 52 258 52 63 52 41 49 85 458 4521
results of data sorted in lexicographically order::
1   10001   100012   2   258  
4   41   41   4521   458  
49   5   52   52   52  
60   6   601   63   85  

sorting options
1.Lexicographical order
2.Number of digits
Enter your selection now: 2
enter 20 positive integer values :
1 10001 100012 2 4 5 6 60 601 41 52 258 52 63 52 41 49 85 458 4521
results of data sorted by number of digits:
1   2   4   5   6  
41   41   49   52   52  
52   60   63   85   258  
458   601   4521   10001   100012  

*/