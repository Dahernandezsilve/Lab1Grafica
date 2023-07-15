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
            {413, 177}, {448, 159}, {502, 88}, {553, 53}, {535, 36}, {676, 37}, {660, 52},
            {750, 145}, {761, 179}, {672, 192}, {659, 214}, {615, 214}, {632, 230}, {580, 230},
            {597, 215}, {552, 214}, {517, 144}, {466, 180}
    };
    std::vector<Vertex2> point2 = {
            {682, 175}, {708, 120}, {735, 148}, {739, 170}
    };


    Color fillColor = {0, 255, 0};
    Color lineColor = {255, 255, 255};
    drawPolygon(points,lineColor);
    fillPolygon(points, lineColor, clearColor,fillColor );
    drawPolygon(point2,lineColor);
    fillPolygon(points, lineColor, fillColor, clearColor);

    renderBuffer();
};

int main() {
    render();
    return 0;
}
