#include <gameManagers/ResourceManager.h>
#include <nodes/Sprite.h>
#include <components/TextureComponent.h>
#include "TestScene.h"

namespace pj::scenes {
    void TestScene::onLoad() {
        auto testSprite = std::make_unique<nodes::Sprite>("eblo");
        auto texComp = testSprite->component<components::TextureComponent>();
        auto posComp = testSprite->component<components::PositionComponent>();
        auto tfmComp = testSprite->component<components::TransformComponent>();

        auto testSprite1 = std::make_unique<nodes::Sprite>("eblo1");
        auto texComp1 = testSprite1->component<components::TextureComponent>();
        auto posComp1 = testSprite1->component<components::PositionComponent>();
        auto tfmComp1 = testSprite1->component<components::TransformComponent>();

        auto texture = gameManagers::ResourceManager::instance().texture("face_halloween.jpg");
        texComp->texture(texture);
        texComp1->texture(texture);

        posComp->xy(0, 0);
        posComp->anchorXY(0.5, 0.5);
        posComp->pivotXY(0.5, 0.5);
        posComp1->xy(0, 0);
        posComp1->anchorXY(0.5, 0.5);
        posComp1->pivotXY(0.5, 0.5);

        //tfmComp->scaleXY(2, 2);
        tfmComp1->scaleXY(0.5, 0.5);

        tfmComp->rotation(30);
        tfmComp1->rotation(-30);

        testSprite->addChild(std::move(testSprite1));
        rootNode->addChild(std::move(testSprite));
    }

    void TestScene::onSwitch() {

    }

    void TestScene::onEject() {

    }

    void TestScene::update(double dt) {
        auto node = rootNode->findChild("eblo");
        auto rotationSpeed = 90.0;
        if (node.has_value()) {
            auto node_nn = node->lock();
            auto tfc = node_nn->component<TransformComponent>();
            tfc->rotation(tfc->rotation() + rotationSpeed * dt);
        }
        BaseScene::update(dt);
    }
}