Dominant Configuration Guide

# Introduction #

To fully configure UVM you must edit certain files to take full advantage of the script.

# Details #

## UVM.ini ##

The first file is the UVM.ini file, this is the first file run and configures core information about the script.

The first section of the script says what the minimum version of Virtual Master is to be able to run this script. As well it shows what the current version of UVM is, if you are custom editing this script you can change the version number or append your own revision number on the end. For example: `Version=1.0 Beta 4 John 1.3`

```
[General]
	MinVersion=3.2
   	Version=1.0 Beta 4
```
The second part of the script denotes what the name of your virtual mistress and slave will be.
```
	Master=Virtual Mistress
   	SubName=slave
```
The third part defines what penalties will be for asking for a punishment, forgetting to ask permission, ignoring a permission that was denied, and what the maximum punishment can ever be. In this example AskPunishment will give a punishment as low as 10 merits, and no higher than 100 merits, forgetting to ask permission will result in a 50 point punishment, and doing something when it has been denied will be a 75 point punishment. These default values can be overriden in each confession if necessary.
```
	AskPunishment=10,100
   	ForgetPenalty=50
   	IgnorePenalty=75
	MaxPunishment=240
```
For UVM's purpose 0 is the lowest merits and 1000 is the highest. You may remove MinMerits or set it to a negative number if you want the sub to be able to go negative. However upon confessing to 'Had Orgasm Without Permission' will reset the subs merits to 0 and 'Request Permission to Orgasm' will cause the sub to loose any extra merits over 900 and be reset to 500.
```
	MinMerits=0
	MaxMerits=1000
```
By default the merit bar is devided into 3 parts, RED, YELLOW, and GREEN. The sub starts with a default of 500 merits in the yellow, if the sub falls below 333 merits the bar will turn red, above 666 the bar turns green.
When the bar is RED many permissions will be denied frequently or 100% of the time. Yellow is normal status. Green allows permissions to be permitted more often.
```
	Yellow=666
	Red=333
```
This is the default alarm option, if you wish to replace it with another .wav file change it here.
```
   	alarm=alarm.wav
```
By default ClothExport is set to on, in case the sub has to delete their status file they can export and import all the clothing they have put into the program before deleting it.
```
	ClothExport=1
```
A natural decay of merits was built into UVM, each day the sub looses 10 merits. Setting this to a lower negative number (i.e. -50) will increase the difficulty of reaching the goal.
```
	DayMerits=-10
```
If you are concerned that the sub may cheat and view code within the program you may want to set Restrict=1 and uncomment AutoEncrypt and ReportPassword (and set your own password) this will encrypt the sub's status file, script, and report so they cannot be viewed.
```
	Restrict=0
        ;AutoEncrypt=1
	;ReportPassword=xxx
```
The TestMenu option should only be used for your own testing purposes. This is documented in the Virtual Master manuals.
```
	TestMenu=0
```

## UVM\_Configuration.inc ##
This file provides several configuration options and overrides to a subs answer when they first start the program.

The first option is ClothCheck, a very strict clothing option. Only set this to 1 if the sub is **VERY WELL** versed in using the clothing options within Virtual Master, this is not recommended for beginners. Turning this on will punish the slave for every item they are **NOT** wearing. Extra clothing that has not been mentioned is allowed.
```
[procedure-init]
	set#=#ClothCheck,0
```
Under most circumstances people working a full-time job work 8 hours a day, +1 hour for lunch, and +2 hours for commute in both directions. Adjust this as necessary for your sub.
```
	;How many hours are allowed for work?
		set!=!WorkHours,11:00
```
Some Doms may wish to change the min/max merits or how many merits are required for the sub to have an orgasm.
```
	;How Many Credits Before Sub Can Come
		set#=#minCumMerits,900
```
The sub will be asked questions the first time the script is run, if you wish to override anything the sub sets you can do this here. Each time the program is launched these options are refreshed.
```
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
```
Advanced scripters may want to set up automatic mailing of reports, autoupdates of the script from an FTP server, and upload photos taken by the subs webcam. Uncomment and configure the sections below, they are fully documented in the Virtual Master documentation.
```
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
```