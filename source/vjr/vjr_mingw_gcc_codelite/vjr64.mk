##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=vjr64
ConfigurationName      :=Debug
WorkspacePath          := "C:\libsf\source\vjr\vjr_mingw_gcc_codelite"
ProjectPath            := "C:\libsf\source\vjr\vjr_mingw_gcc_codelite"
IntermediateDirectory  :=./Debug
OutDir                 := $(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=rhodgin
Date                   :=12/20/14
CodeLitePath           :="C:\Program Files (x86)\CodeLite"
LinkerName             :=C:\mingw-w64\mingw64\bin\g++.exe 
SharedObjectLinkerName :=C:\mingw-w64\mingw64\bin\g++.exe -shared -fPIC
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
ObjectsFileList        :="vjr64.txt"
PCHCompileFlags        :=
MakeDirCommand         :=makedir
RcCmpOptions           := 
RcCompilerName         :=C:\mingw-w64\mingw64\bin\windres.exe 
LinkOptions            :=  
IncludePath            :=  $(IncludeSwitch). $(IncludeSwitch). $(IncludeSwitch)/libsf/source/vjr/ 
IncludePCH             := 
RcIncludePath          := 
Libs                   := $(LibrarySwitch)kernel $(LibrarySwitch)user $(LibrarySwitch)gdi $(LibrarySwitch)winspool $(LibrarySwitch)comdlg $(LibrarySwitch)advapi $(LibrarySwitch)shell $(LibrarySwitch)ole $(LibrarySwitch)oleaut $(LibrarySwitch)uuid $(LibrarySwitch)odbc $(LibrarySwitch)odbccp $(LibrarySwitch)SDL $(LibrarySwitch)glew32 $(LibrarySwitch)glew32s $(LibrarySwitch)freeglut $(LibrarySwitch)freeglut_static $(LibrarySwitch)glu32 $(LibrarySwitch)opengl32 
ArLibs                 :=  "kernel" "user" "gdi" "winspool" "comdlg" "advapi" "shell" "ole" "oleaut" "uuid" "odbc" "odbccp" "SDL" "glew32" "glew32s" "freeglut" "freeglut_static" "glu32" "opengl32" 
LibPath                := $(LibraryPathSwitch). $(LibraryPathSwitch)C:/libsf/source/vjr/vjr_mingw_gcc_codelite/lib64 $(LibraryPathSwitch)C:/libsf/source/vjr/sound/SDL-1.2.15/lib/x64 

##
## Common variables
## AR, CXX, CC, AS, CXXFLAGS and CFLAGS can be overriden using an environment variables
##
AR       := C:\mingw-w64\mingw64\bin\ar.exe rcu
CXX      := C:\mingw-w64\mingw64\bin\g++.exe 
CC       := C:\mingw-w64\mingw64\bin\gcc.exe 
CXXFLAGS :=  -m64 -g -O0 -Wall -Wno-comment -Wno-multichar -Wno-narrowing -Wno-write-strings -Wno-format-contains-nul -fno-permissive $(Preprocessors)
CFLAGS   :=  -m64 -g -O0 -Wall -Wno-comment -Wno-multichar -Wno-narrowing -Wno-write-strings -Wno-format-contains-nul -fpermissive $(Preprocessors)
ASFLAGS  := 
AS       := C:\mingw-w64\mingw64\bin\as.exe 


##
## User defined environment variables
##
CodeLiteDir:=C:\Program Files (x86)\CodeLite
UNIT_TEST_PP_SRC_DIR:=C:\UnitTest++-1.3
Objects0=$(IntermediateDirectory)/vjr_vjr.cpp$(ObjectSuffix) $(IntermediateDirectory)/bmps_bmps.cpp$(ObjectSuffix) 



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
	@$(MakeDirCommand) "./Debug"

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

$(IntermediateDirectory)/bmps_bmps.cpp$(ObjectSuffix): ../bmps/bmps.cpp $(IntermediateDirectory)/bmps_bmps.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/libsf/source/vjr/bmps/bmps.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/bmps_bmps.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/bmps_bmps.cpp$(DependSuffix): ../bmps/bmps.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/bmps_bmps.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/bmps_bmps.cpp$(DependSuffix) -MM "../bmps/bmps.cpp"

$(IntermediateDirectory)/bmps_bmps.cpp$(PreprocessSuffix): ../bmps/bmps.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/bmps_bmps.cpp$(PreprocessSuffix) "../bmps/bmps.cpp"


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) $(IntermediateDirectory)/vjr_vjr.cpp$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/vjr_vjr.cpp$(DependSuffix)
	$(RM) $(IntermediateDirectory)/vjr_vjr.cpp$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/bmps_bmps.cpp$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/bmps_bmps.cpp$(DependSuffix)
	$(RM) $(IntermediateDirectory)/bmps_bmps.cpp$(PreprocessSuffix)
	$(RM) $(OutputFile)
	$(RM) $(OutputFile).exe
	$(RM) ".build-debug/vjr64"


