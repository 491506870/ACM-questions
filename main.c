/*
输入m个长度均为n的DNA序列，求一个DNA序列，到所有序列的总Hamming距离尽量
小。 两个等长字符串的Hamming距离等于字符不同的位置个数，例如，ACGT和GCGA的
Hamming距离为2（左数第1, 4个字符不同）。
输入整数m和n（4≤m≤50, 4≤n≤1000），以及m个长度为n的DNA序列（只包含字母
A，C，G，T），输出到m个序列的Hamming距离和最小的DNA序列和对应的距离。 如有多
解，要求为字典序最小的解。 例如，对于下面5个DNA序列，最优解为TAAGATAC。
TATGATAC
TAAGCTAC
AAAGATCC
TGAGATAC
TAAGATGT
*/
#include<stdio.h>

#define max_m 100
#define max_n 2000

char DNA[max_m][max_n];
char ans[max_n];//最优解的DNA序列

int dis = 0;

char max(int A, int C, int G, int T)
{
    char ans;
    int max = A;
    ans = 'A';
    if(C > max)
    {
        max = C;
        ans = 'C';
    }
    if(G > max)
    {
        max = G;
        ans = 'G';
    }
    if(T > max)
    {
        max = T;
        ans = 'T';
    }
    return ans;
}

int main()
{
    int m, n;
    scanf("%d%d", &m, &n);//输入m个DNA序列，每个长度为n
    getchar();//跳过回车这个字符
    int i, j;
    for(i=1; i<=m; i++)
    {
        for(j=1; j<=n; j++)
        {
            scanf("%c", &DNA[i][j]);
        }
        getchar();
    }

    i = 1;
    int hamming = 0;
    while(i<=n)//遍历最优解的序列
    {
        int dis_A = 0, dis_T = 0, dis_G = 0, dis_C = 0;
        for(j=1; j<=m; j++)//遍历所有的序列的某一项
        {
            if(DNA[j][i] == 'A') dis_A++;
            if(DNA[j][i] == 'C') dis_C++;
            if(DNA[j][i] == 'G') dis_G++;
            if(DNA[j][i] == 'T') dis_T++;
        }
        ans[i] = max(dis_A, dis_C, dis_G, dis_T);
        for(j=1; j<=m; j++)
        {
            if(ans[i] != DNA[j][i])
                hamming++;
        }
        i++;
    }


    printf("%s:", "最优解为");
    for(i=1; i<=n; i++)
    {
        putchar(ans[i]);
    }
    printf("\n%s:%d", "距离为", hamming);


    return 0;
}
