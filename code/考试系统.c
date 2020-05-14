//Data: 2019/3/9 --2019/3/10
//2019/03/13�� �������书��
//2019/03/14 ���� ���ӹ���Աҳ�� 
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

void OpenFile();//���ļ� 
void SaveFile();//�����ļ� 
int LoginPage();//��½ҳ�� 
void menu();//���˵� 
void menu2();//�����˵� 
int search(int id);//��ѯ�˺� 
void reg();//ע���˺� 
void design();//����ϵͳ 
void check();//�鿴��� 
void del();//ɾ����Ŀ
void alter();//�޸���Ŀ 
void revision();//�޸����� 
void exam();//����ģ�� 
void examgrade();//���鿴�ɼ� 
void rank();//��ѯ���� 
void sender();//�����ʼ� 
void senderMenu();//�����ʼ��˵�
void addresseeMenu();//���ʼ��˵�
void unread();//�鿴δ���ʼ�
void read();//�鿴�Ѷ��ʼ�
void readsender();//�鿴�����ʼ�
void AdministratorMenu();//����Ա���� 
void AccountShows();//�˻���ʾ
void AccountQuery();//�˻���ѯ
void MailShow();//��ʾ�ʼ� 
void ChangePassword();//����Ա�޸����� 

int main()
{
	int i, t = 0;
	OpenFile();
a:	menu();	
	printf("\n\n*��������ѡ��Ĺ��ܣ�");
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
			printf("\a\a\n          *�������ѡ��������������� :)\n\n");
			system("pause");
			goto a;
	}
	while(1)
	{
		system("CLS");
		menu2(); 
b:		printf("\n\n*��������ѡ��Ĺ��ܣ�");
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
				printf("\n          *���ݱ���ɹ�:)\n");
				printf("\n          *�ڴ������´�ʹ��:)\n\n");
				system("pause");
				return 0;
			default:
				printf("\a\a\n*�������ѡ��������������� :)\n\n");
				system("pause");
				goto b;
		}
	}
}

void menu()//���˵� 
{
	printf("\n          ************************����ϵͳ*************************\n");
	printf("          *    1.�˺�ע��                      2.�˺ŵ�½         *\n");
	printf("          *********************************************************\n");
}

void menu2()//�����˵� 
{
	printf("\n          *************************�˵�****************************\n");
	printf("          *    1.��Ҫ����                      2.��ѯ�ɼ�         *\n");
	printf("          *    3.�ɼ�����                      4.�޸�����         *\n");
	printf("          *    5.��Ҫ����                      6.�鿴���         *\n");
	printf("          *    7.ɾ����Ŀ                      8.�޸���Ŀ         *\n");
	printf("          *    9.�����ʼ�                      10.�ռ���          *\n");
	printf("          *                      0.�˳�ϵͳ                       *\n");
	printf("          *********************************************************\n");
	printf("\n*%s ͬѧ���ã���ӭ��½������ϵͳ :)  ���ĵ�½IDΪ��%d\n", user.name, user.ID);
}

void reg()//ע���˺� 
{
	char key[20];
	int t;
	printf("\n          ************************ע��ҳ��*************************\n");
	printf("          *����������name:  ");
	scanf("%s", &allUser[n].name);
	printf("          *\n");
	printf("          *����������password:  ");
	scanf("%s", &allUser[n].password);
	do
	{
		printf("          *���ٴ���������password:  ");
		scanf("%s", &key);
		if(strcmp(key, allUser[n].password) == 0) 
			t = 0;
		else 
		{
			t = 1;
			printf("          *������������������������ :) \n");
		}
	}while(t == 1);
	printf("          *\n");
	printf("          *ע��ɹ���\n");
	allUser[n].ID = n + 1000;
	printf("          *\n");
	printf("          *����ID: %d\n", allUser[n].ID);
	system("pause"); 
	n++;
}

int LoginPage()//��½ҳ�� 
{
	int t;
	char key[20];
	printf("\n          ************************��½ҳ��*************************\n");
	printf("          *����������ID:  ");
	scanf("%d", &user.ID);
	if(user.ID == 101)//�ж��Ƿ�Ϊ����Ա 
	{
		do
		{
			printf("          *����������password:  ");
			scanf("%s", &key);
			if(strcmp(key, "54759") == 0) 
				t = 0;
			else 
			{
				t = 1;
				printf("          *������������������������ :) \n");
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
		printf("          *��������˺�δע�ᣬ��ע���˺ź��ٴ�ʹ�ñ����� :) \n");
		return 0;
	}
	do
	{
		printf("          *����������password:  ");
		scanf("%s", &key);
		if(strcmp(key, user.password) == 0) 
			t = 0;
		else 
		{
			t = 1;
			printf("          *������������������������ :) \n");
		}
	}while(t == 1);
	return 1;
}

int search(int id)//��ѯ�˺� 
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

void exam()//����ģ�� 
{
	int book[1000] = {0};
	int i, t, num;
	char key;
	printf("\n  *��ϵͳ��⹲�� %d ����Ŀ\n\n", a);
	printf("  *��������Ҫ���Ե����� ��");
	scanf("%d", &t);
	getchar();
	printf("\n  *��׼�������𣿿��Լ�����ʼ��ף���и��óɼ� :)\n\n");
	grade[b].id = user.ID;
	strcpy(grade[b].name, user.name);
	system("pause");
	system("CLS");
	printf("\n  ***ps.��ע�⣬���д𰸾���Ҫ���д������ϵͳ����Ϊ���Ĵ𰸴���\n***");
	for(i = 0; i < t; i++)
	{
		srand(time(NULL)); //�����������
		num = rand() % a;//�����������
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
		printf("���������Ĵ𰸣�");
		key = getchar();
		getchar();
		if(key == problem[num].answer)
		{
			grade[b].t++;
			printf("�ش���ȷ������\n\n");
		}
		else
		{
			grade[b].f++;
			printf("�ش����... :( \n");
			printf("��ȷ���� %c\n\n", problem[num].answer);
		}
	}
	grade[b].gra = (float)grade[b].t / t * 100;
	printf("      ***���ο��Խ���... ������ȷ��Ϊ %.2f%% ��***\n\n", grade[b].gra);
	b++;
	system("pause");
}

void examgrade()//���鿴�ɼ�
{
	int i, t = 0;
	printf("\n  �ο���Ա  ��ȷ����  �������  ��ȷ��\n");
	for(i = 0; i < b; i++)
	{
		if(grade[i].id != user.ID)
			continue;
		t++;
		printf("%d. %6s  %6d    %6d     %4.2f%%\n", t, grade[i].name, grade[i].t, grade[i].f, grade[i].gra);
	}
	printf("\n\n  ***�������������п��Գɼ���������ת����ҳ�� :) ***\n\n");
	system("pause");
} 


void rank()//��ѯ���� 
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
	printf("   ***Ŀǰ�����û������й� %d �β��ԣ��������������� :) ***\n", b);
	printf("\n  �ο���Ա  ��ȷ����  �������  ��ȷ��\n");
	for(i = 0; i < b; i++)
		printf("%d. %6s  %6d    %6d     %4.2f%%\n", i + 1, grade[i].name, grade[i].t, grade[i].f, grade[i].gra);
	printf("\n\n  ***�������������п��Գɼ���������ת����ҳ�� :) ***\n\n");
	system("pause");
}

void design()//����ϵͳ 
{
	printf("\n*��������Ŀ��\n"); 
	gets(problem[a].title);
	printf("*\n*������Aѡ�\n");
	gets(problem[a].a);
	printf("*\n*������Bѡ�\n");
	gets(problem[a].b);
	printf("*\n*������Cѡ�\n");
	gets(problem[a].c);
	printf("*\n*������Dѡ�\n");
	gets(problem[a].d);
	printf("*\n*��������ȷѡ�\n");
	problem[a].answer = getchar();
	a++;
} 

void check()//�鿴���
{
	int i;
	printf("\n*����⹲�� %d ����Ŀ\n", a);
	for(i = 0; i < a; i++)
	{
		printf("\nNo.%d\n", i + 1);
		printf("Title:\n");
		printf("%s\n", problem[i].title);
		printf("  A:%s\n", problem[i].a);
		printf("  B:%s\n", problem[i].b);
		printf("  C:%s\n", problem[i].c);
		printf("  D:%s\n", problem[i].d);
		printf("��ȷ��Ϊ��%c\n", problem[i].answer);
	}
	putchar('\n');
	system("pause");
} 

void del()//ɾ����Ŀ
{
	int i;
	char ch;
	printf("\n��������Ҫɾ������Ŀ�ı�ţ� ");
	scanf("%d", &i);
	i = i - 1;
	getchar();
	printf("\n��Ҫɾ������Ŀ�������£� \n");
	printf("\nNo.%d\n", i + 1);
	printf("Title:\n");
	printf("%s\n", problem[i].title);
	printf("  A:%s\n", problem[i].a);
	printf("  B:%s\n", problem[i].b);
	printf("  C:%s\n", problem[i].c);
	printf("  D:%s\n", problem[i].d);
	printf("��ȷ��Ϊ��%c\n", problem[i].answer);
	printf("\n��ȷ��ɾ������Ŀ��  Y/N\n");
	ch = getchar();
	getchar();
	if(ch == 'N' || ch == 'n')
	{
		printf("�������ص��˵�ҳ�� :)\n\n");
		system("pause");
		return;
	}
	for(;i < a; i++)
		problem[i] = problem[i + 1];
	a--;
	printf("ɾ���ɹ���������Ŀ����Ѿ����� :)\n\n");
	system("pause");
} 

void alter()//�޸���Ŀ
{
	int i;
	char ch;
	printf("\n��������Ҫ�޸ĵ���Ŀ�ı�ţ� ");
	scanf("%d", &i);
	i = i - 1;
	getchar();
	printf("\n��Ҫ�޸ĵ���Ŀ�������£� \n");
	printf("\nNo.%d\n", i + 1);
	printf("Title:\n");
	printf("%s\n", problem[i].title);
	printf("  A:%s\n", problem[i].a);
	printf("  B:%s\n", problem[i].b);
	printf("  C:%s\n", problem[i].c);
	printf("  D:%s\n", problem[i].d);
	printf("��ȷ��Ϊ��%c\n", problem[i].answer);
	printf("\n��ȷ���޸ĸ���Ŀ��  Y/N\n");
	ch = getchar();
	getchar();
	if(ch == 'N' || ch == 'n')
	{
		printf("�������ص��˵�ҳ�� :)\n\n");
		system("pause");
		return;
	}
	printf("\n*��������Ŀ��\n"); 
	gets(problem[i].title);
	printf("*\n*������Aѡ�\n");
	gets(problem[i].a);
	printf("*\n*������Bѡ�\n");
	gets(problem[i].b);
	printf("*\n*������Cѡ�\n");
	gets(problem[i].c);
	printf("*\n*������Dѡ�\n");
	gets(problem[i].d);
	printf("*\n*��������ȷѡ�\n");
	problem[i].answer = getchar();
	printf("�޸ĳɹ����������ص��˵�ҳ�� :)\n\n");
	system("pause");
} 

void revision()//�޸����� 
{
	char key[20], ch;
	int t, i;
	do
	{
		printf("\n*�����������ڵ����룺");
		gets(key);
		if(strcmp(key, user.password) == 0) 
			t = 0;
		else 
		{
			t = 1;
			printf("*������������������������ :) \n");
			printf("\n*�Ƿ�����޸����� Y/N :");			
			ch = getchar();
			getchar();
			if(ch == 'N' || ch == 'n')
			{
				printf("*�������ص��˵�ҳ�� :)\n\n");
				system("pause");
				return;
			}
		}
	}while(t == 1);
	printf("*���������������룺");
	gets(user.password);
	for(i = 0; i < n; i++)
		if(allUser[i].ID == user.ID)
			break;
	if(i < n) 
		strcpy(allUser[i].password, user.password);
	printf("�޸ĳɹ����������ص��˵�ҳ�� :)\n\n");
	system("pause");
}

void senderMenu()//�����ʼ��˵�
{
	int i; 
d:	printf("\n          *************************������**************************\n");
	printf("          *    1.�����ʼ�                     2.�鿴�ѷ����ʼ�    *\n");
	printf("          *                      0.���ز˵�                       *\n");
	printf("          *********************************************************\n");
 	printf("\n\n*��������ѡ��Ĺ��ܣ�");
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
			printf("\n\n�������ص����˵�ҳ�� :)\n\n");
			system("pause");
			return;
		default:
			printf("\a\a\n          *�������ѡ��������������� :)\n\n");
			system("pause");
			goto d;
	}	
}
 
void sender()//�����ʼ� 
{
	int i, t, j;
	char ch; 
	printf("\n          ************************�����ʼ�*************************\n");
e:	printf("          *\n          *��������Ҫ���Ͷ����ID��");
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
		printf("          *\n          *�������IDδע���˺ţ����������� :) \n");
		printf("          *\n          *�Ƿ�Ҫ�����ʼ��� Y/N :");			
		ch = getchar();
		getchar();
		if(ch != 'N' && ch != 'n')
			goto e;
		else 
		{
			printf("�������ص�������ҳ�� :)\n\n");
			system("pause");
			return; 
		}
	}
	printf("          *\n          *�������ID���û���%s, �Ƿ���������ʼ�  Y/N :", allUser[i - 1000].name);
	ch = getchar();
	getchar();
	if(ch == 'N' || ch == 'n')
	{
		printf("�������ص�������ҳ�� :)\n\n");
		system("pause");
		return; 
	}
	printf("          *\n          *��������Ҫ�����ʼ������ݣ�");
	printf("\n          *ps.���㰴�س����������ʼ��Ѿ�д�� :) \n\n          *Text:");
	gets(mails[ma].text);
	mails[ma].read = 0;
	mails[ma].sender = user.ID;
	mails[ma].addressee = i;
	strcpy(mails[ma].addresseeName, allUser[i - 1000].name);
	strcpy(mails[ma].senderName, user.name);
	ma++;
	printf("          *����ʼ��ѷ��ͣ��������ص�������ҳ�� :)\n\n          *");
	system("pause");
	return; 
}

void readsender()//�鿴�����ʼ�
{
	int i, t = 1;
	printf("\n*���������Ѿ��Ķ����������ʼ�  :)");
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
		printf("\n*��û�з��͵��ʼ� :)\n");
	printf("�������ص�������ҳ�� :)\n\n");
	system("pause");
}

void addresseeMenu()//���ʼ��˵�
{
	int i; 
e:	printf("\n          *************************�ռ���**************************\n");
	printf("          *    1.δ���ʼ�                        2.�Ѷ��ʼ�       *\n");
	printf("          *                      0.���ز˵�                       *\n");
	printf("          *********************************************************\n");
 	printf("\n\n*��������ѡ��Ĺ��ܣ�");
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
			printf("\n\n�������ص����˵�ҳ�� :)\n\n");
			system("pause");
			return;
		default:
			printf("\a\a\n          *�������ѡ��������������� :)\n\n");
			system("pause");
			goto e;
	}	
} 
void unread()//�鿴δ���ʼ� 
{
	int i, t = 1;
	printf("\n*����������δ�Ķ������ʼ�  :)");
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
		printf("\n*��û��δ���ʼ� :)\n");
	printf("*�������ص��ռ���ҳ�� :)\n\n");
	system("pause");
}

void read()//�鿴�Ѷ��ʼ�
{
	int i, t = 1;
	printf("\n*���������Ѿ��Ķ����������ʼ�  :)");
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
		printf("\n*��û���Ѿ����ʼ� :)\n");
	printf("�������ص��ռ���ҳ�� :)\n\n");
	system("pause");
}

void AdministratorMenu()//����Ա���� 
{
	int i;
	while(1)
	{
aa:		system("CLS");
		printf("\n          ***********************����Աҳ��************************\n");
		printf("          *    1.�˺���ʾ                      2.�˺Ų�ѯ         *\n");
		printf("          *    3.�޸�����                      4.�ʼ���ʾ         *\n");
		printf("          *                      0.����ҳ��                       *\n");
		printf("          *********************************************************\n");
		printf("\n\n*��������ѡ��Ĺ��ܣ�");
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
				printf("\n\n          *���ݱ���ɹ�:)\n");
				system("pause");
				return;
			default:
				printf("\a\a\n*�������ѡ��������������� :)\n\n");
				system("pause");
				goto aa;
		}
	}
} 

void AccountShows()//�˻���ʾ 
{
	int i, t = 1;
	printf("\n*����������ע���˱�ϵͳ���û�  :)\n");
	for(i = 0; i < n; i++)
	{
		printf("\nNo.%d\n", t);
		printf("User id: %d\n", allUser[i].ID);
		printf("User name: %s\n", allUser[i].name);
		printf("User password: %s\n\n", allUser[i].password);
		t++;
	}
	if(t == 1)
		printf("\n*�ܱ�Ǹ����ϵͳ��û���û� :)\n");
	printf("*�������ص�����Աҳ�� :)\n\n*");
	system("pause");
}

void AccountQuery()//�˻���ѯ 
{
	int i, t, id;
	char ch[20];
	while(1)
	{
ab:		system("CLS");
		printf("\n          ************************��ѯҳ��*************************\n");
		printf("          *    1.��������                      2.�˺Ų���         *\n");
		printf("          *                      0.����ҳ��                       *\n");
		printf("          *********************************************************\n");
		printf("          *����������ѡ��:  ");
		scanf("%d", &i);
		getchar();
		system("CLS");
		switch(i)
		{
			case 1:
				printf("\n          ************************��������*************************\n");
				printf("          *��������Ҫ��ѯ������:  ");
				gets(ch); 
				for(t = 0; t < n; t++)
					if(strcmp(ch, allUser[t].name) == 0)
						break;
				if(t == n)
				{
					printf("          *�ܱ�Ǹ����ϵͳû�н� %s ���û� :(", ch);
					printf("\n\n          *�������ز�ѯҳ�� :)\n          *");
					system("pause");
					break; 
				}
				printf("\n\n          *���û�����Ϣ���� :) \n\n");
				printf("          *User id: %d\n", allUser[t].ID);
				printf("          *User name: %s\n", allUser[t].name);
				printf("          *User password: %s\n\n", allUser[t].password);
				printf("\n\n          *�������ز�ѯҳ�� :)\n          *");
				system("pause");
				break; 
			case 2:
				printf("\n          ************************�˺Ų���*************************\n");
				printf("          *��������Ҫ��ѯ���˺�:  ");
				scanf("%d", &id);
				getchar(); 
				for(t = 0; t < n; t++)
					if(id == allUser[t].ID)
						break;
				if(t == n)
				{
					printf("          *�ܱ�Ǹ����ϵͳû���˺�Ϊ %d ���û� :(", id);
					printf("\n\n          *�������ز�ѯҳ�� :)\n");
					system("pause");
					break; 
				}
				printf("\n\n          *���û�����Ϣ���� :) \n\n");
				printf("          *User id: %d\n", allUser[t].ID);
				printf("          *User name: %s\n", allUser[t].name);
				printf("          *User password: %s\n\n", allUser[t].password);
				printf("\n\n          *�������ز�ѯҳ�� :)\n          *");
				system("pause");
				break; 
			case 0:
				printf("\n\n          *�������ع���Աҳ�� :)\n");
				system("pause");
				return;
			default:
				printf("\a\a\n          *�������ѡ��������������� :)\n\n          *");
				system("pause");
				goto ab;
		}
	} 
} 

void ChangePassword()//����Ա�޸����� 
{	
	int i, t, id;
	char ch[20], ft;
	while(1)
	{
ab:		system("CLS");
		printf("\n          ************************�޸�����*************************\n");
		printf("          *    1.�����޸�                      2.�˺��޸�         *\n");
		printf("          *                      0.����ҳ��                       *\n");
		printf("          *********************************************************\n");
		printf("          *����������ѡ��:  ");
		scanf("%d", &i);
		getchar();
		system("CLS");
		switch(i)
		{
			case 1:
				printf("\n          ************************�����޸�*************************\n");
				printf("          *��������Ҫ�޸��˺ŵ�����:  ");
				gets(ch); 
				for(t = 0; t < n; t++)
					if(strcmp(ch, allUser[t].name) == 0)
						break;
				if(t == n)
				{
					printf("          *�ܱ�Ǹ����ϵͳû�н� %s ���û� :(", ch);
					printf("\n\n          *���������޸�����ҳ�� :)\n          *");
					system("pause");
					break; 
				}
				printf("\n\n          *���û�����Ϣ���� :) \n\n");
				printf("          *User id: %d\n", allUser[t].ID);
				printf("          *User name: %s\n", allUser[t].name);
				printf("          *User password: %s\n\n", allUser[t].password);
				printf("          *�������Ƿ��޸�  Y/N : ");
				ft = getchar();
				getchar(); 
				if(ft == 'Y' || ft == 'y')
				{
					printf("          *������������:  ");
					gets(allUser[t].password);
					printf("\n\n          *�����޸ĳɹ� :)");
				}
				printf("\n\n          *�������ز�ѯҳ�� :)\n          *");
				system("pause");
				break; 
			case 2:
				printf("\n          ************************�˺Ų���*************************\n");
				printf("          *��������Ҫ�޸�������˺�:  ");
				scanf("%d", &id);
				getchar(); 
				for(t = 0; t < n; t++)
					if(id == allUser[t].ID)
						break;
				if(t == n)
				{
					printf("          *�ܱ�Ǹ����ϵͳû���˺�Ϊ %d ���û� :(", id);
					printf("\n\n          *���������޸�����ҳ�� :)\n");
					system("pause");
					break; 
				}
				printf("\n\n          *���û�����Ϣ���� :) \n\n");
				printf("          *User id: %d\n", allUser[t].ID);
				printf("          *User name: %s\n", allUser[t].name);
				printf("          *User password: %s\n\n", allUser[t].password);
				printf("          *�������Ƿ��޸�  Y/N : ");
				ft = getchar();
				getchar(); 
				if(ft == 'Y' || ft == 'y')
				{
					printf("          *������������:  ");
					gets(allUser[t].password);
					printf("\n\n          *�����޸ĳɹ� :)");
				}
				printf("\n\n          *�������ز�ѯҳ�� :)\n          *");
				system("pause");
				break; 
			case 0:
				printf("\n\n          *�������ع���Աҳ�� :)\n          *");
				system("pause");
				return;
			default:
				printf("\a\a\n          *�������ѡ��������������� :)\n\n          *");
				system("pause");
				goto ab;
		}
	}
	system("CLS"); 
} 

void MailShow()//��ʾ�ʼ� 
{
	int i, t = 1;
	printf("\n          *������ʹ�ñ�ϵͳ���������ʼ�  :)\n");
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
		printf("\n          *�ܱ�Ǹ����û���û�ʹ�ù���ϵͳ���ʼ����� :)\n");
	printf("          *�������ص��ռ���ҳ�� :)\n\n          *");
	system("pause");
}

void OpenFile()//���ļ� 
{
	FILE *fp1, *fp2, *fp3, *fp4;
	int i = 0, j = 0, k = 0, s = 0;
	fp1 = fopen("�û���Ϣdata.dat","ab+");
	fp3 = fopen("�ɼ���Ϣdata.dat","ab+");
	fp2 = fopen("�����Ϣdata.dat","ab+");
	fp4 = fopen("�ʼ���Ϣdata.dat","ab+");
	if(fp1==NULL || fp2==NULL || fp3==NULL || fp4==NULL)
	{
		printf("\n\n\t�ܱ�Ǹ�޷��������ļ�:(\n\n");
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

void SaveFile()//��������
{
	FILE *fp1, *fp2, *fp3, *fp4;
	int i = 0;
	fp1 = fopen("�û���Ϣdata.dat","wb");
	fp3 = fopen("�ɼ���Ϣdata.dat","wb");
	fp2 = fopen("�����Ϣdata.dat","wb");
	fp4 = fopen("�ʼ���Ϣdata.dat","wb");
	if(fp1==NULL || fp2==NULL || fp3==NULL || fp4==NULL)
	{
		printf("\n\n\t�ܱ�Ǹ�޷��������ļ�:(\n\n");
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
