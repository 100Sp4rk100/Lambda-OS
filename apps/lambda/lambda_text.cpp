#include "lambda_text.h"

namespace LambdaApp {

  LambdaText::LambdaText(int x, int y, KDGlyph::Style style, KDGlyph::Style highlight_style, 
    const char * text, const char * text_selected, int lenth, int highlight_lenth, int id, int menu, bool isExecutable) {

    m_x = x;
    m_y = y;
    m_style = style;
    m_highlight_style = highlight_style;
    m_text = text;
    m_text_selected = text_selected;
    m_lenth = lenth + 1;
    m_highlight_lenth = highlight_lenth + 1;
    m_id = id;
    m_menu = menu;
    m_isExecutable = isExecutable;

  }

  LambdaText::LambdaText()
  :m_x(0), m_y(0), m_style(), m_highlight_style(),
    m_text(""), m_text_selected(""), m_lenth(1), m_highlight_lenth(1), m_id(-1) {}

  KDPoint LambdaText::getpoint() const{
    return KDPoint(m_x, m_y);
  }

  KDGlyph::Style LambdaText::getStyle(bool isHighlight) const{
    if (isHighlight){
        return m_highlight_style;
    }else{
        return m_style;
    }
  }

  void LambdaText::setStyle(KDGlyph::Style style, KDGlyph::Style hilight_style){
    m_style = style;
    m_highlight_style = hilight_style;
  }

  const char *  LambdaText::getText(bool isHighlight) const{
    if (isHighlight){
        return m_text_selected;
    }else{
        return m_text;
    }
  }

  int LambdaText::getLenth(bool isHighlight) const{
    if (isHighlight){
        return m_highlight_lenth;
    }else{
        return m_lenth;
    }
  }

  bool LambdaText::idIsSameOf(int id) const{
    return id == m_id;
  }

  int LambdaText::getId(){
    return m_id;
  }

  bool LambdaText::isExecutable(){
    return m_isExecutable;
  }

  int LambdaText::getMenu(){
    return m_menu;
  }

}