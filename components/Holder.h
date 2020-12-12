#pragma once

#include <type_traits>
#include <typeindex>
#include <map>
#include <memory>
#include "BaseComponent.h"

namespace pj::components {
    class Holder {
    private:
        std::map<std::type_index, std::shared_ptr<BaseComponent>> components_;

        template<class... Components>
        typename std::enable_if_t<sizeof...(Components) == 0> registerComponents(){}
    public:
        Holder() = default;
        
        template<class Component>
        void registerComponent() {
            static_assert(std::is_convertible_v<Component*, BaseComponent*>, "Not derived from BaseComponent!");
            components_[std::type_index(typeid(Component))] = std::make_shared<Component>();
        }

        template<class FirstComponent, class... OtherComponents>
        void registerComponents() {
            registerComponent<FirstComponent>();
            registerComponents<OtherComponents...>();
        }

        template<class Component>
        std::shared_ptr<Component> component() {
            return std::dynamic_pointer_cast<Component>(components_.at(typeid(Component)));
        }

        // TODO get component by name
    };
}