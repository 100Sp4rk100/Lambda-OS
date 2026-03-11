#include "off_controller.h"

namespace Off_screen{

    OffController::OffController():
        ViewController(nullptr),
        m_view(){}

    Escher::View* OffController::view(){
        return &m_view;
    }
}