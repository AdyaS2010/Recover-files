#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    // Ensure correct usage
    if (argc != 2)
    {
        printf("Usage: ./recover image\n");
        return 1;
    }

    // Open the forensic image
    FILE *file = fopen(argv[1], "r");
    if (file == NULL)
    {
        printf("Could not open %s.\n", argv[1]);
        return 1;
    }

    // Define a buffer of size 512
    uint8_t buffer[512];

    // Initialize JPEG counter and output file pointer
    int jpg_count = 0;
    FILE *out_file = NULL;

    // Read data from the forensic image
    while (fread(buffer, 512, 1, file))
    {
        // Check if a new JPEG is starting
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff &&
            (buffer[3] & 0xf0) == 0xe0)
        {
            // If an output file is already open, close it
            if (out_file != NULL)
            {
                fclose(out_file);
            }

            // Create a new filename
            char filename[8];
            sprintf(filename, "%03i.jpg", jpg_count++);

            // Open the output file
            out_file = fopen(filename, "w");
            if (out_file == NULL)
            {
                printf("Could not create %s.\n", filename);
                return 1;
            }
        }

        // If an output file is open, write to it
        if (out_file != NULL)
        {
            fwrite(buffer, 512, 1, out_file);
        }
    }

    // Close any remaining files
    if (out_file != NULL)
    {
        fclose(out_file);
    }

    fclose(file);

    return 0;
}
