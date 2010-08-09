;*******************************************************************
;* Popups
;*******************************************************************
[popupgroup-normal]
   	PopupInterval=00:05,03:00
   	PopupMessage=Yes {$zzMaster}
	PopupMaxTime=00:05
   	PopupSlowPenalty1=10
   	PopupSlowPenalty2=5
   	PopupSlowMessage=You must react faster when your {$zzMaster} calls. You are # late.

[popup-Message0]
	Weight=2
	message=You are the property of your {$zzMaster}.

[popup-Message1]
	Weight=2
	message=You are a slave, you have no will of your own.

[popup-Message2]
	Weight=2
	message=Your highest wish is to become the perfect slave.

[popup-Message3]
	Weight=2
	message=You will always dress according to your {$zzMaster}'s instructions.

[popup-Message4]
	Weight=2
	message=You must report everything to your {$zzMaster}.

[popup-Message5]
	Weight=2
	message=You must always obey your {$zzMaster}.

[popup-Message6]
	Weight=2
	message=Just checking to see if you were paying attention.

[popup-Message7]
	Weight=2
	message=Pi is not something you eat.

[popup-Message8]
	Weight=2
	message=A woodchuck can chuck 361.9237001 cubic cm of wood per day.

[popup-Message9]
	Weight=2
	message=The answer to the Ultimate Question of Life, the Universe, and Everything is 42.

[popup-Message10]
	Weight=2
	message=You will always make yourself available to your {$zzMaster}.

[popup-Message11]
	Weight=2
	message=Your {$zzMaster} is everything to you.

[popup-Message12]
	Weight=2
	message=You want to do everything your {$zzMaster} tells you to.

[popup-Message13]
	Weight=2
	Message=Don't forget to read everything in the rules menu.

;*******************************************************************
;* Feedback Popup
;*******************************************************************

[popup-Feedback]
	Weight=3
	Input=What are you thinking about right now?
	NoInputProcedure=NoInput

;*******************************************************************
;* Task Popup
;*******************************************************************

[popup-task]
	message=I will now provide you with a task to do, you must complete it as instructed.
	Procedure=PopupTask

[procedure-PopupTask]
	Select=Random
		Procedure=PopupTaskStretch
		Procedure=PopupTaskExercise
		Procedure=PopupTaskSilly
		Procedure=PopupTaskPain

[procedure-PopupTaskStretch]
	Message=You must stretch, instructions to follow.
	Message=Touch your toes then reach to the sky 10 times.
	Message=Kneel.
	Message=Stretch your hands out in front of you then return to kneeling position 10 times.
	Message=Stand up straight, arms to your sides.
	Message=Spread your legs.
	Message=Squat and hold for 10 seconds, do this 10 times.
	Message=Stand up straight, arms to your sides.
	Message=Bow and stretch your back 10 times.
	Message=Stretch your hands out to the sides.
	Message=Stand up straight, arms to your sides.
	Message=Reach to the sky.
	Message=Bend to the left then to the right stretching your sides, do this 10 times.
	Message=Stand up straight, arms to your sides.
	Message=You are done.

[procedure-PopupTaskExercise]
	Message=You must exercise, instructions to follow.
	Message=With your back straight press the palms of your hands together for 10 seconds. Rest and repeat 15 times.
	Message=Run from one end of the house to the other.
	Message=Run to every room in the house.
	Message=Run around the house/apartment.
	Message=Run to the end of the driveway and back.
	Message=Jog around the block (or equivilant distance).
	Message=Do 15 sit-ups.
	Message=Start lying face down on the floor with your forearms and elbows on the floor. Prop yourself up on your toes and forearms. Keeping your back straight and hips up, hold this position for 10 seconds. Rest and repeat 15 times.
	Message=Do 30 jumping jacks.
	Message=Lie flat on the floor. Pull yourself up into a crunch and hold position for 10 seconds. Slowly lie back down. Rest, and repeat 15 times.
	Message=Do 15 push-ups.
	Message=Stand next to a wall for balance. Raise your left leg so you are standing on just your right leg. Carefully stand up on your toes and hold position for 10 seconds. Slowly lower yourself back to flat-footed. Rest. Repeat 15 times then do the same with the left leg.
	Message=You are done. Tired much?
	
[procedure-PopupTaskSilly]
	Message=You must do silly tasks, instructions to follow.
	Message=Pat your head and rub your stomach 10 times.
	Message=Pull your ears out and puff up your cheeks like a monkey.
	Message=Put your right hand in.
	Message=Put your right hand out.
	Message=Put your right hand in.
	Message=Now shake it all about.
	Message=Do the hokey pokey and turn yourself around.
	Message=Thats what its all about. :)
	Message=Stick your finger up your nose and count to 10.
	Message=Jump up and down like a monkey 10 times.
	Message=Bark like a dog 10 times.
	Message=Good boy, scratch yourself behind the ear.
	Message=You are done, go wash your hands your finger was up your nose!

[procedure-PopupTaskPain]
	Message=I feel like making you hurt, instructions to follow.
	Message=Spank yourself 10 times on each cheek.
	Message=Slap yourself 10 times on each cheek.
	Message=Squeeze your nipples until it hurts.
	Message=Spank yourself with a wooden spoon 10 times on each cheek.
	Message=Spank yourself with a spatula 10 times on each cheek.
	Message=Slap yourself on each thigh 10 times.
	Message=Slap yourself on each calf 10 times.
	Message=Slap the bottom of each foot with a wooden spoon 10 times.
	Message=Slap yourself with a spatula on each arm 10 times.
	Message=Slap each palm of your hands with a wooden spoon 10 times.
	Message=You are done, hurts doesn't it?

;*******************************************************************
;* Bad Mood Popup
;*******************************************************************

[popup-Bad mood]
	If=#deltamerits>#zzmerits
   	message=I'm in a bad mood, take a punishment.
   	punish=1,15

;*******************************************************************
;* Popup Actions
;*******************************************************************