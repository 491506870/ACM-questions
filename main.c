/*���������ַ���s��t�����ж�s�Ƿ���t�������С�����t��ɾ��һЩ�ַ�����ʣ����ַ��������������ɻ��s��
����
�������ɸ��������ݡ�ÿ����������������ASCII������ֺ���ĸ��s��t��ɣ�s��t�ĳ��Ȳ�����100000��
���
��ÿ���������ݣ����s��t���������������Yes�������������No����
*/

#include<stdio.h>
#include<string.h>

#define maxn 100010

char s[maxn];
char t[maxn];//��Ҫ����

int main()
{
    while(scanf("%s%s", s, t) == 2)
    {
        int i, j=0;

        for(i=0; i<strlen(t); i++)
        {
            if(t[i] == s[j])
                j++;
            if(j==strlen(s))
            {
                printf("%s\n", "Yes");
                break;
            }
        }
        if(j != strlen(s))
            printf("%s\n", "No");
    }
    return 0;
}
