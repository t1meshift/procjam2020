#pragma once

#include <string>
#include <vector>
#include <optional>
#include <SFML/Graphics.hpp>
#include <components/Holder.h>
#include <components/PositionComponent.h>
#include <components/TransformComponent.h>

using namespace pj::components;

namespace pj::nodes {
    class BaseNode : public Holder {
    public:
        class Transformation;

        BaseNode();
        explicit BaseNode(std::string id);

        [[nodiscard]] std::string_view id() const;
        void id(std::string value);

        virtual void draw(sf::RenderWindow& window);
        virtual void draw(sf::RenderWindow& window, Transformation t);
        virtual void update(double dt);

        Transformation relativeTransformation();

        std::optional<std::weak_ptr<BaseNode>> findChild(std::string_view id);
        void addChild(std::unique_ptr<BaseNode> node);
    public:
        class Transformation : public PositionComponent, public TransformComponent {
        public:
            Transformation() = default;
            explicit Transformation(const PositionComponent& pos, const TransformComponent& tfm);

            [[nodiscard]] double relativeX() const;
            [[nodiscard]] double relativeY() const;

            Transformation& applyChild(const Transformation& t);
        };
    private:
        std::string id_;
        std::vector<std::shared_ptr<BaseNode>> children_;
    };
}