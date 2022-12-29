#include <stdio.h>
#include <string.h>

typedef enum {false, true} bool;

bool is_full(char map[])
{
    char base[9] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
    for (size_t i = 0; i < 9; i++)
    {
        if (map[i] == base[i]) return false;
    }
    return true;
    
}

char check_win(char map[])
{
    char mid = map[4];
    // diagonal
    if (mid == map[0] && mid == map[8]) return mid;
    if (mid == map[2] && mid == map[6]) return mid;
    // printf("diagonal");
    // lateral
    if (map[0] == map[1] && map[0] == map[2]) return map[2];
    if (map[3] == map[4] && map[3] == map[5]) return map[5];
    if (map[6] == map[7] && map[6] == map[8]) return map[8];
    // printf("lateral");
    // vertical
    if (map[0] == map[3] && map[0] == map[6]) return map[6];
    if (map[1] == map[4] && map[1] == map[7]) return map[7];
    if (map[2] == map[5] && map[2] == map[8]) return map[8];
    return '\0';
}

char convert_name(int player)
{

    if(player == 1) return 'X';
    else return 'O';
}

void print_table(char map[])
{
    printf("     |     |     \n");
    for (int i = 2; i >= 0; i--)
    {
        printf("  %c  |  %c  |  %c  \n", map[i * 3], map[i * 3 + 1], map[i * 3 + 2]);
        if (i != 0) printf("_____|_____|_____\n     |     |     \n");
    }
    printf("     |     |     \n");
    return;
}

int main(void)
{
    const char base[9] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
    char map[9];
    memcpy(map,base, 9);
    int i = 0;
    while (check_win(map) == '\0' && is_full(map) == false)
    {
        int people = convert_name(i % 2 + 1);
        i++;
        printf(" --------- It's %c's turn ! -------\n", people);
        print_table(map);
        int response = 0;
        while (response <= 0 || response > 9)
        {
            printf("Enter the number of your square : ");
            scanf("%d",&response);
            if (map[response - 1] != base[response - 1]) response = 0;
        }
        map[response-1] = people;
    }
    print_table(map);
    if (is_full(map))
    {
        printf("Tie !\n");
    }else{
        printf("Player %c win !", check_win(map));
    }

    return 0;
}