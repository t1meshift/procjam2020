#pragma once

#include <SFML/Graphics.hpp>
#include <nodes/BaseNode.h>

namespace pj::scenes {
    class BaseScene {
    public:
        BaseScene();

        virtual void draw(sf::RenderWindow& window);
        virtual void update(double dt);

        virtual void onLoad() = 0;
        virtual void onSwitch() = 0;
        virtual void onEject() = 0;

    protected:
        std::unique_ptr<nodes::BaseNode> rootNode;
    };
}