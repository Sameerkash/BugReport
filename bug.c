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

//helperfucntion to take input from the tereminal, handles memeory allocation dynamically so no need to assign any memory just pass the pointer
int get_line(char **line)
{
	int c, len = 0, maxlen = 1;

	*line = malloc((len + 1) * sizeof **line);

	while ((c = getchar()) && c != '\n' && c != EOF)
	{
		if (len == maxlen)
		{
			maxlen *= 2;
			*line = realloc(*line, maxlen * sizeof **line);
		}
		(*line)[len++] = c;
	}

	if (len != 0)
		*line = realloc(*line, len * sizeof *line);

	/* removes the new line, if present */
	if ((*line)[len] == '\n' && len != 0)
		--len;
	(*line)[len] = '\0';

	return len;
}

void WriteFile()
{
	FILE *outfile;

	struct PW p;
	char *name;
	char *type;
	char *description;
	enum STATUS status;
	int o;

	printf("WELCOME TO BUG BOUNTY, PLEASE REPORT YOUR BUG DETAILS\n");
	//assigns random id to the bug
	p.uid = rand();
	//accepts user name

	printf("Enter the Name of the user\n");
	get_line(&name);
	strcpy(p.name, name);

	// accepts the type of bug

	printf("Enter the type of the Bug you want to report \n");
	get_line(&type);
	strcpy(p.bugreport.type, type);
	// description of the bug

	printf("Enter the description of the bug\n");
	get_line(&description);
	strcpy(p.bugreport.description, description);

	// status of the bug
	printf("Please select a status for the bug 1 IN_PROCESS, 2 NOT_ASSIGNED, 3 FIXED 4, DELIVERED\n");
	// getchar();
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
		printf("BUG SUCCESSFULLY REPORTED!\n");
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
		printf("id: %d \t name: %s \t description: %s \t type: %s \t status: %d \n", inp.uid, inp.name, inp.bugreport.description, inp.bugreport.type, inp.bugreport.status);
	fclose(inf);
}

int main()
{
	printf("WELCOME TO BUG REPORTING PORTAL, PLEASE SELECT AN OPTION\n");
	printf("1: File a Bug Report\n");
	printf("2: View status of Bugs filed\n");

	//intialize random seed
	srand(time(NULL));

	int c;
	scanf("%d", &c);
	getchar(); // eat the \n after reading c
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

	printf("\nWanna file another bug ? (Y/N): ");
	char ch;
	getchar(); // eat up the \n in buffer
	scanf("%c", &ch);
	getchar(); // eat the \n after reading the char
	if (ch == 'Y' || ch == 'y')
		WriteFile();
	else
		main();

	return 0;
}