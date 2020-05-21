/*
 *Linux内核链表
 */
#include <stdio.h>
#include <string.h>

struct list_head{
	struct list_head *prev;
	struct list_head *next;
};

inline void list_head_init(struct list_head *head)
{
	head->next = head;
	head->prev = head;
}

inline void __add_list(struct list_head *new, struct list_head *prev, struct list_head *next)
{
	prev->next = new;
	new->prev  = prev;
	new->next  = next;
	next->prev = new;
}

inline void add_list(struct list_head *new, struct list_head *head)
{
	__add_list(new, head, head->next);
}

inline void add_list_tail(struct list_head *new, struct list_head *head)
{
	__add_list(new, head->prev, head);
}



inline void __delete_list(struct list_head *prev, struct list_head *next)
{
	prev->next = next;
	next->prev  = prev;
}

inline void delete_list(struct list_head *entry)
{
	__delete_list(entry->prev, entry->next);
	entry->next = (void *)0;
	entry->prev = (void *)0;
}

#define list_for_each(pos, head)     for(pos = (head)->next; pos != (head); pos = pos->next)

#define list_entry(link, type, member) \
	((type *)((char *)(link)-(unsigned long)(&((type *)0)->member)))


#define list_for_each_entry(pos, head, member)				\
	for (pos = list_entry((head)->next, typeof(*pos), member);	\
	     &pos->member != (head); 	\
	     pos = list_entry(pos->member.next, typeof(*pos), member))

/*图书管理系统
 *书结构体包含：
 *  1.书名，作者，出版社
 *  2.是否借出 
 *  3.如果借出，借书人 名字，性别，学号
 *  
 */


struct student{
	char name[20];
	enum{
		male,
		female,
	}sex;
	int numid;
	int date0;
	int date1;
};
struct book{
	char name[30];
	char author[20];
	char publication[50];
};
struct books{
	struct book book;
	int flag;  //0表示未借出
	struct student stu;
	struct list_head list;
};

/*
 *如果是管理员，则可以向链表添加或者删除
 */
int main(int argc, char ** argv)
{
	struct list_head head;
	list_head_init(&head);
	
	printf("***********************\n");
	printf(" 请输入学号或管理员密码\n");
	printf("***********************\n");
	int num, a;
	char *b,*c,*d;
	scanf("%d",&num);
	if(num == 123456) //管理员模式
	{
		while(1)
		{
		printf("添加图书请输入0\n");
		printf("删除图书请输入1\n");
		printf("修改图书信息请输入2\n");
		printf("查询图书借还信息请输入3\n");
		printf("推出请输入9\n");
		scanf("%d",&a);
		switch(a)
		{
			case 0:
				{
					struct book book;
					printf("请输入书名\n");
					gets(book.name);
					printf("请输入图书作者名\n");
					gets(book.author);
					printf("请输入出版社\n");
					gets(book.publication);
				
	
					struct books new;
					memset(&new, 0, sizeof(new));
					new.book = book;
					new.flag = 0;
					add_list(&new.list, &head);
					break;
				}
			case 1:
			case 3:
				{
					char e[30];
					printf("请按书名查询\n");
					gets(e);
					struct books *l;
					list_for_each_entry(l, &head, list)
						{
							if(strncmp (l->book.name, e, strlen(e)) == 0)
								{
									printf("找到了该书\n");
									printf("该图书作者名%s\n",l->book.author);
									printf("该图出版社是%s\n",l->book.publication);
									if(l->flag == 0)
										{
										printf("该图书未借出\n");
										}
									else
										{
										printf("该图书已借出\n");
										printf("借书人%s,学号是%d ,借书日期：%d\n",l->stu.name,l->stu.numid,l->stu.date0);
										}
								}
						}
					break;
					}
					
			case 9:
				break;

		}

		}
	
	

	}
	else
	{}
	return 0;
}
















