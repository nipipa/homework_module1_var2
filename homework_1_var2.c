#include <stdio.h>
#include <math.h>

int DecToBin(int x, int y) // функция перевода из 10 в 2 СИ
{
    int i, b,c=0;
    for (i = 0; x > 0; i++){
        b = x % 2;
        x = (x - b) / 2;
        c += b * pow(10, i);
        if (y == 1){ // условие перевода двоичного числа в отрицитаельное
        if (c == 1) c=0;
        else c=1;
        }
        
    }
}
int main()
{
    int i, j = 0,mass_1[100], mass_2[100];
    printf("Введите количетство элементов массива (макс 100):\n");
    scanf("%d", &j); // узнаем количество элементов в массиве
    if (j > 100) j = 100;// если задано больше 100 элементов, то оно останется раным 100 во избежание ошибок
    else if(j == 0){ // значение 0 получается также когда вместо цифр ввели буквенное значение
        printf("!!!--Вы ввели некорректное значение--!!!");
        return 0;
    }
    else if (j < 0) j = j * (-1); // если ввели отрицательное число, то мы его домножаем просто на (-1)
    for (i = 0; i < j; i++){
        printf("%d элемент => ", i); // задаем массив элементов, записанных пользователем в терминале
        scanf("%d", &mass_1[i]);
        if (mass_1[i] < 0){
            mass_2[i] = 1;
            mass_1[i] = mass_1[i] * (-1);
        }
        else mass_2[i] = 0;
    }
    printf("----------------------\n");
    printf("Dec:\t<==>\tBin:\n");
    for (i = 0; i < j; i++){
        int e;
        if (mass_2[i] == 1) e = mass_1[i] * (-1); // добавляем переменную для корректного вывода результата
        else e = mass_1[i];
        printf("[%d]", i);
        printf("%d\t\t", e); // выводим наш массив, состоящих из чисел в десятичной системе
        printf("%d\n", DecToBin(mass_1[i],mass_2[i]));
    }
}
