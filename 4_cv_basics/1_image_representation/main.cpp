/*
MIT License

Copyright (c) 2023 Society of Robotics and Automation

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/
#include <iostream>
#include <fstream>
#include <vector>
#include <cstdint>
#include <SDL2/SDL.h>

// Pragma directives are used to control allignment of the padding.
// When reading the binary file, it is necessary to allign struct members in a meomory to avoid any misinterpretation.
// That is why, push is used  to set the packing to 1 byte, so that the BMPHeader struct is packed with no padding
// and the pop is used to restore the default packing setting after the BMPHeader struct is defined.
// More about data padding and alignment can be found here: https://www.geeksforgeeks.org/structure-member-alignment-padding-and-data-packing/
#pragma pack(push, 1)

// structure to store the file type data
struct BitMapFileHeader
{
    char file_type[2];          // "BM" (0x42, 0x4D)
    uint32_t file_size;         // Total size of the BMP file in bytes
    uint16_t reserved1;         // Unused (0)
    uint16_t reserved2;         // Unused (0)
    uint32_t pixel_data_offset; // Offset to the start of the pixel data
};

// structure to store image information data
struct BitMapInfoHeader
{
    uint32_t header_size;       // Size of this header (40 bytes)
    int32_t width;              // Width of the image in pixels
    int32_t height;             // Height of the image in pixels
    uint16_t planes;            // Number of color planes (1)
    uint16_t bits_per_pixel;    // Number of bits per pixel (8 for grayscale)
    uint32_t compression;       // Compression method (0 for uncompressed)
    uint32_t image_size;        // Size of the raw image data (0 for uncompressed)
    int32_t x_pixels_per_meter; // Horizontal resolution in pixels per meter
    int32_t y_pixels_per_meter; // Vertical resolution in pixels per meter
    uint32_t colors_used;       // Number of colors used in the image, 0 means all colors are used
    uint32_t colors_important;  // Number of important colors used, 0 means all colors are important
};

// Define the BMPImage structure that contains the File Type Data, Image Information data and the pixel data
struct BMPImage
{
    BitMapFileHeader header;   // File Type Data
    BitMapInfoHeader info;     // Image Information Data
    std::vector<uint8_t> data; // Raw Pixel Data
};
#pragma pack(pop)

// Main function
int main(int argc, char *argv[])
{
    if (argc != 2)
    { // Check if the user provided an input file and return error message if file not found
        std::cerr << "Usage: " << argv[0] << " <input_file.bmp>" << std::endl;
        return 1;
    }

    // Read the BMP image from file
    // open the input file using the filename passed in as an argument (stored in argv[1]).
    std::ifstream infile(argv[1], std::ios::binary);
    if (!infile)
    {
        std::cerr << "Error: Could not open input file: " << argv[1] << std::endl;
        return 1;
    }

    // create a BMPImage object to hold the image data.
    BMPImage image;

    // read the BMP image file and store the size of BitMapFileHeader (14 bytes) in image.header
    infile.read(reinterpret_cast<char *>(&image.header), sizeof(BitMapFileHeader));

    // check if the first two bytes of the BMP header indicate that this is a BMP image (the signature 'BM'). If not, print an error message which returns 1.
    if (image.header.file_type[0] != 'B' || image.header.file_type[1] != 'M')
    {
        std::cerr << "Error: Input file is not a BMP image" << std::endl;
        return 1;
    }

    // Output image file type data to the console
    std::cout << "\n-------------------- Bit Map File Header --------------------" << std::endl;
    std::cout << "File type: " << image.header.file_type << std::endl;
    std::cout << "File Size: " << image.header.file_size << std::endl;
    std::cout << "Pixel Data Offset: " << image.header.pixel_data_offset << std::endl;
    std::cout << "-------------------------------------------------------------\n" << std::endl;

    // read the BMP image file and store the size of BitMapInfoHeader (40 bytes) in image.info
    infile.read(reinterpret_cast<char *>(&image.info), sizeof(BitMapInfoHeader));
    if (image.info.bits_per_pixel != 8)
    {
        std::cerr << "Error: Input file is not an 8-bit BMP image" << std::endl;
        return 1;
    }

    int h = image.info.height;
    int w = image.info.width;

    // Output image attributes to console
    std::cout << "-------------------- Bit Map Info Header --------------------" << std::endl;
    std::cout << "Header Size: " << image.info.header_size << std::endl;
    std::cout << "Width: " << image.info.width << std::endl;
    std::cout << "Height: " << image.info.height << std::endl;
    std::cout << "Planes: " << image.info.planes << std::endl;
    std::cout << "Bits per pixel: " << static_cast<int>(image.info.bits_per_pixel) << std::endl;
    std::cout << "Compression type: " << image.info.compression << std::endl;
    std::cout << "Image Size: " << image.info.image_size << std::endl;
    std::cout << "X pixels per meter: " << image.info.x_pixels_per_meter << std::endl;
    std::cout << "Y pixels per meter: " << image.info.y_pixels_per_meter << std::endl;
    std::cout << "Number of Colors Used: " << image.info.colors_used << std::endl;
    std::cout << "Number of important colors: " << image.info.colors_important << std::endl;
    std::cout << "-------------------------------------------------------------\n" << std::endl;

    // if valid, the code allocates memory for the image data (the pixel values) by resizing the image.data vector to hold width x height elements.
    image.data.resize(w * h);

    // read the image data from the input file into the image.data vector
    infile.read(reinterpret_cast<char *>(image.data.data()), image.data.size());

    // To plot the data of each grayscale pixel fetched from the bitmap file, SDL2 library is used
    SDL_Event event;
    SDL_Renderer *renderer;
    SDL_Window *window;
    SDL_Init(SDL_INIT_VIDEO);

    // Create a Window and Renderer component to display on screen
    SDL_CreateWindowAndRenderer(w, h, 0, &window, &renderer);
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 0);
    SDL_RenderClear(renderer);

    // Plot each pixel on the screen based on its location
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            uint8_t k = image.data[j + i * h];
            SDL_SetRenderDrawColor(renderer, k, k, k, 255);

            // It is to be noted that SDL library follows botton left as the origin of the image
            SDL_RenderDrawPoint(renderer, j, h - i - 1);
        }
    }

    SDL_RenderPresent(renderer);

    // keeping the window active till the quit button is pressed
    while (1)
    {
        if (SDL_PollEvent(&event) && event.type == SDL_QUIT)
            break;
    }

    // Free up the resources
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return EXIT_SUCCESS;
}
