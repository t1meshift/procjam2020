#pragma once

#include <memory>
#include <string>
#include <unordered_map>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <utilities/Singleton.h>

namespace pj::gameManagers {
    class ResourceManager : public utilities::Singleton<ResourceManager> {
    public:
        [[nodiscard]] std::shared_ptr<sf::Texture> texture(const std::string& path);
        [[nodiscard]] std::shared_ptr<sf::SoundBuffer> sound(const std::string& path);
        void clearOrphans();
    private:
        std::string baseAssetsPath = "assets";
        std::unordered_map<std::string, std::shared_ptr<sf::Texture>> textures_;
        std::unordered_map<std::string, std::shared_ptr<sf::SoundBuffer>> sounds_;
    };
}