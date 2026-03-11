#ifndef APPS_LAMBDA_TEXT_H
#define APPS_LAMBDA_TEXT_H

#include <kandinsky/include/kandinsky/context.h>

namespace LambdaApp {

class LambdaText {
public:
  LambdaText(int x, int y, KDGlyph::Style style, KDGlyph::Style highlight_style, 
    const char * text, const char * text_selected, int lenth, int highlight_lenth, int id, int menu, bool isExecutable);

  LambdaText();

  KDPoint getpoint() const;
  KDGlyph::Style getStyle(bool isHighlight) const;
  const char *  getText(bool isHighlight) const;
  int getLenth(bool isHighlight) const;
  bool idIsSameOf(int id) const;
  int getId();
  bool isExecutable();
  int getMenu();
  void setStyle(KDGlyph::Style style, KDGlyph::Style hilight_style);

private:
    int m_x;
    int m_y;
    KDGlyph::Style m_style;
    KDGlyph::Style m_highlight_style;
    const char * m_text;
    const char * m_text_selected;
    int m_lenth;
    int m_highlight_lenth;
    int m_menu;
    int m_id;

    bool m_isExecutable;
};

}

#endif
