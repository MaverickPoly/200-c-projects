#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <dirent.h>
#include <limits.h>

#define MAX_CMD_LEN 256
#define MAX_ARGS 10

void parseInput(char *input, char **args)
{
    int i = 0;
    args[i] = strtok(input, " \n");
    while (args[i] != NULL && i < MAX_ARGS - 1)
    {
        args[++i] = strtok(NULL, " \n");
    }
    args[i] = NULL;
}

void run_cd(char **args)
{
    if (args[1] == NULL)
    {
        printf("cd: missing argument\n");
        return;
    }

    if (chdir(args[1]) != 0)
    {
        perror("cd failed");
    }
}

void run_ls()
{
    char cwd[PATH_MAX];
    if (getcwd(cwd, sizeof(cwd)) == NULL)
    {
        perror("getcwd failed");
        return;
    }

    DIR *dir = opendir(cwd);
    if (dir == NULL)
    {
        perror("opendir failed!");
        return;
    }

    struct dirent *entry;
    while ((entry = readdir(dir)) != NULL)
    {
        // Skip . and ..
        if (strcmp(entry->d_name, ".") && strcmp(entry->d_name, ".."))
        {
            printf("--- %s \n", entry->d_name);
        }
    }
    printf("\n");
    closedir(dir);
}

int main()
{
    char input[MAX_CMD_LEN];
    char *args[MAX_ARGS];

    printf("==== Mini Shell: \n\n");

    while (1)
    {
        char cwd[PATH_MAX];
        getcwd(cwd, sizeof(cwd));
        printf("%s> ", cwd);
        fflush(stdout);

        if (!fgets(input, sizeof(input), stdin))
            break;

        parseInput(input, args);

        if (args[0] == NULL)
            continue;

        if (strcmp(args[0], "exit") == 0)
            break;
        else if (strcmp(args[0], "cd") == 0)
            run_cd(args);
        else if (strcmp(args[0], "ls") == 0)
            run_ls();
        else
            printf("Unsupported command: %s\n", args[0]);
    }

    printf("Exiting shell...\n");
    return 0;
}