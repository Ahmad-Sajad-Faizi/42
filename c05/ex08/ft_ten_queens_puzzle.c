#include <unistd.h>

void    ft_putchar(char c)
{
        write(1, &c, 1);
}

int     ft_is_safe(int board[10], int col, int row)
{
        int     i;

        i = 0;
        while (i < col)
        {
                if (board[i] == row || (board[i] - row == col - i) || (row - board[i] == col - i))
                        return (0);
                i++;
        }
        return (1);
}

void    ft_print_solution(int board[10])
{
        int     i;

        i = 0;
        while (i < 10)
        {
                ft_putchar(board[i] + '0');
                i++;
        }
        ft_putchar('\n');
}

void    ft_solve(int board[10], int col, int *count)
{
        int     row;

        if (col == 10)
        {
                ft_print_solution(board);
                (*count)++;
                return ;
        }
        row = 0;
        while (row < 10)
        {
                if (ft_is_safe(board, col, row))
                {
                        board[col] = row;
                        ft_solve(board, col + 1, count);
                }
                row++;
        }
}

int     ft_ten_queens_puzzle(void)
{
        int     board[10];
        int     count;

        count = 0;
        ft_solve(board, 0, &count);
        return (count);
}
/*
#include <stdio.h>
int     main(void)
{
        int solutions;
        printf("solutions found: \n");
        solutions = ft_ten_queens_puzzle();
        printf("\n Total number of solutions: %d\n", solutions);
        return(0);
}
*/
