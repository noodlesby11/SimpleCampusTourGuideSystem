//data_structure.h
#include<stdio.h>//无向带权图 
#include<stdlib.h>
#include<string.h>
#include<windows.h>
#include<stdbool.h>
#define Infinity 2000//表示无穷大 
#define MaxVertexNum 20 
#define MAX 40 
#define key 11//key为顶点个数 

#ifndef arcell_h
#define arcell_h
typedef struct arcell//边的权值信息
{
	int adj;//权值  
}arcell, adjmatrix[MaxVertexNum][MaxVertexNum];//图的邻接矩阵类型
#endif

#ifndef vexsinfo_h
#define vexsinfo_h
typedef struct vexsinfo//顶点信息 
{
	int position;//景点的编号 
	char name[32];//景点的名称 
	char introduction[256];//景点的介绍 
}vexsinfo;
#endif

#ifndef mgraph_h
#define mgraph_h
typedef struct mgraph//图结构信息
{
	vexsinfo vexs[MaxVertexNum];//顶点向量（数组） 
	adjmatrix arcs;//邻接矩阵 
	int vexnum, arcnum;//顶点数和边数 
}mgraph;
#endif

