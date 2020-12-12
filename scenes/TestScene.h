#pragma once

#include "BaseScene.h"

namespace pj::scenes {
    class TestScene : public BaseScene {
        void onLoad() override;
        void onSwitch() override;
        void onEject() override;

        void update(double dt) override;
    };
}