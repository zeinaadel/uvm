[procedure-init]
	;Do you want the sub to be punished for not wearing the proper clothing?
	;Keep in mind the sub will need to know well how the clothing sections work
	;This is only recommended for Virtual Master vetrans and strict clothing control.
	set#=#ClothCheck,0

	;How many hours are allowed for work?
		set!=!WorkHours,10:00

	;How Many Credits Before Sub Can Come
		set#=#minCumMerits,900


;*******************************************************************
;* ADVANCED CONFIGURATION BELOW THIS LINE
;*******************************************************************

;*******************************************************************
;* Configuration Overrides
;* The sub will be asked questions on first run, if you want to
;* force an answer uncomment the variable below.
;*******************************************************************
	;Housing options, 1 for house 0 for apartment.
		;set#=#Housing,1

	;Webcam
		;set#=#Webcam,1

	;Clothing Options
		;Do you want to wear male, female, or both types of clothing in public?
		;set#=#ClothingMale,1
		;set#=#ClothingFemale,1

		;Should the sub cross dress while at home?
		;set#=#CrossDress,1

	;Punishment Types and Hard Limits.
	;Different People Have Different Limitations, medical conditions, etc.
		;set#=#pPublicHumiliation,1
		;set#=#pHogtie,1
		;set#=#pGag,1

	;What equipment do you have?
	;Any means do you have any of the following types.
		;Collars
		;set#=#eCollarAny,1
		;set#=#eCollarPosture,1

		;Cuffs
		;set#=#eBondageMittens,1
		;set#=#eBarSpreader,1
		;set#=#eBarX,1

		;Gags
		;set#=#eGagBall,1
		;set#=#eGagBallHarness,1
		;set#=#eGagBallPanel,1
		;set#=#eGagDrool,1
		;set#=#eGagInflatable,1
		;set#=#eGagMuzzle,1
		;set#=#eGagRing,1
		;set#=#eGagStuffed,1

		;Punishment Devices
		;set#=#eBelt,1
		;set#=#eNippleClamps,1
		;set#=#eNippleClampsClover,1
		;set#=#eWhip,1

		;Sex Toys
		;set#=#eButtPlug,1
		;set#=#eButtPlugLarge,1
		;set#=#eDildo,1

		;Misc
		;set#=#eBlindfold,1
		;set#=#eHood,1
		;set#=#eChastityDevice,1

;*******************************************************************
;* Mail Configuration
;*******************************************************************
;	Note that the master/mistress can set up a free gmail account to send/recieve reports.
;
;	AutoMailReport=1
;	smtp=smtp.mymailserver.com
;	smtpPort=
;	smtpUser=
;	smtpPassword=
;	masterEmail=
;	masterEmail2=
;	subEmail=
;	MasterMail=SubReport
;	MasterAttach=

;*******************************************************************
;* Auto Update and Report
;*******************************************************************
;[FTP]
;	URL=
;	ftpUser=
;	ftpPassword=
;	ftpServerType=unix
;	ftpDir=/
;	UpdateScript=Restart
;	UpdateProgram=Restart
;	SendReports=0
;	SendPictures=0
;	ftpLog=1
;	TestFtp=1