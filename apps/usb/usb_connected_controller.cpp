#include "usb_connected_controller.h"
#include <apps/i18n.h>
#include <escher/palette.h>
#include "apps/theme_gestion/themeGestion.h"

namespace USB {

constexpr I18n::Message sUSBConnectedMessages[] = {
    I18n::Message::USBConnected,      I18n::Message::ConnectedMessage1,
    I18n::Message::ConnectedMessage2, I18n::Message::TransferDataUrl,
    I18n::Message::BlankMessage,      I18n::Message::ConnectedMessage3,
    I18n::Message::ConnectedMessage4, I18n::Message::ConnectedMessage5};

uint16_t sUSBConnectedColors[] = { 0, 0, 0, 0, 0, 0, 0, 0 };

USBConnectedController::USBConnectedController()
    : ViewController(nullptr),
      m_messageView(sUSBConnectedMessages, reinterpret_cast<KDColor *>(sUSBConnectedColors), 8) 
{
    sUSBConnectedColors[0] = (uint16_t)Theme::ThemeGestion::getColor("KDColorBlack");
    sUSBConnectedColors[1] = (uint16_t)Theme::ThemeGestion::getColor("KDColorBlack");
    sUSBConnectedColors[2] = (uint16_t)Theme::ThemeGestion::getColor("KDColorBlack");
    sUSBConnectedColors[3] = (uint16_t)Theme::ThemeGestion::getColor("YellowDark");
    sUSBConnectedColors[4] = (uint16_t)Theme::ThemeGestion::getColor("KDColorWhite");
    sUSBConnectedColors[5] = (uint16_t)Theme::ThemeGestion::getColor("KDColorBlack");
    sUSBConnectedColors[6] = (uint16_t)Theme::ThemeGestion::getColor("KDColorBlack");
    sUSBConnectedColors[7] = (uint16_t)Theme::ThemeGestion::getColor("KDColorBlack");
}

}  // namespace USB