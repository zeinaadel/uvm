;*******************************************************************
;* Clothing
;*******************************************************************
[question-StayingHome]
	Text=Are you staying home?
	?Yes=StayingHome
	?No=Leaving

[procedure-StayingHome]
	Question=HomeCold

[procedure-Leaving]
	Question=OutCold

[question-VanillaGuests]
	Text=Are there vanilla guests here?
	?Yes=VanillaYes
	?No=VanillaNo

[procedure-VanillaNo]
	Question=HomeCold

[procedure-VanillaYes]
	Question=OutCold

[timer-Clothing]
	Start=08:00
	End=23:59
	Question=VanillaGuests
	Procedure=ClothReport
	
[procedure-ClothReport]	
	notif=forcenaked
	ClothReport=What are you wearing?

[procedure-CheckOn]
	notif=crossdressing
	notif=#ClothCheck=0
	PunishMessage=You are supposed to wear {$zzCheck}.
	Punish=10

;*******************************************************************
;* Home Procedure
;*******************************************************************
[question-HomeCold]
	text=What is the temperature like?
	?Hot=HomeHot
	?Warm=HomeWarm
	?Cold=HomeCold

[procedure-HomeHot]
	SetFlag=Hot
	RemoveFlag=Warm
	RemoveFlag=Cold
	clothing=Home Hot

[Clothing-Home Hot]
	Askable=1
	Change=Daily
	set=BottomHomeHotFemale
	set=BottomHomeHotMale
	set=TopHomeHot
	Set=BraHome
	set=Underwear
	set=HeelsHome
	Set=Shoes
	Set=Corset
	Set=Collar
	Set=Cuffs	

[procedure-HomeWarm]
	RemoveFlag=Hot
	SetFlag=Warm
	RemoveFlag=Cold
	clothing=Home Warm

[Clothing-Home Warm]
	Askable=1
	Change=Daily
	set=BottomHomeWarmFemale
	set=BottomWarmMale
	set=TopWarm
	Set=BraHome
	set=Underwear
	set=HeelsHome
	Set=Shoes
	Set=Corset
	Set=Collar
	Set=Cuffs

[procedure-HomeCold]
	RemoveFlag=Hot
	RemoveFlag=Warm
	SetFflag=Cold
	Clothing=Home Cold

[Clothing-Home Cold]
	Askable=1
	Change=Daily
	set=BottomHomeColdFemale
	set=BottomColdMale
	set=TopCold
	Set=BraHome
	set=Underwear
	set=HeelsHome
	Set=Shoes
	Set=Corset
	Set=Collar
	Set=Cuffs

;*******************************************************************
;* Leaving Procedure
;*******************************************************************
[question-OutCold]
	text=What is the temperature like?
	?Hot=OutHot
	?Warm=OutWarm
	?Cold=OutCold

[procedure-OutHot]
	SetFlag=Hot
	RemoveFlag=Warm
	RemoveFlag=Cold
	clothing=Out Hot

[Clothing-Out Hot]
	Askable=1
	Change=Daily
	set=BottomHotFemale
	set=BottomHotMale
	set=TopHot
	Set=Bra
	set=Underwear
	set=Heels
	Set=Shoes
	Set=Corset

[procedure-OutWarm]
	RemoveFlag=Hot
	SetFlag=Warm
	RemoveFlag=Cold
	clothing=Out Warm

[Clothing-Out Warm]
	Askable=1
	Change=Daily
	set=BottomWarmFemale
	set=BottomWarmMale
	set=TopWarm
	Set=Bra
	set=Underwear
	set=Heels
	Set=Shoes
	Set=Corset

[procedure-OutCold]
	RemoveFlag=Hot
	RemoveFlag=Warm
	SetFflag=Cold
	Clothing=Out Cold

[Clothing-Out Cold]
	Askable=1
	Change=Daily
	set=BottomColdFemale
	set=BottomColdMale
	set=TopCold
	Set=Bra
	set=Underwear
	set=Heels
	Set=Shoes
	Set=Corset

;*******************************************************************
;* Sleep Procedure
;*******************************************************************
[question-SleepCold]
	text=What is the temperature like?
	?Hot=SleepHot
	?Warm=SleepWarm
	?Cold=SleepCold

[procedure-SleepHot]
	SetFlag=Hot
	RemoveFlag=Warm
	RemoveFlag=Cold
	clothing=Sleep Hot

[Clothing-Sleep Hot]
	Askable=1
	Change=Daily
	set=SleepHotFemale
	set=SleepHotMale
	Set=Collar
	Set=Cuffs
	Option=No Underwear

[procedure-SleepWarm]
	RemoveFlag=Hot
	SetFlag=Warm
	RemoveFlag=Cold
	clothing=Sleep Warm

[Clothing-Sleep Warm]
	Askable=1
	Change=Daily
	set=SleepWarmFemale
	set=SleepWarmMale
	set=Underwear
	Set=Collar
	Set=Cuffs

[procedure-SleepCold]
	RemoveFlag=Hot
	RemoveFlag=Warm
	SetFflag=Cold
	Clothing=Sleep Cold

[Clothing-Sleep Cold]
	Askable=1
	Change=Daily
	set=SleepColdFemale
	set=SleepColdMale
	Set=Bra
	set=Underwear
	Set=Collar
	Set=Cuffs

;*******************************************************************
;* Job Work Procedure
;*******************************************************************  
[Clothing-Work]
	Askable=1
	Change=Daily
	Option=Work Appropriate Clothing
	Set=Bra
	set=Underwear
	set=Heels
	Set=Shoes

;*******************************************************************
;* Exercise Procedure
;*******************************************************************

;*******************************************************************
;* Yard Work Procedure
;*******************************************************************

;*******************************************************************
;* Home Work Procedure
;*******************************************************************

;*******************************************************************
;* Clothing Sets - Bottom
;*******************************************************************
[set-BottomHotFemale]
	if=ClothingFemale
	select=all
		Choice=new
			Option=Skirt
				Check=Skirt
			Option=Mini-Skirt
				Check=Mini-Skirt
			Option=Shorts
				Check=Shorts
			Option=Sundress
				Check=Sundress

[set-BottomHomeHotFemale]
	if=ClothingFemale
	if=#CrossDress=1
	select=all
		Choice=new
			Option=Skirt
				Check=Skirt
			Option=Mini-Skirt
				Check=Mini-Skirt
			Option=Shorts
				Check=Shorts
			Option=Sundress
				Check=Sundress
			Option=No Pants

[set-BottomHomeHotMale]
	if=ClothingMale
	IfNotChosen=Skirt
	IfNotChosen=Mini-Skirt
	IfNotChosen=Shorts
	IfNotChosen=Sundress
	Select=All
		Choice=New
			Option=Shorts
				Check=Shorts
			Option=No Pants


[set-BottomHotMale]
	if=ClothingMale
	IfNotChosen=Skirt
	IfNotChosen=Mini-Skirt
	IfNotChosen=Shorts
	IfNotChosen=Sundress
	Select=All
		Choice=New
			Option=Shorts
				Check=Shorts

[set-BottomWarmFemale]
	if=ClothingFemale
	select=all
		Choice=new
			Option=Dress
				Check=Dress
			Option=Skirt
				Check=Skirt
			Option=Mini-Skirt
				Check=Mini-Skirt
			Option=Pants
				Check=Pants
			Option=Shorts
				Check=Shorts
			Option=Sundress

[set-BottomHomeWarmFemale]
	if=ClothingFemale
	if=#CrossDress=1
	select=all
		Choice=new
			Option=Dress
				Check=Dress
			Option=Skirt
				Check=Skirt
			Option=Mini-Skirt
				Check=Mini-Skirt
			Option=Pants
				Check=Pants
			Option=Shorts
				Check=Shorts
			Option=Sundress

[set-BottomWarmMale]
	if=ClothingMale
	IfNotChosen=Dress
	IfNotChosen=Skirt
	IfNotChosen=Pants
	IfNotChosen=Shorts
	IfNotChosen=Sundress
	Select=All
		Choice=New
			Option=Pants
				Check=Pants
			Option=Shorts
				Check=Shorts

[set-BottomColdFemale]
	if=ClothingFemale
	select=all
		Choice=new
			Option=Dress
				Check=Dress
			Option=Skirt
				Check=Skirt
			Option=Pants
				Check=Pants

[set-BottomHomeColdFemale]
	if=ClothingFemale
	if=#CrossDress=1
	select=all
		Choice=new
			Option=Dress
				Check=Dress
			Option=Skirt
				Check=Skirt
			Option=Pants
				Check=Pants

[set-BottomColdMale]
	if=ClothingMale
	IfNotChosen=Dress
	IfNotChosen=Skirt
	IfNotChosen=Pants
	Select=All
		Choice=New
			Option=Pants
				Check=Pants


;*******************************************************************
;* Clothing Sets - Top
;*******************************************************************
[set-TopHot]
	IfNotChosen=SUndress
	Select=All
		Choice=New
			Option=Light Shirt
				Check=LightShirt
			Option=T-Shirt
				Check=T-Shirt
			Option=Tank Top
				Check=TankTop

[set-TopHomeHot]
	IfNotChosen=SUndress
	Select=All
		Choice=New
			Option=Light Shirt
				Check=LightShirt
			Option=T-Shirt
				Check=T-Shirt
			Option=Tank Top
				Check=TankTop
			Option=No Top

[set-TopWarm]
	IfNotChosen=Dress
	IfNotChosen=SUndress
	Select=All
		Choice=New
			Option=Dress Shirt
				Check=DressShirt
			Option=T-Shirt
				Check=T-Shirt

[set-TopCold]
	IfNotChosen=Dress
	Select=All
		Choice=New
			Option=Dress Shirt
				Check=DressShirt
			Option=Sweater
				Check=Sweater

;*******************************************************************
;* Clothing Sets - Underwear
;*******************************************************************

[set-Underwear]
	IfNot=no_underwear
	Select=All
		Choice=New
			Option=No Underwear
			Option=Regular Underwear
				Check=Underwear
			Option=Sexy Underwear
				Check=Underwear
			Option=*

[set-Corset]
	IfNotChosen=Bustier
	notif=#ClothingCorset=0
	Select=All
		Choice=New
			Option=Corset
				Check=Corset
			Option=*
				Weight=3

[set-Bra]
	if=ClothingFemale
	Select=All
		Choice=New
			Option=Bra
				Check=Bra
			Option=No Bra
			Option=Bustier
				Check=Bra
			Option=*


[set-BraHome]
	if=ClothingFemale
	if=#CrossDress=1
	Select=All
		Choice=New
			Option=Bra
				Check=Bra
			Option=No Bra
			Option=Bustier
				Check=Bra
			Option=*

[Set-Heels]
	if=ClothingFemale
	Select=All
		Choice=New
			Option=Pumps
				Check=Shoes
				OptionSet=HeelHeight
			Option=Sandals
				Check=Shoes
				OptionSet=HeelHeight
			Option=*
		Choice=New
			IfChosen=Pumps
			IfChosen=Sandals
			Option=Knee-High Pantyhose
			Option=Thigh-High Pantyhose
			Option=Full-Length Pantyhose
			Option=*

[Set-HeelsHome]
	if=ClothingFemale
	if=#CrossDress=1
	Select=All
		Choice=New
			Option=Pumps
				Check=Shoes
				OptionSet=HeelHeight
			Option=Sandals
				Check=Shoes
				OptionSet=HeelHeight
			Option=*
		Choice=New
			IfChosen=Pumps
			IfChosen=Sandals
			Option=Knee-High Pantyhose
			Option=Thigh-High Pantyhose
			Option=Full-Length Pantyhose
			Option=*
			
[set-HeelHeight]
	Select=All
		Choice=New
			Option= - 1" Heels
			Option= - 2" Heels
			Option= - 3" Heels
			Option= - 4" Heels
			Option= - 5" Heels
			Option= - 6" Heels
			Option= - 7" Heels
			Option= - 8" Heels
			Option=*

[Set-Shoes]
	IfNotChosen=Pumps
	IfNotChosen=Sandals
	Select=All
		Choice=New
			Option=Tennis Shoes
				Check=Shoes
			Option=Boots
				Check=Shoes
			Option=Dress Shoes
				Check=Shoes
			Option=*
		Choice=New
			IfChosen=Tennis Shoes
			IfChosen=Boots
			IfChosen=Dress Shoes
			Option=Ankle Socks
			Option=Sports Socks
			Option=Knee Socks
			Option=*

;*******************************************************************
;* Clothing Sets - Sleep
;*******************************************************************
[set-SleepHotFemale]
	if=ClothingFemale
	if=#CrossDress=1
	select=all
		Choice=new
			Option=Babydoll
			Option=No Night Wear
			Option=*

[set-SleepHotMale]
	if=ClothingMale
	Select=All
		Choice=New
			Option=No Night Wear
			Option=*

[set-SleepWarmFemale]
	if=ClothingFemale
	if=#CrossDress=1
	select=all
		Choice=new
			Option=Babydoll
			Option=Chemise
			Option=Teddy
			Option=T-Shirt
			Option=No Night Wear
			Option=*

[set-SleepWarmMale]
	if=ClothingMale
	Select=All
		Choice=New
			Option=T-Shirt
			Option=No Night Wear
			Option=*

[set-SleepColdFemale]
	if=ClothingFemale
	if=#CrossDress=1
	select=all
		Choice=new
			Option=Chemise
			Option=Teddy
			Option=Pajamas
			Option=T-Shirt
			Option=No Night Wear
			Option=*


[set-SleepColdMale]
	if=ClothingMale
	Select=All
		Choice=New
			Option=Pajamas
			Option=T-shirt
			Option=No Night Wear
			Option=*

;*******************************************************************
;* Clothing Sets - Bondage Items
;*******************************************************************

[set-Cuffs]
	Select=All
		Choice=New
			Option=Wrist Cuffs
				OptionSet=WristChains
			Option=*
				Weight=5
		Choice=New
			Option=Ankle Cuffs
				OptionSet=AnkleChains
			Option=*
				Weight=5

[set-WristChains]
	Select=All
		Choice=New
			Option=Wrist Cuff Chains
			Option=*
				Weight=5

[set-AnkleChains]
	Select=All
		Choice=New
			Option=Ankle Cuff Chains
			Option=*
				Weight=5
	
[set-Collar]
	NotIf=#eCollarAny=0
	Select=All
		Choice=New
			Option=Steel Collar
			Option=Leather Collar
			Option=*
				Weight=5