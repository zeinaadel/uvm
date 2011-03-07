;*******************************************************************
;* Permission - Toilet
;*******************************************************************
[permission-Go to the toilet]
	PreStatus=home
	pct=90
	NewSubStatus=toilet
	EndText=Finished toilet
	Delay=00:01,00:05
	MaxWait=00:05
	Notify=1
	MinInterval=00:30

[status-toilet]
	Substatus=1
	MaxTime=00:10
	SlowPenalty1=10
	SlowPenalty2=1
	Text={!zzStartTime} Use the toilet, you have 10 min. report to me when finished.

;************************************************************************
;*** Permission - TV
;************************************************************************
[permission-Watch TV or Play a Video Game]
	PreStatus=normal
	NewStatus=TV
  	pct=75
	LowMerits=#zzYellow
	LowPct=37
	DenyBelow=#zzRed
	Delay=00:05,00:15
	Addmerit=-30
	ForgetPenalty=120
	IgnorePenalty=180

[status-TV]
	group=home
	SigninInterval=01:00
	SigninPenalty1=10
	SigninPenalty2=1
	MaxTime=04:00
	SlowPenalty1=10
	SlowPenalty2=1
	text=You may now watch TV or play a video game for up to 4 hours. Time Passed: {!zzRunTime}
	text=Report when you have finished and turned everything off.

[report-TV is now turned off]
	PreStatus=TV
	NewStatus=Normal
	OnTop=1
	input=What did you watch?
	NoInputProcedure=NoInput

;************************************************************************
;*** Permission - Internet
;************************************************************************
[permission-Browse the web / chat / play game]
	PreStatus=normal
	NewStatus=Internet
  	pct=75
	LowMerits=#zzYellow
	LowPct=37
	DenyBelow=#zzRed
	Delay=00:05,00:15
	MinInterval=2:00
	ForgetPenalty=120
	IgnorePenalty=180

[status-Internet]
	group=home
	SigninInterval=00:30
	SigninPenalty1=10
	SigninPenalty2=1
	MaxTime=02:00
	SlowPenalty1=10
	SlowPenalty2=1
	text=You may now browse the internet for up to 2 hours. Time Elapsed: {!zzRunTime}
	text=Report when you have finished and closed.

[report-Done Browsing the Internet]
	PreStatus=Internet
	NewStatus=Normal
	OnTop=1
	input=What did you do on the internet?
	NoInputProcedure=NoInput

;*******************************************************************
;* Permission - Eat
;*******************************************************************
[permission-Eat]
	PreStatus=normal
	NewStatus=Eating
	instructions=eat
	pct=80
	Delay=00:02,00:10
	MaxWait=00:30
	MinInterval=04:00
	Notify=1
	ForgetPenalty=60
	IgnorePenalty=90

[permission-Have a Snack]
	instructions=eat
	pct=80
	Delay=00:02,00:30
	MaxWait=01:00
	MinInterval=02:00
	addmerits=-10

[Instructions-Eat]
	Askable=0
	change=Program
	none=No Special Instructions
	choice=new
		option=Eat standing at the table
		option=Eat sitting on the floor
		option=*
			weight=5
	choice=new
		option=Eat out of a dog dish or bowl
		option=Eat with your fingers only
		option=You may only use a spoon
		option=Use only a fork or spoon
		option=You may use cutlery
			weight=6

[status-Eating]
	substatus=1
	group=home
	text={!zzStartTime} Eat your meal or snack now.
	text=Report to me when finished.

[report-Finished my meal]
	PreStatus=Eating
	NewStatus=Normal
	ontop=1
	rules=0

;************************************************************************
;* Permission - Bath / Shower
;************************************************************************
[permission-Take a hot bath/shower]
	DenyIf=ColdShower
	PreStatus=Normal
	NewSubStatus=Hot_bath
	pct=90
	LowMerits=#zzYellow
	LowPct=45
	DenyBelow=#zzRed
	Delay=08:00
	MaxWait=24:00
	MinInterval=08:00
	DenyStatus=Cold_bath
	EndText=Finished bath
	Addmerit=-10
	ForgetPenalty=60
	IgnorePeanlty=90
	
[permission-Take a cold bath/shower]
	PreStatus=Normal
	NewSubStatus=Cold_Bath
	Pct=100
	Delay=08:00
	MaxWait=24:00
	MinInterval=08:00
	EndText=Finished cold bath

[status-Hot_Bath]
	SubStatus=1
	text=Take your bath/shower now.
	text=You have 30 minutes, to shower, dress and get ready. {!zzRunTime}
	text=Report to me when finished.
	MaxTime=00:30
	SlowPenalty1=10
	SlowPenalty2=1

;[report-Finished Cold Bath]
;	PreStatus=Cold_Bath
;	NewStatus=Normal
;	ontop=1
;	rules=0

[status-Cold_Bath]
	SubStatus=1
	text={!zzStartTime} Take a cold bath/shower now.
	text=You have 30 minutes, to shower, dress and get ready. {!zzRunTime}
	text=Report to me when finished.
	MaxTime=00:30
	SlowPenalty1=10
	SlowPenalty2=1

;*******************************************************************
;* Permission - Orgasm
;*******************************************************************
[permission-Have an orgasm]
	Pct=100	
	ForgetPenalty=#zzMerits
	IgnorePenalty=#zzMerits
	NotIf=Chaste
	NotIf=already_edged
	DenyIf=#zzMerits<#minCumMerits
	MinInterval=24:00
	SetFlag=permission_to_cum
	instructions=orgasm

[Instructions-Orgasm]
	Askable=0
	change=Daily
	none=No Special Instructions
	choice=new
		option=Visual Aide: Pictures
		option=Visual Aide: Video
		option=Visual Aide: Only Your Imagination
		option=*
	choice=new
		option=Stimulation: Vibrator
		option=Stimulation: Hand Only
		option=*

[flag-permission_to_cum]
	Text=You have permission to have an orgasm within the next hour. Report when you had one.
	Duration=01:00
	ExpireMessage=Your chance for an orgasm has gone. I don't want you to ask too far in advance.
	
[flag-already_edged]
	Text=You may not get merits for bringing yourself to the edge of orgasm at this time.
	Duration=01:00

[procedure-Edging]
	NotIf=already_edged
	message=Well done frustrating yourself!
	SetFlag=already_edged
	AddMerit=10

[confession-Had an orgasm without permission]
	message=This is VERY disappointing and defeats the whole purpose of my training. I will give you a severe punishment and set your merits to 0.
	;Option - Merits revert to 0 instead of 500
	;set#=#deltamerits,0
	;OPtion- Subtract starting merits from current merits.
	;subtract#=#deltamerits,#zzmerits
	;Option - Punishment
	procedure=BadOrgasm
	punish=#zzmerits
	PunishmentGroup=wanker
	;Option - Set merits to 0
	SetMerits=0
	
[procedure-BadOrgasm]
	set#=#PunishMerits,#zzMerits
	devide#=#PunishMerits,2
	punish=#PunishMerits
	
;*******************************************************************
;* Permission - Extra Work
;*******************************************************************
[permission-Do Extra Work]
   	PreStatus=home
	HighMerits=#zzYellow
	HighPct=25
   	pct=50
	LowMerits=#zzRed
	LowPct=75
   	MinInterval=00:01
   	Delay=08:00
	Message=I am assigning you extra General Cleaning.
	Job=General Cleaning

;*******************************************************************
;* Permissions - Sit
;*******************************************************************
[permission-Sit on Furniture]
	PreStatus=home
	pct=75
	LowMerits=#zzYellow
	LowPct=37
	DenyBelow=#zzRed
	MinInterval=01:00
	Delay=00:05,00:30
	SetFlag=Sit
	Addmerit=-1
	ForgetPenalty=10
	IgnorePenalty=20

[flag-Sit]
	Text=You may sit on furniture, within the next hour. Time Elapsed: {!zzRunTime}
	Duration=01:00
	ExpireMessage=You can no longer sit on furniture without requesting permission.

;*******************************************************************
;* Permissions - Other
;*******************************************************************
[permission-Drink One Glass of Juice]
   	PreStatus=home
   	pct=85
   	MinInterval=00:15
   	Delay=00:05,00:30
	MaxWait=01:00
   	AddMerit=1
	Notify=1

[permission-Drink One Glass of Water]
   	PreStatus=home
   	pct=99
   	MinInterval=00:15
   	Delay=00:05
	MaxWait=01:00
	Notify=1

[permission-Drink One Cup of Coffee/Tea]
   	PreStatus=home
   	pct=80
	LowMerits=#zzYellow
	LowPct=40
	DenyBelow=#zzRed
   	MinInterval=00:15
   	Delay=00:01,00:15
	MaxWait=01:00
   	AddMerit=-5

[permission-Drink One Soda/Energy Drink]
   	PreStatus=home
   	pct=70
	LowMerits=#zzYellow
	LowPct=35
	DenyBelow=#zzRed
   	MinInterval=00:15
   	Delay=00:01,00:15
	MaxWait=01:00
   	AddMerit=-10
	ForgetPenalty=100
	IgnorePenalty=150

[permission-Drink One Glass of Alcohol]
   	PreStatus=home
   	pct=50
	LowMerits=#zzYellow
	LowPct=25
	DenyBelow=#zzRed
   	MinInterval=00:30
   	Delay=00:01,0:30
	MaxWait=02:00
   	AddMerit=-15
	ForgetPenalty=150
	IgnorePenalty=225

[permission-Smoke One Cigarette]
	PreStatus=home
   	pct=70
	LowMerits=#zzYellow
	LowPct=35
	DenyBelow=#zzRed
   	MinInterval=01:00
   	Delay=00:01,00:15
   	MaxWait=02:00
   	AddMerit=-5