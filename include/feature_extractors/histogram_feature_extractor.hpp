#ifndef HISTOGRAM_FEATURE_DESCRIPTOR_HPP_
#define HISTOGRAM_FEATURE_DESCRIPTOR_HPP_

#include "common/types/feature.hpp"
#include "common/types/type.h"

namespace feature {

    class HistogramFeatureExtractor {
    public:
        // @brief intialize feature descriptor
        // @params[IN] cloud: given cloud for feature extraction
        // @return nothing
        explicit HistogramFeatureExtractor()
        {}

        ~HistogramFeatureExtractor()
        {}

        // @brief compute histogram feature of given cloud
        // @params[IN] bin_size: bin size of histogram
        // @params[OUT] feature: histogram feature of given cloud
        // @return nothing
        void compute(PointICloudConstPtr cloud_in, Feature* feature);

        // @brief set histogram bin size
        // @params[IN] histogram_bin_size: histogram bin size
        // @return true if set successfully, otherwise return fasle
        void setHistogramBinSize(const float& histogram_bin_size);

    private:
        void getMinMaxCenter(PointICloudConstPtr cloud_in);
        void computeHistogram(const int bin_size, std::vector<float>* feature);

    private:
        float bin_size_;
        Point min_pt_;
        Point max_pt_;
        Point center_pt_;
    }; /* HistogramFeatureExtractor */
}

#endif  /* HISTOGRAM_FEATURE_DESCRIPTOR_HPP_ */