//함수들의 정의가 담겨있는 c 파일
#include "func.h"

//메뉴 출력 함수
void menu()
{
	printf("--------MENU--------\n");
	printf("1. 학생 정보 입력\n");
	printf("2. 학생 정보 수정\n");
	printf("3. 학생 정보 삭제\n");
	printf("4. 학생 정보 모두 조회\n");
	printf("5. 현재 학생부 파일에 저장\n");
	printf("6. 프로그램 종료\n");
	printf("--------------------\n");
}

//학생 정보 추가하는 함수
void addStudent(Student* s, int* index, int stdNum)
{
	if (*index >= stdNum)
	{
		puts("학생부에 저장할 수 있는 정보의 양이 초과되었습니다.");
		puts("학생 정보를 더 추가하려면 메뉴에서 4를 선택해 기존에 있던 정보를 삭제해주세요!");
		return 0;
	}

	puts("학생부에 추가할 학생 정보를 입력합니다.");

	printf("학생 이름 입력 : ");
	scanf_s("%s", s[*index].name, 15);

	printf("학생 학번 입력 : ");
	scanf_s("%s", s[*index].id, 10);

	printf("학생 학과 입력 : ");
	scanf_s("%s", s[*index].depart, 20);

	printf("학생 전화번호 입력 : ");
	scanf_s("%s", s[*index].tel, 20);

	(*index)++;
}

//학생부 안의 학생 정보 수정하는 함수 (이름으로 학생 찾음)
void modifyStudent(Student* s, int* index, int stdNum)
{
	int i, j;

	char name[15];

	if (*index == 0)
	{
		printf("학생부에 입력되어 있는 학생 정보가 존재하지 않습니다.\n");
		printf("메뉴에서 2를 선택하여 학생 정보를 추가하세요!\n");
		return 0;
	}

	printf("정보를 수정하고자 하는 학생의 이름을 입력하세요 : ");
	scanf_s("%s", name, 15);

	for (i = 0; i < stdNum; i++)
	{
		if (strcmp(name, s[i].name) == 0)
		{
			printf("%s 학생의 정보 수정\n", s[i].name);
			
			printf("이름 : ");
			scanf_s("%s", s[i].name, 15);

			printf("학번 : ");
			scanf_s("%s", s[i].id, 10);

			printf("학과 : ");
			scanf_s("%s", s[i].depart, 20);

			printf("전화번호 : ");
			scanf_s("%s", s[i].tel, 20);

			return 0;
		}
	}

	puts("수정하려는 학생 정보가 존재하지 않습니다!");
}

//학생부 안의 학생 정보 삭제하는 함수 (이름으로 학생 찾음)
void deleteStudent(Student* s, int* index, int stdNum)
{
	int i, j;
	
	char name[15];

	if (*index == 0)
	{
		printf("학생부에 입력되어 있는 학생 정보가 존재하지 않습니다.\n");
		printf("메뉴에서 2를 선택하여 학생 정보를 추가하세요!\n");
		return 0;
	}
	
	printf("정보를 삭제하고자 하는 학생의 이름을 입력하세요 : ");
	scanf_s("%s", name, 15);

	for (i = 0; i < stdNum; i++)
	{
		if (strcmp(name, s[i].name) == 0)
		{
			(*index)--;

			printf("%s 학생의 정보 삭제\n", s[i].name);

			//학생부 구조체 배열이 꽉 차지 않았다면
			if (i != stdNum - 1)
			{
				//학생부 구조체 배열의 빈 공간을 메움
				for (j = i; j < stdNum; j++)
				{
					strcpy(s[j].name, s[j + 1].name);
					strcpy(s[j].id, s[j + 1].id);
					strcpy(s[j].depart, s[j + 1].depart);
					strcpy(s[j].tel, s[j + 1].tel);
				}

				//학생부 구조체 배열의 마지막에 NULL 삽입
				*s[stdNum - 1].name = NULL;
				*s[stdNum - 1].id = NULL;
				*s[stdNum - 1].depart = NULL;
				*s[stdNum - 1].tel = NULL;
			}
			//학생부 구조체 배열이 꽉 찼다면
			else
			{
				//학생부 구조체 배열의 마지막에 NULL 삽입
				*s[stdNum - 1].name = NULL;
				*s[stdNum - 1].id = NULL;
				*s[stdNum - 1].depart = NULL;
				*s[stdNum - 1].tel = NULL;
			}

			return 0;
		}
	}

	puts("삭제하려는 학생 정보가 존재하지 않습니다!");
}

//학생부 안의 모든 학생 정보 출력하는 함수
void viewStudentList(Student* s, int* index)
{
	int i;

	if (*index == 0)
	{
		puts("학생부에 입력되어 있는 학생 정보가 존재하지 않습니다.");
		puts("메뉴에서 2를 선택하여 학생 정보를 추가하세요!");
		return 0;
	}

	puts("학생부에 있는 모든 학생들의 정보를 조회합니다.\n");

	for (i = 0; i < *index; i++)
	{
		printf("[%d] 이름 : %s\n", i + 1, s[i].name);
		printf("    학번 : %s\n", s[i].id);
		printf("    학과 : %s\n", s[i].depart);
		printf("    전화번호 : %s\n\n", s[i].tel);
	}
}

//학생 정보 학생부 파일에 저장하는 함수
void saveStudentList(Student* s, int* index)
{
	int i, state;

	if (*index == 0)
	{
		puts("학생부에 입력되어 있는 학생 정보가 존재하지 않습니다.");
		puts("메뉴에서 2를 선택하여 학생 정보를 추가하세요!");
		return 0;
	}

	FILE* wfp = fopen(fname, "wt");
	if (wfp == NULL)
	{
		puts("파일을 여는 중 오류가 발생했습니다!");
		return 1;
	}

	fputs("학생부 (이름, 학번, 학과, 전화번호)\n\n", wfp);
	for (i = 0; i < *index; i++)
	{
		fprintf(wfp, "%s\t%s\t%s\t%s\n", s[i].name, s[i].id, s[i].depart, s[i].tel);
	}

	state = fclose(wfp);
	if (state != 0)
	{
		puts("파일을 닫는 중 오류가 발생했습니다!");
		return 1;
	}

	puts("현재 학생부 파일에 저장됨");
	puts("경로 : C:\Temp\studentList.txt");
}