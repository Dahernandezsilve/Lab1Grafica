#include "line.h"
#include "point.h"
#include <cmath>

void line(const Vertex2& start, const Vertex2& end) {
    // Convertir las coordenadas decimales en enteros
    int x0 = static_cast<int>(start.x);
    int y0 = static_cast<int>(start.y);
    int x1 = static_cast<int>(end.x);
    int y1 = static_cast<int>(end.y);

    // Calcular las diferencias en X y Y
    int dx = std::abs(x1 - x0);
    int dy = std::abs(y1 - y0);

    // Calcular las direcciones en X y Y
    int sx = (x0 < x1) ? 1 : -1;
    int sy = (y0 < y1) ? 1 : -1;

    // Inicializar el error
    int error = dx - dy;

    // Dibujar los puntos de la línea
    while (true) {
        // Crear un vértice con las coordenadas actuales
        Vertex2 currentPoint(static_cast<float>(x0), static_cast<float>(y0));

        // Dibujar el punto actual
        point(currentPoint);

        // Verificar si se alcanzó el punto final
        if (x0 == x1 && y0 == y1) {
            break;
        }

        // Calcular el doble del error
        int e2 = 2 * error;

        // Actualizar las coordenadas y el error
        if (e2 > -dy) {
            error -= dy;
            x0 += sx;
        }
        if (e2 < dx) {
            error += dx;
            y0 += sy;
        }
    }
}
