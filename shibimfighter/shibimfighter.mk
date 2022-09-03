##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=shibimfighter
ConfigurationName      :=Debug
WorkspaceConfiguration :=Debug
WorkspacePath          :=D:/phuongbk/cppwspace/cppwspace
ProjectPath            :=D:/phuongbk/cppwspace/cppwspace/shibimfighter
IntermediateDirectory  :=$(ConfigurationName)
OutDir                 := $(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=PhuongTD1
Date                   :=03/09/2022
CodeLitePath           :="C:/Program Files/CodeLite"
LinkerName             :=C:/mingw64/bin/g++.exe
SharedObjectLinkerName :=C:/mingw64/bin/g++.exe -shared -fPIC
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
OutputDirectory        :=$(IntermediateDirectory)
OutputFile             :=$(IntermediateDirectory)/$(ProjectName).exe
Preprocessors          :=
ObjectSwitch           :=-o 
ArchiveOutputSwitch    := 
PreprocessOnlySwitch   :=-E
ObjectsFileList        :="shibimfighter.txt"
PCHCompileFlags        :=
MakeDirCommand         :=makedir
RcCmpOptions           := 
RcCompilerName         :=C:/mingw64/bin/windres.exe
LinkOptions            :=  
IncludePath            :=  $(IncludeSwitch). $(IncludeSwitch). $(IncludeSwitch)C:\raylib\win64mingw64\include 
IncludePCH             := 
RcIncludePath          := 
Libs                   := $(LibrarySwitch)raylib $(LibrarySwitch)opengl32 $(LibrarySwitch)gdi32 $(LibrarySwitch)winmm $(LibrarySwitch)pthread 
ArLibs                 :=  "raylib" "opengl32" "gdi32" "winmm" "pthread" 
LibPath                := $(LibraryPathSwitch). $(LibraryPathSwitch)C:\raylib\win64mingw64\lib 

##
## Common variables
## AR, CXX, CC, AS, CXXFLAGS and CFLAGS can be overridden using an environment variable
##
AR       := C:/mingw64/bin/ar.exe rcu
CXX      := C:/mingw64/bin/g++.exe
CC       := C:/mingw64/bin/gcc.exe
CXXFLAGS :=  -g -O0 -Wall  -std=c++14   $(Preprocessors)
CFLAGS   :=  -g -O0 -Wall $(Preprocessors)
ASFLAGS  := 
AS       := C:/mingw64/bin/as.exe


##
## User defined environment variables
##
CodeLiteDir:=C:\Program Files\CodeLite
Objects0=$(IntermediateDirectory)/main.cpp$(ObjectSuffix) $(IntermediateDirectory)/BaseSpace.cpp$(ObjectSuffix) $(IntermediateDirectory)/Fighter.cpp$(ObjectSuffix) $(IntermediateDirectory)/Enemy.cpp$(ObjectSuffix) $(IntermediateDirectory)/Explosion.cpp$(ObjectSuffix) $(IntermediateDirectory)/PowerDrug.cpp$(ObjectSuffix) $(IntermediateDirectory)/Bullet.cpp$(ObjectSuffix) 



Objects=$(Objects0) 

##
## Main Build Targets 
##
.PHONY: all clean PreBuild PrePreBuild PostBuild MakeIntermediateDirs
all: $(OutputFile)

$(OutputFile): $(IntermediateDirectory)/.d $(Objects) 
	@$(MakeDirCommand) $(@D)
	@echo "" > $(IntermediateDirectory)/.d
	@echo $(Objects0)  > $(ObjectsFileList)
	$(LinkerName) $(OutputSwitch)$(OutputFile) @$(ObjectsFileList) $(LibPath) $(Libs) $(LinkOptions)

MakeIntermediateDirs:
	@$(MakeDirCommand) "$(ConfigurationName)"


$(IntermediateDirectory)/.d:
	@$(MakeDirCommand) "$(ConfigurationName)"

PreBuild:


##
## Objects
##
$(IntermediateDirectory)/main.cpp$(ObjectSuffix): main.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/main.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/main.cpp$(DependSuffix) -MM main.cpp
	$(CXX) $(IncludePCH) $(SourceSwitch) "D:/phuongbk/cppwspace/cppwspace/shibimfighter/main.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/main.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/main.cpp$(PreprocessSuffix): main.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/main.cpp$(PreprocessSuffix) main.cpp

$(IntermediateDirectory)/BaseSpace.cpp$(ObjectSuffix): BaseSpace.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/BaseSpace.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/BaseSpace.cpp$(DependSuffix) -MM BaseSpace.cpp
	$(CXX) $(IncludePCH) $(SourceSwitch) "D:/phuongbk/cppwspace/cppwspace/shibimfighter/BaseSpace.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/BaseSpace.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/BaseSpace.cpp$(PreprocessSuffix): BaseSpace.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/BaseSpace.cpp$(PreprocessSuffix) BaseSpace.cpp

$(IntermediateDirectory)/Fighter.cpp$(ObjectSuffix): Fighter.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Fighter.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Fighter.cpp$(DependSuffix) -MM Fighter.cpp
	$(CXX) $(IncludePCH) $(SourceSwitch) "D:/phuongbk/cppwspace/cppwspace/shibimfighter/Fighter.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Fighter.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Fighter.cpp$(PreprocessSuffix): Fighter.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Fighter.cpp$(PreprocessSuffix) Fighter.cpp

$(IntermediateDirectory)/Enemy.cpp$(ObjectSuffix): Enemy.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Enemy.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Enemy.cpp$(DependSuffix) -MM Enemy.cpp
	$(CXX) $(IncludePCH) $(SourceSwitch) "D:/phuongbk/cppwspace/cppwspace/shibimfighter/Enemy.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Enemy.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Enemy.cpp$(PreprocessSuffix): Enemy.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Enemy.cpp$(PreprocessSuffix) Enemy.cpp

$(IntermediateDirectory)/Explosion.cpp$(ObjectSuffix): Explosion.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Explosion.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Explosion.cpp$(DependSuffix) -MM Explosion.cpp
	$(CXX) $(IncludePCH) $(SourceSwitch) "D:/phuongbk/cppwspace/cppwspace/shibimfighter/Explosion.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Explosion.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Explosion.cpp$(PreprocessSuffix): Explosion.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Explosion.cpp$(PreprocessSuffix) Explosion.cpp

$(IntermediateDirectory)/PowerDrug.cpp$(ObjectSuffix): PowerDrug.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/PowerDrug.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/PowerDrug.cpp$(DependSuffix) -MM PowerDrug.cpp
	$(CXX) $(IncludePCH) $(SourceSwitch) "D:/phuongbk/cppwspace/cppwspace/shibimfighter/PowerDrug.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/PowerDrug.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/PowerDrug.cpp$(PreprocessSuffix): PowerDrug.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/PowerDrug.cpp$(PreprocessSuffix) PowerDrug.cpp

$(IntermediateDirectory)/Bullet.cpp$(ObjectSuffix): Bullet.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Bullet.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Bullet.cpp$(DependSuffix) -MM Bullet.cpp
	$(CXX) $(IncludePCH) $(SourceSwitch) "D:/phuongbk/cppwspace/cppwspace/shibimfighter/Bullet.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Bullet.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Bullet.cpp$(PreprocessSuffix): Bullet.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Bullet.cpp$(PreprocessSuffix) Bullet.cpp


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r $(ConfigurationName)/


