#include "HardParticles.h"
#include "ParticleCoreShell.h"
#include "BornAgainNamespace.h"
#include "MathConstants.h"
#include "HomogeneousMaterial.h"
#include "Particle.h"
#include "Rotations.h"

#include <iostream>

class ParticleCoreShellTest : public ::testing::Test
{
protected:
    ParticleCoreShellTest();
    virtual ~ParticleCoreShellTest();

    ParticleCoreShell *mp_coreshell;
};

ParticleCoreShellTest::ParticleCoreShellTest()
    : mp_coreshell(nullptr)
{
    Particle core;
    Particle shell;
    kvector_t position;
    mp_coreshell = new ParticleCoreShell(shell, core, position);
}

ParticleCoreShellTest::~ParticleCoreShellTest()
{
    delete mp_coreshell;
}

TEST_F(ParticleCoreShellTest, InitialState)
{
    EXPECT_EQ(nullptr, mp_coreshell->getAmbientMaterial());
    EXPECT_EQ(nullptr, mp_coreshell->createFormFactor());
    EXPECT_EQ(nullptr, mp_coreshell->getRotation());
    EXPECT_EQ(BornAgain::ParticleCoreShellType, mp_coreshell->getName());
    EXPECT_EQ(BornAgain::ParticleType, mp_coreshell->coreParticle()->getName());
    EXPECT_EQ(BornAgain::ParticleType, mp_coreshell->shellParticle()->getName());
}

TEST_F(ParticleCoreShellTest, Clone)
{
    ParticleCoreShell *p_clone = mp_coreshell->clone();
    EXPECT_EQ(nullptr, p_clone->createFormFactor());
    EXPECT_EQ(nullptr, p_clone->getRotation());
    EXPECT_EQ(BornAgain::ParticleCoreShellType, p_clone->getName());
    EXPECT_EQ(BornAgain::ParticleType, p_clone->coreParticle()->getName());
    EXPECT_EQ(BornAgain::ParticleType, p_clone->shellParticle()->getName());
    delete p_clone;
}

TEST_F(ParticleCoreShellTest, CloneInvertB)
{
    ParticleCoreShell *p_clone = mp_coreshell->cloneInvertB();
    EXPECT_EQ(nullptr, p_clone->createFormFactor());
    EXPECT_EQ(nullptr, p_clone->getRotation());
    EXPECT_EQ(BornAgain::ParticleCoreShellType, p_clone->getName());
    EXPECT_EQ(BornAgain::ParticleType, p_clone->coreParticle()->getName());
    EXPECT_EQ(BornAgain::ParticleType, p_clone->shellParticle()->getName());
    delete p_clone;
}

TEST_F(ParticleCoreShellTest, ComplexCoreShellClone)
{
    HomogeneousMaterial mCore("Ag", 1.245e-5, 5.419e-7);
    HomogeneousMaterial mShell("AgO2", 8.600e-6, 3.442e-7);

    double shell_length(50);
    double shell_width(20);
    double shell_height(10);
    double core_length = shell_length/2;
    double core_width = shell_width/2;
    double core_height = shell_height/2;

    Particle core(mCore, FormFactorBox(core_length, core_width, core_height));
    Particle shell(mShell, FormFactorBox(shell_length, shell_width, shell_height));
    kvector_t relative_pos(0, 0, (shell_height-core_height)/2);
    ParticleCoreShell coreshell(shell, core, relative_pos);
    coreshell.setRotation(RotationY(90*Units::degree));
    coreshell.setPosition(kvector_t(0,0,-10));

    ParticleCoreShell *clone = coreshell.clone();
    EXPECT_EQ(coreshell.coreParticle()->getPosition(), relative_pos);
    EXPECT_EQ(clone->coreParticle()->getPosition(), relative_pos);
}

TEST_F(ParticleCoreShellTest, getChildren)
{
    HomogeneousMaterial mat("mat", 0.0, 0.0);
    Particle core(mat, FormFactorBox(1.0, 1.0, 1.0));
    Particle shell(mat, FormFactorFullSphere(1.0));
    ParticleCoreShell coreshell(shell, core);

    std::vector<const INode*> children = coreshell.getChildren();
    EXPECT_EQ(children.size(), 2u);
    EXPECT_EQ(dynamic_cast<const Particle*>(
                  children.at(0))->getFormFactor()->getName(), BornAgain::FFBoxType);
    EXPECT_EQ(dynamic_cast<const Particle*>(
                  children.at(1))->getFormFactor()->getName(), BornAgain::FFFullSphereType);

    // adding rotation and checking children again
    coreshell.setRotation(RotationZ(0.1));
    children = coreshell.getChildren();
    EXPECT_EQ(children.size(), 3u);
    EXPECT_EQ(children.at(0)->getName(), BornAgain::ZRotationType);
    EXPECT_EQ(dynamic_cast<const Particle*>(
                  children.at(1))->getFormFactor()->getName(), BornAgain::FFBoxType);
    EXPECT_EQ(dynamic_cast<const Particle*>(
                  children.at(2))->getFormFactor()->getName(), BornAgain::FFFullSphereType);
}
