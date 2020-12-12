#include <components/TextureComponent.h>
#include "Sprite.h"

namespace pj::nodes {
    Sprite::Sprite() : BaseNode() {
        using namespace pj::components;
        registerComponents<TextureComponent>();
        auto texComp = component<components::TextureComponent>();
        texComp->addListener("textureChanged", [this]() { onTextureChanged(); });
        texComp->addListener("regionChanged", [this]() { onRegionChanged(); });
    }

    Sprite::Sprite(std::string id) : Sprite() {
        Sprite::id(std::move(id));
    }

    void Sprite::update(double dt) {
        BaseNode::update(dt);
    }

    void Sprite::onTextureChanged() {
        auto texComp = component<components::TextureComponent>();
        auto tfmComp = component<components::TransformComponent>();
        auto tex = texComp->texture();
        auto texSize = tex.lock()->getSize();
        sprite_.setTexture(*tex.lock());
        tfmComp->widthHeight(texSize.x, texSize.y);
    }

    void Sprite::onRegionChanged() {
        auto texComp = component<components::TextureComponent>();
        auto tfmComp = component<components::TransformComponent>();
        auto rgn = texComp->region();
        sprite_.setTextureRect(sf::IntRect(
                static_cast<int>(rgn.x),
                static_cast<int>(rgn.y),
                static_cast<int>(rgn.width),
                static_cast<int>(rgn.height)
        ));
        tfmComp->widthHeight(rgn.x, rgn.y);
    }

    void Sprite::draw(sf::RenderWindow &window, Transformation t) {
        auto tThis = relativeTransformation();
        auto tGlobal = t.applyChild(tThis);

        sf::Transform tSf;
        tSf.translate(static_cast<float>(tGlobal.relativeX()),
                      static_cast<float>(tGlobal.relativeY()));
        auto sx = tThis.width() / sprite_.getTexture()->getSize().x * tGlobal.scaleX();
        auto sy = tThis.height() / sprite_.getTexture()->getSize().y * tGlobal.scaleY();
        tSf.scale(static_cast<float>(sx),
                  static_cast<float>(sy));

        window.draw(sprite_, tSf);

        BaseNode::draw(window, t);
    }
}
