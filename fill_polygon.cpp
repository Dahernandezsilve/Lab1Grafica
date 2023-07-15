#include "fill_polygon.h"
#include "polygon.h"

void fillPolygon(const std::vector<Vertex2>& vertices, const Color& fillColor, const Color& lineColor) {
    // Dibujar el borde del polígono utilizando la función drawPolygon
    drawPolygon(vertices, lineColor);

    // Verificar si hay suficientes vértices para formar un polígono
    if (vertices.size() < 3) {
        return; // No hay suficientes vértices para formar un polígono
    }

    // Rellenar el polígono utilizando la función fillPolygon
    for (size_t i = 1; i < vertices.size() - 1; i++) {
        std::vector<Vertex2> fillVertices = {vertices[0], vertices[i], vertices[i + 1]};
        fillPolygon(fillVertices, fillColor, lineColor);
    }
}
