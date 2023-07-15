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
    std::vector<Vertex2> vertices;
    vertices.emplace_back(100, 100);
    vertices.emplace_back(200, 100);
    vertices.emplace_back(200, 200);
    vertices.emplace_back(150, 250);
    vertices.emplace_back(100, 200);

    Color fillColor = {255, 0, 0};
    Color lineColor = {0, 0, 255};
    fillPolygon(vertices, fillColor, lineColor);

    renderBuffer();
}

int main() {
    render();
    return 0;
}
