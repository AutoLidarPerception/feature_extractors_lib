#ifndef ESF_FEATURE_EXTRACTOR_H_
#define ESF_FEATURE_EXTRACTOR_H_

#include "base_feature_extractor.hpp"
#include <pcl/features/esf.h>

namespace feature {

    class ESFFeatureExtractor : public BaseFeatureExtractor {

    public:
        ESFFeatureExtractor();

        ~ESFFeatureExtractor();

        virtual void compute(const std::vector<PointICloudPtr>& cloud_clusters,
                             std::vector<Feature>* features);

        virtual void compute(const PointICloud& cloud_in, Feature* feature);

        virtual std::string name() const
        {
            return "ESFFeatureExtractor";
        }

    private:
        pcl::ESFEstimation<Point, pcl::ESFSignature640> esf_estimator_;

        static constexpr unsigned int kESFDimension = 640u;
    };
}

#endif /* ESF_FEATURE_EXTRACTOR_H_ */