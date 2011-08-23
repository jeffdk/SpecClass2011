#/// \dir
#/// Contains executables for Assignment 06

# Where is SPEC_HOME relative to this directory
CODE_HOME = ../../../../..

# What libraries does this executable depend on
LINKED_LIBS = Assignment06wthrowe \
    EventHorizon SurfaceFitting HydroComputeItems  HydroStates \
    ApplyObservers DualFrameSystem DualFrameItems HyperbolicGaugeItems \
    Evolution EventTriggers \
    EvolutionStateChangers \
    ScalarWaveFlat ScalarWaveCurved AugmentedVec \
    GeneralizedHarmonic \
    SpatialCoordMaps FoshSystem FoshBoundaryConditions \
    InitialValueProblem VolumeTerms BoundaryConditions \
    ComputeItems GrItems \
    StrahlkorperItems StrahlkorperResidual StrahlkorperDataSupplier \
    StrahlkorperFinderAlgorithm Strahlkorper OnStrahlkorper \
    SurfaceFinderItems SurfaceResidual SurfaceDataSupplier Surface \
    MinimizationAlgorithm \
    Observers \
    BackgroundMetrics EinsteinSolutions CoordinateTransformations TensorFunctions \
    SpectralFilters SpectralFunctionals BasisFunctions FiniteDifference \
    TensorSphericalHarmonics DfftPack SpherePack\
    Mover Interpolators Functionals \
    Domain Slice Subdomain CoordMap Topology DataMesh IndexMap \
    Vars StringParsing DataBox IO Math Tensor MiscUtils \
    MpiWrappers MyContainers LowLevelUtils ErrorHandling

# What .cpp files containing a main function should be compiled (remove .cpp)
EXECUTABLES = ApplyObservers

##############################################################################
# Nothing below here needs to be changed
##############################################################################
include $(CODE_HOME)/MakefileRules/this_machine.def
include $(CODE_HOME)/MakefileRules/Rules

