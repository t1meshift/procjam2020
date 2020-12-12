#pragma once

namespace pj::utilities {
    template<class T>
    class Singleton {
    public:
        static T& instance() {
            static T instance_;
            return instance_;
        }
    protected:
        Singleton() = default;
        ~Singleton() = default;
    public:
        Singleton(const Singleton&) = delete;
        Singleton& operator=(const Singleton&) = delete;
    };
}