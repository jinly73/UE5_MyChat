// Fill out your copyright notice in the Description page of Project Settings.


#include "Client.h"
#include "SocketSubsystem.h"
#include "Interfaces/IPv4/IPv4Address.h"
#include "Sockets.h"
#include "Engine/Engine.h"
#include "Kismet/KismetSystemLibrary.h"

// Sets default values
AClient::AClient()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//���� ����
	Socket = ISocketSubsystem::Get(PLATFORM_SOCKETSUBSYSTEM)->CreateSocket(TEXT("Stream"), TEXT("ServerSocket"));


	// IP�� FString���� �Է¹޾� ����
	FString address = TEXT("127.0.0.1");
	FIPv4Address ip;
	FIPv4Address::Parse(address, ip);

	int32 port = 6000;

	// ��Ʈ�� ������ ��� Ŭ����
	TSharedRef<FInternetAddr> addr = ISocketSubsystem::Get(PLATFORM_SOCKETSUBSYSTEM)->CreateInternetAddr();
	addr->SetIp(ip.Value);
	addr->SetPort(port);

	//GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, FString::Printf(TEXT("Trying to connect.")));



	// ����õ�, ����� �޾ƿ�
	bool isConnetcted = Socket->Connect(*addr);
	UE_LOG(LogTemp, Warning, TEXT("%s"), (isConnetcted ? TEXT("ture") : TEXT("false")));
}

// Called when the game starts or when spawned
void AClient::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AClient::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

