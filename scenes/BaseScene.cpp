#include "BaseScene.h"

namespace pj::scenes {
    BaseScene::BaseScene() {
        rootNode = std::make_unique<nodes::BaseNode>("root");
    }

    void BaseScene::draw(sf::RenderWindow &window) {
        auto rootSize = window.getSize();
        auto tfc = rootNode->component<TransformComponent>();
        tfc->widthHeight(rootSize.x, rootSize.y);
        rootNode->draw(window);
    }

    void BaseScene::update(double dt) {
        rootNode->update(dt);
    }
}