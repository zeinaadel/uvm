;*******************************************************************
;* Reports
;*******************************************************************
[report-SAFEWORD - BACK TO NORMAL]
	input=Why did you use your safeword???
	NoInputProcedure=NoInput
	NewStatus=normal
	rules=0

[report-RERUN CONFIGURATION]
	PreStatus=Normal
	Procedure=Configuration

[Report-Brought myself to the brink of orgasm]
	NotIf=Chaste
	NotIf=permission_to_cum
	NotIf=already_edged
	procedure=edging

[Report-Had an orgasm]
	If=permission_to_cum
	NotIf=Chaste
	NotIf=already_edged
	RemoveFlag=permission_to_cum
	procedure=resetMerits

[report-Changed clothes]
   	PreStatus=Normal
   	Procedure=ClothReport

[Report-Did extra house or yard work]
	PreStatus=Normal
	input#=#minutes,How many minutes did you do extra house work?
	multiply#=#minutes,1
	AddMerit=#minutes	
	
;*******************************************************************
;* Status - Sleep
;*******************************************************************
[report-Go to Bed]
	PreStatus=normal
   	NewStatus=sleeping
	Question=SleepCold
	Procedure=ClothReport
   	instructions=Sleep

[status-Sleeping]
   	group=home
   	Text=Go to sleep you have 10 hours. Report when up.

[report-Up from bed]
   	PreStatus=sleeping
   	NewStatus=normal
	Question=StayingHome
	Procedure=ClothReport

[Instructions-Sleep]
	Askable=0
	change=Daily
	none=No special instructions
	choice=new
		option=Use no blanket
		option=Leave the curtains open
		option=*
			weight=5
	choice=new
		option=Sleep in your bed
			weight=5
		option=Sleep on the couch
			weight=2
		option=Sleep on the floor
		option=Sleep outside (if weather permits)
		option=Sleep in kennel, box, or pet-bed
		option=*
		weight=1

;*******************************************************************
;* Status - Working
;*******************************************************************
[report-Go to Work]
   PreStatus=Normal
   NewStatus=On_job
   Clothing=Work

[status-On_job]
	text=Go to work now.
	text=Report immediately when you are back.
	text=You have {!WorkHours} hours for work and travel in both directions.
	MaxTime=!WorkHours
	SlowPenalty1=10
	SlowPenalty2=1

[report-Home from job]
	PreStatus=On_job
	NewStatus=normal
	ontop=1
	input=Did you come directly home from work?
	NoInputProcedure=NoInput
	Question=EveCold
	Procedure=ClothReport	

;*******************************************************************
;* Status - Going out
;*******************************************************************
[status-Out]
	text=Report immediately when you are back.

[report-Leaving home]
	PreStatus=Normal
	NewStatus=Out
	Question=OutCold
	Procedure=ClothReport

[report-Going to a Party]
	DenyBelow=#zzRed
	PreStatus=Normal
	NewStatus=Out
	Question=OutCold
	Procedure=ClothReport
	AddMerits=-75

[report-Home again]
	prestatus=Out
	NewStatus=Normal
	OnTop=1
	question=VanillaGuests
	Procedure=ClothReport

;************************************************************************
;* Status - Guests
;************************************************************************
[report-Receiving Guests]
	PreStatus=home
	NewStatus=Guests
	question=VanillaGuests
	Procedure=ClothReport
	PgmAction=Minimize

[status-Guests]
	group=home
	text=Report immediately when your guests have left

[report-Guests have left]
	prestatus=guests
	newstatus=normal
	ontop=1
	input=Who were the guest(s)?
	NoInputProcedure=NoInput
	Question=HomeCold
	Procedure=ClothReport

;************************************************************************
;* Status - Ill or Going On Vacation
;************************************************************************
[Report-Ill or Going On Vacation]
	PreStatus=Normal
	NewStatus=Vacation
	PgmAction=Pause

[status-Vacation]
	text=Report immediatly when feeling better or back from vacation.	

[report-No Longer Ill or On Vacation]
	PreStatus=Vacation
	NewStatus=Normal
	ontop=1
	input=What type of sickness did you have or where did you go on vacation?
	NoInputProcedure=NoInput

;*******************************************************************
;* Confessions
;*******************************************************************
[confession-Did not wear exactly what was demanded of clothing]
	notif=#ClothCheck,1
	input#=#NotWorn,How many pieces of clothing did you not wear?
	multiply#=#NotWorn,5
	punish=#NotWorn

[confession-Did something wrong during a punishment]
	Message=The point of a punishement is to teach you a lesson, apparently you did not learn. Why did you not complete the punishment properly?
	AddMerit=-50
	multiply#=#zzPunishmentSeverity,2
	punish=#zzPunishmentSeverity
