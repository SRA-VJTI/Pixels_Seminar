  // These are the header files being included. iostream and vector are standard C++ header files. 
// SDL.h is the header file for the Simple DirectMedia Layer library and SDL_image.h is the header file 
// for the SDL2_image library, which provides support for loading various image formats.
#include <iostream>
#include <vector>
#include "/usr/include/SDL2/SDL.h"
#include "/usr/include/SDL2/SDL_image.h"

// This line brings the entire std namespace into scope.
using namespace std;

// This is the beginning of the main function. argc is the number of command line arguments passed to the program,
// and argv is an array of strings containing those arguments.
int main(int argc, char** argv) {
    // This code checks whether the user has provided a filename as a command line argument.
    // If not, it prints a usage message and exits the program.
    if (argc < 2) {
        cout << "Usage: " << argv[0] << "image.bmp" << endl;
        return 0;
    }
    const char* filename = argv[1];


    // This code initializes the SDL2 library for video output. If it fails, an error message is printed
    // and the program exits with an error code of 1.
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        cerr << "SDL_Init failed: " << SDL_GetError() << endl;
        return 1;
    }
    // This code creates a window with the title "Image" and a size of 640x480 pixels. If it fails,
    // an error message is printed and the program exits with an error code of 1.
    SDL_Window* window = SDL_CreateWindow("Image", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 640, 480, SDL_WINDOW_SHOWN);

    if (window == nullptr) {
        cerr << "SDL_CreateWindow failed: " << SDL_GetError() << endl;
        SDL_Quit();
        return 1;
    }

    // This code creates a renderer for the window using hardware acceleration. If it fails,
    // an error message is printed, the window is destroyed, and the program exits with an error code of 1.
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    if (renderer == nullptr) {
        cerr << "SDL_CreateRenderer failed: " << SDL_GetError() << endl;
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 1;
    }

    // This code loads an image from the file specified by filename using the SDL2_image library.
    // If it fails, an error message is printed, the renderer and window are destroyed, and the program
    // exits with an error code of 1.
    SDL_Surface* surface = IMG_Load(filename);

    if (surface == nullptr) {
        cerr << "IMG_Load failed: " << IMG_GetError() << endl;
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 1;
    }

    // This code checks whether the image has a supported pixel format. In this case, 
    // the program only supports 8-bit grayscale images. If the image has an unsupported format, an error message is printed,
    // the surface is freed, and the renderer and window are destroyed before the program exits with an error code of 1.
    if (surface->format->format != SDL_PIXELFORMAT_INDEX8) {
        cerr << "Unsupported pixel format: " << SDL_GetPixelFormatName(surface->format->format) << endl;
        SDL_FreeSurface(surface);
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 1;
    }

    // Convert to 32-bit RGBA format 
    SDL_Surface* rgbaSurface = SDL_ConvertSurfaceFormat(surface, SDL_PIXELFORMAT_RGBA32, 0);

    if (rgbaSurface == nullptr) {
        cerr << "SDL_ConvertSurfaceFormat failed: " << SDL_GetError() << endl;
        SDL_FreeSurface(surface);
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 1;
    }

    // Create a texture from the pixel data
    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, rgbaSurface);

    if (texture == nullptr) {
        cerr << "SDL_CreateTextureFromSurface failed: " << SDL_GetError() << endl;
        SDL_FreeSurface(rgbaSurface);
        SDL_FreeSurface(surface);
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 1;
    }

    // Get the pixel data
    int pitch = rgbaSurface->pitch;
    int width = rgbaSurface->w;
    int height = rgbaSurface->h;
    void* pixels = rgbaSurface->pixels;

    // Display the image
    SDL_Rect destRect = {0, 0, width, height};
    SDL_RenderCopy(renderer, texture, nullptr, &destRect);
    SDL_RenderPresent(renderer);

    
    SDL_Rect dstRect = { 0, 0, width, height };
    // Event loop
    SDL_Event event;
    bool quit = false;
    while (!quit)
    {
        while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_QUIT)
            {
                quit = true;
            }
        }

        // Clear the renderer
        SDL_RenderClear(renderer);

        // Copy the texture to the renderer
        SDL_RenderCopy(renderer, texture, NULL, &dstRect);

        // Update the screen
        SDL_RenderPresent(renderer);
    }

    // Cleanup
    SDL_DestroyTexture(texture);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}

