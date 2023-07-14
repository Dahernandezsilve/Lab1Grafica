#pragma once
#include <array>
#include "color.h"

// Tamaño del framebuffer
const int framebufferWidth = 800;
const int framebufferHeight = 600;

// Tipo de dato para representar el framebuffer
using Framebuffer = std::array<std::array<Color, framebufferWidth>, framebufferHeight>;

// Variable global que representa el framebuffer
extern Framebuffer framebuffer;

// Color base del framebuffer
extern Color clearColor;

extern Color currentColor;

// Función para limpiar el framebuffer con el color clearColor
void clear();

// Función para renderizar el framebuffer en un archivo BMP
void renderBuffer();
