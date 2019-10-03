// Fill out your copyright notice in the Description page of Project Settings.


#include "BA_GameInstance.h"
#include "OnlineSubsystemImpl.h"
#include "Templates/SharedPointer.h"

UBA_GameInstance::UBA_GameInstance(const FObjectInitializer& ObjectInitializer)
{
	OnCreateSessionCompleteDelegate = FOnCreateSessionCompleteDelegate::CreateUObject(this, &UBA_GameInstance::OnCreateSessionComplete);
	OnStartSessionCompleteDelegate = FOnStartSessionCompleteDelegate::CreateUObject(this, &UBA_GameInstance::OnStartOnlineGameComplete);
}

bool UBA_GameInstance::HostSession(TSharedPtr<const FUniqueNetId> UserId, FName SessionName, bool bIsLan, bool bIsPresence, int32 MaxNumPlayers)
{
	IOnlineSubsystem* const Onlinesub = IOnlineSubsystem::Get();

	if (Onlinesub)
	{
		IOnlineSessionPtr Sessions = Onlinesub->GetSessionInterface();

		if (Sessions.IsValid() && UserId.IsValid())
		{
			SessionSettings = MakeShareable(new FOnlineSessionSettings());
			//SessionSettings->bIsLan
		}
	}
	return false;
}

void UBA_GameInstance::OnCreateSessionComplete(FName SessionName, bool bWasSuccessful)
{
}

void UBA_GameInstance::OnStartOnlineGameComplete(FName SessionName, bool bWasSuccessful)
{
}
