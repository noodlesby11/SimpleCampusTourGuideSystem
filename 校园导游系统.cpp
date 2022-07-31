//校园导游系统.c
#include "welcome.c"
#include "quary1.c"
#include "campus.c"
#include "quary2.c"
int main() {
	int choice = 0;
	int n= 0;
	while (1) {
		welcome();
		printf("请输入对应的数字功能键: ");
		rewind(stdin);//清空缓冲区
		scanf("%d", &choice);
		switch (choice) {
		case 1://查看校园平面图
			system("校园平面图.jpg");
			break;
		case 2://查询景点介绍
			system("cls");
		    introduction(); 
			break;
		case 3://问路查询
			system("cls");
			campus = initgraph();
			shortdistance(campus);
			break;
		case 4://查询景点的所有路径
			system("cls");
			campus = initgraph();
			allshortdistance(campus);
			break;
		case 0://退出程序 
		{
			system("cls");
			printf("欢迎下次使用~\n");
			exit(0);//结束程序 
		}
		break;
		default:
			printf("信息输入错误，请重新输入！\n\n");
			Sleep(1500);
			continue;
		}
		printf("是否退出系统？(yes:1 / no:else )：");
		rewind(stdin);//清空缓冲区
		scanf("%d", &n);
		if (n == 1) {
			break;
		}
	}
	return 0;
}