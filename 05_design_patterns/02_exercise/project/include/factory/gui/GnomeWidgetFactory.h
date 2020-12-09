//
// Created by student on 12/8/20.
//
#pragma once
#include "WidgetFactory.h"
#include "ListGnomeWidget.h"
#include "CheckBoxGnomeWidget.h"
#include "ButtonGnomeWidget.h"


namespace factory{
    namespace gui{
        class GnomeWidgetFactory:public WidgetFactory
        {
        public:
            explicit GnomeWidgetFactory(int gnomeVersion);

            std::shared_ptr<Widget> create(std::string type) override;
        private:
            int gnomeVersion;
        };
    }
}