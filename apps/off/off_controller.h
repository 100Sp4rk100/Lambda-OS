#ifndef OFF_CONTROLLER_H
#define OFF_CONTROLLER_H

#include <escher/view_controller.h>
#include "off_view.h"

namespace Off_screen{

class OffController : public Escher::ViewController{
    public:
        OffController();
        Escher::View * view() override;

    private:
        OffView m_view;
};

}
#endif 