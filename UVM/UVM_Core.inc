;*******************************************************************
;* Header Information
;*******************************************************************
	TopText=Welcome {$zzSubname} to Talven's Ultimate Virtual Mistress {$zzSVersion}.
	TopText=Remember when performing tasks or bondage SAFTEY ABOVE ALL ELSE!
	TopText=-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
	TopText=This program will make sure you do sufficient activities before you are allowed an orgasm.
	TopText=You will need at least {#minCumMerits} merits before you even get a chance. Remember, extra work gets you extra points!
	TopText=Don't forget to sign in when necessary, by pressing reset in the lower right or you may be punished.
	TopText=-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
	TopText=Today you started with {#zzBeginMerits} merit points you currently have {#zzMerits}.
	TopText=The last punishment severity was: {#zzPunishmentSeverity}
	TopText=You last asked to: {$zzPermission}
	TopText=-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
	TopText=Status Messages:

;*******************************************************************
;* Footer Information
;*******************************************************************


;*******************************************************************
;* Startup Events
;*******************************************************************
[events]
	OpenProgram=RefreshCore
	CheckOn=CheckOn
	FirstRun=Configuration

[init]
	NewStatus=Normal
	Merits=500
	procedure=RefreshCore

[procedure-RefreshCore]
	RemoveFlag=ClothingMale
	RemoveFlag=ClothingFemale
	procedure=ClothingMale
	procedure=ClothingFemale
	procedure=init
	procedure=StatusRefresh

[procedure-StatusRefresh]
	SetFlag=StatusRefresh

[flag-StatusRefresh]
	Duration=00:01
	ReportFlag=0
	ExpireProcedure=StatusRefresh

[procedure-ClothingMale]
	if=#ClothingMale=1
	SetFlag=ClothingMale

[procedure-ClothingFemale]
	if=#ClothingFemale=1
	SetFlag=ClothingFemale

[procedure-Webcam]
	notif=#Webcam=0
	PoseCamera=Pose for your webcam.
	
	
;*******************************************************************
;* Normal
;*******************************************************************
[Status-Normal]
	SigninInterval=02:00
	SigninPenalty1=10
	SigninPenalty2=1
	group=Home
	popupgroup=Normal

;*******************************************************************
;* General Procedures
;*******************************************************************
[procedure-ResetMerits]
	set#=#deltamerits,500
	subtract#=#deltamerits,#zzmerits
	AddMerit=#deltamerits
	message=Putting you back at 500 merits. Good luck at getting back at {#minCumMerits} for your next orgasm, slave.

[procedure-Time-up]
	sound=alarm.wav
	message=The punishment time is up, I hope you have learned your lesson.

[procedure-NoInput]
	Message=You need to respond when your {$zzMaster} asks you a question.
	AddMerits=-1

;*******************************************************************
;* Sound Procedures
;*******************************************************************
[procedure-Sound_Chain]
	Sound=UVM_Sound_Chain.wav

[procedure-Sound_Gag]
	Sound=UVM_Sound_Gag.wav

[procedure-Sound_Kitchen]
	Sound=UVM_Sound_Kitchen.wav

[procedure-Sound_Vacuum]
	Sound=UVM_Sound_Vacuum.wav

[procedure-Sound_Whack]
	Sound=UVM_Sound_Whack.wav

[procedure-Sound_Whip]
	Sound=UVM_Sound_Whip.wav

[procedure-Sound_Writing]
	Sound=UVM_Sound_Writing.wav

;*******************************************************************
;* First-Run COnfiguration
;*******************************************************************
[procedure-Configuration]
	Message=TO THE EXTENT NOT PROHIBITED BY APPLICABLE LAW, IN NO EVENT SHALL THE SCRIPT WRITER BE LIABLE FOR PERSONAL INJURY, OR ANY INCIDENTAL, SPECIAL, INDIRECT OR CONSEQUENTIAL DAMAGES WHATSOEVER, INCLUDING, WITHOUT LIMITATION, DAMAGES FOR LOSS OF PROFITS, CORRUPTION OR LOSS OF DATA, FAILURE TO TRANSMIT OR RECEIVE ANY DATA, BUSINESS INTERRUPTION OR ANY OTHER COMMERCIAL DAMAGES OR LOSSES, ARISING OUT OF OR RELATED TO YOUR USE OF OR INABILITY TO USE THE UVM SCRIPT AND SERVICES OR ANY THIRD PARTY SOFTWARE OR APPLICATIONS IN CONJUNCTION WITH THE UVM SCRIPT, HOWEVER CAUSED, REGARDLESS OF THE THEORY OF LIABILITY (CONTRACT, TORT OR OTHERWISE) AND EVEN IF THE SCRIPT WRITER HAS BEEN ADVISED OF THE POSSIBILITY OF SUCH DAMAGES. YOU FURTHER ACKNOWLEDGE THAT THE UVM SCRIPT IS NOT INTENDED OR SUITABLE FOR USE IN SITUATIONS OR ENVIRONMENTS WHERE THE FAILURE OR TIME DELAYS OF, OR ERRORS OR INACCURACIES IN, THE CONTENT, DATA OR INFORMATION PROVIDED BY THE UVM SCRIPT COULD LEAD TO DEATH, PERSONAL INJURY, OR SEVERE PHYSICAL OR ENVIRONMENTAL DAMAGE, INCLUDING WITHOUT LIMITATION THE OPERATION OF NUCLEAR FACILITIES, AIRCRAFT NAVIGATION OR COMMUNICATION SYSTEMS, AIR TRAFFIC CONTROL, LIFE SUPPORT OR WEAPONS SYSTEMS.
	Question=cHousing
	Question=cWebcam
	Procedure=cWebcamNotice
	Question=cClothingMale
	Question=cClothingFemale
	Question=cCrossDress
	Question=cClothingCorset
	Question=cPublicHumiliation
	Question=cHogtie
	Question=cCollarAny
	ShowPicture=UVMImageBondageMittens.jpg
	Question=cBondageMittens
	RemovePicture=UVMImageBondageMittens.jpg
	ShowPicture=UVMImageSpreaderBar.jpg
	Question=cBarSpreader
	RemovePicture=UVMImageSpreaderBar.jpg
	Question=cBarX
	Question=cGag
	Question=cBelt
	Question=cNippleClamps
	Question=cWhip
	Question=cButtPlug
	Question=cButtPlugLarge
	Question=cDildo
	Question=cBlindfold
	Question=cHood
	Question=cChastityDevice
	Message=Keep in mind, your first day will be easy so you can get used to the script, read through the RULES menu. Most of your tasks will be assigned on the second day.

;*** General Questions ***

[question-cHousing]
	Text=Do you live in an apartment or house?
	?House=cHouse
	?Apartment=cApartment
	NoInputProcedure=cHouse

[procedure-cHouse]
	set#=#Housing,1

[procedure-cApartment]
	set#=#Housing,0

[question-cWebcam]
	Text=Do you have a webcam?
	?Yes=cWebcamYes
	?No=cWebcamNo

[procedure-cWebcamYes]
	set#=#Webcam,1

[procedure-cWebcamNo
	set#=#Webcam,0

[procedure-cWebcamNotice]
	if=#Webcam=1
	Message=It is recommeded that you use ManyCam to prevent webcam program conflicts. This is a free download available at manycam.com

[question-cClothingMale]
	Text=Do you want to wear male clothing in public?
	?Yes=cClothingMaleYes
	?No=cClothingMaleNo
	NoInputProcedure=cMaleYes

[procedure-cClothingMaleYes]
	set#=#ClothingMale,1

[procedure-cClothingMaleNo]
	set#=#ClothingMale,0

[question-cClothingFemale]
	Text=Do you want to wear female clothing in public?
	?Yes=cClothingFemaleYes
	?No=cClothingFemaleNo
	NoInputProcedure=cFemaleYes

[procedure-cClothingFemaleYes]
	set#=#ClothingFemale,1

[procedure-cClothingFemaleNo]
	set#=#ClothingFemale,0

[question-cCrossDress]
	Text=Are you willing to crossdress?
	?Yes=cCrossDressYes
	?No=cCrossDressNo

[procedure-cCrossDressNo]
	set#=#CrossDress,0

[procedure-cCrossDressYes]
	set#=#CrossDress,1

[question-cClothingCorset]
	Text=Do you have a corset?
	?Yes=cClothingCorsetYes
	?No=cClothingCorsetNo
	NoInputProcedure=cClothingCorsetYes

[procedure-cClothingCorsetYes]
	set#=#ClothingCorset,1

[procedure-cClothingCorsetNo]
	set#=#ClothingCorset,0

;*** Hard Limits ***

[question-cPublicHumiliation]
	Text=Do you want to be publically humiliated?
	?Yes, it's ok=cPublicHumiliationYes
	?No, Hard Limit=cPublicHumiliationNo
	NoInputProcedure=cPublicHumiliationYes

[procedure-cPublicHumiliationYes]
	set#=#pPublicHumiliation,1

[procedure-cPublicHumiliationNo]
	set#=#pPublicHumiliation,0

[question-cHogtie]
	Text=Can you safely be hogtied?
	?Yes, it's ok=cHogtieYes
	?No, Hard Limit=cHogtieNo
	NoInputProcedure=cHogtieYes

[procedure-cHogtieYes]
	set#=#pHogtie,1

[procedure-cHogtieNo]
	set#=#pHogtie,0

[question-cGag]
	Text=Can you be gagged without injury?
	?Yes, it's ok=cGagYes
	?No, Hard Limit=cGagNo
	NoInputProcedure=cGagYes

[procedure-cGagYes]
	set#=#pGag,1
	Question=cGagBall
	ShowPicture=UVMImageHarnessBallGag.jpg
	Question=cGagBallHarness
	RemovePicture=UVMImageHarnessBallGag.jpg
	ShowPicture=UVMImagePanelBallGag.jpg
	Question=cGagBallPanel
	RemovePicture=UVMImagePanelBallGag.jpg
	ShowPicture=UVMImageDroolGag.jpg
	Question=cGagDrool
	RemovePicture=UVMImageDroolGag.jpg
	ShowPicture=UVMImageInflatableGag.jpg
	Question=cGagInflatable
	RemovePicture=UVMImageInflatableGag.jpg
	Question=cGagMuzzle
	ShowPicture=UVMImageRingGag.jpg
	Question=cGagRing
	RemovePicture=UVMImageRingGag.jpg
	ShowPicture=UVMImageStuffedGag.jpg
	Question=cGagStuffed
	RemovePicture=UVMImageStuffedGag.jpg

[procedure-cGagNo]
	set#=#pGag,0

;*** Equipment Questions ***

[question-cCollarAny]
	Text=Do you have any collar?
	?Yes=cCollarAnyYes
	?No=cCollarAnyNo
	NoInputProcedure=cCollarAnyYes

[procedure-cCollarAnyYes]
	set#=#eCollarAny,1
	ShowPicture=UVMImagePostureCollar.jpg
	Question=cCollarPosture
	RemovePicture=UVMImagePostureCollar.jpg

[procedure-cCollarAnyNo]
	set#=#eCollarAny,0

[question-cCollarPosture]
	NotIf=#eCollarAny,0
	Text=Do you have a posture collar?
	?Yes=cCollarPostureYes
	?No=cCollarPostureNo
	NoInputProcedure=cCollarPostureYes

[procedure-cCollarPostureYes]
	set#=#eCollarPosture,1

[procedure-cCollarPostureNo]
	set#=#eCollarPosture,0

[question-cBondageMittens]
	Text=Do you have bondage mittens?
	?Yes=cBondageMittensYes
	?No=cBondageMittensNo
	NoInputProcedure=cBondageMittensYes

[procedure-cBondageMittensYes]
	set#=#eBondageMittens,1

[procedure-cBondageMittensNo]
	set#=#eBondageMittens,0

[question-cBarSpreader]
	Text=Do you have a spreader bar?
	?Yes=cBarSpreaderYes
	?No=cBarSpreaderNo
	NoInputProcedure=cBarSpreaderYes

[procedure-cBarSpreaderYes]
	set#=#eBarSpreader,1

[procedure-cBarSpreaderNo]
	set#=#eBarSpreader,0

[question-cBarX]
	Text=Do you have an X bar?
	?Yes=cBarXYes
	?No=cBarXNo
	NoInputProcedure=cBarXYes

[procedure-cBarXYes]
	set#=#eBarX,1

[procedure-cBarXNo]
	set#=#eBarX,0

[question-cGagBall]
	NotIf=#pGag,0
	Text=Do you have a ball gag?
	?Yes=cGagBallYes
	?No=cGagBallNo
	NoInputProcedure=cGagBallYes

[procedure-cGagBallYes]
	set#=#eGagBall,1

[procedure-cGagBallNo]
	set#=#eGagBall,0

[question-cGagBallHarness]
	NotIf=#pGag,0
	Text=Do you have a harness ball gag?
	?Yes=cGagBallHarnessYes
	?No=cGagBallHarnessNo
	NoInputProcedure=cGagBallHarnessYes

[procedure-cGagBallHarnessYes]
	set#=#eGagBallHarness,1

[procedure-cGagBallHarnessNo]
	set#=#eGagBallHarness,0

[question-cGagBallPanel]
	NotIf=#pGag,0
	Text=Do you have a panel ball gag?
	?Yes=cGagBallPanelYes
	?No=cGagBallPanelNo
	NoInputProcedure=cGagBallPanelYes

[procedure-cGagBallPanelYes]
	set#=#eGagBallPanel,1

[procedure-cGagBallPanelNo]
	set#=#eGagBallPanel,0

[question-cGagDrool]
	NotIf=#pGag,0
	Text=Do you have a drool gag?
	?Yes=cGagDroolYes
	?No=cGagDroolNo
	NoInputProcedure=cGagDroolYes

[procedure-cGagDroolYes]
	set#=#eGagDrool,1

[procedure-cGagDroolNo]
	set#=#eGagDrool,0

[question-cGagInflatable]
	NotIf=#pGag,0
	Text=Do you have an inflatable gag?
	?Yes=cGagInflatableYes
	?No=cGagInflatableNo
	NoInputProcedure=cGagInflatableYes

[procedure-cGagInflatableYes]
	set#=#eGagInflatable,1

[procedure-cGagInflatableNo]
	set#=#eGagInflatable,0

[question-cGagMuzzle]
	NotIf=#pGag,0
	Text=Do you have a muzzle gag?
	?Yes=cGagMuzzleYes
	?No=cGagMuzzleNo
	NoInputProcedure=cGagMuzzleYes

[procedure-cGagMuzzleYes]
	set#=#eGagMuzzle,1

[procedure-cGagMuzzleNo]
	set#=#eGagMuzzle,0

[question-cGagRing]
	NotIf=#pGag,0
	Text=Do you have a ring gag?
	?Yes=cGagRingYes
	?No=cGagRingNo
	NoInputProcedure=cGagRingYes

[procedure-cGagRingYes]
	set#=#eGagRing,1

[procedure-cGagRingNo]
	set#=#eGagRing,0

[question-cGagStuffed]
	NotIf=#pGag,0
	Text=Do you have a stuffed gag?
	?Yes=cGagStuffedYes
	?No=cGagStuffedNo
	NoInputProcedure=cGagStuffedYes

[procedure-cGagStuffedYes]
	set#=#eGagStuffed,1

[procedure-cGagStuffedNo]
	set#=#eGagStuffed,0

[question-cBelt]
	Text=Do you have a belt?
	?Yes=cBeltYes
	?No=cBeltNo
	NoInputProcedure=cBeltYes

[procedure-cBeltYes]
	set#=#eBelt,1

[procedure-cBeltNo]
	set#=#eBelt,0

[question-cNippleClamps]
	Text=Do you have any nipple clamps?
	?Yes=cNippleClampsYes
	?No=cNippleClampsNo
	NoInputProcedure=cNippleClampsYes

[procedure-cNippleClampsYes]
	set#=#eNippleClamps,1
	ShowPicture=UVMImageCloverNippleClamps.jpg
	Question=cNippleClampsClover
	RemovePicture=UVMImageCloverNippleClamps.jpg

[procedure-cNippleClampsNo]
	set#=#eNippleClamps,0

[question-cNippleClampsClover]
	NotIf=#eNippleClamps,0
	Text=Do you have clover nipple clamps?
	?Yes=cNippleClampsCloverYes
	?No=cNippleClampsCloverNo
	NoInputProcedure=cNippleClampsCloverYes

[procedure-cNippleClampsCloverYes]
	set#=#eNippleClampsClover,1

[procedure-cNippleClampsCloverNo]
	set#=#eNippleClampsClover,0

[question-cWhip]
	Text=Do you have a whip?
	?Yes=cWhipYes
	?No=cWhipNo
	NoInputProcedure=cWhipYes

[procedure-cWhipYes]
	set#=#eWhip,1

[procedure-cWhipNo]
	set#=#eWhip,0

[question-cButtPlug]
	Text=Do you have a small butt plug?
	?Yes=cButtPlugYes
	?No=cButtPlugNo
	NoInputProcedure=cButtPlugYes

[procedure-cButtPlugYes]
	set#=#eButtPlug,1

[procedure-cButtPlugNo]
	set#=#eButtPlug,0

[question-cButtPlugLarge]
	Text=Do you have a large butt plug?
	?Yes=cButtPlugLargeYes
	?No=cButtPlugLargeNo
	NoInputProcedure=cButtPlugLargeYes

[procedure-cButtPlugLargeYes]
	set#=#eButtPlugLarge,1

[procedure-cButtPlugLargeNo]
	set#=#eButtPlugLarge,0

[question-cDildo]
	Text=Do you have a dildo?
	?Yes=cDildoYes
	?No=cDildoNo
	NoInputProcedure=cDildoYes

[procedure-cDildoYes]
	set#=#eDildo,1

[procedure-cDildoNo]
	set#=#eDildo,0

[question-cBlindfold]
	Text=Do you have a blindfold?
	?Yes=cBlindfoldYes
	?No=cBlindfoldNo
	NoInputProcedure=cBlindfoldYes

[procedure-cBlindfoldYes]
	set#=#eBlindfold,1

[procedure-cBlindfoldNo]
	set#=#eBlindfold,0

[question-cHood]
	Text=Do you have a hood?
	?Yes=cHoodYes
	?No=cHoodNo
	NoInputProcedure=cHoodYes

[procedure-cHoodYes]
	set#=#eHood,1

[procedure-cHoodNo]
	set#=#eHood,0

[question-cChastityDevice]
	Text=Do you have a chastity device?
	?Yes=cChastityDeviceYes
	?No=cChastityDeviceNo
	NoInputProcedure=cChastityDeviceYes

[procedure-cChastityDeviceYes]
	set#=#eChastityDevice,1

[procedure-cChastityDeviceNo]
	set#=#eChastityDevice,0