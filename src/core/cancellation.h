#pragma once

namespace craftsim {
    class cancellation {
    public:
        cancellation();
        ~cancellation();

        bool cancel_requested() const;
        void cancel();
    private:
        bool _cancelled;
    };
}