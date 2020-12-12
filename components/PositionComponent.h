#pragma once

#include "BaseComponent.h"

namespace pj::components {
    class PositionComponent : public BaseComponent {
    public:
        PositionComponent();
        [[nodiscard]] double x() const;
        [[nodiscard]] double y() const;
        [[nodiscard]] double anchorX() const;
        [[nodiscard]] double anchorY() const;
        [[nodiscard]] double pivotX() const;
        [[nodiscard]] double pivotY() const;

        void x(double value);
        void y(double value);
        void anchorX(double value);
        void anchorY(double value);
        void pivotX(double value);
        void pivotY(double value);

        void xy(double x, double y);
        void anchorXY(double x, double y);
        void pivotXY(double x, double y);
    private:
        double x_, y_;
        double anchorX_, anchorY_;
        double pivotX_, pivotY_;
    };
}