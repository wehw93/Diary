#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define len 1000

void input() {
    time_t mytime = time(NULL);
    struct tm *now = localtime(&mytime);

    // Форматируем дату в строку "dd-mm-yyyy"
    char date[len];
    sprintf(date, "%02d-%02d-%04d", now->tm_mday, now->tm_mon + 1, now->tm_year + 1900);

    char filename[len];
    sprintf(filename, "Records/%s.txt", date); // Формирование имени файла

    FILE *fptr;
    char space[1] = " ";
    fptr = fopen(filename, "w");
    char things[len] = "";
    if (fptr) {
        printf("Success! Write something, write 'EXIT' to exit\n");
        while (scanf("%s", things)) {
            if (!strcmp(things, "EXIT")) {
                break;
            }
            // Чтение строки
            size_t n = strlen(things);
            for (size_t i = 0; i < n; i++) {
                putc(things[i], fptr);
            }
            putc(space[0], fptr);
        }
        printf("Saved");
    } else {
        printf("ERROR");
    }
    fclose(fptr);
}
