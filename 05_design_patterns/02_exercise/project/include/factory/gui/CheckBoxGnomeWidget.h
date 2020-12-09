//
// Created by student on 12/8/20.
//
#pragma once
#include "Widget.h"

namespace factory {
    namespace gui {
        class CheckBoxGnomeWidget : public Widget {
        public:
            explicit CheckBoxGnomeWidget(int gnomeVersion);

            void draw() override;

        private:
            int gnomeVersion;
        };
    }
}