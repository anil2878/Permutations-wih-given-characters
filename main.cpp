

#include <stdio.h>

#define INPUT_LENGTH 4
#define OUTPUT_LENGTH 4
char inputChar[4] = { 'A', 'B', 'C', 'D' };

void printOutPut(char *str)
{
    static int count = 0;
    printf("%d : %s\n", count++, str);
}

void perMute(char *output, int pos)
{
    if (pos == OUTPUT_LENGTH)
    {
        output[pos] = '\0';
        printOutPut(output);
        return;
    }
    int i;
    for (i = 0; i < INPUT_LENGTH; i++)
    {
        output[pos] = inputChar[i];
        pos++;
        perMute(output, pos);
        pos--;
    }
}

void swap(int i, int curPos)
{
    char tmp = inputChar[i];
    inputChar[i] = inputChar[curPos];
    inputChar[curPos] = tmp;
}


void permuteWithOutRep(char *output, int pos)
{
    if (pos == OUTPUT_LENGTH)
    {
        output[pos] = '\0';
        printOutPut(output);
        return;
    }

    int i;
    for (i = pos; i < INPUT_LENGTH; i++)
    {
        swap(i, pos);
        output[pos] = inputChar[pos];
        permuteWithOutRep(output, pos + 1);
        swap(i, pos);
    }
}

int main()
{
    char output[OUTPUT_LENGTH + 1] = { '\0' };
    perMute(output, 0);
    return 0;
}
