#pragma once

#include <vector>
#include "vertex2.h"
#include "point.h"

// Función para rellenar un polígono definido por un array de vértices
void fillPolygon(const std::vector<Vertex2>& points, Color contourColor, Color fillColor, Color colorBackground);