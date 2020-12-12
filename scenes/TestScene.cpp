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

        posComp->xy(30, 30);
        posComp1->xy(50, 50);

        tfmComp->scaleXY(1.5, 1.5);
        tfmComp1->scaleXY(0.2, 0.2);

        testSprite->addChild(std::move(testSprite1));
        rootNode->addChild(std::move(testSprite));
    }

    void TestScene::onSwitch() {

    }

    void TestScene::onEject() {

    }

    void TestScene::update(double dt) {
        auto node = rootNode->findChild("eblo");
        auto startScale = 0.3;
        auto endScale = 1.5;

        if (node.has_value()) {
            auto node_nn = node->lock();
            auto tfc = node_nn->component<TransformComponent>();
            auto scale = startScale + (endScale - startScale) * ((std::sin(dtSum_) + 1) / 2);
            tfc->scaleXY(scale, scale);
            dtSum_ += dt;
        }
        BaseScene::update(dt);
    }
}