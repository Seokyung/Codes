#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//학생 정보 구조체 선언
typedef struct
{
	//학생부에는 학생의 이름, 학번, 과, 전화번호 정보가 있음
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