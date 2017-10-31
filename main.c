/*给定两个字符串s和t，请判断s是否是t的子序列。即从t中删除一些字符，将剩余的字符连接起来，即可获得s。
输入
包括若干个测试数据。每个测试数据由两个ASCII码的数字和字母串s和t组成，s和t的长度不超过100000。
输出
对每个测试数据，如果s是t的子序列则输出“Yes”，否则输出“No”。
*/

#include<stdio.h>
#include<string.h>

#define maxn 100010

char s[maxn];
char t[maxn];//需要更长

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
