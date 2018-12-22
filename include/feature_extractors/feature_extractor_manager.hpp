#ifndef FEATURE_EXTRACTOR_MANAGER_HPP_
#define FEATURE_EXTRACTOR_MANAGER_HPP_

#include "base_feature_extractor.hpp"
#include "esf_feature_extractor.hpp"
#include "eigenvalue_feature_extractor.hpp"
#include <ros/ros.h>

namespace feature {

    static std::unique_ptr<BaseFeatureExtractor> createFeatureExtractor(FeatureExtractorParams params)
    {
        std::unique_ptr<BaseFeatureExtractor> feature_extractor;
        if (params.extractor_type == "ESF") {
            feature_extractor = std::unique_ptr<BaseFeatureExtractor>(new ESFFeatureExtractor);
            ROS_INFO("[feature] Feature Extractor using Ensemble of Shapes.");
        }
        else if (params.extractor_type == "EigenValueBased") {
            feature_extractor = std::unique_ptr<BaseFeatureExtractor>(new EigenValueFeatureExtractor);
            ROS_INFO("[feature] Feature Extractor using Eigenvalue-based Features.");
        }
        else {
            feature_extractor = std::unique_ptr<BaseFeatureExtractor>(new EigenValueFeatureExtractor);
            ROS_INFO("[feature] Feature Extractor using Eigenvalue-based Features.");
        }
        return feature_extractor;
    }
}

#endif  /* FEATURE_EXTRACTOR_MANAGER_HPP_ */