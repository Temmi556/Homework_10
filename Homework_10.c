#include <stdio.h>

float area_two_squares(float a1, float a2, float a3) {
    return (a1 * a1) + (a2 * a2) - (a3 * a3);
}

void name(int a) {
    if (a == 4)
        printf("Фигура: два перекрывающихся квадрата.\n");
    else
        printf("Неизвестная фигура.\n");
}

void draw_two_squares(int a1, int a2, int overlap, char symbol) {
    int size = a1 + overlap; 
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if ((i < a1 && j < a1) || 
                (i >= overlap && i < overlap + a2 && j >= overlap && j < overlap + a2)) {
                printf("%c ", symbol);
            } else {
                printf("  ");
            }
        }
        printf("\n");
    }
}

int main() {
    int choice;
    float a1, a2, a3;
    char symbol;

    printf("Введите сторону первого квадрата: ");
    scanf("%f", &a1);
    printf("Введите сторону второго квадрата: ");
    scanf("%f", &a2);
    printf("Введите длину перекрытия: ");
    scanf("%f", &a3);

    printf("\nМеню:\n");
    printf("1 - Рассчитать площадь фигуры\n");
    printf("2 - Вывести определение фигуры\n");
    printf("3 - Нарисовать фигуру\n");
    printf("Выберите действие: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            printf("Площадь фигуры: %.2f\n", area_two_squares(a1, a2, a3));
            break;
        case 2:
            name(4);
            break;
        case 3:
            printf("Введите символ для рисования: \n");
            scanf(" %c", &symbol);
            draw_two_squares((int)a1, (int)a2, (int)a3, symbol);
            break;
        default:
            printf("Ошибка: неверный выбор.\n");
            break;
    }

    return 0;
}
