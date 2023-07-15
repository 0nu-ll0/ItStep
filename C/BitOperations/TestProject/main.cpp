﻿#include "functions.h"

/*
1. Ввести целое число n и вывести 2𝑛, используя битовые операции.
2. Вывести двоичное представление целого положительного числа, используя битовые операции.
3. Найти количество единиц в двоичном представлении целого положительного числа.
4. Найти номер старшего бита в двоичном представлении целого положительного числа.
5. Ввести целые числа n и i и вывести целое число, у которого i-й бит установлен в 1, а все остальные биты совпадают с битами числа n на тех же позициях. Например, если введены 9 и 1, ответом будет 11.
6. Ввести целые числа n и i и вывести целое число, у которого i-й бит сброшен в 0, а все остальные биты совпадают с битами числа n на тех же позициях. Например, если введены 11 и 1, ответом будет 9.
7. Ввести целые числа n и i и вывести целое число, у которого i -й бит отличается от i -го бита числа n , а все остальные биты совпадают с битами числа n на тех же позициях. Например, если введены 5 и 1, ответом будет 7.
8. Ввести целое число n (байт) и вывести число, полученное в результате циклического сдвига числа n на один разряд влево, т. е. старший бит перемещается в позицию младшего, а все остальные биты сдвигаются на один разряд влево. Например, если введено 130, ответом будет 5.
9. Определить, сколько раз встречается 11 в двоичном представлении целого положительного числа (в двоичном представлении 11110111 оно встречается 5 раз).
10. Поменять местами два бита с заданными номерами в двоичном представлении целого положительного числа. Воспользуйтесь задачей 7. Например, если введены 5, 0 и 1, ответом будет 6.
11. Вычеркнуть i-й бит из двоичного представления целого положительного числа (младшие i-го биты остаются на месте, старшие сдвигаются на один разряд вправо). Например, если введены 11 и 2, ответом будет 7.
12*. Описать словами результат следующего выражения: x & ( x - 1 ). // обнуление крайнего справа единичного бита
13*. Описать словами результат следующего выражения: x & ( -x ). // выделяет крайний справа единичный бит
14*. Написать выражение, результатом которого является данное значение x, у которого младший нулевой бит установлен в 1. // x | ( x + 1 )
15*. Написать выражение, результатом которого является данное значение x, у которого все биты установлены в 1, кроме младшего нулевого. // ~x &( x - 1 )
*/

int main(int arg_c, char* arg_v[])
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	//###############################################//
	unsigned int index_one = 0;
	unsigned int index_two = 0;
	unsigned int number = 0;
	//###############ЗАДАЧА 1#######################//
	printf_s("%s", "введите число: ");
	scanf_s("%d", &number);

	printf_s("%d\n", one << number);
	//###############ЗАДАЧА 2#######################//
	bin_rep_pos_int(&number);
	//###############ЗАДАЧА 3#######################//
	printf_s("%d\n", units_counter(&number));
	//###############ЗАДАЧА 4#######################//
	if (most_significant_bit_index(&number) > 0)
		printf_s("%s%d\n", "№ индекса старшего бита: ", most_significant_bit_index(&number));
	else
		printf_s("%s\n", "в введенном числе отсутствуют единичные биты");
	//###############ЗАДАЧА 5#######################//
	printf_s("%s", "введите число: ");
	scanf_s("%d", &number);
	printf_s("%s", "введите индекс: ");
	scanf_s("%d", &index_one);

	set_one_bit(&number, &index_one);

	printf_s("%s%d\n", "число после преобразования: ", number);
	//###############ЗАДАЧА 6#######################//
	printf_s("%s", "введите число: ");
	scanf_s("%d", &number);
	printf_s("%s", "введите индекс: ");
	scanf_s("%d", &index_one);

	set_null_bit(&number, &index_one);

	printf_s("%s%d\n", "число после преобразования: ", number);
	//###############ЗАДАЧА 7#######################//
	printf_s("%s", "введите число: ");
	scanf_s("%d", &number);
	printf_s("%s", "введите индекс: ");
	scanf_s("%d", &index_one);

	inversion_bit(&number, &index_one);

	printf_s("%s%d\n", "число после преобразования: ", number);
	/////////////////////////////
	// TASK 8
	//###############ЗАДАЧА 9#######################//
	printf_s("%s%d%s%d%s\n", "в двоичном представлении числа ", number, " встречается ", counter_eleven(&number), " раз(а)");
	//###############ЗАДАЧА 10#######################//
	printf_s("%s", "введите число: ");
	scanf_s("%d", &number);
	printf_s("%s", "введите первый индекс: ");
	scanf_s("%d", &index_one);
	printf_s("%s", "введите второй индекс: ");
	scanf_s("%d", &index_two);

	swap_two_bits(&number, &index_one, &index_two);

	printf_s("%s%d\n", "число после преобразования: ", number);
	//###############ЗАДАЧА 11#######################//
	printf_s("%s", "введите число: ");
	scanf_s("%d", &number);
	printf_s("%s", "введите индекс вычеркиваемого бита: ");
	scanf_s("%d", &index_one);

	strike_out_bit(&number, &index_one);

	printf_s("%s%d\n", "число после преобразования: ", number);
	//###############################################//
	printf_s("%s\n", "для выхода нажмите любую клавишу");
	_getch();
	return 0;
	//###############################################//
}