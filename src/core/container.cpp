#include "container.h"

namespace craftsim {
    std::unique_ptr<container> container::_instance = nullptr;
    std::once_flag container::_initInstanceFlag;

    container::container() {}

    /// @brief Get a shared instnace of the service container.
    /// @return 
    container& container::shared() {
        std::call_once(container::_initInstanceFlag, []() {
            container::_instance.reset(new container());
        });
        return *_instance;
    }
}