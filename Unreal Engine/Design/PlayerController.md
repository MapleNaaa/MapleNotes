#### 增强输入系统
key：InputAction 和 InputMappingContext
```
// BeginPlay()
UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer());

check(Subsystem);
Subsystem->AddMappingContext(InputMappingContext)
```

```
// SetupInputComponent()
EnhancedInputComponent* EnhancedInputComponent = CastCheck<EnhancedInputComponent>(InputComponent);

EnhancedInputComponent->BindAction(InputAction,ETriggerEvent::Triggered,this,&FuncName)
```

