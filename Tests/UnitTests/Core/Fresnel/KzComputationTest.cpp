#include "google_test.h"
#include "IKzComputation.h"
#include "Layer.h"
#include "MultiLayer.h"
#include "MaterialFactoryFuncs.h"
#include "PlainMultiLayerBySLDBuilder.h"
#include "Units.h"

class KzComputationTest : public ::testing::Test
{
protected:
    ~KzComputationTest() override = default;
};

TEST_F(KzComputationTest, initial)
{
    const complex_t sld_0(0.0, 0.0);
    const complex_t sld_1(8.0241e-06, 6.0448e-8);
    const complex_t sld_2(4.0241e-06, 2.0448e-8);
    const complex_t sld_3(1.0241e-06, 2.0448e-8);
    const complex_t sld_4(0.0, 2.0448e-6);

    MultiLayer mLayer;

    Layer layer0(MaterialBySLD("m0", sld_0.real(), sld_0.imag()));
    Layer layer1(MaterialBySLD("m1", sld_1.real(), sld_1.imag()), 10);
    Layer layer2(MaterialBySLD("m2", sld_2.real(), sld_2.imag()), 10);
    Layer layer3(MaterialBySLD("m3", sld_3.real(), sld_3.imag()), 10);
    Layer layer4(MaterialBySLD("m4", sld_4.real(), sld_4.imag()));
    mLayer.addLayer(layer0);
    mLayer.addLayer(layer1);
    mLayer.addLayer(layer2);
    mLayer.addLayer(layer3);
    mLayer.addLayer(layer4);

    kvector_t k = vecOfLambdaAlphaPhi(1.0, 1.0 * Units::deg, 0.0);

    KzComputation computeWithRefIndex(k);
    KzFromSLDComputation computeWithSLD(k.z());

    auto res_ref = ReducedKzComputation::compute(mLayer, k);
    auto res_ri = computeWithRefIndex.compute(mLayer);
    auto res_sld = computeWithSLD.compute(mLayer);

    EXPECT_EQ(res_ref.size(), res_sld.size());
    EXPECT_EQ(res_ref.size(), res_ri.size());
    for (size_t i = 0; i < res_ref.size(); ++i) {
        EXPECT_NEAR(res_ref[i].real(), res_sld[i].real(), 1e-10);
        EXPECT_NEAR(res_ref[i].imag(), res_sld[i].imag(), 1e-10);
        EXPECT_NEAR(res_ref[i].real(), res_ri[i].real(), 1e-10);
        EXPECT_NEAR(res_ref[i].imag(), res_ri[i].imag(), 1e-10);
    }
}

TEST_F(KzComputationTest, negativeKz)
{
    const complex_t sld_0(0.0, 0.0);
    const complex_t sld_1(8.0241e-06, 6.0448e-8);
    const complex_t sld_2(4.0241e-06, 2.0448e-8);
    const complex_t sld_3(1.0241e-06, 2.0448e-8);
    const complex_t sld_4(0.0, 2.0448e-6);

    MultiLayer mLayer;

    Layer layer0(MaterialBySLD("m0", sld_0.real(), sld_0.imag()));
    Layer layer1(MaterialBySLD("m1", sld_1.real(), sld_1.imag()), 10);
    Layer layer2(MaterialBySLD("m2", sld_2.real(), sld_2.imag()), 10);
    Layer layer3(MaterialBySLD("m3", sld_3.real(), sld_3.imag()), 10);
    Layer layer4(MaterialBySLD("m4", sld_4.real(), sld_4.imag()));
    mLayer.addLayer(layer0);
    mLayer.addLayer(layer1);
    mLayer.addLayer(layer2);
    mLayer.addLayer(layer3);
    mLayer.addLayer(layer4);

    kvector_t k = vecOfLambdaAlphaPhi(1.0, -1.0 * Units::deg, 0.0);

    KzComputation computeWithRefIndex(k);
    KzFromSLDComputation computeWithSLD(k.z());

    auto res_ref = ReducedKzComputation::compute(mLayer, k);
    auto res_ri = computeWithRefIndex.compute(mLayer);
    auto res_sld = computeWithSLD.compute(mLayer);

    EXPECT_EQ(res_ref.size(), res_sld.size());
    EXPECT_EQ(res_ref.size(), res_ri.size());
    for (size_t i = 0; i < res_ref.size(); ++i) {
        EXPECT_NEAR(res_ref[i].real(), res_sld[i].real(), 1e-10);
        EXPECT_NEAR(res_ref[i].imag(), res_sld[i].imag(), 1e-10);
        EXPECT_NEAR(res_ref[i].real(), res_ri[i].real(), 1e-10);
        EXPECT_NEAR(res_ref[i].imag(), res_ri[i].imag(), 1e-10);
    }
}

TEST_F(KzComputationTest, absorptiveAmbience)
{
    const complex_t sld_0(8.0241e-06, 6.0448e-5);
    const complex_t sld_1(8.0241e-06, 6.0448e-8);
    const complex_t sld_2(4.0241e-06, 2.0448e-8);
    const complex_t sld_3(1.0241e-06, 2.0448e-8);
    const complex_t sld_4(0.0, 2.0448e-6);

    MultiLayer mLayer;

    Layer layer0(MaterialBySLD("m0", sld_0.real(), sld_0.imag()));
    Layer layer1(MaterialBySLD("m1", sld_1.real(), sld_1.imag()), 10);
    Layer layer2(MaterialBySLD("m2", sld_2.real(), sld_2.imag()), 10);
    Layer layer3(MaterialBySLD("m3", sld_3.real(), sld_3.imag()), 10);
    Layer layer4(MaterialBySLD("m4", sld_4.real(), sld_4.imag()));
    mLayer.addLayer(layer0);
    mLayer.addLayer(layer1);
    mLayer.addLayer(layer2);
    mLayer.addLayer(layer3);
    mLayer.addLayer(layer4);

    kvector_t k = vecOfLambdaAlphaPhi(1.0, 1.0 * Units::deg, 0.0);

    KzComputation computeWithRefIndex(k);
    KzFromSLDComputation computeWithSLD(k.z());

    auto res_ri = computeWithRefIndex.compute(mLayer);
    auto res_sld = computeWithSLD.compute(mLayer);

    EXPECT_EQ(res_ri.size(), res_sld.size());
    for (size_t i = 0; i < res_ri.size(); ++i) {
        EXPECT_NEAR(res_ri[i].real(), res_sld[i].real(), 1e-10);
        EXPECT_NEAR(res_ri[i].imag(), res_sld[i].imag(), 1e-10);
    }
}

TEST_F(KzComputationTest, TiNiSampleWithRoughness)
{
    PlainMultiLayerBySLDBuilder builder;
    std::unique_ptr<MultiLayer> sample(builder.buildSample());

    kvector_t k = vecOfLambdaAlphaPhi(1.0, 0.0001 * Units::deg, 0.0);

    KzComputation computeWithRefIndex(k);
    KzFromSLDComputation computeWithSLD(k.z());

    auto res_ri = computeWithRefIndex.compute(*sample);
    auto res_sld = computeWithSLD.compute(*sample);

    EXPECT_EQ(res_ri.size(), res_sld.size());
    for (size_t i = 0; i < res_ri.size(); ++i) {
        EXPECT_NEAR(res_ri[i].real(), res_sld[i].real(), 1e-10);
        EXPECT_NEAR(res_ri[i].imag(), res_sld[i].imag(), 1e-10);
    }
}
