#include "fill_polygon.h"
#include "polygon.h"

bool isInsidePolygon(const std::vector<Vertex2>& points, const Vertex2& point) {
    bool inside = false;
    size_t numPoints = points.size();

    for (size_t i = 0, j = numPoints - 1; i < numPoints; j = i++) {
        const Vertex2& p1 = points[i];
        const Vertex2& p2 = points[j];

        if (((p1.y > point.y) != (p2.y > point.y)) &&
            (point.x < (p2.x - p1.x) * (point.y - p1.y) / (p2.y - p1.y) + p1.x)) {
            inside = !inside;
        }
    }

    return inside;
}

Vertex2 getRandomPointInsidePolygon(const std::vector<Vertex2>& points) {
    float minX = points[0].x;
    float minY = points[0].y;
    float maxX = points[0].x;
    float maxY = points[0].y;

    for (const Vertex2& point : points) {
        minX = std::min(minX, point.x);
        minY = std::min(minY, point.y);
        maxX = std::max(maxX, point.x);
        maxY = std::max(maxY, point.y);
    }

    float randomX = minX + static_cast<float>(rand()) / static_cast<float>(RAND_MAX / (maxX - minX));
    float randomY = minY + static_cast<float>(rand()) / static_cast<float>(RAND_MAX / (maxY - minY));

    Vertex2 randomPoint(randomX, randomY);

    if (isInsidePolygon(points, randomPoint)) {
        return randomPoint;
    }

    return getRandomPointInsidePolygon(points);
}

void fillBucket(const Vertex2& seed, const Color& backgroundColor, const Color& fillColor, const Color& strokeColor) {
    // Obtener el color del punto semilla
    Color seedColor = framebuffer[seed.y][seed.x];


    // Verificar si el punto semilla está fuera del polígono
    if (seedColor == strokeColor) {
        return;
    }

    // Verificar si el color del punto semilla es igual al color de relleno
    if (seedColor == fillColor) {
        return; // El punto semilla ya está en el color de relleno, no se requiere relleno adicional
    }

    // Verificar si el color del punto semilla es igual al color de fondo
    if (seedColor != backgroundColor) {
        return; // El punto semilla está en el color de fondo, no se debe realizar el relleno
    }

    // Establecer el color de relleno en el punto semilla
    point(seed, fillColor);

    // Llamar recursivamente a fillBucket para los vecinos del punto semilla
    Vertex2 neighborPoint;

    // Vecino de la izquierda
    neighborPoint.x = seed.x - 1;
    neighborPoint.y = seed.y;
    fillBucket(neighborPoint, backgroundColor, fillColor, strokeColor);

    // Vecino de la derecha
    neighborPoint.x = seed.x + 1;
    neighborPoint.y = seed.y;
    fillBucket(neighborPoint, backgroundColor, fillColor, strokeColor);

    // Vecino de arriba
    neighborPoint.x = seed.x;
    neighborPoint.y = seed.y + 1;
    fillBucket(neighborPoint, backgroundColor, fillColor, strokeColor);

    // Vecino de abajo
    neighborPoint.x = seed.x;
    neighborPoint.y = seed.y - 1;
    fillBucket(neighborPoint, backgroundColor, fillColor, strokeColor);
}

void fillPolygon(const std::vector<Vertex2>& points, Color contourColor, Color fillColor, Color colorBackground) {
    float minX = points[0].x;
    float minY = points[0].y;
    float maxX = points[0].x;
    float maxY = points[0].y;

    for (const Vertex2& point : points) {
        minX = std::min(minX, point.x);
        minY = std::min(minY, point.y);
        maxX = std::max(maxX, point.x);
        maxY = std::max(maxY, point.y);
    }

    Vertex2 seed = getRandomPointInsidePolygon(points);
    fillBucket(seed, colorBackground, fillColor, contourColor);
}

