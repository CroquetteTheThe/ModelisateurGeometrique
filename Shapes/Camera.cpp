#ifdef __APPLE__
#include <GLUT/glut.h>
#else

#include <GL/glut.h>
#include <cmath>

#endif

#include "Camera.h"
#include "../Readers/OFFReader.h"

#define PI  3.141592653589793238463

/*Camera::Camera(const Vector3f &color, Vector3f position, Vector3f direction, float fov) : Drawable(color) {
    this->position = position;
    this->direction = direction;
    this->fov = fov;
}*/

Camera::Camera(const Vector3f &color) : Drawable(color) {
    auto reader = OFFReader();
    try {
        this->shape = reader.fromFile("../resources/cam.off");
    } catch (const std::exception &e) {
        perror("Le fichier n'existe pas");
    }
}

void Camera::setPosition(Vector3f position) {
    this->position = position;
}

Vector3f Camera::getPosition() {
    return this->position;
}

void Camera::setDirection(Vector3f direction) {
    this->direction = direction;
}

Vector3f Camera::getDirection() {
    return this->direction;
}

void Camera::setFov(float fov) {
    this->fov = fov;
}


void Camera::draw() {
    glPushMatrix();
    glTranslatef(this->getPosition().x, this->getPosition().y, this->getPosition().z);
    Vector3f lookAtDiff = {this->getPosition().x - this->getDirection().x,
                           this->getPosition().y - this->getDirection().y,
                           this->getPosition().z - this->getDirection().z};
    auto xRotation = atan2(lookAtDiff.x, lookAtDiff.z);
    auto yRotation = atan2(lookAtDiff.y, sqrt(lookAtDiff.x * lookAtDiff.x + lookAtDiff.z * lookAtDiff.z));
    glRotatef((GLfloat) (xRotation * 180 / PI), 0, this->getPosition().y, 0);
    glRotatef((GLfloat) (yRotation * 180 / PI), -this->getPosition().x, 0, 0);
    this->shape->draw();

    glPopMatrix();
}