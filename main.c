#include <stdio.h>
#include <string.h>
#include "Uni_Words.h"
#include "cities.h"

int main(int argc, char* argv[]) {
//-------------------------------------------------------------------------------------------------
//для запуска gcc -o wordcount main.c и /wordcount input.txt
 /*   if (argc < 2) {
        printf("Usage: ./wordcount filename [-o ASC/DESC]\n");
        return 1;
    }

    char* filename = argv[1];
    char* order = "ASC"; // значение по умолчанию

    if (argc >= 4) {
        if (strcmp(argv[2], "-o") == 0) {
            order = argv[3];
        }
    }

    FILE* file = fopen("C:\\Users\\reeds\\CLionProjects\\Sem10\\input.txt", "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    struct Tree* root = NULL;
    char word[100];

    while (fscanf(file, "%s", word) == 1) { // читаем из файла и вставляем в дерево
        root = insertNode(root, word);
    }

    fclose(file);

    if (strcmp(order, "DESC") == 0) {  // выводим в указанном порядке
        reverse(root);
    } else {
        inorder(root);
    }

    freeTree(root); */
//------------------------------------------------------------------------------------------------------------

    for (int i = 0; i < TABLE_SIZE; i++) {
        hashTable[i].occupied = 0;
    }

    int choice;
    char name[50];
    int population;

    while (1) {
        printf("\n*** City database ***\n");
        printf("1. Add a city\n");
        printf("2. Delete a city\n");
        printf("3. List cities\n");
        printf("4. Exit\n");
        printf("Choice: \n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("The name of the city: \n");
                scanf("%s", name);
                printf("The population: \n");
                scanf("%d", &population);
                addCity(name, population);
                break;
            case 2:
                printf("What city to remove: \n");
                scanf("%s", name);
                removeCity(name);
                break;
            case 3:
                listCities();
                break;
            case 4:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Error.\n");
        }
    }
//--------------------------------------------------------------------------------------------------------------------------
    return 0;
}
