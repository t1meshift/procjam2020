#pragma once

#include <memory>
#include <string>
#include <map>
#include <utilities/Singleton.h>
#include <scenes/BaseScene.h>

namespace pj::gameManagers {
    class SceneManager : public utilities::Singleton<SceneManager> {
    public:
        void addScene(std::unique_ptr<scenes::BaseScene> scene, const std::string& name);
        [[nodiscard]] std::shared_ptr<scenes::BaseScene> getScene(const std::string& name);
        [[nodiscard]] std::shared_ptr<scenes::BaseScene> ejectScene(const std::string& name);

        [[nodiscard]] scenes::BaseScene& getCurrentScene();
        void switchScene(const std::string& name);
    private:
        std::map<std::string, std::shared_ptr<scenes::BaseScene>> scenes_;
        std::string currentSceneName_;
    };
}