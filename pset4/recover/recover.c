#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
typedef uint8_t BYTE;
int newfile(BYTE buffer[]);
char str[8];

int main(int argc, char *argv[])
{
    BYTE buffer[512];
    // Check command-line arguments
    if (argc != 2)
    {
        printf("Usage: ./recover card.raw\n");
        return 1;
    }

    FILE* input = fopen(argv[1], "r");
    if (input == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }
    int i = 0;
    FILE* output;
    while(fread(buffer, 512, 1, input))
        {
        if (newfile(buffer))
        {
            if (i == 0)
            {
                sprintf(str, "%03i.jpg",i++);
                output = fopen(str, "w");
            }
            else
            {
            fclose(output);
            sprintf(str, "%03i.jpg",i++);
            output = fopen(str, "w");
            }
            fwrite(buffer, 512, 1, output);
        }
        else
        {
        if (i != 0)
            {
                fwrite(buffer, 512, 1, output);
            }
        }
    }
    // Close files
    fclose(input);
    fclose(output);
}
int newfile(BYTE buffer[])
{
    if(buffer[0] == 0xff && buffer[1]== 0xd8 && buffer[2] == 0xff)
    {
        if (buffer[3]== 0xe0 ||buffer[3]== 0xe1 ||buffer[3]== 0xe2 ||buffer[3]== 0xe3 ||buffer[3]== 0xe4 ||buffer[3]== 0xe5 ||buffer[3]== 0xe6 ||buffer[3]== 0xe7 ||buffer[3]== 0xe8 ||buffer[3]== 0xe9 ||buffer[3]== 0xea ||buffer[3]== 0xeb ||buffer[3]== 0xec ||buffer[3]== 0xed ||buffer[3]== 0xee||buffer[3]== 0xef)
        {
            return 1;
        }
        else
        {
            return 0;
        }

    }
    else
    {
        return 0;
    }
}
