#include <iostream>
#include <cstring>
using namespace std;
int main()
{
    int n, max=0, min=99999999;
    cin>>n;
    char yname[16];
    char oname[16];
    for(int i=0; i<n; i++)
    {
        int y,m,d, temp;
        char name[16];
        cin>>name>>d>>m>>y;
        temp=y*10000+m*100+d;
        if(temp>max)
        {
            max=temp;
            strcpy(yname, name);    
        }
        if(temp<min)
        {
            min=temp;
            strcpy(oname, name);
        }
    }
    cout<<yname<<endl<<oname;
    return 0;
}