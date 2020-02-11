#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//�л� ���� ����ü ����
typedef struct
{
	//�л��ο��� �л��� �̸�, �й�, ��, ��ȭ��ȣ ������ ����
	char name[15];
	char id[10];
	char depart[20];
	char tel[20];
}Student;

void menu();
void addStudent(Student* s, int* index, int stdNum);
void modifyStudent(Student* s, int* index, int stdNum);
void deleteStudent(Student* s, int* index, int stdNum);
void viewStudentList(Student* s, int* index);
void saveStudentList(Student* s, int* index);

static const char* fname = "C:\\temp\\studentList.txt";

static int index = 0;