#/// \dir
#/// Contains a minimal set of files for adding a new executable to SpEC

# Where is SPEC_HOME relative to this directory
CODE_HOME = ../../../../..

# What libraries does this executable depend on
LINKED_LIBS = \
     BasisFunctions DfftPack SpherePack TensorSphericalHarmonics \
     Domain Slice Subdomain Topology IndexMap CoordMap DataMesh \
     Math DataBox StringParsing IO Tensor \
     MiscUtils MpiWrappers MyContainers LowLevelUtils ErrorHandling 

# What .cpp files containing a main function should be compiled (remove .cpp)
EXECUTABLES = LoopOverSubdomains MpiHelloWorld

##############################################################################
# Nothing below here needs to be changed
##############################################################################
include $(CODE_HOME)/MakefileRules/this_machine.def
include $(CODE_HOME)/MakefileRules/Rules

