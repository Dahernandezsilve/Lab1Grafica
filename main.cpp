#include "framebuffer.h"
#include "point.h"
#include "line.h"
#include "polygon.h"
#include "fill_polygon.h"

enum ColorName {
    NAVY_BLUE,
    WHITE
};

// Función para establecer el color actual
void setCurrentColor(ColorName colorName) {
    switch (colorName) {
        case NAVY_BLUE:
            currentColor = {0, 0, 128};  // Azul marino
            break;
        case WHITE:
            currentColor = {255, 255, 255};  // Blanco
            break;
        default:
            break;
    }
}

// Función principal render
void render() {
    clear();

    setCurrentColor(WHITE);
    std::vector<Vertex2> points = {
            {165, 380}, {185, 360}, {180, 330}, {207, 345}, {233, 330}, {230, 360}, {250, 380}, {220, 385}, {205, 410}, {193, 383}
    };
    Color fillColor = {0, 255, 255};
    Color lineColor = {255, 255, 255};
    drawPolygon(points,lineColor);
    fillPolygon(points, lineColor, fillColor, clearColor);

    renderBuffer();
};

int main() {
    render();
    return 0;
}
