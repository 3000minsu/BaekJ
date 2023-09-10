#include <iostream>
#define max(x, y) x > y ? x : y
/*how big the maximum number is?*/
#define maximum 100002
#define min -1001
using namespace std;

int cnt, isAllneg = 0, negTop = min;
int numbers[maximum];
void input(){
	scanf("%d", &cnt);
	for (int i = 0; i < cnt; i++)
    {
        scanf("%d", &numbers[i]);
        if(numbers[i]>=0)
            isAllneg = 1;
        else
        {
            if(negTop<numbers[i])
                negTop = numbers[i];
        }
    }	
}
void compute(){
	int maxOfall = 0, maxTail = 0;
    if(isAllneg == 0)
    {
        printf("%d", negTop);
        return;
    }
	for (int i = 0; i < cnt; i++){
		maxTail = max(0, maxTail + numbers[i]);
		maxOfall = max(maxOfall, maxTail);
	}
	printf("%d", maxOfall);
}
int main(){
	input();
	compute();
	return 0;
}