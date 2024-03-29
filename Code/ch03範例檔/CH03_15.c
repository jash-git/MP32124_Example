#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct employee
{  
	int num,salary;
	char name[10];
	struct employee *llink; /* 左指標欄 */ 
	struct employee *rlink; /* 右指標欄 */ 
};
typedef struct employee node;
typedef node *link;

link findnode(link head,int num)
{
     link ptr;
     ptr=head;
     while(ptr!=NULL)
     {
        if(ptr->num==num)
           return ptr;
        ptr=ptr->rlink;
     }
     return ptr;
}

link insertnode(link head,link ptr,int num,int salary,char name[10])   
{  
    link newnode=(link)malloc(sizeof(node));
    link newhead=(link)malloc(sizeof(node));
    memset(newnode,0,sizeof(node));
    newnode->num=num;
    newnode->salary=salary;
    strcpy(newnode->name,name);
    if(head==NULL) /*雙向串列是空的*/
    {
       memset(newhead,0,sizeof(node));       
       newhead->num=num;
       newhead->salary=salary;
       strcpy(newhead->name,name);
       return newhead;
    }
    else
    {
        if(ptr==NULL)
        {
           head->llink=newnode;
           newnode->rlink=head;
           head=newnode;
        }
        else
        {
            if(ptr->rlink==NULL) /*插入串列尾的位置*/
            {
               ptr->rlink=newnode;
               newnode->llink=ptr;
            }
            else /*插入中間節點的位置*/
            {
                newnode->rlink=ptr->rlink;
                ptr->rlink->llink=newnode;
                ptr->rlink=newnode;
                newnode->llink=ptr;
            }
            
        }
    }
    return head;
}


int main()
{  
	link head,ptr;
	link llinknode=NULL;
	link newnode=NULL;
	int new_num, new_salary;
	char new_name[10];
	int i,j,position=0,find;
	int data[12][2]={ 1001,32367,1002,24388,1003,27556,1007,31299,
    1012,42660,1014,25676,1018,44145,1043,52182,1031,32769,1037,21100,1041,32196,1046,25776};
	char namedata[12][10]={{"Allen"},{"Scott"},{"Marry"},{"John"},
    {"Mark"},{"Ricky"},{"Lisa"},{"Jasica"},{"Hanson"},{"Amy"},{"Bob"},{"Jack"}};
	printf("員工編號 薪水 員工編號 薪水 員工編號 薪水 員工編號 薪水\n");
	printf("-------------------------------------------------------\n");

	for(i=0;i<3;i++)
	{  
		for (j=0;j<4;j++)
			printf("[%2d] [%3d]  ",data[j*3+i][0],data[j*3+i][1]);
		printf("\n");
	}
	head=(link)malloc(sizeof(node)); /*建立串列首*/
	if(head==NULL)
	{  
		printf("Error!! 記憶體配置失敗!!\n");
		exit(1);
	}
	else
	{
        memset(head,0,sizeof(node));
	    head->num=data[0][0];
	    for (j=0;j<10;j++)
		   head->name[j]=namedata[0][j];
	    head->salary=data[0][1];
	    llinknode=head;
	    for(i=1;i<12;i++) /*建立串列*/
	    {  
		   newnode=(link)malloc(sizeof(node));
		   memset(newnode,0,sizeof(node));
		   newnode->num=data[i][0];
		   for (j=0;j<10;j++)
			   newnode->name[j]=namedata[i][j];
		   newnode->salary=data[i][1];
		   llinknode->rlink=newnode;
		   newnode->llink=llinknode;
		   llinknode=newnode;
	   }
    }
	
	while(1)
	{  
		printf("請輸入要插入其後的員工編號,如輸入的編號不在此串列中,\n");
        printf("新輸入的員工節點將視為此串列的串列首,要結束插入過程,請輸入-1：");

		scanf("%d",&position);
		if(position==-1)    /*迴圈中斷條件*/
			break;
		else
		{  
			ptr=findnode(head,position);
            printf("請輸入新插入的員工編號：");
            scanf("%d",&new_num);
            printf("請輸入新插入的員工薪水：");
            scanf("%d",&new_salary);
            printf("請輸入新插入的員工姓名：");
			scanf("%s",new_name);
			head=insertnode(head,ptr,new_num,new_salary,new_name);
		}
	}
	printf("\n\t員工編號    姓名\t薪水\n");         
    printf("\t==============================\n");
	ptr=head;
	while(ptr!=NULL)
	{
       printf("\t[%2d]\t[ %-10s]\t[%3d]\n",ptr->num,ptr->name,ptr->salary);
       ptr=ptr->rlink;   
    }
	system("pause");
	return 0;
}
