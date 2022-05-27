#define _CRT_SECURE_NO_WARNINGS
#include <conio.h>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>

int solve_sudoku(int sudoku[9][9]);
void print_puzzle(int printable1[3][3], int printable2[3][3], int printable3[3][3], int intial1[3][3], int intial2[3][3], int intial3[3][3], int error1[3][3], int error2[3][3], int error3[3][3]);
void rand_modif(int arr[3][3], int arr1[3][3], int arr2[3][3], int arc1[3][3], int arc2[3][3]);
void step_checker(int arr[3][3], int arr1[3][3], int arr2[3][3], int arc1[3][3], int arc2[3][3], int* check, int error[3][3], int errorR1[3][3], int errorR2[3][3], int errorC1[3][3], int errorC2[3][3]);
void step_checker_reset(int arr[3][3], int arr1[3][3], int arr2[3][3], int arc1[3][3], int arc2[3][3], int* check, int error[3][3], int errorR1[3][3], int errorR2[3][3], int errorC1[3][3], int errorC2[3][3]);


void is_valid(int arr[3][3], int arr1[3][3], int arr2[3][3], int arc1[3][3], int arc2[3][3], int* check,int *solve_check)
{
	int i, j, k, m;
	*check = 0;
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			for (k = 0; k < 3; k++)
			{
				for (m = 0; m < 3; m++)
				{
					if (arr[i][j] == arr[k][m] && arr[i][j] != 0)
					{
						if (i != k || j != m)
						{
							(*check)++;
							break;
						}
					}
					if (arr[i][j] == arr1[i][m] && arr[i][j] != 0)
					{

						(*check)++;
						break;
					}
					if (arr[i][j] == arr2[i][m] && arr[i][j] != 0)
					{

						(*check)++;
						break;
					}
					if (arr[j][i] == arc1[m][i] && arr[j][i] != 0)
					{
						(*check)++;
						break;
					}
					if (arr[j][i] == arc2[m][i] && arr[j][i] != 0)
					{

						(*check)++;
						break;
					}
				}
			}
		}
	}
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (arr[i][j] == 0)
				(*solve_check)++;
		}
	}
}


void rand_modif_box(int arr[3][3])
{
	int i, j, k = 0;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (arr[i][j] > 0)
				k++;
			if (k > 4)
				arr[i][j] = 0;
		}

	}

}

void print_init_puzzle(int printable1[3][3], int printable2[3][3], int printable3[3][3])
{
	int r, c, counter = 0;
	for (r = 0; r < 3; r++)
	{

		if (counter == 0)
		{
			printf("\t");
			printf("-------------------------");
			printf("\n");
		}
		printf("       %d: ", r + 1);


		for (c = 0; c < 3; c++)
			if (printable1[r][c] > 0)
				printf("%d ", printable1[r][c]);
			else
				printf(". ");
		printf(": ");

		for (c = 0; c < 3; c++)
			if (printable2[r][c] > 0)
			{
				printf("%d ", printable2[r][c]);
			}
			else
				printf(". ");

		printf(": ");

		for (c = 0; c < 3; c++)
			if (printable3[r][c] > 0)
			{
				printf("%d ", printable3[r][c]);
			}
			else
				printf(". ");

		printf(":");
		printf("\n");

		counter++;
	}

}

void play_input(int puzzle[3][3], int puzzle_i[3][3], int arr1[3][3], int arr2[3][3], int arr3[3][3], int arr4[3][3], int arr5[3][3], int arr6[3][3], int arr7[3][3], int arr8[3][3], int arr9[3][3],
	int arr1_i[3][3], int arr2_i[3][3], int arr3_i[3][3], int arr4_i[3][3], int arr5_i[3][3], int arr6_i[3][3], int arr7_i[3][3], int arr8_i[3][3], int arr9_i[3][3]
	, int error1[3][3], int error2[3][3], int error3[3][3], int error4[3][3], int error5[3][3], int error6[3][3], int error7[3][3], int error8[3][3], int error9[3][3])
{
	
	float r, c;


	printf("\n\033[1;35mEnter the row and column of the element you would like to enter(numbers between 1 and 3):\n\033[0m");
	printf("\033[1;36m");
	if (scanf("%f%f", &r, &c) == 2&&(ceil(r)-r==0 && ceil(c)-c==0))
	{
		printf("\033[0m");
		if (r <= 3 && c <= 3)
		{
			if (puzzle_i[int(r - 1)][int(c - 1)] == 0)
			{
				printf("\033[1;35mEnter the element (%d,%d)\n\033[0m", int(r), int(c));
				printf("\033[1;36m");
				if (scanf("%d", &puzzle[int(r - 1)][int(c - 1)]) == 1)
				{
					if (puzzle[int(r - 1)][int(c - 1)] >= 0 && puzzle[int(r - 1)][int(c - 1)] <= 9)
					{
						printf("\033[0m");
						system("cls");
						printf("\nThe puzzle so far... :\n");
						printf("\t\033[1;36m  1 2 3   1 2 3   1 2 3\n\033[0m");
						print_puzzle(arr1, arr2, arr3, arr1_i, arr2_i, arr3_i, error1, error2, error3);
						print_puzzle(arr4, arr5, arr6, arr4_i, arr5_i, arr6_i, error4, error5, error6);
						print_puzzle(arr7, arr8, arr9, arr7_i, arr8_i, arr9_i, error7, error8, error9);
						printf("\t\033[1;36m-------------------------\033[0m");
					}
					else
					{
						puzzle[int(r - 1)][int(c - 1)] = 0;
						system("cls");
						printf("\n\033[1;31mIncorrect input,please enter numbers between 1 and 9 or enter 0 to clear the cell.\n\033[0m");
						printf("\nThe puzzle so far... :\n");
						printf("\033[1;36m");
						printf("\t  1 2 3   1 2 3   1 2 3\n");
						print_init_puzzle(arr1, arr2, arr3); print_init_puzzle(arr4, arr5, arr6); print_init_puzzle(arr7, arr8, arr9);
						printf("\t-------------------------");
						printf("\033[0m");
					}
				}
				else
				{
					printf("\033[1;31m\n\nThis program only accepts integers for inputs.Thanks for playing!\n\n\033[0m");
					exit(0);
				}
			}
			else
			{
				system("cls");
				printf("\033[1;31m\nThis element (%d,%d) is already in the puzzle,try another slot.\033[0m", int(r), int(c));
				printf("\nThe puzzle so far... :\n");
				printf("\t\033[1;36m  1 2 3   1 2 3   1 2 3\n\033[0m");
				print_puzzle(arr1, arr2, arr3, arr1_i, arr2_i, arr3_i, error1, error2, error3);
				print_puzzle(arr4, arr5, arr6, arr4_i, arr5_i, arr6_i, error4, error5, error6);
				print_puzzle(arr7, arr8, arr9, arr7_i, arr8_i, arr9_i, error7, error8, error9);
				printf("\t\033[1;36m-------------------------\033[0m");
			}

		}
		else
		{
			system("cls");
			printf("\n\033[1;31mIncorrect input,please enter numbers between 1 and 3.\033[0m\n");
			printf("\nThe puzzle so far... :\n");
			printf("\t\033[1;36m  1 2 3   1 2 3   1 2 3\n\033[0");
			print_puzzle(arr1, arr2, arr3, arr1_i, arr2_i, arr3_i, error1, error2, error3);
			print_puzzle(arr4, arr5, arr6, arr4_i, arr5_i, arr6_i, error4, error5, error6);
			print_puzzle(arr7, arr8, arr9, arr7_i, arr8_i, arr9_i, error7, error8, error9);
			printf("\t\033[1;36m-------------------------\033[0m");
		}

	}
	else
	{
		printf("\033[0m");
		printf("\033[1;31m\n\nThis program only accepts integers for inputs.Thanks for playing!\n\n\033[0m");
		exit(0);
	}
	
}

void equating_zero(int arr[3][3])
{
	int i, j;
	for (i = 0; i < 3; i++)
		for (j = 0; j < 3; j++)
			arr[i][j] = 0;
}

void sudoku_reverse(int sudoku[9][9], int box1[3][3], int box2[3][3], int box3[3][3], int box4[3][3], int box5[3][3], int box6[3][3], int box7[3][3], int box8[3][3], int box9[3][3])
{
	int i, j;
	for (i = 0; i < 3; i++)
		for (j = 0; j < 3; j++)
		{
			box1[i][j] = sudoku[i][j];
			box2[i][j] = sudoku[i][j + 3];
			box3[i][j] = sudoku[i][j + 6];
			box4[i][j] = sudoku[i + 3][j];
			box5[i][j] = sudoku[i + 3][j + 3];
			box6[i][j] = sudoku[i + 3][j + 6];
			box7[i][j] = sudoku[i + 6][j];
			box8[i][j] = sudoku[i + 6][j + 3];
			box9[i][j] = sudoku[i + 6][j + 6];
		}
}

void sudoku_init(int sudoku[9][9], int arr1[3][3], int arr2[3][3], int arr3[3][3], int arr4[3][3], int arr5[3][3], int arr6[3][3], int arr7[3][3], int arr8[3][3], int arr9[3][3])
{
	int i, j;
	for (i = 0; i < 3; i++)
		for (j = 0; j < 3; j++)
		{
			sudoku[i][j] = arr1[i][j];
			sudoku[i][j + 3] = arr2[i][j];
			sudoku[i][j + 6] = arr3[i][j];
			sudoku[i + 3][j] = arr4[i][j];
			sudoku[i + 3][j + 3] = arr5[i][j];
			sudoku[i + 3][j + 6] = arr6[i][j];
			sudoku[i + 6][j] = arr7[i][j];
			sudoku[i + 6][j + 3] = arr8[i][j];
			sudoku[i + 6][j + 6] = arr9[i][j];

		}


}

void equating_matricies(int arr_i[3][3], int arr[3][3])
{
	int i, j;
	for (i = 0; i < 3; i++)
		for (j = 0; j < 3; j++)
			arr_i[i][j] = arr[i][j];
}

int random(int sudoku[9][9], int arr1[3][3], int arr2[3][3], int arr3[3][3], int arr4[3][3], int arr5[3][3], int arr6[3][3], int arr7[3][3], int arr8[3][3], int arr9[3][3])
{
	int i, j, sudoku_i[9][9], z = 0;
	srand(time(0));

	do {
		for (i = 0; i < 9; i++)
		{
			for (j = 0; j < 9; j++)
			{
				sudoku[i][j] = (rand() % 9)+1;
			}
		}


		sudoku_reverse(sudoku, arr1, arr2, arr3, arr4, arr5, arr6, arr7, arr8, arr9);


		rand_modif(arr1, arr2, arr3, arr4, arr7); rand_modif(arr2, arr1, arr3, arr5, arr8); rand_modif(arr3, arr1, arr2, arr6, arr9);
		rand_modif(arr4, arr5, arr6, arr1, arr7); rand_modif(arr5, arr4, arr6, arr2, arr8); rand_modif(arr6, arr4, arr5, arr3, arr9);
		rand_modif(arr7, arr1, arr4, arr8, arr9); rand_modif(arr8, arr7, arr9, arr2, arr5); rand_modif(arr9, arr7, arr8, arr3, arr6);
		rand_modif_box(arr1); rand_modif_box(arr2); rand_modif_box(arr3); rand_modif_box(arr4); rand_modif_box(arr5); rand_modif_box(arr6);
		rand_modif_box(arr7); rand_modif_box(arr8); rand_modif_box(arr9);


		sudoku_init(sudoku, arr1, arr2, arr3, arr4, arr5, arr6, arr7, arr8, arr9);

		for (i = 0; i < 9; i++)
			for (j = 0; j < 9; j++)
				sudoku_i[i][j] = sudoku[i][j];


		if (solve_sudoku(sudoku_i))
		{
			z = 1;
		}
	} while (z != 1);





	return 0;
}

void init_step_checker(int arr[3][3], int arr1[3][3], int arr2[3][3], int arc1[3][3], int arc2[3][3], int* check)
{
	int i, j, k, m;
	*check = 0;
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			for (k = 0; k < 3; k++)
			{
				for (m = 0; (m < 3) && (arr[i][j] != 0); m++)
				{
					if (i != k || j != m)
					{
						if (arr[i][j] == arr[k][m])
						{

							(*check)++;
							printf("\033[1;31m");
							printf("\n%d is an invalid input in (%d,%d)\n", arr[k][m], k + 1, m + 1);
							printf("\033[0m");
							
							break;
						}
					}
					if (arr[i][j] == arr1[i][m])
					{
						(*check)++;
						printf("\033[1;31m");
						printf("\n%d is an invalid input in (%d,%d)\n", arr1[i][m], i + 1, m + 1);
						printf("\033[0m");
						
						break;
					}
					if (arr[i][j] == arr2[i][m])
					{

						(*check)++;
						printf("\033[1;31m");
						printf("\n%d is an invalid input in (%d,%d)\n", arr2[i][m], i + 1, m + 1);
						printf("\033[0m");
						
						break;
					}
					if (arr[j][i] == arc1[m][i] && arr[j][i] != 0)
					{
						(*check)++;
						printf("\033[1;31m");
						printf("\n%d is an invalid input in (%d,%d)\n", arc1[m][i], m + 1, i + 1);
						printf("\033[0m");
						
						break;
					}
					if (arr[j][i] == arc2[m][i] && arr[j][i] != 0)
					{
						(*check)++;
						printf("\033[1;31m");
						printf("\n%d is an invalid input in (%d,%d)\n", arc2[m][i], m + 1, i + 1);
						printf("\033[0m");
						
						break;
					}
				}
				if (*check > 0)
					break;
			}
			if (*check > 0)
				break;
		}
		if (*check > 0)
			break;
	}

}

void init(int puzzle[3][3], int arr1[3][3], int arr2[3][3], int arr3[3][3], int arr4[3][3], int arr5[3][3], int arr6[3][3], int arr7[3][3], int arr8[3][3], int arr9[3][3], float* choice_init, int* init_counter)
{
	int i, check = 0;
	float r, c, N;
	printf("\033[1;36m");
	if (scanf("%f", &N) == 1&&ceil(N)-N==0)
	{
		printf("\033[0m");
		if (N > 0 && N <= 9)
		{

			for (i = 1; i <= N; i++)
			{
				printf("\n\033[1;35mEnter the row and column of the element you would like to enter(numbers between 1 and 3):\n\033[0m");
				printf("\033[1;36m");
				if (scanf("%f%f", &r, &c) == 2&&(ceil(r)-r==0)&&(ceil(c)-c==0))
				{
					printf("\033[0m");
					if (r <= 3 && c <= 3)
					{
						printf("\033[1;35mEnter the element (%d,%d)\n\033[0m", int(r), int(c));
						printf("\033[1;36m");
						if (scanf("%d", &puzzle[int(r - 1)][int(c - 1)]) == 1)
						{
							printf("\033[0m");
							if (puzzle[int(r - 1)][int(c - 1)] >= 0 && puzzle[int(r - 1)][int(c - 1)] <= 9)
							{
								switch (int(*choice_init))
								{
								case 1:
									init_step_checker(arr1, arr2, arr3, arr4, arr7, &check);
									break;
								case 2:
									init_step_checker(arr2, arr1, arr3, arr5, arr8, &check);
									break;
								case 3:
									init_step_checker(arr3, arr1, arr2, arr6, arr9, &check);
									break;
								case 4:
									init_step_checker(arr4, arr5, arr6, arr1, arr7, &check);
									break;
								case 5:
									init_step_checker(arr5, arr4, arr6, arr2, arr8, &check);
									break;
								case 6:
									init_step_checker(arr6, arr4, arr5, arr3, arr9, &check);
									break;
								case 7:
									init_step_checker(arr7, arr8, arr9, arr1, arr4, &check);
									break;
								case 8:
									init_step_checker(arr8, arr7, arr9, arr2, arr5, &check);
									break;
								case 9:
									init_step_checker(arr9, arr7, arr8, arr3, arr6, &check);
									break;
								default:
									break;

								}
								if (check == 0)
								{
									printf("\033[0m");
									system("cls");
									printf("\nThe puzzle so far... :\n");
									printf("\033[1;36m");
									printf("\t  1 2 3   1 2 3   1 2 3\n");
									print_init_puzzle(arr1, arr2, arr3); print_init_puzzle(arr4, arr5, arr6); print_init_puzzle(arr7, arr8, arr9);
									printf("\t-------------------------");
									printf("\033[0m");
									(*init_counter)++;
								}
								else
								{
									system("cls");
									printf("\n\033[1;31mIllegal input,please revise the puzzle and try again.\033[0m\n");
									printf("\nThe puzzle so far... :\n");
									printf("\033[1;36m");
									printf("\t  1 2 3   1 2 3   1 2 3\n");
									print_init_puzzle(arr1, arr2, arr3); print_init_puzzle(arr4, arr5, arr6); print_init_puzzle(arr7, arr8, arr9);
									printf("\t-------------------------");
									printf("\033[0m");
								}
							}
							else
							{
								puzzle[int(r - 1)][int(c - 1)] = 0;
								system("cls");
								printf("\n\033[1;31mIncorrect input,please enter numbers between 1 and 9 or enter 0 to clear the cell.\n\033[0m");
								printf("\nThe puzzle so far... :\n");
								printf("\033[1;36m");
								printf("\t  1 2 3   1 2 3   1 2 3\n");
								print_init_puzzle(arr1, arr2, arr3); print_init_puzzle(arr4, arr5, arr6); print_init_puzzle(arr7, arr8, arr9);
								printf("\t-------------------------");
								printf("\033[0m");
							}
						}
						else
						{
							printf("\033[0m");
							printf("\033[1;31m\n\nThis program only accepts integers for inputs.Thanks for playing!\n\n\033[0m");
							exit(0);
						}
					}
					else
					{
						system("cls");
						printf("\n\033[1;31mIncorrect input,please enter numbers between 1 and 3.\n\033[0m");
						printf("\nThe puzzle so far... :\n");
						printf("\033[1;36m");
						printf("\t  1 2 3   1 2 3   1 2 3\n");
						print_init_puzzle(arr1, arr2, arr3); print_init_puzzle(arr4, arr5, arr6); print_init_puzzle(arr7, arr8, arr9);
						printf("\t-------------------------");
						printf("\033[0m");
					}
				}
				else
				{
					printf("\033[0m");
					printf("\033[1;31m\n\nThis program only accepts integers for inputs.Thanks for playing!\n\n\033[0m");
					exit(0);
				}
			}
		}
		else
		{
			system("cls");
			printf("\n\033[1;31mIncorrect input,you can only enter up to 9 elements per box\n\033[0m");
			printf("\nThe puzzle so far... :\n");
			printf("\033[1;36m");
			printf("\t  1 2 3   1 2 3   1 2 3\n");
			print_init_puzzle(arr1, arr2, arr3); print_init_puzzle(arr4, arr5, arr6); print_init_puzzle(arr7, arr8, arr9);
			printf("\t-------------------------");
			printf("\033[0m");
		}
	}
	else
	{
		printf("\033[0m");
		printf("\033[1;31m\n\nThis program only accepts integers for inputs.Thanks for playing!\n\n\033[0m");
		exit(0);
	}
}

void print_puzzle(int printable1[3][3], int printable2[3][3], int printable3[3][3], int intial1[3][3], int intial2[3][3], int intial3[3][3],int error1[3][3],int error2[3][3],int error3[3][3])
{
	int r, c, counter = 0;
	for (r = 0; r < 3; r++)
	{

		if (counter == 0)
		{
			printf("\t\033[1;36m");
			printf("-------------------------");
			printf("\n\033[0m");
		}
		printf("\033[1;36m       %d: \033[0m", r + 1);

		for (c = 0; c < 3; c++)
			if (printable1[r][c] > 0)
			{
				if (printable1[r][c] != intial1[r][c] && error1[r][c] == 0)
				{
					printf("\033[01;33m");
					printf("%d ", printable1[r][c]);
					printf("\033[0m");
				}
				else if (error1[r][c] == -1)
				{
					printf("\033[01;31m");
					printf("%d ", printable1[r][c]);
					printf("\033[0m");
				}
				else
					printf("\033[1;36m%d \033[0m", printable1[r][c]);
			}
			else
				printf("\033[1;36m. \033[0m");
		printf("\033[1;36m: \033[0m");

		for (c = 0; c < 3; c++)
			if (printable2[r][c] > 0)
			{
				if (printable2[r][c] != intial2[r][c] && error2[r][c]==0)
				{
					printf("\033[01;33m");
					printf("%d ", printable2[r][c]);
					printf("\033[0m");
				}
				else if (error2[r][c] == -1)
				{
					printf("\033[01;31m");
					printf("%d ", printable2[r][c]);
					printf("\033[0m");
				}
				else
					printf("\033[1;36m%d \033[0m", printable2[r][c]);
			}
			else
				printf("\033[1;36m. \033[0m");
		printf("\033[1;36m: \033[0m");

		for (c = 0; c < 3; c++)
			if (printable3[r][c] > 0)
			{
				if (printable3[r][c] != intial3[r][c]&&error3[r][c]==0)
				{
					printf("\033[01;33m");
					printf("%d ", printable3[r][c]);
					printf("\033[0m");
				}
				else if (error3[r][c] == -1)
				{
					printf("\033[01;31m");
					printf("%d ", printable3[r][c]);
					printf("\033[0m");
				}
				else
					printf("\033[1;36m%d \033[0m", printable3[r][c]);
			}
			else
				printf("\033[1;36m. \033[0m");
		printf("\033[1;36m: \033[0m");
		printf("\n");
		counter++;
	}

}

void play(int arr1[3][3], int arr2[3][3], int arr3[3][3], int arr4[3][3], int arr5[3][3], int arr6[3][3], int arr7[3][3], int arr8[3][3], int arr9[3][3]
	, int arr1_i[3][3], int arr2_i[3][3], int arr3_i[3][3], int arr4_i[3][3], int arr5_i[3][3], int arr6_i[3][3], int arr7_i[3][3], int arr8_i[3][3], int arr9_i[3][3], int* time_check
	,int error1[3][3], int error2[3][3], int error3[3][3], int error4[3][3], int error5[3][3], int error6[3][3], int error7[3][3], int error8[3][3], int error9[3][3] )

{
	float choice, turns = 1;
	int time;

	*time_check = 0;
	clock_t start, end;
	start = clock();
	int time_min=0;
	int time_sec=0;

	do
	{

		printf("\033[1;35m\nPlease choose which 3x3 box you'd like to enter a number in(1-9):\033[0m");
		printf("\033[1;36m");
		if (scanf("%f", &choice) == 1&&ceil(choice)-choice==0)
		{
			printf("\033[0m");
			int check = 0;
			switch (int(choice))
			{
			case 1:
				play_input(arr1, arr1_i, arr1, arr2, arr3, arr4, arr5, arr6, arr7, arr8, arr9, arr1_i, arr2_i, arr3_i, arr4_i, arr5_i, arr6_i, arr7_i, arr8_i, arr9_i,
					error1, error2, error3, error4, error5, error6, error7, error8, error9);
				system("cls");
				step_checker(arr1, arr2, arr3, arr4, arr7, &check, error1, error2, error3, error4, error7);
				step_checker_reset(arr1, arr2, arr3, arr4, arr7, &check, error1, error2, error3, error4, error7);
				step_checker(arr2, arr1, arr3, arr5, arr8, &check, error2, error1, error3, error5, error8);
				step_checker(arr3, arr1, arr2, arr6, arr9, &check, error3, error1, error2, error6, error9);
				step_checker(arr4, arr5, arr6, arr1, arr7, &check, error4, error5, error6, error1, error7);
				step_checker(arr5, arr4, arr6, arr2, arr8, &check, error5, error4, error6, error2, error8);
				step_checker(arr6, arr4, arr5, arr3, arr9, &check, error6, error4, error5, error3, error9);
				step_checker(arr7, arr8, arr9, arr1, arr4, &check, error7, error8, error9, error1, error4);
				step_checker(arr8, arr7, arr9, arr2, arr5, &check, error8, error7, error9, error2, error5);
				step_checker(arr9, arr7, arr8, arr3, arr6, &check, error9, error7, error8, error3, error6);
				printf("\t\033[1;36m  1 2 3   1 2 3   1 2 3\n\033[0m");
				print_puzzle(arr1, arr2, arr3, arr1_i, arr2_i, arr3_i, error1, error2, error3);
				print_puzzle(arr4, arr5, arr6, arr4_i, arr5_i, arr6_i, error4, error5, error6);
				print_puzzle(arr7, arr8, arr9, arr7_i, arr8_i, arr9_i, error7, error8, error9);
				printf("\t\033[1;36m-------------------------\033[0m");
				printf("\033[0m");
				
				break;
			case 2:
				play_input(arr2, arr2_i, arr1, arr2, arr3, arr4, arr5, arr6, arr7, arr8, arr9, arr1_i, arr2_i, arr3_i, arr4_i, arr5_i, arr6_i, arr7_i, arr8_i, arr9_i,
					error1, error2, error3, error4, error5, error6, error7, error8, error9);
				system("cls");
				step_checker(arr2, arr1, arr3, arr5, arr8, &check, error2, error1, error3, error5, error8);
				step_checker_reset(arr2, arr1, arr3, arr5, arr8, &check, error2, error1, error3, error5, error8);
				step_checker(arr1, arr2, arr3, arr4, arr7, &check, error1, error2, error3, error4, error7);
				step_checker(arr3, arr1, arr2, arr6, arr9, &check, error3, error1, error2, error6, error9);
				step_checker(arr4, arr5, arr6, arr1, arr7, &check, error4, error5, error6, error1, error7);
				step_checker(arr5, arr4, arr6, arr2, arr8, &check, error5, error4, error6, error2, error8);
				step_checker(arr6, arr4, arr5, arr3, arr9, &check, error6, error4, error5, error3, error9);
				step_checker(arr7, arr8, arr9, arr1, arr4, &check, error7, error8, error9, error1, error4);
				step_checker(arr8, arr7, arr9, arr2, arr5, &check, error8, error7, error9, error2, error5);
				step_checker(arr9, arr7, arr8, arr3, arr6, &check, error9, error7, error8, error3, error6);
				printf("\t\033[1;36m  1 2 3   1 2 3   1 2 3\n\033[0m");
				print_puzzle(arr1, arr2, arr3, arr1_i, arr2_i, arr3_i, error1, error2, error3);
				print_puzzle(arr4, arr5, arr6, arr4_i, arr5_i, arr6_i, error4, error5, error6);
				print_puzzle(arr7, arr8, arr9, arr7_i, arr8_i, arr9_i, error7, error8, error9);
				printf("\t\033[1;36m-------------------------\033[0m");
				printf("\033[0m");
				break;
			case 3:
				play_input(arr3, arr3_i, arr1, arr2, arr3, arr4, arr5, arr6, arr7, arr8, arr9, arr1_i, arr2_i, arr3_i, arr4_i, arr5_i, arr6_i, arr7_i, arr8_i, arr9_i,
					error1, error2, error3, error4, error5, error6, error7, error8, error9);
				system("cls");
				step_checker(arr3, arr1, arr2, arr6, arr9, &check, error3, error1, error2, error6, error9);
				step_checker_reset(arr3, arr1, arr2, arr6, arr9, &check, error3, error1, error2, error6, error9);
				step_checker(arr1, arr2, arr3, arr4, arr7, &check, error1, error2, error3, error4, error7);
				step_checker(arr2, arr1, arr3, arr5, arr8, &check, error2, error1, error3, error5, error8);
				step_checker(arr4, arr5, arr6, arr1, arr7, &check, error4, error5, error6, error1, error7);
				step_checker(arr5, arr4, arr6, arr2, arr8, &check, error5, error4, error6, error2, error8);
				step_checker(arr6, arr4, arr5, arr3, arr9, &check, error6, error4, error5, error3, error9);
				step_checker(arr7, arr8, arr9, arr1, arr4, &check, error7, error8, error9, error1, error4);
				step_checker(arr8, arr7, arr9, arr2, arr5, &check, error8, error7, error9, error2, error5);
				step_checker(arr9, arr7, arr8, arr3, arr6, &check, error9, error7, error8, error3, error6);
				printf("\t\033[1;36m  1 2 3   1 2 3   1 2 3\n\033[0m");
				print_puzzle(arr1, arr2, arr3, arr1_i, arr2_i, arr3_i, error1, error2, error3);
				print_puzzle(arr4, arr5, arr6, arr4_i, arr5_i, arr6_i, error4, error5, error6);
				print_puzzle(arr7, arr8, arr9, arr7_i, arr8_i, arr9_i, error7, error8, error9);
				printf("\t\033[1;36m-------------------------\033[0m");
				printf("\033[0m");
				break;
			case 4:
				play_input(arr4, arr4_i, arr1, arr2, arr3, arr4, arr5, arr6, arr7, arr8, arr9, arr1_i, arr2_i, arr3_i, arr4_i, arr5_i, arr6_i, arr7_i, arr8_i, arr9_i,
					error1, error2, error3, error4, error5, error6, error7, error8, error9);
				system("cls");
				step_checker(arr4, arr5, arr6, arr1, arr7, &check, error4, error5, error6, error1, error7);
				step_checker_reset(arr4, arr5, arr6, arr1, arr7, &check, error4, error5, error6, error1, error7);
				step_checker(arr1, arr2, arr3, arr4, arr7, &check, error1, error2, error3, error4, error7);
				step_checker(arr2, arr1, arr3, arr5, arr8, &check, error2, error1, error3, error5, error8);
				step_checker(arr3, arr1, arr2, arr6, arr9, &check, error3, error1, error2, error6, error9);
				step_checker(arr5, arr4, arr6, arr2, arr8, &check, error5, error4, error6, error2, error8);
				step_checker(arr6, arr4, arr5, arr3, arr9, &check, error6, error4, error5, error3, error9);
				step_checker(arr7, arr8, arr9, arr1, arr4, &check, error7, error8, error9, error1, error4);
				step_checker(arr8, arr7, arr9, arr2, arr5, &check, error8, error7, error9, error2, error5);
				step_checker(arr9, arr7, arr8, arr3, arr6, &check, error9, error7, error8, error3, error6);
				printf("\t\033[1;36m  1 2 3   1 2 3   1 2 3\n\033[0m");
				print_puzzle(arr1, arr2, arr3, arr1_i, arr2_i, arr3_i, error1, error2, error3);
				print_puzzle(arr4, arr5, arr6, arr4_i, arr5_i, arr6_i, error4, error5, error6);
				print_puzzle(arr7, arr8, arr9, arr7_i, arr8_i, arr9_i, error7, error8, error9);
				printf("\t\033[1;36m-------------------------\033[0m");
				printf("\033[0m");
				break;
			case 5:
				play_input(arr5, arr5_i, arr1, arr2, arr3, arr4, arr5, arr6, arr7, arr8, arr9, arr1_i, arr2_i, arr3_i, arr4_i, arr5_i, arr6_i, arr7_i, arr8_i, arr9_i,
					error1, error2, error3, error4, error5, error6, error7, error8, error9);
				system("cls");
				step_checker(arr5, arr4, arr6, arr2, arr8, &check, error5, error4, error6, error2, error8);
				step_checker_reset(arr5, arr4, arr6, arr2, arr8, &check, error5, error4, error6, error2, error8);
				step_checker(arr1, arr2, arr3, arr4, arr7, &check, error1, error2, error3, error4, error7);
				step_checker(arr2, arr1, arr3, arr5, arr8, &check, error2, error1, error3, error5, error8);
				step_checker(arr3, arr1, arr2, arr6, arr9, &check, error3, error1, error2, error6, error9);
				step_checker(arr4, arr5, arr6, arr1, arr7, &check, error4, error5, error6, error1, error7);
				step_checker(arr6, arr4, arr5, arr3, arr9, &check, error6, error4, error5, error3, error9);
				step_checker(arr7, arr8, arr9, arr1, arr4, &check, error7, error8, error9, error1, error4);
				step_checker(arr8, arr7, arr9, arr2, arr5, &check, error8, error7, error9, error2, error5);
				step_checker(arr9, arr7, arr8, arr3, arr6, &check, error9, error7, error8, error3, error6);
				printf("\t\033[1;36m  1 2 3   1 2 3   1 2 3\n\033[0m");
				print_puzzle(arr1, arr2, arr3, arr1_i, arr2_i, arr3_i, error1, error2, error3);
				print_puzzle(arr4, arr5, arr6, arr4_i, arr5_i, arr6_i, error4, error5, error6);
				print_puzzle(arr7, arr8, arr9, arr7_i, arr8_i, arr9_i, error7, error8, error9);
				printf("\t\033[1;36m-------------------------\033[0m");
				printf("\033[0m");
			
				break;
			case 6:
				play_input(arr6, arr6_i, arr1, arr2, arr3, arr4, arr5, arr6, arr7, arr8, arr9, arr1_i, arr2_i, arr3_i, arr4_i, arr5_i, arr6_i, arr7_i, arr8_i, arr9_i,
					error1, error2, error3, error4, error5, error6, error7, error8, error9);
				system("cls");
				step_checker(arr6, arr4, arr5, arr3, arr9, &check, error6, error4, error5, error3, error9);
				step_checker_reset(arr6, arr4, arr5, arr3, arr9, &check, error6, error4, error5, error3, error9);
				step_checker(arr1, arr2, arr3, arr4, arr7, &check, error1, error2, error3, error4, error7);
				step_checker(arr2, arr1, arr3, arr5, arr8, &check, error2, error1, error3, error5, error8);
				step_checker(arr3, arr1, arr2, arr6, arr9, &check, error3, error1, error2, error6, error9);
				step_checker(arr4, arr5, arr6, arr1, arr7, &check, error4, error5, error6, error1, error7);
				step_checker(arr5, arr4, arr6, arr2, arr8, &check, error5, error4, error6, error2, error8);
				step_checker(arr7, arr8, arr9, arr1, arr4, &check, error7, error8, error9, error1, error4);
				step_checker(arr8, arr7, arr9, arr2, arr5, &check, error8, error7, error9, error2, error5);
				step_checker(arr9, arr7, arr8, arr3, arr6, &check, error9, error7, error8, error3, error6);
				printf("\t\033[1;36m  1 2 3   1 2 3   1 2 3\n\033[0m");
				print_puzzle(arr1, arr2, arr3, arr1_i, arr2_i, arr3_i, error1, error2, error3);
				print_puzzle(arr4, arr5, arr6, arr4_i, arr5_i, arr6_i, error4, error5, error6);
				print_puzzle(arr7, arr8, arr9, arr7_i, arr8_i, arr9_i, error7, error8, error9);
				printf("\t\033[1;36m-------------------------\033[0m");
				printf("\033[0m");
				
				break;
			case 7:
				play_input(arr7, arr7_i, arr1, arr2, arr3, arr4, arr5, arr6, arr7, arr8, arr9, arr1_i, arr2_i, arr3_i, arr4_i, arr5_i, arr6_i, arr7_i, arr8_i, arr9_i,
					error1, error2, error3, error4, error5, error6, error7, error8, error9);
				system("cls");
				step_checker(arr7, arr8, arr9, arr1, arr4, &check, error7, error8, error9, error1, error4);
				step_checker_reset(arr7, arr8, arr9, arr1, arr4, &check, error7, error8, error9, error1, error4);
				step_checker(arr1, arr2, arr3, arr4, arr7, &check, error1, error2, error3, error4, error7);
				step_checker(arr2, arr1, arr3, arr5, arr8, &check, error2, error1, error3, error5, error8);
				step_checker(arr3, arr1, arr2, arr6, arr9, &check, error3, error1, error2, error6, error9);
				step_checker(arr4, arr5, arr6, arr1, arr7, &check, error4, error5, error6, error1, error7);
				step_checker(arr5, arr4, arr6, arr2, arr8, &check, error5, error4, error6, error2, error8);
				step_checker(arr6, arr4, arr5, arr3, arr9, &check, error6, error4, error5, error3, error9);
				step_checker(arr8, arr7, arr9, arr2, arr5, &check, error8, error7, error9, error2, error5);
				step_checker(arr9, arr7, arr8, arr3, arr6, &check, error9, error7, error8, error3, error6);
				printf("\t\033[1;36m  1 2 3   1 2 3   1 2 3\n\033[0m");
				print_puzzle(arr1, arr2, arr3, arr1_i, arr2_i, arr3_i, error1, error2, error3);
				print_puzzle(arr4, arr5, arr6, arr4_i, arr5_i, arr6_i, error4, error5, error6);
				print_puzzle(arr7, arr8, arr9, arr7_i, arr8_i, arr9_i, error7, error8, error9);
				printf("\t\033[1;36m-------------------------\033[0m");
				printf("\033[0m");
			
				break;
			case 8:
				play_input(arr8, arr8_i, arr1, arr2, arr3, arr4, arr5, arr6, arr7, arr8, arr9, arr1_i, arr2_i, arr3_i, arr4_i, arr5_i, arr6_i, arr7_i, arr8_i, arr9_i,
					error1, error2, error3, error4, error5, error6, error7, error8, error9);
				system("cls");
				step_checker(arr8, arr7, arr9, arr2, arr5, &check, error8, error7, error9, error2, error5);
				step_checker_reset(arr8, arr7, arr9, arr2, arr5, &check, error8, error7, error9, error2, error5);
				step_checker(arr1, arr2, arr3, arr4, arr7, &check, error1, error2, error3, error4, error7);
				step_checker(arr2, arr1, arr3, arr5, arr8, &check, error2, error1, error3, error5, error8);
				step_checker(arr3, arr1, arr2, arr6, arr9, &check, error3, error1, error2, error6, error9);
				step_checker(arr4, arr5, arr6, arr1, arr7, &check, error4, error5, error6, error1, error7);
				step_checker(arr5, arr4, arr6, arr2, arr8, &check, error5, error4, error6, error2, error8);
				step_checker(arr6, arr4, arr5, arr3, arr9, &check, error6, error4, error5, error3, error9);
				step_checker(arr7, arr8, arr9, arr1, arr4, &check, error7, error8, error9, error1, error4);
				step_checker(arr9, arr7, arr8, arr3, arr6, &check, error9, error7, error8, error3, error6);
				printf("\t\033[1;36m  1 2 3   1 2 3   1 2 3\n\033[0m");
				print_puzzle(arr1, arr2, arr3, arr1_i, arr2_i, arr3_i, error1, error2, error3);
				print_puzzle(arr4, arr5, arr6, arr4_i, arr5_i, arr6_i, error4, error5, error6);
				print_puzzle(arr7, arr8, arr9, arr7_i, arr8_i, arr9_i, error7, error8, error9);
				printf("\t\033[1;36m-------------------------\033[0m");
				printf("\033[0m");
				
				break;
			case 9:
				play_input(arr9, arr9_i, arr1, arr2, arr3, arr4, arr5, arr6, arr7, arr8, arr9, arr1_i, arr2_i, arr3_i, arr4_i, arr5_i, arr6_i, arr7_i, arr8_i, arr9_i,
					error1, error2, error3, error4, error5, error6, error7, error8, error9);
				system("cls");
				step_checker(arr9, arr7, arr8, arr3, arr6, &check, error9, error7, error8, error3, error6);
				step_checker_reset(arr9, arr7, arr8, arr3, arr6, &check, error9, error7, error8, error3, error6);
				step_checker(arr1, arr2, arr3, arr4, arr7, &check, error1, error2, error3, error4, error7);
				step_checker(arr2, arr1, arr3, arr5, arr8, &check, error2, error1, error3, error5, error8);
				step_checker(arr3, arr1, arr2, arr6, arr9, &check, error3, error1, error2, error6, error9);
				step_checker(arr4, arr5, arr6, arr1, arr7, &check, error4, error5, error6, error1, error7);
				step_checker(arr5, arr4, arr6, arr2, arr8, &check, error5, error4, error6, error2, error8);
				step_checker(arr6, arr4, arr5, arr3, arr9, &check, error6, error4, error5, error3, error9);
				step_checker(arr7, arr8, arr9, arr1, arr4, &check, error7, error8, error9, error1, error4);
				step_checker(arr8, arr7, arr9, arr2, arr5, &check, error8, error7, error9, error2, error5);
				printf("\t\033[1;36m  1 2 3   1 2 3   1 2 3\n\033[0m");
				print_puzzle(arr1, arr2, arr3, arr1_i, arr2_i, arr3_i, error1, error2, error3);
				print_puzzle(arr4, arr5, arr6, arr4_i, arr5_i, arr6_i, error4, error5, error6);
				print_puzzle(arr7, arr8, arr9, arr7_i, arr8_i, arr9_i, error7, error8, error9);
				printf("\t\033[1;36m-------------------------\033[0m");
				printf("\033[0m");
				
				break;
			default:
				printf("\033[01;31m");
				printf("\nIncorrect input,please try again.");
				printf("\033[0m");
				break;
			}
			end = clock();
			time = (end - start) / CLOCKS_PER_SEC;
			time_min = time /60;
			
			if (time > 180)
			{
				(*time_check)++;
				break;
			}
			else
				printf("\n\n\033[1;36mYou have %02d:%02d left to finish the puzzle!\033[0m\n\n", 2 - time_min, 60 - time%60);

			printf("\n\033[1;35mDo you want to enter another number? enter any number to continue or enter 0 to stop playing.\n\033[0m");
			printf("\033[1;36m");
			if(scanf("%f", &turns)!=1&&ceil(turns)-turns==0)
			{
				printf("\033[0m");
				printf("\033[1;31m\n\nThis program only accepts integers for inputs.Thanks for playing!\n\n\033[0m");
				exit(0);
			}

			printf("\033[0m");
		}
		else
		{
			printf("\033[0m");
			printf("\033[1;31m\n\nThis program only accepts integers for inputs.Thanks for playing!\n\n\033[0m");
			exit(0);
		}
	}while (turns != 0);
}

void final_checker(int arr[3][3], int arr1[3][3], int arr2[3][3], int arc1[3][3], int arc2[3][3], int* check)
{
	int i, j, k, m;
	*check = 0;
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			for (k = 0; k < 3; k++)
			{
				for (m = 0; m < 3; m++)
				{
					if (arr[i][j] == arr[k][m])
					{
						if (i != k || j != m)
						{
							(*check)++;
							break;
						}
					}
					if (arr[i][j] == arr1[i][m])
					{

						(*check)++;
						break;
					}
					if (arr[i][j] == arr2[i][m])
					{

						(*check)++;
						break;
					}
					if (arr[j][i] == arc1[m][i])
					{
						(*check)++;
						break;
					}
					if (arr[j][i] == arc2[m][i])
					{

						(*check)++;
						break;
					}
					if (arr[i][j] == 0 || arr[j][i] == 0)
					{
						(*check)++;
						break;
					}
				}
			}
		}
	}

}

void rand_modif(int arr[3][3], int arr1[3][3], int arr2[3][3], int arc1[3][3], int arc2[3][3])
{
	int i, j, k, m;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			for (k = 0; k < 3; k++)
			{
				for (m = 0; m < 3; m++)
				{
					if (arr[i][j] == arr[k][m])
					{
						if (i != k || j != m)
						{
							arr[k][m] = 0;

						}
					}
					if (arr[i][j] == arr1[i][m])
					{

						arr1[i][m] = 0;
					}
					if (arr[i][j] == arr2[i][m])
					{

						arr2[i][m] = 0;
					}
					if (arr[j][i] == arc1[m][i])
					{
						arc1[m][i] = 0;
					}
					if (arr[j][i] == arc2[m][i])
					{

						arc2[m][i] = 0;
					}
				}
			}
		}
	}

}

void step_checker(int arr[3][3], int arr1[3][3], int arr2[3][3], int arc1[3][3], int arc2[3][3], int* check,int error[3][3], int errorR1[3][3], int errorR2[3][3], int errorC1[3][3], int errorC2[3][3])
{
	/*need another checker to reset the red spots*/
	int i, j, k, m;
	*check = 0;
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			for (k = 0; k < 3; k++)
			{
				for (m = 0; (m < 3); m++)
				{
					if (i != k || j != m)
					{
						if (arr[i][j] == arr[k][m]&&arr[i][j]!=0)
						{

							(*check)++;
							error[i][j] = -1;
							error[k][m] = -1;
							break;
						}
						
					
						
					}
					if (arr[i][j] == arr1[i][m] && arr[i][j] != 0)
					{
						(*check)++;
						error[i][j] = -1;
						errorR1[i][m] = -1;
						break;
					}
					
					if (arr[i][j] == arr2[i][m] && arr[i][j] != 0)
					{

						(*check)++;
						error[i][j] = -1;
						errorR2[i][m] = -1;
						break;
					}
					
					if (arr[j][i] == arc1[m][i] && arr[j][i] != 0)
					{
						(*check)++;
						error[j][i] = -1;
						errorC1[m][i] = -1;
						break;
					}
					
					if (arr[j][i] == arc2[m][i] && arr[j][i] != 0)
					{
						(*check)++;
						error[j][i] = -1;
						errorC2[m][i] = -1;
						break;
					}
					

				}
				
			}
			
		}
	
	}
	

}

void step_checker_reset(int arr[3][3], int arr1[3][3], int arr2[3][3], int arc1[3][3], int arc2[3][3], int* check, int error[3][3], int errorR1[3][3], int errorR2[3][3], int errorC1[3][3], int errorC2[3][3])
{
	int i, j, k;
	int counter = 0, counterR1 = 0, counterR2 = 0, counterC1 = 0, counterC2 = 0;
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			for (k = 0; k < 3; k++)
			{
				if ((i != k || k != j) && arr[i][j] != 0)
				{
					if (arr[i][j] == arr[j][k])
						counter++;
				}
				if(arr[i][j]!=0)
				{	
				if (arr[i][j] == arr1[i][k])
						counterR1++;
				if (arr[i][j] == arr2[i][k])
						counterR2++;
				if (arr[i][j] == arc1[k][j])
						counterC1++;
				if (arr[i][j] == arc2[k][j])
						counterC2++;
				}
			}
		}
	}
	
	if (counter == 0 && counterR1 == 0 && counterR2 == 0 && counterC1 == 0 && counterC2 == 0)
	{
		for (i = 0; i < 3; i++)
			for (j = 0; j < 3; j++)
			{
				error[i][j] = 0;
				errorR1[i][j] = 0;
				errorR2[i][j] = 0;
				errorC1[i][j] = 0;
				errorC2[i][j] = 0;
				
			}
	}
}

int number_unassigned(int sudoku[9][9], int* row, int* col)
{
	int empty_cell = 0;
	int i, j;
	for (i = 0; i < 9; i++)
	{
		for (j = 0; j < 9; j++)
		{
			if (sudoku[i][j] == 0)
			{
				*row = i;
				*col = j;
				empty_cell = 1;
				return empty_cell;
			}
		}
	}
	return empty_cell;
}

int is_safe(int sudoku[9][9], int n, int r, int c)
{
	int i, j;
	for (i = 0; i < 9; i++)
	{
		if (sudoku[r][i] == n)
			return 0;
	}
	for (i = 0; i < 9; i++)
	{
		if (sudoku[i][c] == n)
			return 0;
	}
	int row_start = (r / 3) * 3;
	int col_start = (c / 3) * 3;
	for (i = row_start; i < row_start + 3; i++)
	{
		for (j = col_start; j < col_start + 3; j++)
		{
			if (sudoku[i][j] == n)
				return 0;
		}
	}
	return 1;
}

int solve_sudoku(int sudoku[9][9])
{
	int row;
	int col;
	int i;

	if (number_unassigned(sudoku, &row, &col) == 0)
		return 1;

	for (i = 1; i <= 9; i++)
	{
		if (is_safe(sudoku, i, row, col))
		{
			sudoku[row][col] = i;
			if (solve_sudoku(sudoku))
				return 1;
			sudoku[row][col] = 0;
		}
	}
	return 0;
}




