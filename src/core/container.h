#pragma once
#include <memory>
#include <mutex>
#include <string>
#include <unordered_map>
#include <concepts>
#include "../subsystems/subsystem.h"

namespace craftsim {
    class container {
    public:
        static container& shared();
        template <typename T>
        void add(const std::string&, std::shared_ptr<T>);
        template <typename T>
        std::shared_ptr<T> get(const std::string&);
    private:
        container();
        static std::unique_ptr<container> _instance;
        static std::once_flag _initInstanceFlag;

        std::unordered_map<std::string, std::shared_ptr<subsystem>> _container;
        std::mutex _containerMutex;
    };

    template <typename T>
    void container::add(const std::string& key, std::shared_ptr<T> value) {
        std::lock_guard<std::mutex> lock(_containerMutex);
        _container[key] = value;
    }

    template <typename T>
    std::shared_ptr<T> container::get(const std::string &key) {
        std::lock_guard<std::mutex> lock(_containerMutex);
        auto it = _container.find(key);
        if (it != _container.end()) {
            auto derived = std::dynamic_pointer_cast<T>(it->second);
            if (derived) {
                return derived;
            } else {
                throw std::bad_cast();
            }
        } else {
            throw std::runtime_error("subsystem not found in container");
        }
    }
}