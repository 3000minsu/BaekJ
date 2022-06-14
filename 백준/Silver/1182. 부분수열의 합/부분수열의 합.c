#include <stdio.h>
int arr[20] = { 0 };
int visit[20] = { 0 };
int cnt = 0, ch=0, n, s;
void back(int add, int st)
{
    if (add == s&&ch==0)
    {
        cnt++;
        ch = 1;
    }
    for (int i = st; i < n; i++)
    {
     
        if (visit[i] == 0)
        {
            visit[i] = 1;
            ch = 0;
            back(add + arr[i], i + 1);
            //수를 선택했을 때는 0이 되는거 포함
            visit[i] = 0;
        }
        else
        {
            ch = 1;
            back(add, i + 1);
            //수를 선택하지 않았을때 0이 되는 경우의 수 제외
        }
        
    }
}
int main()
{
    scanf("%d %d", &n, &s);
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    for (int i = 0; i < n; i++)
    {
        back(arr[i], i+1);
        for (int j = 0; j < n; j++)
          visit[j] = 0;
        ch=0;
    }
    printf("%d", cnt);
    return 0;
}