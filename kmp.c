#include <stdio.h>
#include <string.h>
int next[100];
void getNext(char ptn[], int next[])
{
    int len = strlen(ptn);
    next[0] = -1; // 下标0处的初始化
    int k = -1;
    int j = 0;
    while (j < len) // get_next函数进行升级的点：这里不是j<len-1 而是j<len，这样能够不回溯计数
    {
        if (k == -1 || ptn[k] == ptn[j])
        {
            j++;
            k++;
            next[j] = k;
        }
        else
        {
            k = next[k];
        }
    }
}
int kmp(char src[], char ptn[])
{
    int len_src = strlen(src);
    int len_ptn = strlen(ptn);
    int i = 0, n = 0, k = 0; // k应该从0开始，而非-1
    while (i < len_src)
    {
        if (k == -1 || src[i] == ptn[k])
        {
            ++i;
            ++k;
        }
        else
        {
            k = next[k];
        }
        if (k == len_ptn) // 实现不回溯计数
        {
            n++;
            k = next[k];
        }
    }
    return n;
}
int main()
{
    char src[100000], ptn[10000];
    scanf("%s %s", &src, &ptn);
    getNext(ptn, next);
    printf("%d", kmp(src, ptn));
}