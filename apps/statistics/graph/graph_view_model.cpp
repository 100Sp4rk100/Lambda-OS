#include "graph_view_model.h"

#include "apps/theme_gestion/themeGestion.h"
#include "assert.h"

using namespace Statistics;

I18n::Message GraphViewModel::MessageForGraphView(GraphView graphView) {
  constexpr I18n::Message k_messages[k_numberOfGraphViews] = {
      I18n::Message::Histogram, I18n::Message::BoxAndWhiskers,
      I18n::Message::CumulativeFrequency, I18n::Message::NormalProbabilityPlot};
  return k_messages[IndexOfGraphView(graphView)];
}

const Escher::Image* const GraphViewModel::ImageForGraphView(
    GraphView graphView) {
  const Escher::Image* const k_images[k_numberOfGraphViews] = {
      Theme::ThemeGestion::getIconImage("HistogramIcon"), Theme::ThemeGestion::getIconImage("BoxIcon"),
      Theme::ThemeGestion::getIconImage("CumulativeIcon"), Theme::ThemeGestion::getIconImage("StatisticsNormalIcon")};
  return k_images[IndexOfGraphView(graphView)];
}

GraphViewModel::GraphView GraphViewModel::GraphViewAtIndex(uint8_t index) {
  return static_cast<GraphView>(index);
}

uint8_t GraphViewModel::IndexOfGraphView(GraphView graphView) {
  assert(static_cast<uint8_t>(graphView) >= 0 &&
         static_cast<uint8_t>(graphView) < k_numberOfGraphViews);
  return static_cast<uint8_t>(graphView);
}
