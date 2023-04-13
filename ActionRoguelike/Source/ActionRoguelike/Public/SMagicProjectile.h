// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SMagicProjectile.generated.h"
class USphereComponent;
class UProjectilemovementComponent;
class UParticalSystemComponent;

UCLASS()
class ACTIONROGUELIKE_API ASMagicProjectile : public AActor//�̳�actor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASMagicProjectile();

protected:
	UPROPERTY(VisibleAnywhere)
		USphereComponent* SphereComp;//�������

	UPROPERTY(VisibleAnywhere)
		UProjectilemovementComponent* movementComp;//Ͷ�����˶�����������ٶȣ�ֱ���˶�
	
	UPROPERTY(VisibleAnywhere)
		UParticalSystemComponent* EffectComp;//����ϵͳ���
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
