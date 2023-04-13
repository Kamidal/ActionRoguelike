// Fill out your copyright notice in the Description page of Project Settings.


#include "SCharacter.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/CharacterMovementComponent.h"

// Sets default values
ASCharacter::ASCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	SpringArmComp = CreateDefaultSubobject<USpringArmComponent>("SpringArmComp");
	SpringArmComp ->SetupAttachment(RootComponent);

	CameraComp = CreateDefaultSubobject<UCameraComponent>("CameraComp");
	CameraComp->SetupAttachment(SpringArmComp);

	GetCharacterMovement()->bOrientRotationToMovement = true;
	bUseControllerRotationYaw = false;

}

// Called when the game starts or when spawned
void ASCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}



// Called every frame
void ASCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// Called to bind functionality to input
void ASCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)//用户输入
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	PlayerInputComponent->BindAxis("MoveForward", this, &ASCharacter::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &ASCharacter::MoveRight);

	PlayerInputComponent->BindAxis("Turn", this, &APawn::AddControllerYawInput);//转向函数
	PlayerInputComponent->BindAxis("Lookup", this, &APawn::AddControllerPitchInput);

}

void ASCharacter::MoveForward(float Value)
{
	FRotator ControlRot = GetControlRotation();//需要摄像机旋转角度，
	//AddMovementInput(GetActorForwardVector(), Value);//前移动函数，期望传入一个能控制摄像机的而不是角色方向上的矢量
	ControlRot.Pitch = 0.0f;//确保不需要上仰或俯视
	ControlRot.Roll = 0.0f;
	AddMovementInput(ControlRot.Vector(), Value);
}
void ASCharacter::MoveRight(float Value)
{
	FRotator ControlRot = GetControlRotation();//需要摄像机旋转角度，
	//AddMovementInput(GetActorForwardVector(), Value);//前移动函数，期望传入一个能控制摄像机的而不是角色方向上的矢量
	ControlRot.Pitch = 0.0f;//确保不需要上仰或俯视
	ControlRot.Roll = 0.0f;
	//X = Forward(red)
	//Y = Right(Green)
	//Z = up(Blue)

	FVector RightVector = FRotationMatrix(ControlRot).GetScaledAxis(EAxis::Y);
	AddMovementInput(GetActorRightVector(), Value);//右移动函数
}
