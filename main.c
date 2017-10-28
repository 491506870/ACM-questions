/*
����m�����Ⱦ�Ϊn��DNA���У���һ��DNA���У����������е���Hamming���뾡��
С�� �����ȳ��ַ�����Hamming��������ַ���ͬ��λ�ø��������磬ACGT��GCGA��
Hamming����Ϊ2��������1, 4���ַ���ͬ����
��������m��n��4��m��50, 4��n��1000�����Լ�m������Ϊn��DNA���У�ֻ������ĸ
A��C��G��T���������m�����е�Hamming�������С��DNA���кͶ�Ӧ�ľ��롣 ���ж�
�⣬Ҫ��Ϊ�ֵ�����С�Ľ⡣ ���磬��������5��DNA���У����Ž�ΪTAAGATAC��
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
char ans[max_n];//���Ž��DNA����

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
    scanf("%d%d", &m, &n);//����m��DNA���У�ÿ������Ϊn
    getchar();//�����س�����ַ�
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
    while(i<=n)//�������Ž������
    {
        int dis_A = 0, dis_T = 0, dis_G = 0, dis_C = 0;
        for(j=1; j<=m; j++)//�������е����е�ĳһ��
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


    printf("%s:", "���Ž�Ϊ");
    for(i=1; i<=n; i++)
    {
        putchar(ans[i]);
    }
    printf("\n%s:%d", "����Ϊ", hamming);


    return 0;
}
