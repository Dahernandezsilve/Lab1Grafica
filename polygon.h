#pragma once

#include <vector>
#include "vertex2.h"
#include "line.h"

// Función para dibujar un polígono conectando los puntos en el orden especificado
void drawPolygon(const std::vector<Vertex2>& points, const Color& fillColor);
