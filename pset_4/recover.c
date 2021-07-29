#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef uint8_t BYTE;

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: %s image", argv[0]);
        return 1;
    }
    // Load a card
    FILE *f = fopen(argv[1], "r");
    if (!f)
    {
        printf("Cannot open %s file", argv[1]);
        return 2;
    }
    BYTE buffer[512];
    FILE *image = NULL;
    int cnt = 0;
    char filename[8];
    while (fread(&buffer, 512, 1, f))
    {
        if (buffer[0] == 0xff
            && buffer[1] == 0xd8
            && buffer[2] == 0xff
            && (buffer[3] & 0xe0) == 0xe0)
        {
            sprintf(filename, "%03i.jpg", cnt);

            image = fopen(filename, "w");

            cnt++;
        }

        if (image != NULL)
        {
            fwrite(buffer, sizeof(char), 512, image);
        }
    }

    fclose(f);
    fclose(image);
    return 0;
}
