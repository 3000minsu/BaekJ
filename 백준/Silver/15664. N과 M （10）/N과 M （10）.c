#include <stdio.h>
int n, m, rn=0;
int arr[8][2] = { 0 };//각 숫자당 개수까지 저장함
int ans[8];
void dfs(int cnt, int pa)
{
    if (cnt == m)
    {
        for (int i = 0; i < m; i++)
            printf("%d ", ans[i]);
        printf("\n");
        return;
    }
    for (int i = pa; i < rn; i++)
    {
        if (arr[i][1] > 0)
        {
            arr[i][1]--;
            ans[cnt] = arr[i][0];
            dfs(cnt + 1, i);
            arr[i][1]++;
        }
    }
}
int main()
{
    int temp,temp2, a, ch=0, i=0;
    scanf("%d %d", &n, &m);
    while(i<n)
    {
        scanf("%d", &a);
        for (int j = 0; j < rn; j++)
        {
            if (arr[j][0] == a)
            {
                ch = 1;
                arr[j][1]++;
            }
        }
        if (ch == 0)
        {
            arr[rn][0] = a;
            arr[rn][1] = 1;
            rn++;
        }
        i++;
        ch = 0;
    }
    for (int i = 0; i < rn; i++)//오름차순 정렬
    {
        for (int j = 0; j <rn - i - 1; j++)
        {
            if (arr[j][0] > arr[j + 1][0])
            {
                temp = arr[j][0];
                temp2 = arr[j][1];
                arr[j][0] = arr[j + 1][0];
                arr[j][1] = arr[j + 1][1];
                arr[j + 1][0] = temp;
                arr[j + 1][1] = temp2;
            }
        }
    }
    dfs(0, 0);
    return 0;
}