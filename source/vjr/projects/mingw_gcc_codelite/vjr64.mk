##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=vjr64
ConfigurationName      :=Debug
WorkspacePath          := "C:\libsf\source\vjr\projects\mingw_gcc_codelite"
ProjectPath            := "C:\libsf\source\vjr\projects\mingw_gcc_codelite"
IntermediateDirectory  :=./Debug
OutDir                 := $(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=Rick
Date                   :=12/22/14
CodeLitePath           :="C:\Program Files (x86)\CodeLite"
LinkerName             :=C:\mingw-w64-4.9.2\mingw64\bin\g++.exe 
SharedObjectLinkerName :=C:\mingw-w64-4.9.2\mingw64\bin\g++.exe -shared -fPIC
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
OutputFile             :=c:/libsf_offline/source/vjr/bin/64-bit/vjr_gcc_64.exe
Preprocessors          :=
ObjectSwitch           :=-o 
ArchiveOutputSwitch    := 
PreprocessOnlySwitch   :=-E
ObjectsFileList        :="vjr64.txt"
PCHCompileFlags        :=
MakeDirCommand         :=makedir
RcCmpOptions           := 
RcCompilerName         :=C:\mingw-w64-4.9.2\mingw64\bin\windres.exe 
LinkOptions            :=  
IncludePath            :=  $(IncludeSwitch). $(IncludeSwitch). $(IncludeSwitch)C:/libsf/source/vjr/projects/vs2010/ 
IncludePCH             := 
RcIncludePath          := 
Libs                   := $(LibrarySwitch)kernel32 $(LibrarySwitch)user32 $(LibrarySwitch)gdi32 $(LibrarySwitch)winspool $(LibrarySwitch)comdlg32 $(LibrarySwitch)advapi32 $(LibrarySwitch)shell32 $(LibrarySwitch)ole32 $(LibrarySwitch)oleaut32 $(LibrarySwitch)uuid $(LibrarySwitch)odbc32 $(LibrarySwitch)odbccp32 $(LibrarySwitch)SDL $(LibrarySwitch)glew32 $(LibrarySwitch)glew32s $(LibrarySwitch)freeglut $(LibrarySwitch)freeglut_static $(LibrarySwitch)glu32 $(LibrarySwitch)opengl32 
ArLibs                 :=  "kernel32" "user32" "gdi32" "winspool" "comdlg32" "advapi32" "shell32" "ole32" "oleaut32" "uuid" "odbc32" "odbccp32" "SDL" "glew32" "glew32s" "freeglut" "freeglut_static" "glu32" "opengl32" 
LibPath                := $(LibraryPathSwitch). $(LibraryPathSwitch)C:/libsf/source/vjr/projects/mingw_gcc_codelite/lib64 $(LibraryPathSwitch)C:/libsf/source/vjr/source/sound/SDL-1.2.15/lib/amd64 

##
## Common variables
## AR, CXX, CC, AS, CXXFLAGS and CFLAGS can be overriden using an environment variables
##
AR       := C:\mingw-w64-4.9.2\mingw64\bin\ar.exe rcu
CXX      := C:\mingw-w64-4.9.2\mingw64\bin\g++.exe 
CC       := C:\mingw-w64-4.9.2\mingw64\bin\gcc.exe 
CXXFLAGS :=  -m64 -g -O0 -Wall -Wno-comment -Wno-multichar -Wno-narrowing -Wno-write-strings -Wno-format-contains-nul $(Preprocessors)
CFLAGS   :=  -m64 -g -O0 -Wall -Wno-comment -Wno-multichar -Wno-narrowing -Wno-write-strings -Wno-format-contains-nul $(Preprocessors)
ASFLAGS  := 
AS       := C:\mingw-w64-4.9.2\mingw64\bin\as.exe 


##
## User defined environment variables
##
CodeLiteDir:=C:\Program Files (x86)\CodeLite
UNIT_TEST_PP_SRC_DIR:=C:\UnitTest++-1.3
Objects0=$(IntermediateDirectory)/source_vjr.cpp$(ObjectSuffix) $(IntermediateDirectory)/bmps_bmps.cpp$(ObjectSuffix) 



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
$(IntermediateDirectory)/source_vjr.cpp$(ObjectSuffix): ../../source/vjr.cpp $(IntermediateDirectory)/source_vjr.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/libsf/source/vjr/source/vjr.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/source_vjr.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/source_vjr.cpp$(DependSuffix): ../../source/vjr.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/source_vjr.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/source_vjr.cpp$(DependSuffix) -MM "../../source/vjr.cpp"

$(IntermediateDirectory)/source_vjr.cpp$(PreprocessSuffix): ../../source/vjr.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/source_vjr.cpp$(PreprocessSuffix) "../../source/vjr.cpp"

$(IntermediateDirectory)/bmps_bmps.cpp$(ObjectSuffix): ../../source/bmps/bmps.cpp $(IntermediateDirectory)/bmps_bmps.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/libsf/source/vjr/source/bmps/bmps.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/bmps_bmps.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/bmps_bmps.cpp$(DependSuffix): ../../source/bmps/bmps.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/bmps_bmps.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/bmps_bmps.cpp$(DependSuffix) -MM "../../source/bmps/bmps.cpp"

$(IntermediateDirectory)/bmps_bmps.cpp$(PreprocessSuffix): ../../source/bmps/bmps.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/bmps_bmps.cpp$(PreprocessSuffix) "../../source/bmps/bmps.cpp"


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) $(IntermediateDirectory)/source_vjr.cpp$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/source_vjr.cpp$(DependSuffix)
	$(RM) $(IntermediateDirectory)/source_vjr.cpp$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/bmps_bmps.cpp$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/bmps_bmps.cpp$(DependSuffix)
	$(RM) $(IntermediateDirectory)/bmps_bmps.cpp$(PreprocessSuffix)
	$(RM) $(OutputFile)
	$(RM) $(OutputFile).exe
	$(RM) ".build-debug/vjr64"


