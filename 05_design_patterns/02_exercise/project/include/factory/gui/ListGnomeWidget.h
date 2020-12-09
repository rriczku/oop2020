//
// Created by student on 12/8/20.
//
#pragma once
#include "Widget.h"

namespace factory {
    namespace gui {
        class ListGnomeWidget : public Widget {
        public:
            explicit ListGnomeWidget(int gnomeVersion);

            void draw() override;

        private:
            int gnomeVersion;
        };
    }
}