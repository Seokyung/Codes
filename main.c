#include "func.h"

int main()
{
	int choice;
	int stdNum;

	printf("[학생부 관리 프로그램]\n");

	printf("몇 명의 정보를 학생부에 입력하시겠습니까? ");
	scanf_s("%d", &stdNum);

	Student* s = (Student*)malloc(sizeof(Student) * stdNum);

	puts("");

	while (1)
	{
		menu();
		printf("선택 : ");
		scanf_s("%d", &choice);

		switch (choice)
		{
		case 1: addStudent(s, &index, stdNum); break; //학생 정보 입력
		case 2: modifyStudent(s, &index, stdNum); break; //학생 정보 수정
		case 3: deleteStudent(s, &index, stdNum); break; //학생 정보 삭제
		case 4: viewStudentList(s, &index); break; //학생 정보 조회
		case 5: saveStudentList(s, &index); break; //학생부 파일에 저장
		case 6: //프로그램 종료
			printf("프로그램을 종료합니다.\n");
			return 0;
		default: printf("메뉴에 없는 항목을 선택하셨습니다. 다시 선택해주세요!\n"); break;
		}
	}

	free(s);

	return 0;
}