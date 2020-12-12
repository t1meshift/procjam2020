#include "Events.h"


namespace pj::utilities {
    void EventEmitter::addListener(const std::string &eventId, const std::function<void()>& callback) {
        auto it = listeners_.find(eventId);
        listeners_[eventId].push_back(callback);

    }

    void EventEmitter::clearListeners(const std::string &eventId) {
        listeners_.erase(eventId);
    }

    void EventEmitter::clearAllListeners() {
        listeners_.clear();
    }

    void EventEmitter::emit(const std::string& eventId) {
        for (const auto& cb : listeners_[eventId]) {
            cb();
        }
    }
}
