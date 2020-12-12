#include "ResourceManager.h"

namespace pj::gameManagers {
    // TODO rewrite to template-generated managers
    std::shared_ptr<sf::Texture> ResourceManager::texture(const std::string &path) {
        auto foundTex = textures_.find(path);
        if (foundTex != textures_.end()) {
            return foundTex->second;
        } else {
            auto tex = std::make_shared<sf::Texture>();
            if (!tex->loadFromFile(baseAssetsPath + "/images/" + path)) {
                throw std::runtime_error("Could not find asset " + path);
            }
            textures_.emplace(path, tex);
            return tex;
        }
    }

    std::shared_ptr<sf::SoundBuffer> ResourceManager::sound(const std::string &path) {
        auto foundSnd = sounds_.find(path);
        if (foundSnd != sounds_.end()) {
            return foundSnd->second;
        } else {
            auto snd = std::make_shared<sf::SoundBuffer>();
            if (!snd->loadFromFile(baseAssetsPath + "/sounds/" + path)) {
                throw std::runtime_error("Could not find asset " + path);
            }
            sounds_.emplace(path, snd);
            return snd;
        }
    }

    void ResourceManager::clearOrphans() {
        for (auto it = textures_.begin(); it != textures_.end(); ) {
            if (it->second.use_count() <= 1) {
                it = textures_.erase(it);
            } else {
                ++it;
            }
        }
        for (auto it = sounds_.begin(); it != sounds_.end(); ) {
            if (it->second.use_count() <= 1) {
                it = sounds_.erase(it);
            } else {
                ++it;
            }
        }
    }
}