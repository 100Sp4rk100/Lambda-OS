#include "lambda_view.h"
#include "apps/i18n.h"
#include "apps/apps_container.h"

#include "../clock_timer.h"

#include "apps/theme_gestion/themeGestion.h"
#include "apps/theme_gestion/backgroundGestion.h"
#include "apps/theme_gestion/dynamicColorProfil_gestion.h"

namespace LambdaApp {

LambdaView::LambdaView() :
  View(){

    setStyle();

    // create menus

    // menu_id -> 0: main menu
    createMenu();
    addToMenu(10, 20, 
      m_style, 
      m_style_highlight, 
      I18n::translate(I18n::Message::MainRow_Theme_A), 
      I18n::translate(I18n::Message::MainRow_Theme_B), 
      8, 8,
      1, false);
    addToMenu(10, 45, 
      m_style,
      m_style_highlight,
      I18n::translate(I18n::Message::MainRow_Clock_A), 
      I18n::translate(I18n::Message::MainRow_Clock_B),
      9, 9,
      2, false);
    closeMenu();

    // menu_id -> 1: theme menu
    createMenu();
    addToMenu(10, 20, 
      m_style, 
      m_style_highlight, 
      I18n::translate(I18n::Message::SubRow_Theme_1_A), 
      I18n::translate(I18n::Message::SubRow_Theme_1_B), 
      25, 25, 
      0, true); // id -> 2
    addToMenu(10, 45, 
      m_style, 
      m_style_highlight, 
      I18n::translate(I18n::Message::SubRow_Theme_2_A), 
      I18n::translate(I18n::Message::SubRow_Theme_2_B), 
      10, 10, 
      0, true); // id -> 3
    addToMenu(10, 70, 
      m_style, 
      m_style_highlight, 
      I18n::translate(I18n::Message::SubRow_Theme_3_A), 
      I18n::translate(I18n::Message::SubRow_Theme_3_B), 
      10, 10, 
      0, true); // id -> 4

    addToMenu(10, 95, 
      m_style, 
      m_style_highlight, 
      I18n::translate(I18n::Message::SubRow_Theme_4_A), 
      I18n::translate(I18n::Message::SubRow_Theme_4_B), 
      25, 25, 
      0, true); // id -> 5

    addToMenu(10, 120, 
      m_style, 
      m_style_highlight, 
      I18n::translate(I18n::Message::SubRow_Theme_5_A), 
      I18n::translate(I18n::Message::SubRow_Theme_5_B), 
      50, 50, 
      0, true); // id -> 6

    addToMenu(10, 145, 
      m_style, 
      m_style_highlight, 
      I18n::translate(I18n::Message::SubRow_Theme_6_A), 
      I18n::translate(I18n::Message::SubRow_Theme_6_B), 
      25, 25, 
      0, true); // id -> 7
    closeMenu();

    // menu_id -> 2: clock menu
    createMenu();
    addToMenu(10, 20, 
      m_style, 
      m_style_highlight, 
      I18n::translate(I18n::Message::SubRow_Clock_1_A), 
      I18n::translate(I18n::Message::SubRow_Clock_1_B), 
      26, 26, 
      0, true); // id -> 8

    addToMenu(10, 45, 
      m_style, 
      m_style_highlight, 
      I18n::translate(I18n::Message::SubRow_Clock_2_A), 
      I18n::translate(I18n::Message::SubRow_Clock_2_B), 
      22, 22, 
      0, true); // id -> 9

    closeMenu();

    init();
    generateMenuStart();
  }

void LambdaView::drawRect(KDContext *ctx, KDRect rect) const{
  clear(ctx);
  reloadRows(ctx);
}

void LambdaView::clear(KDContext *ctx) const{
  if (Theme::ThemeGestion::isThereBackground()){
    ctx->fillRectWithPixels(KDRect(0, 0, background_width, background_height), reinterpret_cast<const KDColor *>(Theme::ThemeGestion::getBackground()), nullptr);
  }else{
    ctx->fillRect(KDRect(0, 0, background_width, background_height), Theme::ThemeGestion::getBackgroundColor());
  }
}

void LambdaView::increaseRow() {
  int pos = m_select - m_minSelect;
  pos = (pos + 1) % m_menu.menuSize[m_numbermenu];
  m_select = m_minSelect + pos;
  markWholeFrameAsDirty();
}

void LambdaView::decreaseRow() {
  int pos = m_select - m_minSelect;
  pos = (pos - 1 + m_menu.menuSize[m_numbermenu]) % m_menu.menuSize[m_numbermenu];
  m_select = m_minSelect + pos;
  markWholeFrameAsDirty();
}


void LambdaView::reloadRows(KDContext *ctx) const{
  int start = m_menu.menuStart[m_numbermenu];
  int end = start + m_menu.menuSize[m_numbermenu];
  for (int i = start; i < end; i++) {
      const LambdaText &text = m_menu.mainTextRows[i];
      bool isHighlight = text.idIsSameOf(m_select);
      ctx->drawTransparentString(text.getText(isHighlight), text.getpoint(), text.getStyle(isHighlight), text.getLenth(isHighlight));
  }
  ctx->drawTransparentString("Made by 100Sp4rk100", KDPoint(5, 200), m_style, 20);
}

bool LambdaView::PreviousMenu(){
  if (m_previous_menu_id==0) return false;
  m_previous_menu_id--;
  m_numbermenu = m_menu.previousMenu[m_previous_menu_id];
  m_minSelect = m_menu.menuStart[m_numbermenu];
  m_select = m_minSelect;
  m_numberrows = m_minSelect + m_menu.menuSize[m_numbermenu] - 1;
  
  markWholeFrameAsDirty();
  return true;
}


void LambdaView::loadMenu(){
  if (m_menu.mainTextRows[m_select].isExecutable()){
    executeCurrentSelection(m_select);
  }
  m_menu.previousMenu[m_previous_menu_id] = m_numbermenu;
  m_previous_menu_id++;
  m_numbermenu = m_menu.mainTextRows[m_select].getMenu();
  m_minSelect = m_menu.menuStart[m_numbermenu];
  m_select = m_minSelect;
  m_numberrows = m_minSelect + m_menu.menuSize[m_numbermenu] - 1;
  
  markWholeFrameAsDirty();
}

void LambdaView::generateMenuStart(){
  int currentIndex = 0;
  for (int i = 0; i < total_menu; i++) {
    m_menu.menuStart[i] = currentIndex;
    currentIndex += m_menu.menuSize[i];
  }
}

void LambdaView::createMenu(){
  m_menu_index++;
  m_menu_start_index = m_id_index;
}

void LambdaView::addToMenu(int x, int y, KDGlyph::Style style, KDGlyph::Style highlight_style, 
  const char * text, const char * text_selected, int lenth, int highlight_lenth, int toMenu, bool isExecutable){
  m_menu.mainTextRows[m_id_index] = LambdaText(x, y, 
        style, 
        highlight_style, 
        text, 
        text_selected, 
        lenth, highlight_lenth, m_id_index, 
        toMenu, isExecutable);
  m_id_index++;
}

void LambdaView::closeMenu(){
  m_menu.menuSize[m_menu_index] = m_id_index - m_menu_start_index;
}

void LambdaView::init(){
  m_minSelect = 0;
  m_select = m_minSelect;
  m_numbermenu = 0;
  m_numberrows = m_minSelect + m_menu.menuSize[m_numbermenu] - 1;
}

void LambdaView::setStyle(){
  m_style.glyphColor = Theme::ThemeGestion::getColor("TextColor");
  m_style.backgroundColor = Theme::ThemeGestion::getColor("BackgroundColor");
  m_style.font = KDFont::Size::Large;

  m_style_highlight.glyphColor = Theme::ThemeGestion::getColor("TextHillightColor");
  m_style_highlight.backgroundColor = Theme::ThemeGestion::getColor("BackgroundColorHilight");
  m_style_highlight.font = KDFont::Size::Large;

}

void LambdaView::reloadStyle(){
  setStyle();
  for (int i = 0; i < total_rows; i++){
    m_menu.mainTextRows[i].setStyle(m_style, m_style_highlight);
  }
}

void LambdaView::executeCurrentSelection(int id){
  if (id == 2){ //menu_id -> 1, row -> 1
    Theme::ThemeGestion::setCurrent(0);
    AppsContainer::sharedAppsContainer()->reloadTitleBarView();
    reloadStyle();
    markWholeFrameAsDirty();
  }else if (id==3){ //menu_id -> 1, row -> 2
    Theme::ThemeGestion::setCurrent(1);
    AppsContainer::sharedAppsContainer()->reloadTitleBarView();
    reloadStyle();
    markWholeFrameAsDirty();
  }else if (id==4){ //menu_id -> 1, row -> 3
    Theme::ThemeGestion::setCurrent(2);
    AppsContainer::sharedAppsContainer()->reloadTitleBarView();
    reloadStyle();
    markWholeFrameAsDirty();
  }else if (id==5){ //menu_id -> 1, row -> 4
    Theme::ThemeGestion::setCurrent(3);
    AppsContainer::sharedAppsContainer()->reloadTitleBarView();
    reloadStyle();
    markWholeFrameAsDirty();
  }else if (id==6){ //menu_id -> 1, row -> 5
    if (Theme::DynamicColorProfilGestion::reload()){
      Theme::ThemeGestion::setCurrent(4);
      AppsContainer::sharedAppsContainer()->reloadTitleBarView();
      reloadStyle();
      markWholeFrameAsDirty();
    }
  }else if (id==7){ //menu_id -> 1, row -> 6
    Theme::ThemeGestion::changeSquareIconState();
  }
  else if (id==8){ //menu_id -> 2, row -> 1
    ClockTimer::ClockTimer::init();
  }else if (id==9){ //menu_id -> 2, row -> 2
    ClockTimer::ClockTimer::init();
    if(ClockTimer::ClockTimer::isEnabled()){
      ClockTimer::ClockTimer::desactivate();
    }else{
      ClockTimer::ClockTimer::activate();
    }
  }
  
}

}