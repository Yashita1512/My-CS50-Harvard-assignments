#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "wav.h"

int check_format(WAVHEADER header);
int get_block_size(WAVHEADER header);

int main(int argc, char *argv[])
{
    // Ensure proper usage
    // TODO #1
    if(argc != 3)
    {
        printf("Usage improper\n");
        return 1;
    }

    // Open input file for reading
    // TODO #2
    FILE *input = fopen(argv[1], "rb");
    if (input == NULL)
    {
        printf("Input file invalid.\n");
        return 2;
    }

    // Read header
    // TODO #3
    WAVHEADER input_header;
    if (fread(&input_header, sizeof(WAVHEADER), 1, input) != 1)
    {
        fclose(input);
        return 3;
    }

    // Use check_format to ensure WAV format
    // TODO #4
    if(!check_format(input_header)){
        return 3;
    }

    // Open output file for writing
    // TODO #5
    FILE *output = fopen(argv[2], "wb");
    if (output == NULL)
    {
        printf("Output file invalid.\n");
        fclose(input);
        return 4;
    }

    // Write header to file
    // TODO #6
    if (fwrite(&input_header, sizeof(WAVHEADER), 1, output) != 1)
    {
        fclose(output);
        fclose(input);
        return 7;
    }

    // Use get_block_size to calculate size of block
    // TODO #7
    int block_size = get_block_size(input_header);

    // Write reversed audio to file
    // TODO #8
    //Take the file pointer to the start of last block;
    fseek(input, block_size, SEEK_END);

    //Declaring an array to store a block of audio data until it is written on the output file
    BYTE buffer[block_size];

    //checking if the file pointer is not in the wave header size
    while(ftell(input) - block_size > sizeof(input_header))
    {
        //Takes the file pointer to the start of next block to be read
        fseek(input, -2*block_size, SEEK_CUR);

        //Reads the block in reverse from the inpot file and writes the blocks in the output file in straight order
        fread(buffer, block_size, 1, input);
        fwrite(buffer, block_size, 1, output);
    }

    fclose(output);
    fclose(input);

    return 0;
}

int check_format(WAVHEADER header)
{
    // TODO #4
    if (header.format[0] == 'W' && header.format[1] == 'A' && header.format[2] == 'V' && header.format[3] == 'E')
    {
        return 1;
    }
    return 0;
}

int get_block_size(WAVHEADER header)
{
    // TODO #7
    int block_size = header.numChannels * header.bitsPerSample / 8;
    return block_size;
}
