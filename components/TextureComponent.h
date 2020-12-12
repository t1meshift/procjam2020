#pragma once

#include <string_view>
#include <SFML/Graphics.hpp>
#include <utilities/Rect.h>
#include "BaseComponent.h"

namespace pj::components {
    class TextureComponent : public BaseComponent {
    public:
        TextureComponent();

        [[nodiscard]] std::weak_ptr<sf::Texture> texture() const;
        [[nodiscard]] utilities::Rect region() const;

        void texture(std::shared_ptr<sf::Texture> tex);
        void region(utilities::Rect rect);

    private:
        utilities::Rect region_;
        std::shared_ptr<sf::Texture> texture_;
    };
}