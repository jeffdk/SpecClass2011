#/// \dir
#/// Contains a minimal set of files for adding a new executable to SpEC

# Where is SPEC_HOME relative to this directory
CODE_HOME = ../../../../..

# What libraries does this executable depend on
LINKED_LIBS = DataMesh MyContainers ErrorHandling LowLevelUtils \
                           Tensor Assignment03Bohn

# What .cpp files containing a main function should be compiled (remove .cpp)
EXECUTABLES = MyMeshExecBohn MyDM_ExecBohn InvertTensorExecBohn

##############################################################################
# Nothing below here needs to be changed
##############################################################################
include $(CODE_HOME)/MakefileRules/this_machine.def
include $(CODE_HOME)/MakefileRules/Rules

