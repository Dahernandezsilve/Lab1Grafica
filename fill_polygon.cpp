#include "fill_polygon.h"

void fillPolygon(const std::vector<Vertex2>& vertices) {
    if (vertices.size() < 3) {
        return; // No hay suficientes vértices para formar un polígono
    }

    // Encontrar los valores mínimos y máximos de las coordenadas X y Y
    float minX = vertices[0].x;
    float minY = vertices[0].y;
    float maxX = vertices[0].x;
    float maxY = vertices[0].y;

    for (size_t i = 1; i < vertices.size(); i++) {
        const Vertex2& vertex = vertices[i];

        if (vertex.x < minX) {
            minX = vertex.x;
        }
        if (vertex.x > maxX) {
            maxX = vertex.x;
        }
        if (vertex.y < minY) {
            minY = vertex.y;
        }
        if (vertex.y > maxY) {
            maxY = vertex.y;
        }
    }

    // Rellenar el polígono utilizando el algoritmo de escaneo de líneas
    for (float y = minY; y <= maxY; y++) {
        // Vector que almacena los puntos de intersección con la línea
        std::vector<float> intersections;

        for (size_t i = 0; i < vertices.size(); i++) {
            const Vertex2& v1 = vertices[i];
            const Vertex2& v2 = vertices[(i + 1) % vertices.size()];

            if ((v1.y <= y && v2.y > y) || (v1.y > y && v2.y <= y)) {
                // Calcular la intersección de la línea con la coordenada Y actual
                float intersection = v1.x + (y - v1.y) * (v2.x - v1.x) / (v2.y - v1.y);
                intersections.push_back(intersection);
            }
        }

        // Ordenar las intersecciones en orden ascendente
        std::sort(intersections.begin(), intersections.end());

        // Rellenar el área entre las intersecciones
        for (size_t i = 0; i < intersections.size(); i += 2) {
            int startX = static_cast<int>(intersections[i]);
            int endX = static_cast<int>(intersections[i + 1]);

            for (int x = startX; x < endX; x++) {
                point(Vertex2{static_cast<float>(x), y});
            }
        }
    }
}
