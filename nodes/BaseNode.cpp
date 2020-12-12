#include "BaseNode.h"

#include <utility>

namespace pj::nodes {
    BaseNode::BaseNode() {
        using namespace pj::components;
        registerComponents<PositionComponent, TransformComponent>();
    }

    BaseNode::BaseNode(std::string id) : BaseNode() {
        id_ = std::move(id);
    }

    std::optional<std::weak_ptr<BaseNode>> BaseNode::findChild(std::string_view id) {
        std::optional<std::weak_ptr<BaseNode>> foundChild = std::nullopt;

        for (const auto& child : children_) {
            if (child->id() == id) {
                foundChild = child;
                break;
            }
            foundChild = child->findChild(id);
        }

        return foundChild;
    }

    std::string_view BaseNode::id() const {
        return id_;
    }

    void BaseNode::id(std::string value) {
        id_ = std::move(value);
    }

    void BaseNode::addChild(std::unique_ptr<BaseNode> node) {
        children_.push_back(std::move(node));
    }

    void BaseNode::draw(sf::RenderWindow &window) {
        draw(window, relativeTransformation());
    }

    void BaseNode::draw(sf::RenderWindow &window, Transformation t) {
        auto childTransform = t.applyChild(relativeTransformation());

        for (const auto& child : children_) {
            child->draw(window, childTransform);
        }
    }

    void BaseNode::update(double dt) {
        for (const auto& child : children_) {
            child->update(dt);
        }
    }

    BaseNode::Transformation BaseNode::relativeTransformation() {
        return Transformation(*component<PositionComponent>(), *component<TransformComponent>());
    }

    BaseNode::Transformation::Transformation(const PositionComponent& pos, const TransformComponent& tfm) :
        PositionComponent(pos), TransformComponent(tfm) {}

    double BaseNode::Transformation::relativeX() const {
        //return x() - pivotX() * width() * scaleX();
        return x();
    }

    double BaseNode::Transformation::relativeY() const {
        //return y() - pivotY() * height() * scaleY();
        return y();
    }

    BaseNode::Transformation &BaseNode::Transformation::applyChild(const BaseNode::Transformation &t) {
        xy(x() + t.x(), y() + t.y());
        scaleXY(scaleX() * t.scaleX(), scaleY() * t.scaleY());
        return *this;
    }
}
