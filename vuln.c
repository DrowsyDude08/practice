#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void vuln() {
    char command[128];
    printf("Enter target: ");
    fgets(command, sizeof(command), stdin);
    command[strcspn(command, "\n")] = 0; // Убираем перевод строки
    
    char full_command[256];
    snprintf(full_command, sizeof(full_command), "ping -c 1 %s", command);
    printf("Executing: %s\n", full_command);
    system(full_command); // Уязвимость: командная инъекция
}

int main() {
    setbuf(stdout, NULL);
    puts("Welcome to the command injection challenge!");
    vuln();
    return 0;
}