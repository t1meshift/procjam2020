#pragma once

#include <string>
#include <string_view>
#include <memory>
#include <utilities/Events.h>

namespace pj::components {
    class BaseComponent : public utilities::EventEmitter {
    public:
        BaseComponent() = default;
        explicit BaseComponent(std::string name);
        [[nodiscard]] virtual std::string_view name() const;
    private:
        std::string name_;
    };
}