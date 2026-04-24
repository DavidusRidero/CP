#include<stdio.h>
#include <stdlib.h>
#include <string.h>

char *source = "Input.txt";
const char pattern[] = "XMAS";
size_t p_length = strlen(pattern);

#define MIN(a,b) (((a) < (b)) ? (a) : (b))
#define MAX(a,b) (((a) > (b)) ? (a) : (b))

char** array;
size_t edge = 0;

void initialize() {
    array = malloc(edge * sizeof(int*));
    for (int i = 0; i < edge; i++)
        array[i] = malloc(edge * sizeof(int));
}

void ingest() {
    FILE *file = fopen(source, "r");
    if (file == NULL) perror("Error opening file");

    char line[8192];
    fgets(line, sizeof(line), file);
    line[strcspn(line, "\n")] = '\0';
    edge = strlen(line);

    initialize();
    memcpy(array[0], line, edge);

    int i = 1;
    while (fgets(line, sizeof(line), file)) {
        line[strcspn(line, "\n")] = '\0';
        memcpy(array[i++], line, edge);
    }
    fclose(file);
}

//Returns the A[i,j]th element, and -1 if out of bounds.
char retrieve(const int i,const int j) {
    if ( i < 0 || i>=edge || j < 0 || j>=edge ) return '0';
    return array[i][j];
}

int shoot(const int i, const int j, const int x_offset, const int y_offset) {

    //Check if offset-walk results in the pattern.
    char word[p_length+1];
    int c_x = i, c_y = j;

    for (int a = 0; a<p_length; a++, c_x += x_offset, c_y += y_offset)
        word[a] = retrieve(c_x,c_y);

    word[p_length] = '\0';

    //Return 1 if yes, else obfuscate and return 0.
    if (strcmp(word, pattern) == 0) return 1;

    // c_x = i, c_y = j;
    // for (int a = 0; a<p_length; a++, c_x += x_offset, c_y += y_offset)
    //     obfuscate(c_x,c_y);

    return 0;
}

int eight_fold_path(const int i, const int j) {

    //Invoke Shoot() for all permutations of offset, ignoring (0,0).
    int accumulator = 0;

    for (int x_offset = -1; x_offset <= 1; x_offset++)
        for (int y_offset = -1; y_offset <= 1; y_offset++) {
            if (x_offset == 0 && y_offset == 0) continue;
            accumulator += shoot(i,j,x_offset,y_offset);
        }

    //Return how many valid patterns originating from A[i,j].
    return accumulator;
}

int search() {
    printf("Search invoked.\n");
    //Iterate through all elements.
    //Invoke Eight-Fold Path when X encountered.
    int solution = 0;

    for (int i = 0; i < edge; i++)
        for (int j = 0; j < edge; j++)
            if (array[i][j] == pattern[0])
                solution += eight_fold_path(i,j);

    //Return the final solution.
    return solution;
}

int xpath(const int i, const int j) {
    int accumulator = 0;

    //We know M exists at A[i,j]. Check for accompanying M at +/-2 positions.
    if ()
}

int xsearch() {
    printf("Search invoked.\n");
    int solution = 0;

    for (int i = 0; i < edge; i++)
        for (int j = 0; j < edge; j++)
            if (array[i][j] == 'M')
                solution += xpath(i,j);

    return solution;
}

void print() {
    printf("Print invoked.\n");

    for (size_t i = 0; i < edge; i++) {
        for (size_t j = 0; j < edge; j++)
            printf("%c ", array[i][j]);
        printf("\n");
    }
}

int main() {
    ingest();
    printf("Ingestion done.\n");

    //print();
    printf("Printing done.\n");

    // const int solution = search();
    const int solution = xsearch();
    printf("Solution = %d\n", solution);
}