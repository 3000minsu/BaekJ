#include <stdio.h>
#include <stdlib.h>
#define inf 999999999
typedef struct _Node {
	struct _Node* link;
	int vertex;
	int value;
}node;
typedef struct _Element {
	int vertex;
	int value;
}element;
node* graph;
element heap[4000000];
int dp[20001];
int visit[20001] = { 0 };
int v, e, k, hsize=0;

void heap_push(int ver, int val)
{
	int child, parent, temp;
	heap[++hsize].vertex = ver;
	heap[hsize].value = val;
	child = hsize;
	parent = child / 2;
	while (child > 1 && heap[parent].value > heap[child].value) {
		temp = heap[parent].value;
		heap[parent].value = heap[child].value;
		heap[child].value = temp;
		temp = heap[parent].vertex;
		heap[parent].vertex = heap[child].vertex;
		heap[child].vertex = temp;
		child = parent;
		parent = child / 2;
	}
}
element heap_pop()
{
	element result = heap[1];
	int parent, child, temp;
	heap[1].value = heap[hsize].value;
	heap[1].vertex = heap[hsize].vertex;
	hsize--;
	parent = 1;
	child = parent * 2;
	if (child + 1 <= hsize) {
		child = (heap[child].value < heap[child + 1].value) ? child : child + 1;
	}

	while (child <= hsize && heap[parent].value > heap[child].value) {
		temp = heap[parent].value;
		heap[parent].value = heap[child].value;
		heap[child].value = temp;
		temp = heap[parent].vertex;
		heap[parent].vertex = heap[child].vertex;
		heap[child].vertex = temp;

		parent = child;
		child = child * 2;
		if (child + 1 <= hsize) {
			child = (heap[child].value < heap[child + 1].value) ? child : child + 1;
		}
	}

	return result;


}



void dij()
{
	int now=k, ch=0;
	element te;
	node* temp;
	dp[now] = 0;
	visit[now] = 1;
	if (graph[now].link == NULL)
		return;
	do
	{
		ch = 0;
		temp = graph[now].link;
		while (temp != NULL)
		{
			if (!visit[temp->vertex])
			{
				if (dp[temp->vertex] > dp[now] + temp->value)
				{
					dp[temp->vertex] = dp[now] + temp->value;
					heap_push(temp->vertex, dp[temp->vertex]);

				}
			}
			temp = temp->link;
			
		}
		
		while (hsize>=1)
		{
			te = heap_pop();
			if (visit[te.vertex] != 1)
			{
				ch = 1;
				now = te.vertex;
				break;
			}
		}


		visit[now] = 1;

	} while (ch == 1);


}
int main()
{
	int a, b, w;
	node* temp;
	scanf("%d %d", &v, &e);
	scanf("%d", &k);
	graph = (node*)malloc(sizeof(node) * (v+1));
	for (int i = 1; i <= v; i++)
	{
		graph[i].link = NULL;
		graph[i].vertex = 0;
		graph[i].value = 0;
		dp[i] = inf;
	}
	for (int i = 0; i < e; i++)
	{
		scanf("%d %d %d", &a, &b, &w);
		temp = (node*)malloc(sizeof(node));
		temp->link = graph[a].link;
		temp->vertex = b;
		temp->value = w;
		graph[a].link = temp;
	}
	dij();
	for (int i = 1; i <= v; i++)
	{
		if (dp[i] == inf && i != k)
			printf("INF\n");
		else
			printf("%d\n", dp[i]);
	}
	return 0;
}