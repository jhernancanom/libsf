##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Release
ProjectName            :=vjr
ConfigurationName      :=Release
WorkspacePath          := "C:\libsf\source\vjr\vjr"
ProjectPath            := "C:\libsf\source\vjr\vjr"
IntermediateDirectory  :=./Release
OutDir                 := $(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=Administrator
Date                   :=08/03/14
CodeLitePath           :="C:\Program Files\CodeLite"
LinkerName             :=C:\MinGW-4.8.1\bin\g++.exe 
SharedObjectLinkerName :=C:\MinGW-4.8.1\bin\g++.exe -shared -fPIC
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
OutputFile             :=../vjr.exe
Preprocessors          :=$(PreprocessorSwitch)NDEBUG 
ObjectSwitch           :=-o 
ArchiveOutputSwitch    := 
PreprocessOnlySwitch   :=-E
ObjectsFileList        :="vjr.txt"
PCHCompileFlags        :=
MakeDirCommand         :=makedir
RcCmpOptions           := 
RcCompilerName         :=C:\MinGW-4.8.1\bin\windres.exe 
LinkOptions            :=  
IncludePath            :=  $(IncludeSwitch). $(IncludeSwitch). 
IncludePCH             := 
RcIncludePath          := 
Libs                   := $(LibrarySwitch)kernel32 $(LibrarySwitch)user32 $(LibrarySwitch)gdi32 $(LibrarySwitch)winspool $(LibrarySwitch)comdlg32 $(LibrarySwitch)advapi32 $(LibrarySwitch)shell32 $(LibrarySwitch)ole32 $(LibrarySwitch)oleaut32 $(LibrarySwitch)uuid $(LibrarySwitch)odbc32 $(LibrarySwitch)odbccp32 $(LibrarySwitch)SDL 
ArLibs                 :=  "kernel32" "user32" "gdi32" "winspool" "comdlg32" "advapi32" "shell32" "ole32" "oleaut32" "uuid" "odbc32" "odbccp32" "SDL" 
LibPath                := $(LibraryPathSwitch). 

##
## Common variables
## AR, CXX, CC, AS, CXXFLAGS and CFLAGS can be overriden using an environment variables
##
AR       := C:\MinGW-4.8.1\bin\ar.exe rcu
CXX      := C:\MinGW-4.8.1\bin\g++.exe 
CC       := C:\MinGW-4.8.1\bin\gcc.exe 
CXXFLAGS :=  -O2 -Wall -Wno-comment -Wno-multichar -Wno-narrowing -Wno-write-strings -Wno-format-contains-nul -Wno-strict-aliasing $(Preprocessors)
CFLAGS   :=  -O2 -Wall $(Preprocessors)
ASFLAGS  := 
AS       := C:\MinGW-4.8.1\bin\as.exe 


##
## User defined environment variables
##
CodeLiteDir:=C:\Program Files\CodeLite
UNIT_TEST_PP_SRC_DIR:=C:\UnitTest++-1.3
Objects0=$(IntermediateDirectory)/vjr_vjr.cpp$(ObjectSuffix) 



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
	@$(MakeDirCommand) "./Release"

PreBuild:


##
## Objects
##
$(IntermediateDirectory)/vjr_vjr.cpp$(ObjectSuffix): ../vjr.cpp $(IntermediateDirectory)/vjr_vjr.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/libsf/source/vjr/vjr.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/vjr_vjr.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/vjr_vjr.cpp$(DependSuffix): ../vjr.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/vjr_vjr.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/vjr_vjr.cpp$(DependSuffix) -MM "../vjr.cpp"

$(IntermediateDirectory)/vjr_vjr.cpp$(PreprocessSuffix): ../vjr.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/vjr_vjr.cpp$(PreprocessSuffix) "../vjr.cpp"


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) $(IntermediateDirectory)/vjr_vjr.cpp$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/vjr_vjr.cpp$(DependSuffix)
	$(RM) $(IntermediateDirectory)/vjr_vjr.cpp$(PreprocessSuffix)
	$(RM) $(OutputFile)
	$(RM) $(OutputFile).exe
	$(RM) ".build-release/vjr"


