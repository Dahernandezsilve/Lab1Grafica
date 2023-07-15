#include "polygon.h"
#include "line.h"

void drawPolygon(const std::vector<Vertex2>& points, const Color& color) {
    if (points.size() < 2) {
        return; // No hay suficientes puntos para dibujar un polígono
    }

    for (size_t i = 0; i < points.size() - 1; i++) {
        line(points[i], points[i + 1], color);
    }

    // Dibujar una línea desde el último punto hasta el primer punto
    line(points.back(), points.front(), color);
}
