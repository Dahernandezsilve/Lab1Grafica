//
// Created by daher on 13/07/2023.
//
#include "framebuffer.h"
#include <fstream>

Framebuffer framebuffer;
Color clearColor = {0, 0, 0};  // Negro
Color currentColor = {255, 0, 0};  // Rojo

void clear() {
    for (auto& row : framebuffer) {
        for (auto& pixel : row) {
            pixel = clearColor;
        }
    }
}

void renderBuffer() {
    std::ofstream file("../out.bmp", std::ios::binary);

    // Encabezado del archivo BMP
    unsigned int fileSize = sizeof(Color) * framebufferWidth * framebufferHeight + 54;
    unsigned int dataOffset = 54;
    unsigned int imageSize = sizeof(Color) * framebufferWidth * framebufferHeight;
    unsigned int width = framebufferWidth;
    unsigned int height = framebufferHeight;
    unsigned short int planes = 1;
    unsigned short int bitsPerPixel = 24;
    unsigned int compression = 0;
    unsigned int dataSize = 0;
    unsigned int horizontalResolution = 2835;  // 72 dpi
    unsigned int verticalResolution = 2835;    // 72 dpi

    file.write("BM", 2);
    file.write(reinterpret_cast<const char*>(&fileSize), 4);
    file.write("\x00\x00\x00\x00", 4);  // Reserved
    file.write(reinterpret_cast<const char*>(&dataOffset), 4);
    file.write("\x28\x00\x00\x00", 4);  // Info header size
    file.write(reinterpret_cast<const char*>(&width), 4);
    file.write(reinterpret_cast<const char*>(&height), 4);
    file.write(reinterpret_cast<const char*>(&planes), 2);
    file.write(reinterpret_cast<const char*>(&bitsPerPixel), 2);
    file.write(reinterpret_cast<const char*>(&compression), 4);
    file.write(reinterpret_cast<const char*>(&imageSize), 4);
    file.write(reinterpret_cast<const char*>(&horizontalResolution), 4);
    file.write(reinterpret_cast<const char*>(&verticalResolution), 4);
    file.write("\x00\x00\x00\x00", 4);  // Colors in color table
    file.write("\x00\x00\x00\x00", 4);  // Important color count

    // Datos del framebuffer
    for (const auto& row : framebuffer) {
        for (const auto& pixel : row) {
            file.write(reinterpret_cast<const char*>(&pixel), sizeof(Color));
        }
    }

    file.close();
}
