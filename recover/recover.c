#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int main(int argc, char *argv[])
{
    if (argc != 2) {
        printf("Improper usage.\n");
        return 1;
    }

    FILE *inputf = fopen(argv[1], "rb");

    if (inputf == NULL)
    {
        printf("Cannot open the image.\n");
        return 2;
    }

    typedef uint8_t BYTE;
    BYTE buffer[512];
    int j = 0;
    FILE *output_file = NULL;
    char img_name[8];

    while(fread(buffer, sizeof(char), 512, inputf) == 512)
    {
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            if (output_file != NULL)
            {
                fclose(output_file);
            }

            sprintf(img_name, "%03i.jpg", j);
            output_file = fopen(img_name, "wb");
            j++;

            if (output_file == NULL)
            {
                fclose(inputf);
                return 3;
            }
        }

         if (output_file != NULL)
         {
            if (fwrite(buffer, sizeof(BYTE), 512, output_file) != 512)
            {
                fclose(output_file);
                fclose(inputf);
                return 4;
            }
        }
    }

    if (output_file != NULL)
    {
        fclose(output_file);
    }

    fclose(inputf);
    return 0;
}

