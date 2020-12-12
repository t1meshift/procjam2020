#include "BaseComponent.h"

#include <utility>

namespace pj::components {
    BaseComponent::BaseComponent(std::string name) : name_(std::move(name)) {

    }

    std::string_view BaseComponent::name() const {
        return name_;
    }
}
