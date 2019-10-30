//算法2 T(N)=O(N^2)
//其实我写的这个算法已经涉及到了 sum+number[i]<0 这一概念了，这个写法反而比较累赘，官方mooc上的代码更加精简清晰。

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;                    //数组元素个数
    scanf("%d",&n);
    int i=0;
    int number[n];
    for(i=0;i<n;i++)
    {
        scanf("%d",&number[i]);
    }
    int sum;
    sum=0;
    int result;
    result=0;
    int j=0;
    while(j<n)
    {
        for(i=j;i<n;i++)
        {
            if(sum+number[i]<0)
            {
                break;
            }
            else
            {
                sum+=number[i];
            }
            if(result<sum)
            {
                result=sum;
            }
        }
        sum=0;
        j=j+1;
    }
    printf("%d",result);
    return 0;
}





//算法 4 ，T(N)=O(N)
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;                    //数组元素个数
    scanf("%d",&n);
    int i=0;
    int number[n];
    for(i=0;i<n;i++)
    {
        scanf("%d",&number[i]);
    }
    int sum;
    sum=0;
    int result;
    result=0;
        for(i=0;i<n;i++)
        {
            if(sum+number[i]<0)
            {
                sum=0;
            }
            else
            {
                sum+=number[i];
            }
            if(result<sum)
            {
                result=sum;
            }
        }
    printf("%d",result);
    return 0;
}
