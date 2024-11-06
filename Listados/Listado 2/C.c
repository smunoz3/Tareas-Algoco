#include<stdio.h>
int main()
{
    int N, i, j, temp;
    while(1)
    {
        scanf("%d", &N);
        if(N==0) break;
        else
        {
            int a1[N], a2[N], a3[N];
            for(i=0; i<N; i++)
            {
                scanf("%d", &a1[i]);
                a3[i] = a1[i];
            }

            for(i=0; i<N; i++)
            {
                scanf("%d", &a2[i]);
            }

            for(i=0; i<N-1; i++)
            {
                for(j=i+1; j<N; j++)
                {
                    if(a1[i] > a1[j])
                    {
                        temp = a1[i];
                        a1[i] = a1[j];
                        a1[j] = temp;
                    }
                }
            }

            for(i=0; i<N-1; i++)
            {
                for(j=i+1; j<N; j++)
                {
                    if(a2[i] > a2[j])
                    {
                        temp = a2[i];
                        a2[i] = a2[j];
                        a2[j] = temp;
                    }
                }
            }

            for(i=0; i<N; i++)
            {
                for(j=0; j<N; j++)
                {
                    if(a3[i] == a1[j])
                    {
                        a3[i] = a2[j];
                        break;
                    }
                }
            }

            for(i=0; i<N; i++)
            {
                printf("%d\n", a3[i]);
            }
        }
    }
    return 0;
}