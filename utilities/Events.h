#pragma once

#include <unordered_map>
#include <functional>

namespace pj::utilities {
    class EventEmitter {
    public:
        void addListener(const std::string& eventId, const std::function<void()>& callback);
        void clearListeners(const std::string& eventId);
        void clearAllListeners();

        void emit(const std::string& eventId);
    private:
        std::unordered_map<std::string, std::vector<std::function<void()>>> listeners_;
    };
}