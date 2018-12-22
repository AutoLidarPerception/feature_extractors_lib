#ifndef EIGENVALUE_FEATURE_EXTRACTOR_HPP_
#define EIGENVALUE_FEATURE_EXTRACTOR_HPP_

#include "base_feature_extractor.hpp"

namespace feature {

    class EigenValueFeatureExtractor : public BaseFeatureExtractor {

    public:
        EigenValueFeatureExtractor();

        ~EigenValueFeatureExtractor();

        virtual void compute(const std::vector<PointICloudPtr>& cloud_clusters,
                             std::vector<Feature>* features);

        virtual void compute(const PointICloud& cloud_in, Feature* feature);

        /// \brief Get the descriptor's dimension.
        virtual unsigned int dimension() const
        {
            return kDimension;
        };

        virtual std::string name() const
        {
            return "EigenValueFeatureExtractor";
        }

    private:

        static constexpr unsigned int kDimension = 9u;
    };
}

#endif /* EIGENVALUE_FEATURE_EXTRACTOR_HPP_ */