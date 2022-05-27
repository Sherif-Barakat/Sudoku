#define _CRT_SECURE_NO_WARNINGS
#include <conio.h>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "Sudoku.h"
#include <math.h>

int main()
{
	float choice;
	int box1[3][3] ,box2[3][3] ,box3[3][3],box4[3][3],box5[3][3],box6[3][3],box7[3][3],box8[3][3],box9[3][3];
	int box1_i[3][3], box2_i[3][3], box3_i[3][3], box4_i[3][3], box5_i[3][3], box6_i[3][3], box7_i[3][3], box8_i[3][3], box9_i[3][3];
	int error1[3][3], error2[3][3], error3[3][3], error4[3][3], error5[3][3], error6[3][3], error7[3][3], error8[3][3], error9[3][3];
	equating_zero(box1); equating_zero(box2); equating_zero(box3);
	equating_zero(box4); equating_zero(box5); equating_zero(box6);
	equating_zero(box7); equating_zero(box8); equating_zero(box9);
	equating_zero(error1); equating_zero(error2); equating_zero(error3);
	equating_zero(error4); equating_zero(error5); equating_zero(error6);
	equating_zero(error7); equating_zero(error8); equating_zero(error9);
	equating_matricies(box1_i, box1); equating_matricies(box2_i, box2); equating_matricies(box3_i, box3);
	equating_matricies(box4_i, box4); equating_matricies(box5_i, box5); equating_matricies(box6_i, box6);
	equating_matricies(box7_i, box7); equating_matricies(box8_i, box8); equating_matricies(box9_i, box9);
	int c1=0, c2=0, c3=0, c4=0, c5=0, c6=0, c7=0, c8=0, c9=0;
	int sudoku[9][9];
	int init_counter=0;
	int solve_check=0;
	float turns = 1, choice_init;
	int time_check;
	int solver_check1=0, solver_check2 = 0, solver_check3 = 0, solver_check4 = 0, solver_check5 = 0, solver_check6 = 0, solver_check7 = 0,
		solver_check8 = 0, solver_check9 = 0;
	int init_check1 = 0, init_check2 = 0, init_check3 = 0, init_check4 = 0, init_check5 = 0, init_check6 = 0, init_check7 = 0, init_check8 = 0, init_check9 = 0 ;
	int element_check=0,useless=0;
	
	printf("Welcome to the sudoku puzzle game");
	printf("\nThis program allows you to make a sudoku puzzle AND have someone else solve it!");
	printf("\nIt can also automatically solve your puzzle for you if it gets too hard!\n\n");
	
	
	do 
	{
		
		printf("\nPlease choose one of the following options:\n");
		printf("\n1-I want to make a puzzle manually");
		printf("\n2-Make a puzzle for me");
		printf("\n3-Start playing");
		printf("\n4-Reset the puzzle to its intial state");
		printf("\n5-Solve the puzzle for me");
		printf("\n6-Check my final solution");
		printf("\n7-Show me the current state of the puzzle");
		printf("\n8-Reset everything and start a new game");
		printf("\n9-Quit the game\n");
	
		
		if (scanf("%f", &choice) == 1 &&ceil(choice)-choice==0)
		{
			system("cls");
			printf("\t\033[1;36m  1 2 3   1 2 3   1 2 3\n\033[0m");
			print_puzzle(box1, box2, box3, box1_i, box2_i, box3_i, error1, error2, error3);
			print_puzzle(box4, box5, box6, box4_i, box5_i, box6_i, error4, error5, error6);
			print_puzzle(box7, box8, box9, box7_i, box8_i, box9_i, error7, error8, error9);
			printf("\t\033[1;36m-------------------------\033[0m");
			switch (int(choice))
			{

			case 1:

			{
				printf("\n\033[1;35mThis is the intial stage of the puzzle\nEnter a number between 1 and 9 in each box.\n\033[0m");
				do {
					
					printf("\n\033[1;35mPlease choose which 3x3 box you'd like to enter a number in(1-9):\033[0m");
					printf("\033[1;36m");
					if (scanf("%f", &choice_init)==1&&ceil(choice_init)-choice_init==0)
					{
						printf("\033[0m");
						switch (int(choice_init))
						{
						case 1:
							printf("\033[1;35m\nPlease enter the amount of elements you would like to enter in grid #1:\n\033[0m");
							init(box1, box1, box2, box3, box4, box5, box6, box7, box8, box9, &choice_init, &init_counter);
							break;
						case 2:
							printf("\n\033[1;35mPlease enter the amount of elements you would like to enter in grid #2:\n\033[0m");
							init(box2, box1, box2, box3, box4, box5, box6, box7, box8, box9, &choice_init, &init_counter);
							break;
						case 3:
							printf("\n\033[1;35mPlease enter the amount of elements you would like to enter in grid #3:\n\033[0m");
							init(box3, box1, box2, box3, box4, box5, box6, box7, box8, box9, &choice_init, &init_counter);
							break;
						case 4:
							printf("\n\033[1;35mPlease enter the amount of elements you would like to enter in grid #4:\n\033[0m");
							init(box4, box1, box2, box3, box4, box5, box6, box7, box8, box9, &choice_init, &init_counter);
							break;
						case 5:
							printf("\n\033[1;35mPlease enter the amount of elements you would like to enter in grid #5:\n\033[0m");
							init(box5, box1, box2, box3, box4, box5, box6, box7, box8, box9, &choice_init, &init_counter);
							break;
						case 6:
							printf("\n\033[1;35mPlease enter the amount of elements you would like to enter in grid #6:\n\033[0m");
							init(box6, box1, box2, box3, box4, box5, box6, box7, box8, box9, &choice_init, &init_counter);
							break;
						case 7:
							printf("\n\033[1;35mPlease enter the amount of elements you would like to enter in grid #7:\n\033[0m");
							init(box7, box1, box2, box3, box4, box5, box6, box7, box8, box9, &choice_init, &init_counter);
							break;
						case 8:
							printf("\n\033[1;35mPlease enter the amount of elements you would like to enter in grid #8:\n\033[0m");
							init(box8, box1, box2, box3, box4, box5, box6, box7, box8, box9, &choice_init, &init_counter);
							break;
						case 9:
							printf("\n\033[1;35mPlease enter the amount of elements you would like to enter in grid #9:\n\033[0m");
							init(box9, box1, box2, box3, box4, box5, box6, box7, box8, box9, &choice_init, &init_counter);
							break;
						default:
							printf("\n\033[1;31mIncorrect input,please try again.\033[0m");
							break;
						}
						printf("\n\n\033[1;35mDo you want to enter another number? enter 0 to stop making the puzzle or enter any other number to continue playing\n\033[0m");
						printf("\033[1;36m");
						printf("\033[0m");
						if (scanf("%f", &turns) != 1&&ceil(turns)-turns==0)
						{
							printf("\033[0m");
							printf("\033[1;31m\n\nThis program only accepts integers for inputs.Thanks for playing!\n\n\033[0m");
							exit(0);
						}
					}
					else
					{
						printf("\033[1;31m\n\nThis program only accepts integers for inputs.Thanks for playing1!\n\n\033[0m");
						exit(0);
					}
				} while (turns != 0 && init_counter <= 9);


				equating_zero(error1); equating_zero(error2); equating_zero(error3);
				equating_zero(error4); equating_zero(error5); equating_zero(error6);
				equating_zero(error7); equating_zero(error8); equating_zero(error9);
				is_valid(box1, box2, box3, box4, box7, &init_check1,&useless);  is_valid(box2, box1, box3, box5, box8, &init_check2, &useless);
				is_valid(box3, box1, box2, box6, box9, &init_check3, &useless); is_valid(box4, box5, box6, box1, box7, &init_check4, &useless);
				is_valid(box5, box4, box6, box2, box8, &init_check5, &useless); is_valid(box6, box4, box5, box3, box9, &init_check6, &useless);
				is_valid(box7, box8, box9, box1, box4, &init_check7, &useless); is_valid(box8, box7, box9, box2, box5, &init_check8, &useless);
				is_valid(box9, box7, box8, box3, box6, &init_check9, &useless);
				
				system("cls");
				if (init_check1 == 0 && init_check2 == 0 && init_check3 == 0 && init_check4 == 0 && init_check5 == 0 && init_check6 == 0 && init_check7 == 0 && init_check8 == 0 && init_check9 == 0)
				{
					equating_matricies(box1_i, box1); equating_matricies(box2_i, box2); equating_matricies(box3_i, box3);
					equating_matricies(box4_i, box4); equating_matricies(box5_i, box5); equating_matricies(box6_i, box6);
					equating_matricies(box7_i, box7); equating_matricies(box8_i, box8); equating_matricies(box9_i, box9);
					if (init_counter < 9)
					{
						printf("\n\n\033[1;31mThe puzzle you entered has too few elements to be valid,please enter more elements and try again.\033[0m\n\n");
						
					}
				}
				else
				{
					printf("\n\n\033[1;31mThe puzzle you entered is invalid,please enter a correct puzzle and try again.\033[0m\n\n");
					equating_zero(box1); equating_zero(box2); equating_zero(box3);
					equating_zero(box4); equating_zero(box5); equating_zero(box6);
					equating_zero(box7); equating_zero(box8); equating_zero(box9);
				}
			
				printf("\nThe entered puzzle is:\n");
				printf("\t\033[1;36m  1 2 3   1 2 3   1 2 3\n\033[0m");
				print_puzzle(box1, box2, box3, box1_i, box2_i, box3_i, error1, error2, error3);
				print_puzzle(box4, box5, box6, box4_i, box5_i, box6_i, error4, error5, error6);
				print_puzzle(box7, box8, box9, box7_i, box8_i, box9_i, error7, error8, error9);
				printf("\t\033[1;36m-------------------------\033[0m");
				break;
			}

			case 2:

			{

				random(sudoku, box1, box2, box3, box4, box5, box6, box7, box8, box9);
				equating_matricies(box1_i, box1); equating_matricies(box2_i, box2); equating_matricies(box3_i, box3);
				equating_matricies(box4_i, box4); equating_matricies(box5_i, box5); equating_matricies(box6_i, box6);
				equating_matricies(box7_i, box7); equating_matricies(box8_i, box8); equating_matricies(box9_i, box9);
				system("cls");
				printf("\nThe random puzzle is... :\n");
				printf("\t\033[1;36m  1 2 3   1 2 3   1 2 3\n\033[0m");
				print_puzzle(box1, box2, box3, box1_i, box2_i, box3_i, error1, error2, error3);
				print_puzzle(box4, box5, box6, box4_i, box5_i, box6_i, error4, error5, error6);
				print_puzzle(box7, box8, box9, box7_i, box8_i, box9_i, error7, error8, error9);
				printf("\t\033[1;36m-------------------------\033[0m");
				init_counter = 10;

				break;
			}

			case 3:

			{
				if (init_counter > 9)
				{
					system("cls");
					printf("\n\033[1;35mYou can now start playing the game,good luck!");
					printf("\nYou have 3 minutes to complete the puzzle\nGood luck!");
					printf("\nPlease keep in mind that this sudoku puzzle is divided into 9 matricies of order 3x3.\n\033[0m");
					printf("\t\033[1;36m  1 2 3   1 2 3   1 2 3\n\033[0m");
					print_puzzle(box1, box2, box3, box1_i, box2_i, box3_i, error1, error2, error3);
					print_puzzle(box4, box5, box6, box4_i, box5_i, box6_i, error4, error5, error6);
					print_puzzle(box7, box8, box9, box7_i, box8_i, box9_i, error7, error8, error9);
					printf("\t\033[1;36m-------------------------\033[0m");
					play(box1, box2, box3, box4, box5, box6, box7, box8, box9, box1_i, box2_i, box3_i, box4_i, box5_i, box6_i, box7_i, box8_i, box9_i, &time_check, error1, error2, error3, error4
						, error5, error6, error7, error8, error9);
					system("cls");
					if (time_check == 1)
					{
						printf("\n\033[1;31mSorry,time is up!\nBetter luck next time!\033[0m");
						exit(0);

					}
					printf("\nThe puzzle so far... :\n");
					printf("\t\033[1;36m  1 2 3   1 2 3   1 2 3\n\033[0m");
					print_puzzle(box1, box2, box3, box1_i, box2_i, box3_i, error1, error2, error3);
					print_puzzle(box4, box5, box6, box4_i, box5_i, box6_i, error4, error5, error6);
					print_puzzle(box7, box8, box9, box7_i, box8_i, box9_i, error7, error8, error9);
					printf("\t\033[1;36m-------------------------\033[0m");
					if (time_check == 1)
					{
						equating_matricies(box1, box1_i); equating_matricies(box2, box2_i); equating_matricies(box3, box3_i);
						equating_matricies(box4, box4_i); equating_matricies(box5, box5_i); equating_matricies(box6, box6_i);
						equating_matricies(box7, box7_i); equating_matricies(box8, box8_i); equating_matricies(box9, box9_i);
					}
					break;
				}
				else
				{
					printf("\n\n\033[1;31mYou can't play without making a puzzle or generating a random puzzle.\n\n\033[0m");
					break;
				}
			}
			

			case 4:
			{
				system("cls");
				equating_matricies(box1, box1_i); equating_matricies(box2, box2_i); equating_matricies(box3, box3_i);
				equating_matricies(box4, box4_i); equating_matricies(box5, box5_i); equating_matricies(box6, box6_i);
				equating_matricies(box7, box7_i); equating_matricies(box8, box8_i); equating_matricies(box9, box9_i);
				equating_zero(error1); equating_zero(error2); equating_zero(error3);
				equating_zero(error4); equating_zero(error5); equating_zero(error6);
				equating_zero(error7); equating_zero(error8); equating_zero(error9);
				printf("\nResetting puzzle...");
				printf("\nThe entered puzzle is:\n");
				printf("\t\033[1;36m  1 2 3   1 2 3   1 2 3\n");
				print_init_puzzle(box1_i, box2_i, box3_i); print_init_puzzle(box4_i, box5_i, box6_i); print_init_puzzle(box7_i, box8_i, box9_i);
				printf("\t-------------------------\033[0m");
				break;
			}

			case 5:

			{
				element_check = 0;
				system("cls");
				is_valid(box1_i, box2_i, box3_i, box4_i, box7_i, &solver_check1,&element_check);  is_valid(box2_i, box1_i, box3_i, box5_i, box8_i, &solver_check2, &element_check);
				is_valid(box3_i, box1_i, box2_i, box6_i, box9_i, &solver_check3, &element_check); is_valid(box4_i, box5_i, box6_i, box1_i, box7_i, &solver_check4, &element_check);
				is_valid(box5_i, box4_i, box6_i, box2_i, box8_i, &solver_check5, &element_check); is_valid(box6_i, box4_i, box5_i, box3_i, box9_i, &solver_check6, &element_check);
				is_valid(box7_i, box8_i, box9_i, box1_i, box4_i, &solver_check7, &element_check); is_valid(box8_i, box7_i, box9_i, box2_i, box5_i, &solver_check8, &element_check);
				is_valid(box9_i, box7_i, box8_i, box3_i, box6_i, &solver_check9, &element_check);
				
				if (solver_check1 == 0 && solver_check2 == 0 && solver_check3 == 0 && solver_check4 == 0 && solver_check5 == 0 && solver_check6 == 0 && solver_check7 == 0 && solver_check8 == 0 && solver_check9 == 0 && element_check<72)
				{
					sudoku_init(sudoku, box1_i, box2_i, box3_i, box4_i, box5_i, box6_i, box7_i, box8_i, box9_i);
					solve_sudoku(sudoku);
					if (solve_sudoku(sudoku))
						solve_check = 1;
					if (solve_check == 1)
					{
						equating_zero(error1); equating_zero(error2); equating_zero(error3);
						equating_zero(error4); equating_zero(error5); equating_zero(error6);
						equating_zero(error7); equating_zero(error8); equating_zero(error9);
						sudoku_reverse(sudoku, box1, box2, box3, box4, box5, box6, box7, box8, box9);
						system("cls");
						printf("\nThe final solution is... :\n");
						printf("\t\033[1;36m  1 2 3   1 2 3   1 2 3\n\033[0m");
						print_puzzle(box1, box2, box3, box1_i, box2_i, box3_i, error1, error2, error3);
						print_puzzle(box4, box5, box6, box4_i, box5_i, box6_i, error4, error5, error6);
						print_puzzle(box7, box8, box9, box7_i, box8_i, box9_i, error7, error8, error9);
						printf("\t\033[1;36m-------------------------\033[0m");

					}
					else
					{
						sudoku_reverse(sudoku, box1, box2, box3, box4, box5, box6, box7, box8, box9);
						system("cls");
						printf("\n\033[1;31mThe entered puzzle doesn't have a solution,change the puzzle and try again.\n\033[0m");
						printf("\t\033[1;36m  1 2 3   1 2 3   1 2 3\n\033[0m");
						print_puzzle(box1, box2, box3, box1_i, box2_i, box3_i, error1, error2, error3);
						print_puzzle(box4, box5, box6, box4_i, box5_i, box6_i, error4, error5, error6);
						print_puzzle(box7, box8, box9, box7_i, box8_i, box9_i, error7, error8, error9);
						printf("\t\033[1;36m-------------------------\033[0m");

					}
				}
				else
				{
					system("cls");
					printf("\n\033[1;31mThe entered puzzle doesn't have a solution,change the puzzle and try again.\n\033[0m");
					printf("\t\033[1;36m  1 2 3   1 2 3   1 2 3\n\033[0m");
					print_puzzle(box1, box2, box3, box1_i, box2_i, box3_i, error1, error2, error3);
					print_puzzle(box4, box5, box6, box4_i, box5_i, box6_i, error4, error5, error6);
					print_puzzle(box7, box8, box9, box7_i, box8_i, box9_i, error7, error8, error9);
					printf("\t\033[1;36m-------------------------\033[0m");
				}
				break;
			}

			case 6:

			{

				system("cls");
				printf("\nChecking your final solution...");

				final_checker(box1, box2, box3, box4, box7, &c1); final_checker(box2, box1, box3, box5, box8, &c2);
				final_checker(box3, box1, box2, box6, box9, &c3); final_checker(box4, box5, box6, box1, box7, &c4);
				final_checker(box5, box4, box6, box2, box8, &c5); final_checker(box6, box4, box5, box3, box9, &c6);
				final_checker(box7, box8, box9, box1, box4, &c7); final_checker(box8, box7, box9, box2, box5, &c8);
				final_checker(box9, box7, box8, box3, box6, &c9);
				if (c1 != 0 || c2 != 0 || c3 != 0 || c4 != 0 || c5 != 0 || c6 != 0 || c7 != 0 || c8 != 0 || c9 != 0)
					printf("\033[1;31m\n\nThe solution is incorrect,please try again\n\n\033[0m");
				if (c1 == 0 && c2 == 0 && c3 == 0 && c4 == 0 && c5 == 0 && c6 == 0 && c7 == 0 && c8 == 0 && c9 == 0)
					printf("\033[1;36m\n\nCongratulations! Your solution is correct!\n\n\033[0m");

				printf("\t\033[1;36m  1 2 3   1 2 3   1 2 3\n\033[0m");
				print_puzzle(box1, box2, box3, box1_i, box2_i, box3_i, error1, error2, error3);
				print_puzzle(box4, box5, box6, box4_i, box5_i, box6_i, error4, error5, error6);
				print_puzzle(box7, box8, box9, box7_i, box8_i, box9_i, error7, error8, error9);
				printf("\t\033[1;36m-------------------------\033[0m");
				break;
			}
			case 7:
			{
				system("cls");
				printf("\n\nThe current state of the puzzle is:\n\n");
				printf("\t\033[1;36m  1 2 3   1 2 3   1 2 3\n\033[0m");
				print_puzzle(box1, box2, box3, box1_i, box2_i, box3_i, error1, error2, error3);
				print_puzzle(box4, box5, box6, box4_i, box5_i, box6_i, error4, error5, error6);
				print_puzzle(box7, box8, box9, box7_i, box8_i, box9_i, error7, error8, error9);
				printf("\t\033[1;36m-------------------------\033[0m");
				break;
			}
			case 8:

			{
				equating_zero(box1); equating_zero(box2); equating_zero(box3);
				equating_zero(box4); equating_zero(box5); equating_zero(box6);
				equating_zero(box7); equating_zero(box8); equating_zero(box9);
				equating_zero(error1); equating_zero(error2); equating_zero(error3);
				equating_zero(error4); equating_zero(error5); equating_zero(error6);
				equating_zero(error7); equating_zero(error8); equating_zero(error9);
				equating_matricies(box1_i, box1); equating_matricies(box2_i, box2); equating_matricies(box3_i, box3);
				equating_matricies(box4_i, box4); equating_matricies(box5_i, box5); equating_matricies(box6_i, box6);
				equating_matricies(box7_i, box7); equating_matricies(box8_i, box8); equating_matricies(box9_i, box9);
				system("cls");
				printf("\t\033[1;36m  1 2 3   1 2 3   1 2 3\n\033[0m");
				print_puzzle(box1, box2, box3, box1_i, box2_i, box3_i, error1, error2, error3);
				print_puzzle(box4, box5, box6, box4_i, box5_i, box6_i, error4, error5, error6);
				print_puzzle(box7, box8, box9, box7_i, box8_i, box9_i, error7, error8, error9);
				printf("\t\033[1;36m-------------------------\033[0m");
				break;
			}

			default:

			{
				if (choice == 9)
					printf("\n\n\033[1;35mThanks for playing!\033[0m\n\n");
				else
				{
					printf("\n\033[1;31mIncorrect input,Enter any number to exit or 1 to rerun the program:\n\033[0m");
					printf("\033[1;36m");
					if(scanf("%f", &choice)!=1&&ceil(choice)-choice==0)
					{
						printf("\033[0m");
						printf("\033[1;31m\n\nThis program only accepts integers for inputs.Thanks for playing!\n\n\033[0m");
						exit(0);
					}
					printf("\033[0m");
				}

				break;
			}


			}
		}
		else
		{
			printf("\033[1;31m\n\nThis program only accepts integers for inputs.Thanks for playing!\n\n\033[0m");
			exit(0);
		}
	} while (choice>=1 && choice <=8);
	return 0;
}



