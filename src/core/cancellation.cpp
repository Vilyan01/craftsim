#include "cancellation.h"

namespace craftsim {
    cancellation::cancellation() : _cancelled(false) {}

    cancellation::~cancellation() {}

    bool cancellation::cancel_requested() const {
        return _cancelled;
    }
    
    void cancellation::cancel() {
        _cancelled = true;
    }
}