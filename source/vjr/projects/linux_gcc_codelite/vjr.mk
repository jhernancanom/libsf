##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=vjr
ConfigurationName      :=Debug
WorkspacePath          := "/libsf/source/vjr/projects/linux_gcc_codelite"
ProjectPath            := "/libsf/source/vjr/projects/linux_gcc_codelite"
IntermediateDirectory  :=./Debug
OutDir                 := $(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=rick
Date                   :=01/17/15
CodeLitePath           :="/home/rick/.codelite"
LinkerName             :=/usr/bin/g++ 
SharedObjectLinkerName :=/usr/bin/g++ -shared -fPIC
ObjectSuffix           :=.o
DependSuffix           :=.o.d
PreprocessSuffix       :=.i
DebugSwitch            :=-g 
IncludeSwitch          :=-I
LibrarySwitch          :=-l
OutputSwitch           :=-o 
LibraryPathSwitch      :=-L
PreprocessorSwitch     :=-D
SourceSwitch           :=-c 
OutputFile             :=$(IntermediateDirectory)/$(ProjectName)
Preprocessors          :=
ObjectSwitch           :=-o 
ArchiveOutputSwitch    := 
PreprocessOnlySwitch   :=-E
ObjectsFileList        :="vjr.txt"
PCHCompileFlags        :=
MakeDirCommand         :=mkdir -p
LinkOptions            :=  
IncludePath            :=  $(IncludeSwitch). $(IncludeSwitch). 
IncludePCH             := 
RcIncludePath          := 
Libs                   := 
ArLibs                 :=  
LibPath                := $(LibraryPathSwitch). 

##
## Common variables
## AR, CXX, CC, AS, CXXFLAGS and CFLAGS can be overriden using an environment variables
##
AR       := /usr/bin/ar rcu
CXX      := /usr/bin/g++ 
CC       := /usr/bin/gcc 
CXXFLAGS :=  -g -O0 -Wall -Wno-comment -Wno-multichar -Wno-narrowing -Wno-write-strings -Wno-format-contains-nul $(Preprocessors)
CFLAGS   :=  -g -O0 -Wall  -Wno-comment -Wno-multichar -Wno-narrowing -Wno-write-strings -Wno-format-contains-nul $(Preprocessors)
ASFLAGS  := 
AS       := /usr/bin/as 


##
## User defined environment variables
##
CodeLiteDir:=/usr/share/codelite
Objects0=$(IntermediateDirectory)/source_vjr.cpp$(ObjectSuffix) 



Objects=$(Objects0) 

##
## Main Build Targets 
##
.PHONY: all clean PreBuild PrePreBuild PostBuild
all: $(OutputFile)

$(OutputFile): $(IntermediateDirectory)/.d $(Objects) 
	@$(MakeDirCommand) $(@D)
	@echo "" > $(IntermediateDirectory)/.d
	@echo $(Objects0)  > $(ObjectsFileList)
	$(LinkerName) $(OutputSwitch)$(OutputFile) @$(ObjectsFileList) $(LibPath) $(Libs) $(LinkOptions)

$(IntermediateDirectory)/.d:
	@test -d ./Debug || $(MakeDirCommand) ./Debug

PreBuild:


##
## Objects
##
$(IntermediateDirectory)/source_vjr.cpp$(ObjectSuffix): ../../source/vjr.cpp $(IntermediateDirectory)/source_vjr.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/libsf/source/vjr/source/vjr.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/source_vjr.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/source_vjr.cpp$(DependSuffix): ../../source/vjr.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/source_vjr.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/source_vjr.cpp$(DependSuffix) -MM "../../source/vjr.cpp"

$(IntermediateDirectory)/source_vjr.cpp$(PreprocessSuffix): ../../source/vjr.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/source_vjr.cpp$(PreprocessSuffix) "../../source/vjr.cpp"


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) ./Debug/*$(ObjectSuffix)
	$(RM) ./Debug/*$(DependSuffix)
	$(RM) $(OutputFile)
	$(RM) ".build-debug/vjr"


