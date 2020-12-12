#pragma once

namespace pj::utilities {
    class Rect {
    public:
        double x = 0, y = 0, width = 0, height = 0;
        [[nodiscard]] double endX() const {
            return x + width;
        }
        [[nodiscard]] double endY() const {
            return y + height;
        }
    };
}