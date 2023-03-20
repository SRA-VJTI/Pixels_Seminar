#include <iostream>
#include <fstream>
#include <vector>
#include <cstdint>
#include <SDL2/SDL.h>


// Pragma directives are used to control allignment of the padding.
// When reading the binary file, it is necessary to allign struct members in a meomory to avoid any misinterpretation.
// That is why, push is used  to set the packing to 1 byte, so that the BMPHeader struct is packed with no padding
// and the pop is used to restore the default packing setting after the BMPHeader struct is defined.
#pragma pack(push, 1)
struct BMPHeader {
    char signature[2];      // "BM" (0x42, 0x4D)
    uint32_t file_size;     // Total size of the BMP file in bytes
    uint16_t reserved1;     // Unused (0)
    uint16_t reserved2;     // Unused (0)
    uint32_t data_offset;   // Offset to the start of the pixel data
    uint32_t header_size;  // Size of this header (40 bytes)
    int32_t width;          // Width of the image in pixels
    int32_t height;          // Height of the image in pixels
    uint16_t planes;         // Number of color planes (1)
    uint16_t bits_per_pixel;   // Number of bits per pixel (8 for grayscale)
    uint32_t compression;     // Compression method (0 for uncompressed)
    uint32_t image_size;       // Size of the raw image data (0 for uncompressed
    int32_t x_pixels_per_meter;  // Horizontal resolution in pixels per meter
    int32_t y_pixels_per_meter;  // Vertical resolution in pixels per meter
    uint32_t colors_used;         // Number of colors used in the image, 0 means all colors are used
    uint32_t colors_important;    // Number of important colors used, 0 means all colors are important
};

// Define the BMPImage structure that contains the BMPHeader and the pixel data
struct BMPImage {
    BMPHeader header;
    std::vector<uint8_t> data;
};
#pragma pack(pop)


// Main function
int main(int argc, char* argv[]) {
    if (argc != 2) {                                // Check if the user provided an input file and return error message if file not found
        std::cerr << "Usage: " << argv[0] << " <input_file.bmp>" << std::endl;
        return 1;
    }

    // Read the BMP image from file
    // open the input file using the filename passed in as an argument (stored in argv[1]).
    std::ifstream infile(argv[1], std::ios::binary);
    if (!infile) {
        std::cerr << "Error: Could not open input file: " << argv[1] << std::endl;
        return 1;
    }
    // create a BMPImage object to hold the image data.
    // check if the first two bytes of the BMP header indicate that this is a BMP image (the signature 'BM'). If not, print an error message which returns 1.
    
    BMPImage image;
    infile.read(reinterpret_cast<char*>(&image.header), sizeof(BMPHeader));
    if (image.header.signature[0] != 'B' || image.header.signature[1] != 'M') {
        std::cerr << "Error: Input file is not a BMP image" << std::endl;
        return 1;
    }
    if (image.header.bits_per_pixel != 8) {
        std::cerr << "Error: Input file is not an 8-bit BMP image" << std::endl;
        return 1;
    }

    // if valid, the code allocates memory for the image data (the pixel values) by resizing the image.data vector to hold width x height elements.
    // read the image data from the input file into the image.data vector
    image.data.resize(image.header.width * image.header.height);
    infile.read(reinterpret_cast<char*>(image.data.data()), image.data.size());
           
    // Output image attributes to console
    std::cout << "Image width: " << image.header.width << std::endl;
    std::cout << "Image height: " << image.header.height << std::endl;
    std::cout << "Color depth: " << static_cast<int>(image.header.bits_per_pixel) << " bits per pixel" << std::endl;
    std::cout << "Compression type: " << image.header.compression << std::endl;
    std::cout << "Pixel array offset: " << image.header.data_offset << std::endl;



    // Editing the grayscale bitmap image into black and white form, i.e. editing the image
    std::vector<uint8_t> bw_data(image.header.width * image.header.height);
    for (int y = 0; y < image.header.height; y++) {
        for (int x = 0; x < image.header.width; x++) {
            uint8_t b = image.data[(image.header.height - y - 1) * image.header.width + x];
            uint8_t bw = (b > 127) ? 255 : 0;
            bw_data[y * image.header.width + x] = bw;
        }
    }

    // Create a window and a surface for displaying the image
    SDL_Window* window = SDL_CreateWindow("Image Viewer", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, image.header.width, image.header.height, SDL_WINDOW_SHOWN);
    SDL_Surface* surface = SDL_GetWindowSurface(window);

    // Lock the surface to get a pointer to its pixel data
    SDL_LockSurface(surface);
    uint8_t* pixels = static_cast<uint8_t*>(surface->pixels);


    // Copy the grayscale image data to the surface
    int pitch = surface->pitch;
    for (int y = 0; y < image.header.height; y++) {
        for (int x = 0; x < image.header.width; x++) {
            uint8_t* pixel = pixels + y * pitch + x;
            *pixel = bw_data[y * image.header.width + x];
        }
    }

    // Unlock the surface
    SDL_UnlockSurface(surface);

    // Update the window with the new surface data
    SDL_UpdateWindowSurface(window);

    // Wait for the user to close the window
    bool quit = false;
    while (!quit) {
        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                quit = true;
            }
        }
    }

    // Clean up resources
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}
