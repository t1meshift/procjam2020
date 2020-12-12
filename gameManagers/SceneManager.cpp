#include <stdexcept>
#include "SceneManager.h"

namespace pj::gameManagers {
    void SceneManager::addScene(std::unique_ptr<scenes::BaseScene> scene, const std::string &name) {
        // TODO check if scene exists
        scenes_[name] = std::move(scene);
    }

    std::shared_ptr<scenes::BaseScene> SceneManager::getScene(const std::string &name) {
        auto scene = scenes_.find(name);
        if (scene != scenes_.end()) {
            return scene->second;
        }
        return nullptr;
    }

    std::shared_ptr<scenes::BaseScene> SceneManager::ejectScene(const std::string &name) {
        if (currentSceneName_ == name) {
            throw std::runtime_error("Scene " + currentSceneName_ + " is in use!");
        }

        auto scene = std::move(scenes_.at(name));
        scene->onEject();
        scenes_.erase(name);
        return std::move(scene);
    }

    scenes::BaseScene& SceneManager::getCurrentScene() {
        if (currentSceneName_.empty()) {
            throw std::runtime_error("No scene is loaded");
        }
        return *scenes_.at(currentSceneName_).get();
    }

    void SceneManager::switchScene(const std::string &name) {
        if (!currentSceneName_.empty()) scenes_.at(currentSceneName_)->onSwitch();
        currentSceneName_ = name;
        scenes_.at(name)->onLoad();
    }
}