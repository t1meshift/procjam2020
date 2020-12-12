#include <gameManagers/ResourceManager.h>

#include <utility>
#include "TextureComponent.h"

namespace pj::components {
    TextureComponent::TextureComponent() : BaseComponent("TextureComponent") {

    }

    std::weak_ptr<sf::Texture> TextureComponent::texture() const {
        return texture_;
    }

    utilities::Rect TextureComponent::region() const {
        return region_;
    }

    void TextureComponent::texture(std::shared_ptr<sf::Texture> tex) {
        texture_ = std::move(tex);
        emit("textureChanged");
    }

    void TextureComponent::region(utilities::Rect rect) {
        region_ = rect;
        emit("regionChanged");
    }
}
