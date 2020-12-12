#pragma once

#include <SFML/Graphics.hpp>
#include "BaseNode.h"

namespace pj::nodes {
    class Sprite : public BaseNode {
    public:
        Sprite();
        explicit Sprite(std::string id);

        void update(double dt) override;
        void draw(sf::RenderWindow &window, Transformation t) override;

    private:
        void onTextureChanged();
        void onRegionChanged();

        sf::Sprite sprite_;
    };
}
