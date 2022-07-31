//quary1,c
#include"data_structure.h"
//全局变量 
int d[30];
int visited[30];
int shortest[MaxVertexNum][MaxVertexNum];//定义全局变量存储最小路径 
int pathh[MaxVertexNum][MaxVertexNum];//定义存储路径

//查找景点在图中的序号
int locatevex(mgraph c, int v)//locatevex
{
	int i;
	for (i = 1; i <= c.vexnum; i++)
		if (v == c.vexs[i].position)  return i;//找到，返回顶点序号i 
	return -1;//没有找到这个顶点 
}

//查询两景点间的最短路径（floyd算法）
void floyd(mgraph c)
{
	int i, j, k;
	for (i = 1; i <= key; i++)//将图的邻接矩阵赋值给 shortest二维数组，将矩阵pathh全部初始化为-1 
	{
		for (j = 1; j <= key; j++)
		{
			shortest[i][j] = c.arcs[i][j].adj;
			pathh[i][j] = j;
		}
	}
	int i1, j1, k1 = 0;
	for (i1 = 1; i1 <= key; i1++)
	{
		for (j1 = 1; j1 <= key; j1++)
		{
			k1++;
		}
	}

	for (k = 1; k <= key; k++)//核心操作，完成了以k为中间点对所有的顶点对（i,j）进行检测和修改 
	{
		for (i = 1; i <= key; i++)
		{
			for (j = 1; j <= key; j++)
			{
				if (shortest[i][j] > shortest[i][k] + shortest[k][j])
				{
					shortest[i][j] = shortest[i][k] + shortest[k][j];
					pathh[i][j] = pathh[i][k];//记录一下所走的路 //P数组用来存放前驱顶点  
				}
			}
		}
	}
}

//打印出最短路径 
void display(mgraph c, int i, int j)
{
	int a, b;
	a = i; b = j;
	printf("您要查询的两景点间最短路径：\n\n");
	printf("%d%s", a, c.vexs[a].name);
	while (pathh[i][j] != b)
	{
		printf("-->%d%s", pathh[i][j], c.vexs[pathh[i][j]].name);
		i = pathh[i][j];
	}
	printf("-->%d%s\n\n", b, c.vexs[b].name);
	printf("%s-->%s的最短路径是：%d 米。\n\n", c.vexs[a].name, c.vexs[b].name, shortest[a][b]);
}

//任意两点间最短距离（弗洛伊德算法）
int shortdistance(mgraph c)
{
	int i, j;
	int choice = 0;
	while (1)
	{
		rewind(stdin);//清空缓冲区
		printf("请输入要查询的两个不同景点的数字编号（1->11）中间用空格间隔开。\n");
		scanf("%d %d", &i, &j);
		if (i > key || i<0 || j>key || j < 0||i==j)
		{
			printf("输入信息错误！\n\n");
			continue;
		}
		else
		{
			floyd(c);
			display(c, i, j);
			printf("是否需继续查询？(yes:1 / no:else )：");
			rewind(stdin);//清空缓冲区
			scanf("%d", &choice);
			if (choice != 1)
			{
				break;
			}
		}
		system("cls");
	}
	printf("\n");
	return 1;
}
