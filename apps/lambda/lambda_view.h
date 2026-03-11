#ifndef APPS_LAMBDA_VIEW_H
#define APPS_LAMBDA_VIEW_H

#include <escher/view.h>

#include "lambda_text.h"

namespace LambdaApp {

const int total_rows = 10;
const int total_menu = 3;

struct Menu {
  LambdaText mainTextRows[total_rows];
  int menuSize[total_menu];
  int menuStart[total_menu];
  int previousMenu[total_menu];
};

class LambdaView : public Escher::View {
public:
  LambdaView();
  void drawRect(KDContext *ctx, KDRect rect) const override;

  void clear(KDContext *ctx) const;

  void increaseRow();
  void decreaseRow();

  void reloadRows(KDContext *ctx) const;

  void loadMenu();

  void generateMenuStart();

  bool PreviousMenu();

private:
  int m_select;
  int m_minSelect;
  int m_numberrows;
  int m_numbermenu;
  KDGlyph::Style m_style;
  KDGlyph::Style m_style_highlight;
  Menu m_menu;

  int m_menu_index = -1;
  int m_id_index = 0;
  int m_menu_start_index;
  int m_previous_menu_id = 0;
  void createMenu();
  void addToMenu(int x, int y, KDGlyph::Style style, KDGlyph::Style highlight_style, 
    const char * text, const char * text_selected, int lenth, int highlight_lenth, int toMenu, bool isExecutable);
  void closeMenu();
  void init();
  void setStyle();
  void reloadStyle();

  void executeCurrentSelection(int id);
};

}

#endif
