#include "epsilon.h"

#include "apps/calculation/calculation_icon_epsilon.h"
#include "apps/code/code_icon_epsilon.h"
#include "apps/distributions/distributions_icon_epsilon.h"
#include "apps/distributions/images/binomial_icon_epsilon.h"
#include "apps/distributions/images/chi_squared_icon_epsilon.h"
#include "apps/distributions/images/exponential_icon_epsilon.h"
#include "apps/distributions/images/fisher_icon_epsilon.h"
#include "apps/distributions/images/geometric_icon_epsilon.h"
#include "apps/distributions/images/hypergeometric_icon_epsilon.h"
#include "apps/distributions/images/normal_icon_epsilon.h"
#include "apps/distributions/images/poisson_icon_epsilon.h"
#include "apps/distributions/images/student_icon_epsilon.h"
#include "apps/distributions/images/uniform_icon_epsilon.h"
#include "apps/distributions/images/calculation1_icon_epsilon.h"
#include "apps/distributions/images/calculation2_icon_epsilon.h"
#include "apps/distributions/images/calculation3_icon_epsilon.h"
#include "apps/distributions/images/calculation4_icon_epsilon.h"
#include "apps/elements/elements_icon_epsilon.h"
#include "apps/finance/finance_icon_epsilon.h"
#include "apps/graph/graph_icon_epsilon.h"
#include "apps/inference/inference_icon_epsilon.h"
#include "apps/inference/images/confidence_interval_epsilon.h"
#include "apps/inference/images/significance_test_epsilon.h"
#include "apps/regression/regression_icon_epsilon.h"
#include "apps/sequence/sequence_icon_epsilon.h"
#include "apps/settings/settings_icon_epsilon.h"
#include "apps/solver/solver_icon_epsilon.h"
#include "apps/statistics/stat_icon_epsilon.h"
#include "apps/statistics/box_icon_epsilon.h"
#include "apps/statistics/cumulative_icon_epsilon.h"
#include "apps/statistics/histogram_icon_epsilon.h"
#include "apps/statistics/statistics_normal_icon_epsilon.h"
#include "apps/lambda/lambda_icon.h"
#include "apps/off/off_icon_epsilon.h"
#include "apps/settings/sub_menu/press_to_test_success_epsilon.h"

namespace Theme {

const Escher::Image * EpsilonIconProfil::getIcon(const char* name) const {
    if (strcmp(name, "CalculationIcon") == 0) {
        return ImageStore::CalculationIconEpsilon;
    }else if (strcmp(name, "CodeIcon") == 0) {
        return ImageStore::CodeIconEpsilon;
    }else if (strcmp(name, "DistributionIcon") == 0) {
        return ImageStore::DistributionsIconEpsilon;
    }else if (strcmp(name, "ElementIcon") == 0) {
        return ImageStore::ElementsIconEpsilon;
    }else if (strcmp(name, "FinanceIcon") == 0) {
        return ImageStore::FinanceIconEpsilon;
    }else if (strcmp(name, "GraphIcon") == 0) {
        return ImageStore::GraphIconEpsilon;
    }else if (strcmp(name, "InferenceIcon") == 0) {
        return ImageStore::InferenceIconEpsilon;
    }else if (strcmp(name, "RegressionIcon") == 0) {
        return ImageStore::RegressionIconEpsilon;
    }else if (strcmp(name, "SequenceIcon") == 0) {
        return ImageStore::SequenceIconEpsilon;
    }else if (strcmp(name, "SettingsIcon") == 0) {
        return ImageStore::SettingsIconEpsilon;
    }else if (strcmp(name, "SolverIcon") == 0) {
        return ImageStore::SolverIconEpsilon;
    }else if (strcmp(name, "StatIcon") == 0) {
        return ImageStore::StatIconEpsilon;
    }else if (strcmp(name, "OffIcon") == 0) {
        return ImageStore::OffIconEpsilon;
    }else if (strcmp(name, "PressToTestSuccess") == 0) {
        return ImageStore::PressToTestSuccessEpsilon;
    }else if (strcmp(name, "HistogramIcon") == 0) {
        return ImageStore::HistogramIconEpsilon;
    }else if (strcmp(name, "BoxIcon") == 0) {
        return ImageStore::BoxIconEpsilon;
    }else if (strcmp(name, "CumulativeIcon") == 0) {
        return ImageStore::CumulativeIconEpsilon;
    }else if (strcmp(name, "StatisticsNormalIcon") == 0) {
        return ImageStore::StatisticsNormalIconEpsilon;
    }else if (strcmp(name, "ConfidenceInterval") == 0) {
        return ImageStore::ConfidenceIntervalEpsilon;
    }else if (strcmp(name, "SignificanceTest") == 0) {
        return ImageStore::SignificanceTestEpsilon;
    }else if (strcmp(name, "BinomialIcon") == 0) {
        return ImageStore::BinomialIconEpsilon;
    }else if (strcmp(name, "ExponentialIcon") == 0) {
        return ImageStore::ExponentialIconEpsilon;
    }else if (strcmp(name, "ChiSquaredIcon") == 0) {
        return ImageStore::ChiSquaredIconEpsilon;
    }else if (strcmp(name, "GeometricIcon") == 0) {
        return ImageStore::GeometricIconEpsilon;
    }else if (strcmp(name, "PoissonIcon") == 0) {
        return ImageStore::PoissonIconEpsilon;
    }else if (strcmp(name, "UniformIcon") == 0) {
        return ImageStore::UniformIconEpsilon;
    }else if (strcmp(name, "NormalIcon") == 0) {
        return ImageStore::NormalIconEpsilon;
    }else if (strcmp(name, "StudentIcon") == 0) {
        return ImageStore::StudentIconEpsilon;
    }else if (strcmp(name, "HypergeometricIcon") == 0) {
        return ImageStore::HypergeometricIconEpsilon;
    }else if (strcmp(name, "FisherIcon") == 0) {
        return ImageStore::FisherIconEpsilon;
    }else if (strcmp(name, "Calculation1Icon") == 0) {
        return ImageStore::Calculation1IconEpsilon;
    }else if (strcmp(name, "Calculation2Icon") == 0) {
        return ImageStore::Calculation2IconEpsilon;
    }else if (strcmp(name, "Calculation3Icon") == 0) {
        return ImageStore::Calculation3IconEpsilon;
    }else if (strcmp(name, "Calculation4Icon") == 0) {
        return ImageStore::Calculation4IconEpsilon;
    }else if (strcmp(name, "LambdaIcon") == 0) {
        return ImageStore::LambdaIcon;
    }

    return ImageStore::CalculationIconEpsilon;
}
}