# /// \dir ApplyObservers/Executables
# /// Contains the executable ApplyObservers which allows to run
# /// ComputeItems and Observers postprocessing.

CODE_HOME = ../../../../..

SUBDIRECTORIES = 

# This must include ALL libs (both required and optional) in the correct order
# Will change to ONLY optional after Larry's dependency analyzer work is done
ALL_INCLUDED_AND_LINKED_LIBS = \
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
    MpiWrappers MyContainers LowLevelUtils ErrorHandling \
    Assignment06danh Assignment07danh
# Required libs
INCLUDED_AND_LINKED_LIBS = \
    ApplyObservers \
    Evolution EventTriggers \
    DualFrameSystem DualFrameItems \
    EvolutionStateChangers SpatialCoordMaps FoshSystem FoshBoundaryConditions \
    StrahlkorperItems StrahlkorperResidual StrahlkorperDataSupplier\
    StrahlkorperFinderAlgorithm Strahlkorper \
    SurfaceFinderItems SurfaceResidual SurfaceDataSupplier Surface \
    MinimizationAlgorithm \
    Observers ComputeItems GrItems \
    BackgroundMetrics EinsteinSolutions CoordinateTransformations TensorFunctions \
    SpectralFilters SpectralFunctionals BasisFunctions \
    DfftPack SpherePack TensorSphericalHarmonics \
    Mover Interpolators Functionals \
    Domain Slice Subdomain CoordMap Topology DataMesh IndexMap \
    Vars StringParsing DataBox IO Math Tensor MiscUtils \
    MpiWrappers MyContainers LowLevelUtils ErrorHandling \


EXECUTABLES = MyApplyObservers

##############################################################################
# Nothing below here needs to be changed
##############################################################################
include $(CODE_HOME)/MakefileRules/this_machine.def
include $(CODE_HOME)/MakefileRules/Rules
