#include "lambda.h"

#include "apps/calculation/calculation_icon.h"
#include "apps/code/code_icon.h"
#include "apps/distributions/distributions_icon.h"
#include "apps/distributions/images/binomial_icon.h"
#include "apps/distributions/images/chi_squared_icon.h"
#include "apps/distributions/images/exponential_icon.h"
#include "apps/distributions/images/fisher_icon.h"
#include "apps/distributions/images/geometric_icon.h"
#include "apps/distributions/images/hypergeometric_icon.h"
#include "apps/distributions/images/normal_icon.h"
#include "apps/distributions/images/poisson_icon.h"
#include "apps/distributions/images/student_icon.h"
#include "apps/distributions/images/uniform_icon.h"
#include "apps/distributions/images/calculation1_icon.h"
#include "apps/distributions/images/calculation2_icon.h"
#include "apps/distributions/images/calculation3_icon.h"
#include "apps/distributions/images/calculation4_icon.h"
#include "apps/elements/elements_icon.h"
#include "apps/finance/finance_icon.h"
#include "apps/graph/graph_icon.h"
#include "apps/inference/inference_icon.h"
#include "apps/inference/images/confidence_interval.h"
#include "apps/inference/images/significance_test.h"
#include "apps/regression/regression_icon.h"
#include "apps/sequence/sequence_icon.h"
#include "apps/settings/settings_icon.h"
#include "apps/solver/solver_icon.h"
#include "apps/statistics/stat_icon.h"
#include "apps/statistics/box_icon.h"
#include "apps/statistics/cumulative_icon.h"
#include "apps/statistics/histogram_icon.h"
#include "apps/statistics/statistics_normal_icon.h"
#include "apps/lambda/lambda_icon.h"
#include "apps/off/off_icon.h"
#include "apps/settings/sub_menu/press_to_test_success.h"

namespace Theme {

const Escher::Image * LambdaIconProfil::getIcon(const char* name) const {
    if (strcmp(name, "CalculationIcon") == 0) {
        return ImageStore::CalculationIcon;
    }else if (strcmp(name, "CodeIcon") == 0) {
        return ImageStore::CodeIcon;
    }else if (strcmp(name, "DistributionIcon") == 0) {
        return ImageStore::DistributionsIcon;
    }else if (strcmp(name, "ElementIcon") == 0) {
        return ImageStore::ElementsIcon;
    }else if (strcmp(name, "FinanceIcon") == 0) {
        return ImageStore::FinanceIcon;
    }else if (strcmp(name, "GraphIcon") == 0) {
        return ImageStore::GraphIcon;
    }else if (strcmp(name, "InferenceIcon") == 0) {
        return ImageStore::InferenceIcon;
    }else if (strcmp(name, "RegressionIcon") == 0) {
        return ImageStore::RegressionIcon;
    }else if (strcmp(name, "SequenceIcon") == 0) {
        return ImageStore::SequenceIcon;
    }else if (strcmp(name, "SettingsIcon") == 0) {
        return ImageStore::SettingsIcon;
    }else if (strcmp(name, "SolverIcon") == 0) {
        return ImageStore::SolverIcon;
    }else if (strcmp(name, "StatIcon") == 0) {
        return ImageStore::StatIcon;
    }else if (strcmp(name, "OffIcon") == 0) {
        return ImageStore::OffIcon;
    }else if (strcmp(name, "PressToTestSuccess") == 0) {
        return ImageStore::PressToTestSuccess;
    }else if (strcmp(name, "HistogramIcon") == 0) {
        return ImageStore::HistogramIcon;
    }else if (strcmp(name, "BoxIcon") == 0) {
        return ImageStore::BoxIcon;
    }else if (strcmp(name, "CumulativeIcon") == 0) {
        return ImageStore::CumulativeIcon;
    }else if (strcmp(name, "StatisticsNormalIcon") == 0) {
        return ImageStore::StatisticsNormalIcon;
    }else if (strcmp(name, "ConfidenceInterval") == 0) {
        return ImageStore::ConfidenceInterval;
    }else if (strcmp(name, "SignificanceTest") == 0) {
        return ImageStore::SignificanceTest;
    }else if (strcmp(name, "BinomialIcon") == 0) {
        return ImageStore::BinomialIcon;
    }else if (strcmp(name, "ExponentialIcon") == 0) {
        return ImageStore::ExponentialIcon;
    }else if (strcmp(name, "ChiSquaredIcon") == 0) {
        return ImageStore::ChiSquaredIcon;
    }else if (strcmp(name, "GeometricIcon") == 0) {
        return ImageStore::GeometricIcon;
    }else if (strcmp(name, "PoissonIcon") == 0) {
        return ImageStore::PoissonIcon;
    }else if (strcmp(name, "UniformIcon") == 0) {
        return ImageStore::UniformIcon;
    }else if (strcmp(name, "NormalIcon") == 0) {
        return ImageStore::NormalIcon;
    }else if (strcmp(name, "StudentIcon") == 0) {
        return ImageStore::StudentIcon;
    }else if (strcmp(name, "HypergeometricIcon") == 0) {
        return ImageStore::HypergeometricIcon;
    }else if (strcmp(name, "FisherIcon") == 0) {
        return ImageStore::FisherIcon;
    }else if (strcmp(name, "Calculation1Icon") == 0) {
        return ImageStore::Calculation1Icon;
    }else if (strcmp(name, "Calculation2Icon") == 0) {
        return ImageStore::Calculation2Icon;
    }else if (strcmp(name, "Calculation3Icon") == 0) {
        return ImageStore::Calculation3Icon;
    }else if (strcmp(name, "Calculation4Icon") == 0) {
        return ImageStore::Calculation4Icon;
    }else if (strcmp(name, "LambdaIcon") == 0) {
        return ImageStore::LambdaIcon;
    }

    return ImageStore::CalculationIcon;
}
}