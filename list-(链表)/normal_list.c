#include <stdio.h>
#include <stdlib.h>

struct pt{
	int ia;
	struct pt *ptnext;
};
void add_list_head(struct pt *ptnew);
void add_list(struct pt *ptnew);
void list_entry();
void delete_node(int i);
struct pt *pthead = NULL;

int main(void)
{
	struct pt *ptnew1, *ptnew2, *ptnew3;
	ptnew1 = (struct pt *)malloc(sizeof(struct pt));
	ptnew1->ia = 1;	
	ptnew2 = (struct pt *)malloc(sizeof(struct pt));
	ptnew2->ia = 2;
	ptnew3 = (struct pt *)malloc(sizeof(struct pt));
	ptnew3->ia = 3;
#if 0	/* 头插方式 */
	add_list_head(ptnew1);
	add_list_head(ptnew2);
	add_list_head(ptnew3);
	
#else /* 尾插方式 */
	add_list(ptnew1);
	add_list(ptnew2);
	add_list(ptnew3);
#endif
	list_entry();
	delete_node(2);
	list_entry();
	return 0;
}
/* 头部插入 */
void add_list_head(struct pt *ptnew)
{
	ptnew->ptnext = pthead;
	pthead = ptnew;
}

void list_entry()
{
	struct pt *pt;
	for(pt = pthead; pt != NULL; pt = pt->ptnext)
	{
		printf("%d.\n",pt->ia);
	}
}
/* 带头节点的尾部插入 */
void add_list(struct pt *ptnew)
{
	struct pt *pt;
	pt = pthead;
	struct pt *ptprev;
	if(pthead == NULL)
	{
		struct pt *pthead_node 		= (struct pt *)malloc(sizeof(struct pt));
		pthead_node->ia	 	= 0;
		pthead				= pthead_node;
		pthead_node->ptnext = ptnew;
		ptnew->ptnext 		= NULL;
	}
	else{
		while(pt)
		{
			ptprev = pt;
			pt = pt->ptnext;
		}
		ptprev->ptnext = ptnew;
		ptnew->ptnext = NULL;
	}	
}
/*  删除节点*/
void delete_node(int i)
{
	struct pt *ptprev, *pt;
	for(pt = pthead; pt != NULL; ptprev = pt, pt = pt->ptnext)
	{
		if(pt->ia == i){
				ptprev->ptnext = pt->ptnext;
				free(pt);
				break;
		}			
	}
	
}




