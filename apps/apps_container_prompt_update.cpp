#include "apps_container.h"
#include "apps/theme_gestion/themeGestion.h"

const I18n::Message AppsContainer::k_promptMessages[] = {
    I18n::Message::UpdateAvailable, I18n::Message::UpdateMessage1,
    I18n::Message::UpdateMessage2,  I18n::Message::BlankMessage,
    I18n::Message::UpdateMessage3,  I18n::Message::UpdateMessage4};

const KDColor AppsContainer::k_promptColors[] = {
    Theme::ThemeGestion::getColor("KDColorBlack"), Theme::ThemeGestion::getColor("KDColorBlack"), Theme::ThemeGestion::getColor("KDColorBlack"),
    Theme::ThemeGestion::getColor("Theme::ThemeGestion::getColor("KDColorWhite")"), Theme::ThemeGestion::getColor("KDColorBlack"), Theme::ThemeGestion::getColor("YellowDark")};

const int AppsContainer::k_promptNumberOfMessages = 6;
