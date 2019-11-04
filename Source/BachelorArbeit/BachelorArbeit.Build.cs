// Fill out your copyright notice in the Description page of Project Settings.

using UnrealBuildTool;

public class BachelorArbeit : ModuleRules
{
	public BachelorArbeit(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
	
		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "OnlineSubsystem", });

		// Uncomment if you are using online features
		 PrivateDependencyModuleNames.Add("OnlineSubsystem");

        DynamicallyLoadedModuleNames.Add("OnlineSubsystemNull");

		// Uncomment if you are using Slate UI
		// PrivateDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore" });
		

		// To include OnlineSubsystemSteam, add it to the plugins section in your uproject file with the Enabled attribute set to true
	}
}
