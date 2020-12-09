//
// Created by student on 12/8/20.
//
#pragma once
#include "Widget.h"

namespace factory {
    namespace gui {
        class ListKdeWidget : public Widget {
        public:

            explicit ListKdeWidget(int kdeVersion);

            void draw() override;

        private:
            int kdeVersion;
        };
    }
}