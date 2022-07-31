//quary2.c
#include"data_structure.h"
void Dijkstra(mgraph c,int v0,int p[],int d[])
{
    int v, w, k = 1, min, t;
    int final[MaxVertexNum]; 
    //初始化数据
    for (v = 1; v <= c.vexnum; v++) 
    {
        final[v] = 0;
        d[v] = c.arcs[v0][v].adj; 
        p[v] = 0;
    }
    //先将起点收入合集
    d[v0] = 0; 
    final[v0] = 1;

    //每次求得V0到某个v顶点的最短路径 
    for (v = 1; v <= c.vexnum; v++)
    {
        min = Infinity;
        for (w = 1; w <= c.vexnum; w++)//找出最近的顶点和权值 
        {
            if (!final[w] && d[w] < min)//有边 
            {
                k = w;
                min = d[w];
            }
        }
        final[k] = 1;//将目前找到的最近的顶点置1 
        //修正当前最短路径及距离
        for (w = 1; w <= c.vexnum; w++)
        {	//如果收录了v使路径更短的话
            if (!final[w] && (min + c.arcs[k][w].adj < d[w]))
            {
                d[w] = min + c.arcs[k][w].adj;//修改当前路径长度
                p[w] = k; //更新路径
            }
        }
    }
}
int allshortdistance(mgraph c) {
    int p[12] = { 0 };   // 记录顶点 0 到各个顶点的最短的路径
    int d[12] = { 0 };   // 记录顶点 0 到各个顶点的总权值
    while (1)
    {
        int v = 0;
        printf("请输入要查询的景点的数字编号（1->11）：");
        rewind(stdin);//清空缓冲区
        scanf("%d", &v);
        if (v <= 11)
        {
            system("cls");
            Dijkstra(c, v, p, d);
            printf("%d%s到其他顶点的最短路径有：\n\n",v,c.vexs[v].name);
            for (int i = c.vexnum; i >= 1; i--) {
                int a[11] = { 0 };//路径暂存数组
                printf("%d%s-->", v, c.vexs[v].name);
                int j = i;
                //采用嵌套的方式输出各个最短路径上的所有顶点
                int k = 0;
                while (p[j] != 0) {
                    a[k++] = p[j];
                    j = p[j];
                }
                //倒序输出
                for (int i = 10; i >= 0; i--)
                {
                    if(a[i]!=0)
                    printf("%d%s-->",a[i],c.vexs[a[i]].name);
                }
                printf("%d%s\n", i, c.vexs[i].name);
                printf("该最短路径长度为:%d米\n\n", d[i]);
            }
            int choice = 0;
            printf("是否需继续查询？(yes:1 / no:else )：");
            rewind(stdin);//清空缓冲区
            scanf("%d", &choice);
            if (choice != 1) {
                printf("\n");
                break;
            }
            system("cls");
        }
        else
        {
            printf("信息输入错误！请重新输入！\n\n");
            continue;
        }
    }
    return 0;
}