#pragma once

#include "BaseScene.h"

namespace pj::scenes {
    class TestScene : public BaseScene {
    public:
        void onLoad() override;
        void onSwitch() override;
        void onEject() override;

        void update(double dt) override;

    private:
        double dtSum_ = 0;
    };
}