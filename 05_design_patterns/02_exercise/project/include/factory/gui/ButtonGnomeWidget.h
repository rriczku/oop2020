//
// Created by student on 12/9/20.
//
#pragma once
#include "Widget.h"

namespace factory {
    namespace gui {
        class ButtonGnomeWidget : public Widget {
        public:
            explicit ButtonGnomeWidget(int gnomeVersion);

            void draw() override;

        private:
            int gnomeVersion;
        };
    }
}