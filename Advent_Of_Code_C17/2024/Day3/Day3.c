#include <ctype.h>
#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 8192
unsigned long long solution = 0;
int flag = 1;

void regex_state_machine(const char* line) {
    const char* prefix = "mul(";
    const char* enable = "do()";
    const char* disable = "don't()";

    size_t prefix_len = strlen(prefix);
    size_t enable_len = strlen(enable);
    size_t disable_len = strlen(disable);

    size_t line_len = strlen(line);

    for (size_t i = 0; i < line_len; i++) {
        if (strncmp(&line[i], enable, enable_len)==0) {flag = 1; continue;}

        if (strncmp(&line[i], disable, disable_len)==0) {flag = 0; continue;}

        if (flag && strncmp(&line[i], prefix, prefix_len) == 0) {
            //found a "mul("

            int n1 = 0,n2 = 0;
            size_t cursor = i + prefix_len;
            // cursor at first character after (

            //Accumulate the first integer.
            while (cursor < line_len && isdigit(line[cursor])) {
                n1 = n1 * 10 + line[cursor] - '0';
                cursor++;
            }

            //Check if the next character is a ',', else reject.
            if (cursor < line_len && line[cursor] == ',') cursor++;
            else { i = cursor-1 ; continue; }

            //Accumulate the second integer.
            while (cursor < line_len && isdigit(line[cursor])) {
                n2 = n2 * 10 + line[cursor] - '0';
                cursor++;
            }

            //Check if the last character is a ')', else reject.
            if (cursor < line_len && line[cursor] == ')') cursor++;
            else { i = cursor-1 ; continue; }

            const unsigned long long sol = n1*n2;

            printf("mul(");
            printf("%d", n1);
            printf("%c", ',');
            printf("%d", n2);
            printf("%s", ") = ");
            printf("%llu\n", sol);
            solution += sol;
            i = cursor-1;
        }


    }
}



int main() {
    FILE *file = fopen("Input.txt", "r");

    if (file == NULL) { perror("Error opening file"); return 2; }

    char line[MAX_LENGTH];
    while (fgets(line, sizeof(line), file) != NULL) {
        line[strcspn(line, "\n")] = '\0';
        regex_state_machine(line);
    }
    printf("%llu\n", solution);
    return 3;
}