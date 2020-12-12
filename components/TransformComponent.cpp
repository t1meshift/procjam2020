#include "TransformComponent.h"
#include "BaseComponent.h"

namespace pj::components {
    TransformComponent::TransformComponent() : BaseComponent("TransformComponent") {
        width_ = height_ = 0;
        scaleX_ = scaleY_ = 1;
        rotation_ = 0;
    }

    double TransformComponent::width() const {
        return width_;
    }

    double TransformComponent::height() const {
        return height_;
    }

    double TransformComponent::scaleX() const {
        return scaleX_;
    }

    double TransformComponent::scaleY() const {
        return scaleY_;
    }

    double TransformComponent::rotation() const {
        return rotation_;
    }

    void TransformComponent::width(double value) {
        width_ = value;
    }

    void TransformComponent::height(double value) {
        height_ = value;
    }

    void TransformComponent::scaleX(double value) {
        scaleX_ = value;
    }

    void TransformComponent::scaleY(double value) {
        scaleY_ = value;
    }

    void TransformComponent::rotation(double value) {
        rotation_ = value;
    }

    void TransformComponent::widthHeight(double width, double height) {
        width_ = width;
        height_ = height;
    }

    void TransformComponent::scaleXY(double x, double y) {
        scaleX_ = x;
        scaleY_ = y;
    }
}
