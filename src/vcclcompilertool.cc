// Copyright 2012 William Dang.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//    http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
#include "precompiled.h"
#include "vcclcompilertool.h"

#define VCCLCOMPILERTOOL_IMPL X(AdditionalIncludeDirectories) \
  X(AdditionalOptions) \
  X(AdditionalUsingDirectories) \
  X(AssemblerListingLocation) \
  X(AssemblerOutput) \
  X(BasicRuntimeChecks) \
  X(BrowseInformation) \
  X(BrowseInformationFile) \
  X(BufferSecurityCheck) \
  X(CallingConvention) \
  X(CompileAs) \
  X(CompileAsManaged) \
  X(CompileOnly) \
  X(DebugInformationFormat) \
  X(DefaultCharIsUnsigned) \
  X(Detect64BitPortabilityProblems) \
  X(DisableLanguageExtensions) \
  X(DisableSpecificWarnings) \
  X(EnableEnhancedInstructionSet) \
  X(EnableFiberSafeOptimizations) \
  X(EnableFunctionLevelLinking) \
  X(EnableIntrinsicFunctions) \
  X(EnablePREfast) \
  X(ErrorReporting) \
  X(ExceptionHandling) \
  X(ExecutionBucket) \
  X(ExpandAttributedSource) \
  X(FavorSizeOrSpeed) \
  X(FloatingPointExceptions) \
  X(floatingPointModel) \
  X(ForceConformanceInForLoopScope) \
  X(ForcedIncludeFiles) \
  X(ForcedUsingFiles) \
  X(FullIncludePath) \
  X(GeneratePreprocessedFile) \
  X(GenerateXMLDocumentationFiles) \
  X(IgnoreStandardIncludePath) \
  X(InlineFunctionExpansion) \
  X(KeepComments) \
  X(MinimalRebuild) \
  X(ObjectFile) \
  X(OmitDefaultLibName) \
  X(OmitFramePointers) \
  X(OpenMP) \
  X(Optimization) \
  X(PrecompiledHeaderFile) \
  X(PrecompiledHeaderThrough) \
  X(PreprocessorDefinitions) \
  X(ProgramDataBaseFileName) \
  X(RuntimeLibrary) \
  X(RuntimeTypeInfo) \
  X(ShowIncludes) \
  X(SmallerTypeCheck) \
  X(StringPooling) \
  X(StructMemberAlignment) \
  X(SuppressStartupBanner) \
  X(ToolKind) \
  X(toolName) \
  X(ToolPath) \
  X(TreatWChar_tAsBuiltInType) \
  X(UndefineAllPreprocessorDefinitions) \
  X(UndefinePreprocessorDefinitions) \
  X(UseFullPaths) \
  X(UsePrecompiledHeader) \
  X(UseUnicodeResponseFiles) \
  X(VCProjectEngine) \
  X(WarnAsError) \
  X(WarningLevel) \
  X(WholeProgramOptimization) \
  X(XMLDocumentationFileName)


#define X(NAME) const char* VCCLCompilerTool::NAME() const { \
    auto iter = properties.find(# NAME); \
    return iter == properties.end() ? "" : iter->second.c_str(); \
}
VCCLCOMPILERTOOL_IMPL
#undef X

VCCLCompilerTool::VCCLCompilerTool(const VCProject::Configuration& configuration) {
  auto iter = configuration.properties.find("VCCLCompilerTool");
  if (iter != configuration.properties.end()) {
    properties = iter->second;
  }
}
