// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class Middle_Main_Project : ModuleRules
{
	public Middle_Main_Project(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "HeadMountedDisplay" });
	}
}
