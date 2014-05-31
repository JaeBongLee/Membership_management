#include "management.h"

/*int deletePerson()
{
char num[12];
int select;
printf("達聖 俳持税 俳腰聖 脊径馬室推:");
scanf("%s", num);
for (int i = 0; i < n; i++)
{
if (strcmp(num, Person[i].personNum) == 0)
{
printf("俳 腰 : %s\n",Person[i].personNum);
printf("戚 硯 : %s\n",Person[i].personName);
printf("爽 社 : %s\n",Person[i].personAdress);
printf("穿鉢腰硲: %s\n", Person[i].phoneNum);

printf("戚 俳持税 舛左研 走酔獣畏柔艦猿?");
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
void askForMoreAct()
{
	int ask;

	printf("\n嬢恐 楳疑聖 蓄亜稽 馬叔闇亜推?(Yes : 1 or No : 0):");
	
	while (1)
	{
		fflush(stdin);
		scanf_s("%d", &ask);

		if (ask != 0 && ask != 1)
		{
			printf("設公吉 脊径脊艦陥. 陥獣 脊径馬室推.\n");
			printf("\n嬢恐 楳疑聖 蓄亜稽 馬叔闇亜推?(Yes : 1 or No : 0):");
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

	printf("噺据 腰硲: %d\n",Person[n-1].personNum + 1);
	Person[n].personNum = Person[n - 1].personNum + 1;

	printf("噺据 戚硯:");
	fflush(stdin);
	scanf("%s", &Person[n].personName);


	while (1)
	{
		printf("噺据 爽社:");
		fflush(stdin);
		scanf("%[^\n]s", &Person[n].personAdress);
		if (Person[n].personAdress[0] != '\0' && Person[n].personAdress[0] != 32)
			break;
		printf("Error! 莫縦拭 限走省澗 舛左研 脊径梅柔艦陥.\n");
	}
	
	while (1)
	{
			printf("噺据 輩球肉 腰硲:");
			fflush(stdin);
			scanf("%[^\n]", &Person[n].phoneNum);
			
			if (checkValidData(Person[n].phoneNum) == 1)
				break;
			
			printf("Error! 莫縦拭 限走省澗 舛左研 脊径梅柔艦陥 (xxx-xxxx-xxxx)莫縦生稽 脊径背 爽室推\n");
	}


	n++;
	askForMoreAct();

}

int saveFile()
{
	FILE *dataWrite = fopen(ADDRESS, "wt");
	int ask;
	for (int i = 0; i < n; i++){
		fputs(Person[i].personNum, dataWrite);
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

	printf("煽舌鞠醸柔艦陥.\n");
	askForMoreAct();


	return 0;
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

	printf("\n嬢恐 楳疑聖 蓄亜稽 馬叔闇亜推?(Yes : 1 or No : 0):");

	while (1)
	{
		fflush(stdin);
		scanf_s("%d", &ask);

		if (ask != 0 && ask != 1)
		{
			printf("設公吉 脊径脊艦陥. 陥獣 脊径馬室推.\n");
			printf("\n嬢恐 楳疑聖 蓄亜稽 馬叔闇亜推?(Yes : 1 or No : 0):");
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

void choiceAct()
{
	while (1)
	{

		int selectNum = 0;//固 坦製 鉢檎拭辞 嬢恐 楳疑聖 拝 依昔走 煽舌馬澗 痕呪

		system("cls");
		fflush(stdin);

		printf("\n\n嬢恐 楳疑聖 馬叔闇亜推?\n\n");
		printf("=============================================================================\n");
		printf("1.噺据 左奄\n");
		printf("2.噺据 去系馬奄\n");
		printf("3.噺据 肢薦馬奄\n");
		printf("4.噺据 呪舛馬奄\n");
		printf("5.煽舌馬奄\n");
		printf("6.噺据 伊事馬奄\n");
		printf("7.曽戟馬奄\n\n");
		printf("=============================================================================\n");
		printf("\n脊径:");




		while (1){// 森須坦軒
			scanf_s("%d", &selectNum);

			if (selectNum < 1 || selectNum >7){
				printf("設公吉 収切研 脊径馬写柔艦陥. 陥獣 脊径馬室推.\n");
				printf("\n脊径:");
			}
			else
				break;

		}
		if (selectNum == 1)
		{
			if (printFileData() == 1){
				system("cls");
				printf("\n覗稽益轡聖 曽戟杯艦陥.\n\n");
				break;
			}
		}
		else if (selectNum == 2)
		{
			if (addNewPerson() == 1){
				system("cls");
				printf("\n覗稽益轡聖 曽戟杯艦陥.\n\n");
				break;
			}
		}

		else if (selectNum == 5)
		{
			if (saveFile() == 1){
				system("cls");
				printf("\n覗稽益轡聖 曽戟杯艦陥.\n\n");
				break;
			}
		}
		else if (selectNum == 7)
		{
			system("cls");
			printf("\n覗稽益轡聖 曽戟杯艦陥.\n\n");
			break;
		}
	}

}

/*int cutArray(char *forCutArray, char *forSaveArray){
	/*chat莫生稽 煽舌鞠赤澗 舛左級聖 馬蟹馬蟹 差紫背 穿蝕痕呪稽 識情吉 person.~~~拭 朝杷馬奄 是背 幻窮 敗呪
	吐庚切蟹 鯵楳聖 幻蟹檎 鋼差聖 曽戟馬澗 覗稽益轡
	紫遂馬澗 敗呪 : uploadDataToMemory
	
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
fscnaf拭 企背辞 硝壱蟹辞 琶推蒸嬢遭 敗呪脊艦陥 ばばばばばばばばば

*/

void uploadDataToMemory()
{
	/*督析聖 伸嬢辞 益員拭 煽舌吉 舛左級聖 穿蝕生稽 識情吉 Person.~~拭 隔澗 敗呪*/
	FILE * dataRead = fopen(ADDRESS, "rt");
	int i = 0;
	if (dataRead == NULL)
	{
		puts("督析神蚤 叔鳶!");
		return -1;
	}
	
	fgets(userDataInfo, sizeof(userDataInfo), dataRead);// 湛匝拭 赤澗 廃越級聖 石嬢臣 凶澗 廃匝聖 乞砧 石嬢身
	//督析戚 魁劾凶猿走 0採斗 獣拙馬澗 Person[n].~~~拭 督析拭 赤澗 鎧遂聖 差紫,煽舌敗
	while (!feof(dataRead)){
		char tempBuf[BUFFER_SIZE];
		fscanf(dataRead, "%d", &Person[n].personNum);

		fscanf(dataRead, "%s", Person[n].personName);
		fgetc(dataRead);

		int j = 0;
		char ch;
		while ((ch = fgetc(dataRead)) != '\t' && ch != -1)
		{
			Person[n].personAdress[j++] = ch;
		}
		Person[n].personAdress[j] = '\0';

		fscanf(dataRead, "%s", Person[n].phoneNum);	

		n++;//鋼差聖 宜 凶原陥 n聖 装亜
	}n--;
	fclose(dataRead);
}
int main(void)
{
	uploadDataToMemory();
	choiceAct();
}

