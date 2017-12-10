#pragma once


#include <vector>
#include "../Utils/Vector3f.h"
#include "Drawable.h"


class Shape : public Drawable {
public:
    explicit Shape(const Vector3f &color);

    void draw() override;

    void addPoint(Vector3f point);

    void calculeNormales();

    void addFace(std::vector<int> face);


private:
    std::vector<Vector3f> points;
    std::vector<std::vector<int>> faces;
    std::vector<Vector3f> normales;
};

