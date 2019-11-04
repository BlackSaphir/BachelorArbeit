// Fill out your copyright notice in the Description page of Project Settings.


#include "BA_GameInstance.h"
#include "OnlineSubsystemImpl.h"
#include "OnlineSessionSettings.h"
#include "Templates/SharedPointer.h"

UBA_GameInstance::UBA_GameInstance(const FObjectInitializer& ObjectInitializer)
{
	OnCreateSessionCompleteDelegate = FOnCreateSessionCompleteDelegate::CreateUObject(this, &UBA_GameInstance::OnCreateSessionComplete);
	OnStartSessionCompleteDelegate = FOnStartSessionCompleteDelegate::CreateUObject(this, &UBA_GameInstance::OnStartOnlineGameComplete);
	//OnFindSessionCompleteDelegate = FOnFindSessionsCompleteDelegate::CreateUObject(this, &UBA_GameInstance::OnFind)
}

void UBA_GameInstance::StartSession()
{
	ULocalPlayer* const Player = GetFirstGamePlayer();

	//HostSession(Player->GetPreferred(UniqueNetId(), true, true);
}

bool UBA_GameInstance::HostSession(TSharedPtr<const FUniqueNetId> UserId, FName SessionName, bool bIsLan, bool bIsPresence, int32 MaxNumPlayers)
{
	IOnlineSubsystem* const OnlineSub = IOnlineSubsystem::Get();

	if (OnlineSub)
	{
		IOnlineSessionPtr Sessions = OnlineSub->GetSessionInterface();

		if (Sessions.IsValid() && UserId.IsValid())
		{
			SessionSettings = MakeShareable(new FOnlineSessionSettings());

			SessionSettings->bIsLANMatch = bIsLan;
			SessionSettings->bUsesPresence = bIsPresence;
			SessionSettings->NumPublicConnections = MaxNumPlayers;
			SessionSettings->NumPrivateConnections = 0;
			SessionSettings->bAllowInvites = true;
			SessionSettings->bShouldAdvertise = true;
			SessionSettings->bAllowJoinViaPresence = true;
			SessionSettings->bAllowJoinViaPresenceFriendsOnly = false;

			SessionSettings->Set(SETTING_MAPNAME, FString("Map_AR"), EOnlineDataAdvertisementType::ViaOnlineService);

			OnCreateSessionCompleteDelegateHandle = Sessions->AddOnCreateSessionCompleteDelegate_Handle(OnCreateSessionCompleteDelegate);

			return Sessions->CreateSession(*UserId, SessionName, *SessionSettings);
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
