#include "func.h"

int main()
{
	int choice;
	int stdNum;

	printf("[�л��� ���� ���α׷�]\n");

	printf("�� ���� ������ �л��ο� �Է��Ͻðڽ��ϱ�? ");
	scanf_s("%d", &stdNum);

	Student* s = (Student*)malloc(sizeof(Student) * stdNum);

	puts("");

	while (1)
	{
		menu();
		printf("���� : ");
		scanf_s("%d", &choice);

		switch (choice)
		{
		case 1: addStudent(s, &index, stdNum); break; //�л� ���� �Է�
		case 2: modifyStudent(s, &index, stdNum); break; //�л� ���� ����
		case 3: deleteStudent(s, &index, stdNum); break; //�л� ���� ����
		case 4: viewStudentList(s, &index); break; //�л� ���� ��ȸ
		case 5: saveStudentList(s, &index); break; //�л��� ���Ͽ� ����
		case 6: //���α׷� ����
			printf("���α׷��� �����մϴ�.\n");
			return 0;
		default: printf("�޴��� ���� �׸��� �����ϼ̽��ϴ�. �ٽ� �������ּ���!\n"); break;
		}
	}

	free(s);

	return 0;
}