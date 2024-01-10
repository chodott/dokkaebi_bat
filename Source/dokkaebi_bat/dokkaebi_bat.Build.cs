// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class dokkaebi_bat : ModuleRules
{
	public dokkaebi_bat(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "HeadMountedDisplay", "EnhancedInput" });
	}
}
