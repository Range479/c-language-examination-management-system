//Data: 2019/3/9 --2019/3/10
//2019/03/13晚 更新邮箱功能
//2019/03/14 下午 增加管理员页面 
//Name: Range
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct Problem
{
	char title[1000];
	char a[1000];
	char b[1000];
	char c[1000];
	char d[1000];
	char answer;	
}Pro;

typedef struct Grade
{
	int id;
	char name[20];
	int t;
	int f;
	float gra;
}Gra;

typedef struct User
{
	int ID;
	char name[20];
	char password[20];
}Use;

typedef struct mail
{
	int addressee;
	char addresseeName[20];
	int sender;
	char senderName[20];
	char text[10000];
	int read;
}Mail;

Use allUser[1000];
Use user;
Pro problem[1000];
Gra grade[1000];
Mail mails[10000];
int n = 0, a = 0, b = 0, ma = 0;

void OpenFile();//打开文件 
void SaveFile();//保存文件 
int LoginPage();//登陆页面 
void menu();//主菜单 
void menu2();//二级菜单 
int search(int id);//查询账号 
void reg();//注册账号 
void design();//出题系统 
void check();//查看题库 
void del();//删除题目
void alter();//修改题目 
void revision();//修改密码 
void exam();//考试模块 
void examgrade();//考查看成绩 
void rank();//查询排名 
void sender();//发送邮件 
void senderMenu();//发送邮件菜单
void addresseeMenu();//收邮件菜单
void unread();//查看未读邮件
void read();//查看已读邮件
void readsender();//查看发送邮件
void AdministratorMenu();//管理员界面 
void AccountShows();//账户显示
void AccountQuery();//账户查询
void MailShow();//显示邮件 
void ChangePassword();//管理员修改密码 

int main()
{
	int i, t = 0;
	OpenFile();
a:	menu();	
	printf("\n\n*请输入您选择的功能：");
	scanf("%d", &i);
	system("CLS");
	switch(i)
	{
		case 1:
			reg();
			system("CLS");
			goto a;
			break;
		case 2:
			t = LoginPage();
			if(t == 0)
				goto a;
			break;	
		default:
			printf("\a\a\n          *您输入的选项错误请重新输入 :)\n\n");
			system("pause");
			goto a;
	}
	while(1)
	{
		system("CLS");
		menu2(); 
b:		printf("\n\n*请输入您选择的功能：");
		scanf("%d", &i);
		getchar();
		system("CLS");
		switch(i)
		{
			case 1:
				exam();
				break; 
			case 2:
				examgrade();
				break; 
			case 3:
				rank();
				break; 
			case 4:
				revision();
				break;
			case 5:
				design();
				break;
			case 6:
				check();
				break;
			case 7:
				del();
				break;
			case 8:
				alter();
				break; 
			case 9:
				senderMenu();
				break; 
			case 10:
				addresseeMenu();
				break; 
			case 0:
				SaveFile();
				printf("\n          *数据保存成功:)\n");
				printf("\n          *期待您的下次使用:)\n\n");
				system("pause");
				return 0;
			default:
				printf("\a\a\n*您输入的选项错误请重新输入 :)\n\n");
				system("pause");
				goto b;
		}
	}
}

void menu()//主菜单 
{
	printf("\n          ************************考试系统*************************\n");
	printf("          *    1.账号注册                      2.账号登陆         *\n");
	printf("          *********************************************************\n");
}

void menu2()//二级菜单 
{
	printf("\n          *************************菜单****************************\n");
	printf("          *    1.我要考试                      2.查询成绩         *\n");
	printf("          *    3.成绩排名                      4.修改密码         *\n");
	printf("          *    5.我要出题                      6.查看题库         *\n");
	printf("          *    7.删除题目                      8.修改题目         *\n");
	printf("          *    9.发送邮件                      10.收件箱          *\n");
	printf("          *                      0.退出系统                       *\n");
	printf("          *********************************************************\n");
	printf("\n*%s 同学您好，欢迎登陆本答题系统 :)  您的登陆ID为：%d\n", user.name, user.ID);
}

void reg()//注册账号 
{
	char key[20];
	int t;
	printf("\n          ************************注册页面*************************\n");
	printf("          *请输入您的name:  ");
	scanf("%s", &allUser[n].name);
	printf("          *\n");
	printf("          *请输入您的password:  ");
	scanf("%s", &allUser[n].password);
	do
	{
		printf("          *请再次输入您的password:  ");
		scanf("%s", &key);
		if(strcmp(key, allUser[n].password) == 0) 
			t = 0;
		else 
		{
			t = 1;
			printf("          *您输入的密码错误，请重新输入 :) \n");
		}
	}while(t == 1);
	printf("          *\n");
	printf("          *注册成功！\n");
	allUser[n].ID = n + 1000;
	printf("          *\n");
	printf("          *您的ID: %d\n", allUser[n].ID);
	system("pause"); 
	n++;
}

int LoginPage()//登陆页面 
{
	int t;
	char key[20];
	printf("\n          ************************登陆页面*************************\n");
	printf("          *请输入您的ID:  ");
	scanf("%d", &user.ID);
	if(user.ID == 101)//判断是否为管理员 
	{
		do
		{
			printf("          *请输入您的password:  ");
			scanf("%s", &key);
			if(strcmp(key, "54759") == 0) 
				t = 0;
			else 
			{
				t = 1;
				printf("          *您输入的密码错误，请重新输入 :) \n");
			}
		}while(t == 1);
		system("CLS");
		AdministratorMenu();
		system("CLS");
		return 0;
	}
	getchar();
	printf("          *\n");
	t = search(user.ID);
	if(!t)
	{
		printf("          *您输入的账号未注册，请注册账号后再次使用本程序 :) \n");
		return 0;
	}
	do
	{
		printf("          *请输入您的password:  ");
		scanf("%s", &key);
		if(strcmp(key, user.password) == 0) 
			t = 0;
		else 
		{
			t = 1;
			printf("          *您输入的密码错误，请重新输入 :) \n");
		}
	}while(t == 1);
	return 1;
}

int search(int id)//查询账号 
{
	int i;
	for(i = 0; i < n; i++)
		if(allUser[i].ID == id)
			break;
	if(i == n) 
		return 0;
	else
	{
		user = allUser[i];
		return 1;
	}
} 

void exam()//考试模块 
{
	int book[1000] = {0};
	int i, t, num;
	char key;
	printf("\n  *本系统题库共有 %d 道题目\n\n", a);
	printf("  *请输入您要测试的题数 ：");
	scanf("%d", &t);
	getchar();
	printf("\n  *您准备好了吗？考试即将开始！祝您有个好成绩 :)\n\n");
	grade[b].id = user.ID;
	strcpy(grade[b].name, user.name);
	system("pause");
	system("CLS");
	printf("\n  ***ps.请注意，所有答案均需要填大写。否则，系统将认为您的答案错误！\n***");
	for(i = 0; i < t; i++)
	{
		srand(time(NULL)); //设置随机种子
		num = rand() % a;//随机生成数字
		if(book[num] == 1)
		{
			i--;
			continue;
		}
		book[num] = 1;
		printf("\nNo.%d\n", i + 1);
		printf("Title:\n");
		printf("%s\n", problem[num].title);
		printf("  A:%s\n", problem[num].a);
		printf("  B:%s\n", problem[num].b);
		printf("  C:%s\n", problem[num].c);
		printf("  D:%s\n", problem[num].d);
		printf("请输入您的答案：");
		key = getchar();
		getchar();
		if(key == problem[num].answer)
		{
			grade[b].t++;
			printf("回答正确！！！\n\n");
		}
		else
		{
			grade[b].f++;
			printf("回答错误... :( \n");
			printf("正确答案是 %c\n\n", problem[num].answer);
		}
	}
	grade[b].gra = (float)grade[b].t / t * 100;
	printf("      ***本次考试结束... 您的正确率为 %.2f%% ！***\n\n", grade[b].gra);
	b++;
	system("pause");
}

void examgrade()//考查看成绩
{
	int i, t = 0;
	printf("\n  参考人员  正确个数  错误个数  正确率\n");
	for(i = 0; i < b; i++)
	{
		if(grade[i].id != user.ID)
			continue;
		t++;
		printf("%d. %6s  %6d    %6d     %4.2f%%\n", t, grade[i].name, grade[i].t, grade[i].f, grade[i].gra);
	}
	printf("\n\n  ***以上是您的所有考试成绩，即将跳转回主页面 :) ***\n\n");
	system("pause");
} 


void rank()//查询排名 
{
	int i, j;
	Gra temp;
	for(i = 0; i < b; i++)
		for(j = i + 1; j < b; j++)
			if(grade[i].gra < grade[j].gra)
			{
				temp = grade[i];
				grade[i] = grade[j];
				grade[j] = temp;
			}
	printf("   ***目前所有用户共进行过 %d 次测试，以下是所有排名 :) ***\n", b);
	printf("\n  参考人员  正确个数  错误个数  正确率\n");
	for(i = 0; i < b; i++)
		printf("%d. %6s  %6d    %6d     %4.2f%%\n", i + 1, grade[i].name, grade[i].t, grade[i].f, grade[i].gra);
	printf("\n\n  ***以上是您的所有考试成绩，即将跳转回主页面 :) ***\n\n");
	system("pause");
}

void design()//出题系统 
{
	printf("\n*请输入题目：\n"); 
	gets(problem[a].title);
	printf("*\n*请输入A选项：\n");
	gets(problem[a].a);
	printf("*\n*请输入B选项：\n");
	gets(problem[a].b);
	printf("*\n*请输入C选项：\n");
	gets(problem[a].c);
	printf("*\n*请输入D选项：\n");
	gets(problem[a].d);
	printf("*\n*请输入正确选项：\n");
	problem[a].answer = getchar();
	a++;
} 

void check()//查看题库
{
	int i;
	printf("\n*本题库共有 %d 道题目\n", a);
	for(i = 0; i < a; i++)
	{
		printf("\nNo.%d\n", i + 1);
		printf("Title:\n");
		printf("%s\n", problem[i].title);
		printf("  A:%s\n", problem[i].a);
		printf("  B:%s\n", problem[i].b);
		printf("  C:%s\n", problem[i].c);
		printf("  D:%s\n", problem[i].d);
		printf("正确答案为：%c\n", problem[i].answer);
	}
	putchar('\n');
	system("pause");
} 

void del()//删除题目
{
	int i;
	char ch;
	printf("\n请输入你要删除的题目的编号： ");
	scanf("%d", &i);
	i = i - 1;
	getchar();
	printf("\n您要删除的题目内容如下： \n");
	printf("\nNo.%d\n", i + 1);
	printf("Title:\n");
	printf("%s\n", problem[i].title);
	printf("  A:%s\n", problem[i].a);
	printf("  B:%s\n", problem[i].b);
	printf("  C:%s\n", problem[i].c);
	printf("  D:%s\n", problem[i].d);
	printf("正确答案为：%c\n", problem[i].answer);
	printf("\n您确定删除该题目吗？  Y/N\n");
	ch = getchar();
	getchar();
	if(ch == 'N' || ch == 'n')
	{
		printf("即将返回到菜单页面 :)\n\n");
		system("pause");
		return;
	}
	for(;i < a; i++)
		problem[i] = problem[i + 1];
	a--;
	printf("删除成功，所有题目编号已经更新 :)\n\n");
	system("pause");
} 

void alter()//修改题目
{
	int i;
	char ch;
	printf("\n请输入你要修改的题目的编号： ");
	scanf("%d", &i);
	i = i - 1;
	getchar();
	printf("\n您要修改的题目内容如下： \n");
	printf("\nNo.%d\n", i + 1);
	printf("Title:\n");
	printf("%s\n", problem[i].title);
	printf("  A:%s\n", problem[i].a);
	printf("  B:%s\n", problem[i].b);
	printf("  C:%s\n", problem[i].c);
	printf("  D:%s\n", problem[i].d);
	printf("正确答案为：%c\n", problem[i].answer);
	printf("\n您确定修改该题目吗？  Y/N\n");
	ch = getchar();
	getchar();
	if(ch == 'N' || ch == 'n')
	{
		printf("即将返回到菜单页面 :)\n\n");
		system("pause");
		return;
	}
	printf("\n*请输入题目：\n"); 
	gets(problem[i].title);
	printf("*\n*请输入A选项：\n");
	gets(problem[i].a);
	printf("*\n*请输入B选项：\n");
	gets(problem[i].b);
	printf("*\n*请输入C选项：\n");
	gets(problem[i].c);
	printf("*\n*请输入D选项：\n");
	gets(problem[i].d);
	printf("*\n*请输入正确选项：\n");
	problem[i].answer = getchar();
	printf("修改成功，即将返回到菜单页面 :)\n\n");
	system("pause");
} 

void revision()//修改密码 
{
	char key[20], ch;
	int t, i;
	do
	{
		printf("\n*请输入您现在的密码：");
		gets(key);
		if(strcmp(key, user.password) == 0) 
			t = 0;
		else 
		{
			t = 1;
			printf("*您输入的密码错误，请重新输入 :) \n");
			printf("\n*是否继续修改密码 Y/N :");			
			ch = getchar();
			getchar();
			if(ch == 'N' || ch == 'n')
			{
				printf("*即将返回到菜单页面 :)\n\n");
				system("pause");
				return;
			}
		}
	}while(t == 1);
	printf("*请输入您的新密码：");
	gets(user.password);
	for(i = 0; i < n; i++)
		if(allUser[i].ID == user.ID)
			break;
	if(i < n) 
		strcpy(allUser[i].password, user.password);
	printf("修改成功，即将返回到菜单页面 :)\n\n");
	system("pause");
}

void senderMenu()//发送邮件菜单
{
	int i; 
d:	printf("\n          *************************发件箱**************************\n");
	printf("          *    1.发送邮件                     2.查看已发送邮件    *\n");
	printf("          *                      0.返回菜单                       *\n");
	printf("          *********************************************************\n");
 	printf("\n\n*请输入您选择的功能：");
	scanf("%d", &i);
	system("CLS");
	switch(i)
	{
		case 1:
			sender();
			system("CLS");
			goto d;
			break;
		case 2:
			readsender();
			system("CLS");
			goto d;
			break;
		case 0:	
			printf("\n\n即将返回到主菜单页面 :)\n\n");
			system("pause");
			return;
		default:
			printf("\a\a\n          *您输入的选项错误请重新输入 :)\n\n");
			system("pause");
			goto d;
	}	
}
 
void sender()//发送邮件 
{
	int i, t, j;
	char ch; 
	printf("\n          ************************发送邮件*************************\n");
e:	printf("          *\n          *请输入您要发送对象的ID：");
	scanf("%d", &i);
	getchar();
	for(j = 0; j < n; j++)
		if(allUser[i].ID == i)
			break;
	if(i == n) 
		t = 0;
	else
		t = 1;
	if(t == 0)
	{
		printf("          *\n          *您输入的ID未注册账号，请重新输入 :) \n");
		printf("          *\n          *是否还要发送邮件？ Y/N :");			
		ch = getchar();
		getchar();
		if(ch != 'N' && ch != 'n')
			goto e;
		else 
		{
			printf("即将返回到发件箱页面 :)\n\n");
			system("pause");
			return; 
		}
	}
	printf("          *\n          *您输入的ID的用户是%s, 是否给他发送邮件  Y/N :", allUser[i - 1000].name);
	ch = getchar();
	getchar();
	if(ch == 'N' || ch == 'n')
	{
		printf("即将返回到发件箱页面 :)\n\n");
		system("pause");
		return; 
	}
	printf("          *\n          *请输入您要发送邮件的内容：");
	printf("\n          *ps.当你按回车键及代表邮件已经写完 :) \n\n          *Text:");
	gets(mails[ma].text);
	mails[ma].read = 0;
	mails[ma].sender = user.ID;
	mails[ma].addressee = i;
	strcpy(mails[ma].addresseeName, allUser[i - 1000].name);
	strcpy(mails[ma].senderName, user.name);
	ma++;
	printf("          *你的邮件已发送，即将返回到发件箱页面 :)\n\n          *");
	system("pause");
	return; 
}

void readsender()//查看发送邮件
{
	int i, t = 1;
	printf("\n*以下是您已经阅读过的所有邮件  :)");
	for(i = 0; i < ma; i++)
	{
		if(mails[i].sender != user.ID)
			continue;
		printf("\nNo.%d\n", t);
		printf("Addressee id: %d\n", mails[i].addressee);
		printf("Addressee name: %s\n", mails[i].addresseeName);
		printf("Text:\n   %s\n\n", mails[i].text);
		t++; 
	}
	if(t == 1)
		printf("\n*您没有发送的邮件 :)\n");
	printf("即将返回到发件箱页面 :)\n\n");
	system("pause");
}

void addresseeMenu()//收邮件菜单
{
	int i; 
e:	printf("\n          *************************收件箱**************************\n");
	printf("          *    1.未读邮件                        2.已读邮件       *\n");
	printf("          *                      0.返回菜单                       *\n");
	printf("          *********************************************************\n");
 	printf("\n\n*请输入您选择的功能：");
	scanf("%d", &i);
	system("CLS");
	switch(i)
	{
		case 1:
			unread();
			system("CLS");
			goto e;
			break;
		case 2:
			read();
			system("CLS");
			goto e;
			break;
		case 0:	
			printf("\n\n即将返回到主菜单页面 :)\n\n");
			system("pause");
			return;
		default:
			printf("\a\a\n          *您输入的选项错误请重新输入 :)\n\n");
			system("pause");
			goto e;
	}	
} 
void unread()//查看未读邮件 
{
	int i, t = 1;
	printf("\n*以下是您尚未阅读过的邮件  :)");
	for(i = 0; i < ma; i++)
	{
		if(mails[i].addressee != user.ID || mails[i].read == 1)
			continue;
		mails[i].read = 1;
		printf("\nNo.%d\n", t);
		printf("Sender id: %d\n", mails[i].sender);
		printf("Sender name: %s\n", mails[i].senderName);
		printf("Text:\n   %s\n\n", mails[i].text);
		t++;
	}
	if(t == 1)
		printf("\n*您没有未读邮件 :)\n");
	printf("*即将返回到收件箱页面 :)\n\n");
	system("pause");
}

void read()//查看已读邮件
{
	int i, t = 1;
	printf("\n*以下是您已经阅读过的所有邮件  :)");
	for(i = 0; i < ma; i++)
	{
		if(mails[i].addressee != user.ID || mails[i].read == 0)
			continue;
		printf("\nNo.%d\n", t);
		printf("Sender id: %d\n", mails[i].sender);
		printf("Sender name: %s\n", mails[i].senderName);
		printf("Text:\n   %s\n\n", mails[i].text);
		t++; 
	}
	if(t == 1)
		printf("\n*您没有已经读邮件 :)\n");
	printf("即将返回到收件箱页面 :)\n\n");
	system("pause");
}

void AdministratorMenu()//管理员界面 
{
	int i;
	while(1)
	{
aa:		system("CLS");
		printf("\n          ***********************管理员页面************************\n");
		printf("          *    1.账号显示                      2.账号查询         *\n");
		printf("          *    3.修改密码                      4.邮件显示         *\n");
		printf("          *                      0.返回页面                       *\n");
		printf("          *********************************************************\n");
		printf("\n\n*请输入您选择的功能：");
		scanf("%d", &i);
		getchar();
		system("CLS");
		switch(i)
		{
			case 1:
				AccountShows(); 
				break; 
			case 2:
				AccountQuery(); 
				break; 
			case 3:
				ChangePassword();
				break; 
			case 4:
				MailShow();
				break;
			case 0:
				SaveFile();
				printf("\n\n          *数据保存成功:)\n");
				system("pause");
				return;
			default:
				printf("\a\a\n*您输入的选项错误请重新输入 :)\n\n");
				system("pause");
				goto aa;
		}
	}
} 

void AccountShows()//账户显示 
{
	int i, t = 1;
	printf("\n*以下是所有注册了本系统的用户  :)\n");
	for(i = 0; i < n; i++)
	{
		printf("\nNo.%d\n", t);
		printf("User id: %d\n", allUser[i].ID);
		printf("User name: %s\n", allUser[i].name);
		printf("User password: %s\n\n", allUser[i].password);
		t++;
	}
	if(t == 1)
		printf("\n*很抱歉，本系统还没有用户 :)\n");
	printf("*即将返回到管理员页面 :)\n\n*");
	system("pause");
}

void AccountQuery()//账户查询 
{
	int i, t, id;
	char ch[20];
	while(1)
	{
ab:		system("CLS");
		printf("\n          ************************查询页面*************************\n");
		printf("          *    1.姓名查找                      2.账号查找         *\n");
		printf("          *                      0.返回页面                       *\n");
		printf("          *********************************************************\n");
		printf("          *请输入您的选择:  ");
		scanf("%d", &i);
		getchar();
		system("CLS");
		switch(i)
		{
			case 1:
				printf("\n          ************************姓名查找*************************\n");
				printf("          *请输入您要查询的姓名:  ");
				gets(ch); 
				for(t = 0; t < n; t++)
					if(strcmp(ch, allUser[t].name) == 0)
						break;
				if(t == n)
				{
					printf("          *很抱歉，本系统没有叫 %s 的用户 :(", ch);
					printf("\n\n          *即将返回查询页面 :)\n          *");
					system("pause");
					break; 
				}
				printf("\n\n          *该用户的信息如下 :) \n\n");
				printf("          *User id: %d\n", allUser[t].ID);
				printf("          *User name: %s\n", allUser[t].name);
				printf("          *User password: %s\n\n", allUser[t].password);
				printf("\n\n          *即将返回查询页面 :)\n          *");
				system("pause");
				break; 
			case 2:
				printf("\n          ************************账号查找*************************\n");
				printf("          *请输入您要查询的账号:  ");
				scanf("%d", &id);
				getchar(); 
				for(t = 0; t < n; t++)
					if(id == allUser[t].ID)
						break;
				if(t == n)
				{
					printf("          *很抱歉，本系统没有账号为 %d 的用户 :(", id);
					printf("\n\n          *即将返回查询页面 :)\n");
					system("pause");
					break; 
				}
				printf("\n\n          *该用户的信息如下 :) \n\n");
				printf("          *User id: %d\n", allUser[t].ID);
				printf("          *User name: %s\n", allUser[t].name);
				printf("          *User password: %s\n\n", allUser[t].password);
				printf("\n\n          *即将返回查询页面 :)\n          *");
				system("pause");
				break; 
			case 0:
				printf("\n\n          *即将返回管理员页面 :)\n");
				system("pause");
				return;
			default:
				printf("\a\a\n          *您输入的选项错误请重新输入 :)\n\n          *");
				system("pause");
				goto ab;
		}
	} 
} 

void ChangePassword()//管理员修改密码 
{	
	int i, t, id;
	char ch[20], ft;
	while(1)
	{
ab:		system("CLS");
		printf("\n          ************************修改密码*************************\n");
		printf("          *    1.姓名修改                      2.账号修改         *\n");
		printf("          *                      0.返回页面                       *\n");
		printf("          *********************************************************\n");
		printf("          *请输入您的选择:  ");
		scanf("%d", &i);
		getchar();
		system("CLS");
		switch(i)
		{
			case 1:
				printf("\n          ************************姓名修改*************************\n");
				printf("          *请输入您要修改账号的姓名:  ");
				gets(ch); 
				for(t = 0; t < n; t++)
					if(strcmp(ch, allUser[t].name) == 0)
						break;
				if(t == n)
				{
					printf("          *很抱歉，本系统没有叫 %s 的用户 :(", ch);
					printf("\n\n          *即将返回修改密码页面 :)\n          *");
					system("pause");
					break; 
				}
				printf("\n\n          *该用户的信息如下 :) \n\n");
				printf("          *User id: %d\n", allUser[t].ID);
				printf("          *User name: %s\n", allUser[t].name);
				printf("          *User password: %s\n\n", allUser[t].password);
				printf("          *请问您是否修改  Y/N : ");
				ft = getchar();
				getchar(); 
				if(ft == 'Y' || ft == 'y')
				{
					printf("          *请输入新密码:  ");
					gets(allUser[t].password);
					printf("\n\n          *密码修改成功 :)");
				}
				printf("\n\n          *即将返回查询页面 :)\n          *");
				system("pause");
				break; 
			case 2:
				printf("\n          ************************账号查找*************************\n");
				printf("          *请输入您要修改密码的账号:  ");
				scanf("%d", &id);
				getchar(); 
				for(t = 0; t < n; t++)
					if(id == allUser[t].ID)
						break;
				if(t == n)
				{
					printf("          *很抱歉，本系统没有账号为 %d 的用户 :(", id);
					printf("\n\n          *即将返回修改密码页面 :)\n");
					system("pause");
					break; 
				}
				printf("\n\n          *该用户的信息如下 :) \n\n");
				printf("          *User id: %d\n", allUser[t].ID);
				printf("          *User name: %s\n", allUser[t].name);
				printf("          *User password: %s\n\n", allUser[t].password);
				printf("          *请问您是否修改  Y/N : ");
				ft = getchar();
				getchar(); 
				if(ft == 'Y' || ft == 'y')
				{
					printf("          *请输入新密码:  ");
					gets(allUser[t].password);
					printf("\n\n          *密码修改成功 :)");
				}
				printf("\n\n          *即将返回查询页面 :)\n          *");
				system("pause");
				break; 
			case 0:
				printf("\n\n          *即将返回管理员页面 :)\n          *");
				system("pause");
				return;
			default:
				printf("\a\a\n          *您输入的选项错误请重新输入 :)\n\n          *");
				system("pause");
				goto ab;
		}
	}
	system("CLS"); 
} 

void MailShow()//显示邮件 
{
	int i, t = 1;
	printf("\n          *以下是使用本系统发的所有邮件  :)\n");
	for(i = 0; i < ma; i++)
	{
		printf("\n          *No.%d\n", t);
		printf("          *Sender id: %d\n", mails[i].sender);
		printf("          *Sender name: %s\n", mails[i].senderName);
		printf("          *Addressee id: %d\n", mails[i].addressee);
		printf("          *Addresseer name: %s\n", mails[i].addresseeName);
		printf("          *Text:   %s\n\n", mails[i].text);
		t++;
	}
	if(t == 1)
		printf("\n          *很抱歉，后没有用户使用过本系统的邮件功能 :)\n");
	printf("          *即将返回到收件箱页面 :)\n\n          *");
	system("pause");
}

void OpenFile()//打开文件 
{
	FILE *fp1, *fp2, *fp3, *fp4;
	int i = 0, j = 0, k = 0, s = 0;
	fp1 = fopen("用户信息data.dat","ab+");
	fp3 = fopen("成绩信息data.dat","ab+");
	fp2 = fopen("题库信息data.dat","ab+");
	fp4 = fopen("邮件信息data.dat","ab+");
	if(fp1==NULL || fp2==NULL || fp3==NULL || fp4==NULL)
	{
		printf("\n\n\t很抱歉无法打开数据文件:(\n\n");
		system("pause");
		exit(0);
	}
	while(!feof(fp1))
	{
		if(fread(&allUser[i], sizeof(Use), 1, fp1)==1)
		{
			n++;
			i++;
		}
	}
	while(!feof(fp2))
	{
		if(fread(&problem[k], sizeof(Pro), 1, fp2)==1)
		{
			a++;
			k++;
		}
	}
	while(!feof(fp3))
	{
		if(fread(&grade[j], sizeof(Gra), 1, fp3)==1)
		{
			b++;
			j++;
		}
	}
	while(!feof(fp4))
	{
		if(fread(&mails[s], sizeof(Mail), 1, fp4)==1)
		{
			s++;
			ma++;
		}
	}
	fclose(fp1);
	fclose(fp2);
	fclose(fp3);
	fclose(fp4);
}

void SaveFile()//保存数据
{
	FILE *fp1, *fp2, *fp3, *fp4;
	int i = 0;
	fp1 = fopen("用户信息data.dat","wb");
	fp3 = fopen("成绩信息data.dat","wb");
	fp2 = fopen("题库信息data.dat","wb");
	fp4 = fopen("邮件信息data.dat","wb");
	if(fp1==NULL || fp2==NULL || fp3==NULL || fp4==NULL)
	{
		printf("\n\n\t很抱歉无法打开数据文件:(\n\n");
		system("pause");
		exit(0);
	}
	for(i = 0; i < n; i++)
		fwrite(&allUser[i], sizeof(Use), 1, fp1);
	for(i = 0; i < a; i++)
		fwrite(&problem[i], sizeof(Pro), 1, fp2);
	for(i = 0; i < b; i++)
		fwrite(&grade[i], sizeof(Gra), 1, fp3);
	for(i = 0; i < ma; i++)
		fwrite(&mails[i], sizeof(Mail), 1, fp4);
	fclose(fp1);
	fclose(fp2);
	fclose(fp3);
	fclose(fp4);
} 
