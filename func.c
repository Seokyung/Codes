//�Լ����� ���ǰ� ����ִ� c ����
#include "func.h"

//�޴� ��� �Լ�
void menu()
{
	printf("--------MENU--------\n");
	printf("1. �л� ���� �Է�\n");
	printf("2. �л� ���� ����\n");
	printf("3. �л� ���� ����\n");
	printf("4. �л� ���� ��� ��ȸ\n");
	printf("5. ���� �л��� ���Ͽ� ����\n");
	printf("6. ���α׷� ����\n");
	printf("--------------------\n");
}

//�л� ���� �߰��ϴ� �Լ�
void addStudent(Student* s, int* index, int stdNum)
{
	if (*index >= stdNum)
	{
		puts("�л��ο� ������ �� �ִ� ������ ���� �ʰ��Ǿ����ϴ�.");
		puts("�л� ������ �� �߰��Ϸ��� �޴����� 4�� ������ ������ �ִ� ������ �������ּ���!");
		return 0;
	}

	puts("�л��ο� �߰��� �л� ������ �Է��մϴ�.");

	printf("�л� �̸� �Է� : ");
	scanf_s("%s", s[*index].name, 15);

	printf("�л� �й� �Է� : ");
	scanf_s("%s", s[*index].id, 10);

	printf("�л� �а� �Է� : ");
	scanf_s("%s", s[*index].depart, 20);

	printf("�л� ��ȭ��ȣ �Է� : ");
	scanf_s("%s", s[*index].tel, 20);

	(*index)++;
}

//�л��� ���� �л� ���� �����ϴ� �Լ� (�̸����� �л� ã��)
void modifyStudent(Student* s, int* index, int stdNum)
{
	int i, j;

	char name[15];

	if (*index == 0)
	{
		printf("�л��ο� �ԷµǾ� �ִ� �л� ������ �������� �ʽ��ϴ�.\n");
		printf("�޴����� 2�� �����Ͽ� �л� ������ �߰��ϼ���!\n");
		return 0;
	}

	printf("������ �����ϰ��� �ϴ� �л��� �̸��� �Է��ϼ��� : ");
	scanf_s("%s", name, 15);

	for (i = 0; i < stdNum; i++)
	{
		if (strcmp(name, s[i].name) == 0)
		{
			printf("%s �л��� ���� ����\n", s[i].name);
			
			printf("�̸� : ");
			scanf_s("%s", s[i].name, 15);

			printf("�й� : ");
			scanf_s("%s", s[i].id, 10);

			printf("�а� : ");
			scanf_s("%s", s[i].depart, 20);

			printf("��ȭ��ȣ : ");
			scanf_s("%s", s[i].tel, 20);

			return 0;
		}
	}

	puts("�����Ϸ��� �л� ������ �������� �ʽ��ϴ�!");
}

//�л��� ���� �л� ���� �����ϴ� �Լ� (�̸����� �л� ã��)
void deleteStudent(Student* s, int* index, int stdNum)
{
	int i, j;
	
	char name[15];

	if (*index == 0)
	{
		printf("�л��ο� �ԷµǾ� �ִ� �л� ������ �������� �ʽ��ϴ�.\n");
		printf("�޴����� 2�� �����Ͽ� �л� ������ �߰��ϼ���!\n");
		return 0;
	}
	
	printf("������ �����ϰ��� �ϴ� �л��� �̸��� �Է��ϼ��� : ");
	scanf_s("%s", name, 15);

	for (i = 0; i < stdNum; i++)
	{
		if (strcmp(name, s[i].name) == 0)
		{
			(*index)--;

			printf("%s �л��� ���� ����\n", s[i].name);

			//�л��� ����ü �迭�� �� ���� �ʾҴٸ�
			if (i != stdNum - 1)
			{
				//�л��� ����ü �迭�� �� ������ �޿�
				for (j = i; j < stdNum; j++)
				{
					strcpy(s[j].name, s[j + 1].name);
					strcpy(s[j].id, s[j + 1].id);
					strcpy(s[j].depart, s[j + 1].depart);
					strcpy(s[j].tel, s[j + 1].tel);
				}

				//�л��� ����ü �迭�� �������� NULL ����
				*s[stdNum - 1].name = NULL;
				*s[stdNum - 1].id = NULL;
				*s[stdNum - 1].depart = NULL;
				*s[stdNum - 1].tel = NULL;
			}
			//�л��� ����ü �迭�� �� á�ٸ�
			else
			{
				//�л��� ����ü �迭�� �������� NULL ����
				*s[stdNum - 1].name = NULL;
				*s[stdNum - 1].id = NULL;
				*s[stdNum - 1].depart = NULL;
				*s[stdNum - 1].tel = NULL;
			}

			return 0;
		}
	}

	puts("�����Ϸ��� �л� ������ �������� �ʽ��ϴ�!");
}

//�л��� ���� ��� �л� ���� ����ϴ� �Լ�
void viewStudentList(Student* s, int* index)
{
	int i;

	if (*index == 0)
	{
		puts("�л��ο� �ԷµǾ� �ִ� �л� ������ �������� �ʽ��ϴ�.");
		puts("�޴����� 2�� �����Ͽ� �л� ������ �߰��ϼ���!");
		return 0;
	}

	puts("�л��ο� �ִ� ��� �л����� ������ ��ȸ�մϴ�.\n");

	for (i = 0; i < *index; i++)
	{
		printf("[%d] �̸� : %s\n", i + 1, s[i].name);
		printf("    �й� : %s\n", s[i].id);
		printf("    �а� : %s\n", s[i].depart);
		printf("    ��ȭ��ȣ : %s\n\n", s[i].tel);
	}
}

//�л� ���� �л��� ���Ͽ� �����ϴ� �Լ�
void saveStudentList(Student* s, int* index)
{
	int i, state;

	if (*index == 0)
	{
		puts("�л��ο� �ԷµǾ� �ִ� �л� ������ �������� �ʽ��ϴ�.");
		puts("�޴����� 2�� �����Ͽ� �л� ������ �߰��ϼ���!");
		return 0;
	}

	FILE* wfp = fopen(fname, "wt");
	if (wfp == NULL)
	{
		puts("������ ���� �� ������ �߻��߽��ϴ�!");
		return 1;
	}

	fputs("�л��� (�̸�, �й�, �а�, ��ȭ��ȣ)\n\n", wfp);
	for (i = 0; i < *index; i++)
	{
		fprintf(wfp, "%s\t%s\t%s\t%s\n", s[i].name, s[i].id, s[i].depart, s[i].tel);
	}

	state = fclose(wfp);
	if (state != 0)
	{
		puts("������ �ݴ� �� ������ �߻��߽��ϴ�!");
		return 1;
	}

	puts("���� �л��� ���Ͽ� �����");
	puts("��� : C:\Temp\studentList.txt");
}