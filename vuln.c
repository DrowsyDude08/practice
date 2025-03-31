#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void vuln() {
    char command[128];
    printf("Enter target: ");
    fgets(command, sizeof(command), stdin);
    command[strcspn(command, "\n")] = 0;

    char full_command[256];
    snprintf(full_command, sizeof(full_command), "ping -c 1 %s", command);
    printf("Executing: %s\n", full_command);
    system(full_command);
}

int main() {
    setbuf(stdout, NULL);
    // Проверка наличия переменной FLAG
    if (!getenv("FLAG")) {
        fprintf(stderr, "Error: FLAG environment variable is not set!\n");
        exit(1);
    }
    puts("Welcome to the command injection challenge!");
    vuln();
    return 0;
}