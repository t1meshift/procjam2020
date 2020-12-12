#include "PositionComponent.h"

namespace pj::components {
    PositionComponent::PositionComponent() : BaseComponent("PositionComponent") {
        x_ = y_ = anchorX_ = anchorY_ = pivotX_ = pivotY_ = 0;
    }

    double PositionComponent::x() const {
        return x_;
    }

    double PositionComponent::y() const {
        return y_;
    }

    double PositionComponent::anchorX() const {
        return anchorX_;
    }

    double PositionComponent::anchorY() const {
        return anchorY_;
    }

    double PositionComponent::pivotX() const {
        return pivotX_;
    }

    double PositionComponent::pivotY() const {
        return pivotY_;
    }

    void PositionComponent::x(double value) {
        x_ = value;
    }

    void PositionComponent::y(double value) {
        y_ = value;
    }

    void PositionComponent::anchorX(double value) {
        anchorX_ = value;
    }

    void PositionComponent::anchorY(double value) {
        anchorY_ = value;
    }

    void PositionComponent::pivotX(double value) {
        pivotX_ = value;
    }

    void PositionComponent::pivotY(double value) {
        pivotY_ = value;
    }

    void PositionComponent::xy(double x, double y) {
        x_ = x;
        y_ = y;
    }

    void PositionComponent::anchorXY(double x, double y) {
        anchorX_ = x;
        anchorY_ = y;
    }

    void PositionComponent::pivotXY(double x, double y) {
        pivotX_ = x;
        pivotY_ = y;
    }
}
