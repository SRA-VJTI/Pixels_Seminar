// These are the necessary includes for the C++ standard library and POSIX headers that we
// will be using. We also declare that we will be using the std namespace.

#include <iostream>
#include <fstream>
#include <cstring>
#include <unistd.h>
#include <fcntl.h>

using namespace std;

// Now we are going to define the BMP header struct and its fields. The #pragma pack
// directive is used to ensure that the struct is packed tightly, with no padding between fields.
// The fields in the struct correspond to the various attributes of the BMP image file. you can also find it online 

#pragma pack(push, 1)

struct BMPHeader {
    uint16_t signature;
    uint32_t file_size;
    uint16_t reserved1;
    uint16_t reserved2;
    uint32_t offset;
    uint32_t header_size;
    uint32_t width;
    uint32_t height;
    uint16_t planes;
    uint16_t bit_depth;
    uint32_t compression;
    uint32_t image_size;
    uint32_t x_pixels_per_meter;
    uint32_t y_pixels_per_meter;
    uint32_t colors_used;
    uint32_t colors_important;
};

#pragma pack(pop)

// Now lets move on to the main function. We first declare the filename of the BMP image file that we 
// want to read, and then open the file using the open() function from the POSIX library.
// Note that if file is in another directory , whole path should be given.
// If the file cannot be opened, we print an error message to cerr and exit the program with a non-zero status code.

int main() {
    const char* filename = "image.bmp";
    int fd = open(filename, O_RDONLY);

    if (fd < 0) {
        cerr << "Error: could not open file" << endl;
        return 1;
    }

    // Next, we declare a BMPHeader struct and initialize it to all zeros using the memset() function.
    // The memset() function is a C standard library function that sets a block of memory with a particular value.
    //  It takes three arguments: a pointer to the block of memory, the value to set, and the size of the block.
    // We then use the read() function to read the BMP header from the file into the BMPHeader struct.
    // If the number of bytes read is not equal to the size of the header struct, we print an error
    // message and exit the program.

    // We then check that the BMP file has a valid signature (0x4D42), and that the image is 8-bit grayscale.
    // 0x4D42 is basically a BM format.
    // If either of these checks fails, we print an error message and exit the program.
    


    BMPHeader header;
    memset(&header, 0, sizeof(header));

    if (read(fd, &header, sizeof(header)) != sizeof(header)) {
        cerr << "Error: could not read BMP header" << endl;
        close(fd);
        return 1;
    }


    if (header.bit_depth != 8) {
        cerr << "Error: image is not 8-bit grayscale" << endl;
        close(fd);
        return 1;
    }


    // Finally check if the data's been stored
    cout << "Image size: " << header.width << "x" << header.height << endl;
    cout << "Bits per pixel: " << header.bit_depth << endl;
    cout << "Image data size: " << header.image_size << endl;



    
}
