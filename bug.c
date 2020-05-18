#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

enum STATUS
{
	IN_PROCESS,
	NOT_ASSIGNED,
	FIXED,
	DELIVERED
};

struct bug
{
	char type[10];
	char description[200];
	int status;
};
struct PW
{
	int uid;
	char name[20];
	struct bug bugreport;
};

void WriteFile()
{
	FILE *outfile;

	struct PW p;
	char name[20];
	char type[20];
	char description[200];
	enum STATUS status;
	int o;

	printf("WELCOME TO BUG BOUNTY, PLEASE REPORT YOUR BUG DETAILS\n");
	//assigns random id to the bug
	p.uid = rand();
	//accepts user name
	printf("Enter the Name of the user\n");

	scanf("%s", &name);
	// strtok(name, "\n");
	strcpy(p.name, name);
	// getchar();
	// accepts the type of bug
	printf("Enter the type of the Bug you want to report \n");
	fgets(type, sizeof(type), stdin);
	getchar();
	strcpy(p.bugreport.type, type);
	// description of the bug
	printf("Enter the description of the bug\n");
	fgets(description, sizeof(description), stdin);
	getchar();
	strcpy(p.bugreport.description, description);
	// status of the bug
	printf("Please select a status for the bug 1 IN_PROCESS, 2 NOT_ASSIGNED, 3 FIXED 4, DELIVERED\n");

	while (getchar() != '\n')
		scanf("%d", &o);

	// accepts the status of the bug
	switch (o)
	{
	case 1:
		p.bugreport.status = IN_PROCESS;
		break;
	case 2:
		p.bugreport.status = NOT_ASSIGNED;
		break;
	case 3:
		p.bugreport.status = FIXED;
	case 4:
		p.bugreport.status = DELIVERED;
		break;
	default:
		printf("Wrong input");
		break;
	}

	//Appends the contents to file
	outfile = fopen("bugs.txt", "a");
	fwrite(&p, sizeof(struct PW), 1, outfile);
	if (fwrite != 0)
		printf("BUG SUCCESSFULLY REPORTEDy !\n");
	else
		printf("OOPs, something went wrong!!\n");
	fclose(outfile);
}

// Read the contents from file
void readFile()
{
	FILE *inf;
	struct PW inp;
	inf = fopen("bugs.txt", "r");
	if (inf == NULL)
	{
		fprintf(stderr, "\nOOps something went wrong!\n");
		exit(1);
	}
	while (fread(&inp, sizeof(struct PW), 1, inf))
		printf("id: %d \n name: %s \n description: %s \n type: %s \n status: %d \n", inp.uid, inp.name, inp.bugreport.description, inp.bugreport.type, inp.bugreport.status);
	fclose(inf);
}

void main()
{
	printf("WELCOME TO BUG REPORTING PORTAL, PLEASE SELECT AN OPTION\n");
	printf("1: File a Bug Report\n");
	printf("2: View status of Bugs filed\n");

	//intialize random seed
	srand(time(NULL));

	int c;
	scanf("%d", &c);
	switch (c)
	{
	case 1:
		WriteFile();
		break;
	case 2:
		readFile();
		break;
	default:
		printf("Invalid choice. Please select one of the above options");
		break;
	}
}
