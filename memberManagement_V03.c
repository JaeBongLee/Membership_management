#include "management.h"

/*int deletePerson()
{
char num[12];
int select;
printf("ã�� �л��� �й��� �Է��ϼ���:");
scanf("%s", num);
for (int i = 0; i < n; i++)
{
if (strcmp(num, Person[i].personNum) == 0)
{
printf("�� �� : %s\n",Person[i].personNum);
printf("�� �� : %s\n",Person[i].personName);
printf("�� �� : %s\n",Person[i].personAdress);
printf("��ȭ��ȣ: %s\n", Person[i].phoneNum);

printf("�� �л��� ������ ����ðڽ��ϱ�?");
printf("(YES : 1 NO :0):");
scanf("%d", &select);

if (select == 1)
{
for (int j = i; i < n; j++)
{
Person[i].personAdress = Person[i + 1].personAdress;
}
}
}
}
}*/
int askForMoreAct()
{
	int ask;

	printf("\n� �ൿ�� �߰��� �Ͻǰǰ���?(Yes : 1 or No : 0):");
	
	while (1)
	{
		fflush(stdin);
		scanf_s("%d", &ask);

		if (ask != 0 && ask != 1)
		{
			printf("�߸��� �Է��Դϴ�. �ٽ� �Է��ϼ���.\n");
			printf("\n� �ൿ�� �߰��� �Ͻǰǰ���?(Yes : 1 or No : 0):");
		}
		else if (ask == 1){
			return 0;
		}
		else if (ask == 0)
		{
			return 1;
		}
	}
}

int checkValidData(char * list)
{
	int i;
	int length = strlen(list);
	if (length == 0)
	{
		return 0;
	}
	if (length > MAX_PHONENUM)
	{
		return 0;
	}
	for (i=0; i < length;i++)
	{
		if (!(('0' <= Person[n].phoneNum[i] && Person[n].phoneNum[i] <= '9') || Person[n].phoneNum[i] == '-'))
			return 0;
	}
	return 1;
}

int addNewPerson()
{
	system("cls");
	printf("=============================================================================\n");

	printf("ȸ�� ��ȣ: %d\n",checkStudentNumMax() + 1);
	Person[n].personNum = checkStudentNumMax() + 1;

	printf("ȸ�� �̸�:");
	fflush(stdin);
	scanf("%s", &Person[n].personName);


	while (1)
	{
		printf("ȸ�� �ּ�:");
		fflush(stdin);
		scanf("%[^\n]s", &Person[n].personAdress);
		if (Person[n].personAdress[0] != '\0' && Person[n].personAdress[0] != 32)
			break;
		printf("Error! ���Ŀ� �����ʴ� ������ �Է��߽��ϴ�.\n");
	}
	
	while (1)
	{
			printf("ȸ�� �ڵ��� ��ȣ:");
			fflush(stdin);
			scanf("%[^\n]", &Person[n].phoneNum);
			
			if (checkValidData(Person[n].phoneNum) == 1)
				break;
			
			printf("Error! ���Ŀ� �����ʴ� ������ �Է��߽��ϴ� (xxx-xxxx-xxxx)�������� �Է��� �ּ���\n");
	}


	n++;
	return askForMoreAct();

}

int saveFile()
{
	FILE *dataWrite = fopen(ADDRESS, "wt");
	int ask;
	fputs(userDataInfo, dataWrite);
	for (int i = 0; i < n; i++){
		
		fprintf(dataWrite,"%d", Person[i].personNum);
		fputs("\t", dataWrite);
		fputs(Person[i].personName, dataWrite);
		fputs("\t", dataWrite);
		fputs(Person[i].personAdress, dataWrite);
		fputs("\t", dataWrite);
		fputs(Person[i].phoneNum, dataWrite);
		fputs("\n", dataWrite);
	}

	fclose(dataWrite);
	system("cls");

	printf("����Ǿ����ϴ�.\n");
	


	return askForMoreAct();
}

int printFileData()
{

	int i;

	int ask;

	system("cls");

	printf("%s", userDataInfo);
	for (i = 0; i < n; i++)
	{
		printf("%d\t", Person[i].personNum);
		printf("%s\t", Person[i].personName);
		printf("%s\t", Person[i].personAdress);
		printf("%s\n", Person[i].phoneNum);
	}

	printf("\n� �ൿ�� �߰��� �Ͻǰǰ���?(Yes : 1 or No : 0):");

	while (1)
	{
		fflush(stdin);
		scanf_s("%d", &ask);

		if (ask != 0 && ask != 1)
		{
			printf("�߸��� �Է��Դϴ�. �ٽ� �Է��ϼ���.\n");
			printf("\n� �ൿ�� �߰��� �Ͻǰǰ���?(Yes : 1 or No : 0):");
		}
		else if (ask == 1){
			return 0;
		}
		else if (ask == 0)
		{
			return 1;
		}
	}

}

int checkStudentNumMax()
{
	int max = Person[0].personNum;

	for (int i = 0; i < n; i++)
	{
		if (max < Person[i].personNum)
			max = Person[i].personNum;
	}
	return max;
}

int searchPerson()
{
	int choiceNum;
	int personNum;
	int count = 0;
	char personName[MAX_PERSONNAME];
	char phoneNum[MAX_PHONENUM];
	int i;

	printf("=============================================================================\n");
	printf("� ������ �л��� ã�� ���ΰ���?\n\n");
	printf("1.�й�\n 2.�л� �̸�\n 3.��ȭ��ȣ\n");
	
	while (1)
	{
		printf("�Է�:");
		fflush(stdin);
		scanf("%d", &choiceNum);
		if (choiceNum != 1 && choiceNum != 2 && choiceNum != 3 )
			printf("�߸��� �Է��Դϴ�.");
		else
			break;
	}

	if (choiceNum == 1)
	{
		printf("ã�� �л��� �й��� �Է��ϼ���:");
		fflush(stdin);
		scanf("%d", &personNum);

		for (i = 0; i < n; i++)
		{
			if (personNum == Person[i].personNum)
			{
				printf("%d:", personNum);
				printf("%s\t", Person[i].personName);
				printf("%s\t", Person[i].personAdress);
				printf("%s\n", Person[i].phoneNum);
				break;
				
			}
		}
		if (i == n && personNum != Person[i-1].personNum )
			printf("ã���ô� �й��� �л��� ���ų� �߸��� �Է��Դϴ�.\n");
		
	}
	if (choiceNum == 2)
	{
		printf("ã���ô� �л��� �̸��� �Է��ϼ���:");
		fflush(stdin);
		scanf("%s", &personName);
		for (i = 0; i < n; i++)
		{
			if (strcmp(Person[i].personName, personName) == 0)
			{
				printf("%d:", Person[i].personNum);
				printf("%s\t", Person[i].personName);
				printf("%s\t", Person[i].personAdress);
				printf("%s\n", Person[i].phoneNum);
				count++;

			}
		}
		if (i == n && count == 0)
			printf("ã���ô� �й��� �л��� ���ų� �߸��� �Է��Դϴ�.\n");
	}
	if (choiceNum == 3)
	{
		printf("ã���ô� �л��� ��ȭ��ȣ�� �Է��ϼ���:");
		fflush(stdin);
		scanf("%s", &phoneNum);
		for (i = 0; i < n; i++)
		{
			if (strcmp(Person[i].phoneNum, phoneNum) == 0)
			{
				printf("%d:", Person[i].personNum);
				printf("%s\t", Person[i].personName);
				printf("%s\t", Person[i].personAdress);
				printf("%s\n", Person[i].phoneNum);
				count++;

			}
		}
		if (i == n && count == 0)
			printf("ã���ô� �й��� �л��� ���ų� �߸��� �Է��Դϴ�.\n");
	}
	return askForMoreAct();
}

void deleteData(int i)
{
	int deleteNum;
	
	while (1)
	{
		printf("�����Ͻðڽ��ϱ�?(yes : 1, no : 0)");
		fflush(stdin);
		scanf("%d", &deleteNum);
		if (deleteNum != 1 && deleteNum != 0)
			printf("�߸��� �Է��Դϴ�");

		else
			break;
	}

	if (deleteNum == 1)
	{
		for (int j = i; j < n; j++)
		{
			Person[j] = Person[j+1];
		}
		n--;
	}

}

int deletePerson()
{
	int choiceNum;
	int personNum;
	int count = 0;
	char personName[MAX_PERSONNAME];
	char phoneNum[MAX_PHONENUM];
	int i;

	printf("=============================================================================\n");
	printf("� ������ �л��� ã�� ���ΰ���?\n\n");
	printf("1.�й�\n 2.�л� �̸�\n 3.��ȭ��ȣ\n");

	while (1)
	{
		printf("�Է�:");
		fflush(stdin);
		scanf("%d", &choiceNum);
		if (choiceNum != 1 && choiceNum != 2 && choiceNum != 3)
			printf("�߸��� �Է��Դϴ�.");
		else
			break;
	}

	if (choiceNum == 1)
	{
		printf("ã�� �л��� �й��� �Է��ϼ���:");
		fflush(stdin);
		scanf("%d", &personNum);

		for (i = 0; i < n; i++)
		{
			if (personNum == Person[i].personNum)
			{
				
				printf("%d:", personNum);
				printf("%s\t", Person[i].personName);
				printf("%s\t", Person[i].personAdress);
				printf("%s\n", Person[i].phoneNum);
				deleteData(i);
				
				
				break;

			}
		}
		if (i == n && personNum != Person[i - 1].personNum)
			printf("ã���ô� �й��� �л��� ���ų� �߸��� �Է��Դϴ�.\n");

	}
	if (choiceNum == 2)
	{
		printf("ã���ô� �л��� �̸��� �Է��ϼ���:");
		fflush(stdin);
		scanf("%s", &personName);
		for (i = 0; i < n; i++)
		{
			if (strcmp(Person[i].personName, personName) == 0)
			{
				printf("%d:", Person[i].personNum);
				printf("%s\t", Person[i].personName);
				printf("%s\t", Person[i].personAdress);
				printf("%s\n", Person[i].phoneNum);
				deleteData(i);
				count++;

			}
		}
		if (i == n && count == 0)
			printf("ã���ô� �й��� �л��� ���ų� �߸��� �Է��Դϴ�.\n");
	}
	if (choiceNum == 3)
	{
		printf("ã���ô� �л��� ��ȭ��ȣ�� �Է��ϼ���:");
		fflush(stdin);
		scanf("%s", &phoneNum);
		for (i = 0; i < n; i++)
		{
			if (strcmp(Person[i].phoneNum, phoneNum) == 0)
			{
				printf("%d:", Person[i].personNum);
				printf("%s\t", Person[i].personName);
				printf("%s\t", Person[i].personAdress);
				printf("%s\n", Person[i].phoneNum);
				deleteData(i);
				count++;

			}
		}
		if (i == n && count == 0)
			printf("ã���ô� �й��� �л��� ���ų� �߸��� �Է��Դϴ�.\n");
	}
	return askForMoreAct();
}

void rewirteData(int i)
{
	int selectNum;
	printf("=============================================================================\n");
	printf("�� �л��� � ������ �����Ͻ� �ǰ���?\n");
	printf("1.���\n 2.�л��̸�\n3.�ּ�\n4.��ȭ��ȣ\n");

	while (1)
	{
		printf("�Է�:");
		fflush(stdin);
		scanf("%d", &selectNum);
		if (selectNum != 1 && selectNum != 2 && selectNum != 3 && selectNum != 4)
			printf("�߸��� �Է��Դϴ�.\n");
		else
			break;
	}

	if (selectNum == 1)
	{
		return;
	}
	else if (selectNum == 2)
	{
		printf("���� �� �̸�:");
		fflush(stdin);
		scanf("%s", &Person[i].personName);
	}
	else if (selectNum == 3)
	{
		while (1)
		{
			printf("ȸ�� �ּ�:");
			fflush(stdin);
			scanf("%[^\n]s", &Person[i].personAdress);
			if (Person[i].personAdress[0] != '\0' && Person[i].personAdress[0] != 32)
				break;
			printf("Error! ���Ŀ� �����ʴ� ������ �Է��߽��ϴ�.\n");
		}

	}
	else if (selectNum == 4)
	{
		while (1)
		{
			printf("���� �� ȸ�� �ڵ��� ��ȣ:");
			fflush(stdin);
			scanf("%[^\n]", &Person[i].phoneNum);

			if (checkValidData(Person[i].phoneNum) == 1)
				break;

			printf("Error! ���Ŀ� �����ʴ� ������ �Է��߽��ϴ� (xxx-xxxx-xxxx)�������� �Է��� �ּ���\n");
		}

	}
}

int rewritePerson()
{
	int choiceNum;
	int personNum;
	int count = 0;
	char personName[MAX_PERSONNAME];
	char phoneNum[MAX_PHONENUM];
	int i;

	printf("=============================================================================\n");
	printf("� ������ �л��� ã�� ���ΰ���?\n\n");
	printf("1.�й�\n 2.�л� �̸�\n 3.��ȭ��ȣ\n");

	while (1)
	{
		printf("�Է�:");
		fflush(stdin);
		scanf("%d", &choiceNum);
		if (choiceNum != 1 && choiceNum != 2 && choiceNum != 3)
			printf("�߸��� �Է��Դϴ�.\n");
		else
			break;
	}

	if (choiceNum == 1)
	{
		printf("ã�� �л��� �й��� �Է��ϼ���:");
		fflush(stdin);
		scanf("%d", &personNum);

		for (i = 0; i < n; i++)
		{
			if (personNum == Person[i].personNum)
			{
				int selectNum;
				printf("%d:", personNum);
				printf("%s\t", Person[i].personName);
				printf("%s\t", Person[i].personAdress);
				printf("%s\n", Person[i].phoneNum);
				rewirteData(i);
				
				break;

			}
		}
		if (i == n && personNum != Person[i-1].personNum)
			printf("ã���ô� �й��� �л��� ���ų� �߸��� �Է��Դϴ�.\n");

	}
	if (choiceNum == 2)
	{
		printf("ã���ô� �л��� �̸��� �Է��ϼ���:");
		fflush(stdin);
		scanf("%s", &personName);
		for (i = 0; i < n; i++)
		{
			if (strcmp(Person[i].personName, personName) == 0)
			{
				int selectNum;
				printf("%d:", Person[i].personNum);
				printf("%s\t", Person[i].personName);
				printf("%s\t", Person[i].personAdress);
				printf("%s\n", Person[i].phoneNum);
				rewirteData(i);
				count++;

			}
		}
		if (i == n && count == 0)
			printf("ã���ô� �й��� �л��� ���ų� �߸��� �Է��Դϴ�.\n");
	}
	if (choiceNum == 3)
	{
		printf("ã���ô� �л��� ��ȭ��ȣ�� �Է��ϼ���:");
		fflush(stdin);
		scanf("%s", &phoneNum);
		for (i = 0; i < n; i++)
		{
			if (strcmp(Person[i].phoneNum, phoneNum) == 0)
			{
				printf("%d:", Person[i].personNum);
				printf("%s\t", Person[i].personName);
				printf("%s\t", Person[i].personAdress);
				printf("%s\n", Person[i].phoneNum);
				rewirteData(i);
				count++;

			}
		}
		if (i == n && count == 0)
			printf("ã���ô� �й��� �л��� ���ų� �߸��� �Է��Դϴ�.\n");
	}


	return askForMoreAct();
}

void choiceAct()
{
	while (1)
	{

		int selectNum = 0;//�� ó�� ȭ�鿡�� � �ൿ�� �� ������ �����ϴ� ����

		system("cls");
		fflush(stdin);

		printf("\n\n� �ൿ�� �Ͻǰǰ���?\n\n");
		printf("=============================================================================\n");
		printf("1.ȸ�� ����\n");
		printf("2.ȸ�� ����ϱ�\n");
		printf("3.ȸ�� �����ϱ�\n");
		printf("4.ȸ�� �����ϱ�\n");
		printf("5.�����ϱ�\n");
		printf("6.ȸ�� �˻��ϱ�\n");
		printf("7.�����ϱ�\n\n");
		printf("=============================================================================\n");
		printf("\n�Է�:");




		while (1){// ����ó��
			scanf_s("%d", &selectNum);

			if (selectNum < 1 || selectNum >7){
				printf("�߸��� ���ڸ� �Է��ϼ̽��ϴ�. �ٽ� �Է��ϼ���.\n");
				printf("\n�Է�:");
			}
			else
				break;

		}
		if (selectNum == 1)
		{
			if (printFileData() == 1){
				system("cls");
				printf("\n���α׷��� �����մϴ�.\n\n");
				break;
			}
		}
		else if (selectNum == 2)
		{
			if (addNewPerson() == 1){
				system("cls");
				printf("\n���α׷��� �����մϴ�.\n\n");
				break;
			}
		}

		else if (selectNum == 3)
		{
			system("cls");
			if (deletePerson() == 1){
				system("cls");
				printf("\n���α׷��� �����մϴ�.\n\n");
				break;
			}
		}

		else if (selectNum == 4)
		{
			system("cls");
			if (rewritePerson() == 1){
				system("cls");
				printf("\n���α׷��� �����մϴ�.\n\n");
				break;
			}
		}

		else if (selectNum == 5)
		{
			if (saveFile() == 1){
				system("cls");
				printf("\n���α׷��� �����մϴ�.\n\n");
				break;
			}
		}
		else if (selectNum == 6)
		{
			system("cls");
			if (searchPerson() == 1){
				system("cls");
				printf("\n���α׷��� �����մϴ�.\n\n");
				break;
			}
		}

		else if (selectNum == 7)
		{
			system("cls");
			printf("\n���α׷��� �����մϴ�.\n\n");
			break;
		}
	}

}

/*int cutArray(char *forCutArray, char *forSaveArray){
	/*chat������ ������ִ� �������� �ϳ��ϳ� ������ ���������� ����� person.~~~�� ī���ϱ� ���� ���� �Լ�
	�ǹ��ڳ� ������ ������ �ݺ��� �����ϴ� ���α׷�
	����ϴ� �Լ� : uploadDataToMemory
	
	int i;
	for (i = 0; i < BUFFER_SIZE; i++)
	{
		if (forCutArray[i] == '\t' || forCutArray[i] == '\n')
		{
			break;
		}
		forSaveArray[i] = forCutArray[i];
	}

	return i + 1;
}
fscnaf�� ���ؼ� �˰��� �ʿ������ �Լ��Դϴ� �ФФФФФФФФ�

*/

void uploadDataToMemory()
{
	/*������ ��� �װ��� ����� �������� �������� ����� Person.~~�� �ִ� �Լ�*/
	FILE * dataRead = fopen(ADDRESS, "rt");
	int i = 0;
	
	if (dataRead == NULL)
	{
		puts("���Ͽ��� ����!");
		return -1;
	}
	
	fgets(userDataInfo, sizeof(userDataInfo), dataRead);// ù�ٿ� �ִ� �ѱ۵��� �о�� ���� ������ ��� �о��
	//������ ���������� 0���� �����ϴ� Person[n].~~~�� ���Ͽ� �ִ� ������ ����,������
	while (!feof(dataRead)){
		int j = 0;
		char ch;
		char tempBuf[BUFFER_SIZE];
		fscanf(dataRead, "%d", &Person[n].personNum);

		fscanf(dataRead, "%s", Person[n].personName);
		fgetc(dataRead);

		
		while ((ch = fgetc(dataRead)) != '\t' && ch != -1)
		{
			Person[n].personAdress[j++] = ch;
		}
		Person[n].personAdress[j] = '\0';

		fscanf(dataRead, "%s", Person[n].phoneNum);	

		n++;//�ݺ��� �� ������ n�� ����
	}n--;
	fclose(dataRead);
}
int main(void)
{
	uploadDataToMemory();
	choiceAct();
}

