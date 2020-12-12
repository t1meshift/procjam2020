#pragma once

#include "BaseComponent.h"

namespace pj::components {
    class TransformComponent : public BaseComponent {
    public:
        TransformComponent();

        [[nodiscard]] double width() const;
        [[nodiscard]] double height() const;
        [[nodiscard]] double scaleX() const;
        [[nodiscard]] double scaleY() const;
        [[nodiscard]] double rotation() const;

        void width(double value);
        void height(double value);
        void scaleX(double value);
        void scaleY(double value);
        void rotation(double value);

        void widthHeight(double width, double height);
        void scaleXY(double x, double y);

    private:
        double width_, height_;
        double scaleX_, scaleY_;
        double rotation_;
    };
}