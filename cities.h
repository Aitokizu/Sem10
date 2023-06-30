#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CITIES 100
#define TABLE_SIZE 50

typedef struct {
    char name[50];
    int population;
} City;

typedef struct {
    char key[50];
    City city;
    int occupied;
} HashNode;

HashNode hashTable[TABLE_SIZE]; // хештаблица

unsigned int hashFunction(char* key) { // хеширование для индекса в табл
    unsigned int hash = 0;
    unsigned int p = 31;
    for (int i = 0; i < strlen(key); i++) {
        hash = (hash * p) + key[i];
    }
    return hash % TABLE_SIZE;
}

void addCity(char* name, int population) {
    unsigned int index = hashFunction(name);

    while (hashTable[index].occupied) {   // проверка наличия коллизий
        index = (index + 1) % TABLE_SIZE;
    }

    strcpy(hashTable[index].key, name); // добавление города
    strcpy(hashTable[index].city.name, name);
    hashTable[index].city.population = population;
    hashTable[index].occupied = 1;

    printf("The city %s is added.\n", name);
}

void removeCity(char* name) {
    unsigned int index = hashFunction(name);

    while (hashTable[index].occupied) { // поиск города
        if (strcmp(hashTable[index].key, name) == 0) {
            // Город найден, удаляем его
            hashTable[index].occupied = 0;
            printf("The city %s is deleted.\n", name);
            return;
        }
        index = (index + 1) % TABLE_SIZE;
    }

    printf("The city %s is not found.\n", name);
}

void listCities() {
    printf("Cities:\n");
    for (int i = 0; i < TABLE_SIZE; i++) {
        if (hashTable[i].occupied) {
            printf("City: %s, Population: %d\n", hashTable[i].city.name, hashTable[i].city.population);
        }
    }
}
