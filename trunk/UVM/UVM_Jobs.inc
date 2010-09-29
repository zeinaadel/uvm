;*******************************************************************
;* Jobs
;*******************************************************************
[procedure-AddWorkMerits]
	AddMerit=#zzLate

;*******************************************************************
;* Personal Care
;*******************************************************************
[status-Personal_Care]
	substatus=1
	group=home
	PointCamera=Point the camera where you will be doing your personal care (if possible).
	CameraInterval=00:01,00:10
	Text=Report to me when finished.

[job-Brush Your Teeth]
	Run=daily
	NewStatus=Personal_Care
	muststart=1
	MinTime=00:03
	QuickPenalty1=6
	QuickPenalty2=3
	RemindPenalty=6
	AddMerit=3
	Text=Minimum Duration: {!zzMinTime} | Completed: {!zzRunTime}

[job-Exercise]
	interval=5,7
	respit=5d
	NewStatus=Personal_Care
	muststart=1
	MinTime=00:15
	QuickPenalty1=30
	QuickPenalty2=5
	MaxTime=00:15
	SlowProcedure=AddWorkMerits
	RemindPenalty=30
	AddMerit=15
	Text=Minimum Duration: {!zzMinTime} | Completed: {!zzRunTime}

[job-Body Grooming]
	interval=7,14
	respit=5d
	NewStatus=Personal_Care
	muststart=1
	MinTime=00:15
	QuickPenalty1=30
	QuickPenalty2=5
	MaxTime=00:15
	SlowProcedure=AddWorkMerits
	RemindPenalty=30
	AddMerit=15
	Text=Minimum Duration: {!zzMinTime} | Completed: {!zzRunTime}

;*******************************************************************
;* House Work
;*******************************************************************
[status-House_Work]
	substatus=1
	group=home
	Text=Report to me when finished.
	PointCamera=Point the camera where you will be doing your house work (if possible).
	CameraInterval=00:01,00:10

[job-Take out The Garbage]
	interval=7
	Respit=7d
	NewStatus=house_work
	muststart=1
	MinTime=00:03
	QuickPenalty1=6
	QuickPenalty2=3
	MaxTime=00:03
	SlowProcedure=AddWorkMerits
	RemindPenalty=6
	AddMerit=3
	Text=Minimum Duration: {!zzMinTime} | Completed: {!zzRunTime}

[job-General Cleaning]
	interval=5,7
	respit=5d
	NewStatus=house_work
	muststart=1
	MinTime=00:10
	QuickPenalty1=20
	QuickPenalty2=5
	MaxTime=00:10
	SlowProcedure=AddWorkMerits
	RemindPenalty=20
	AddMerit=10
	Text=Minimum Duration: {!zzMinTime} | Completed: {!zzRunTime}

[job-Clean the kitchen]
	interval=2,3
	respit=2d
	NewStatus=house_work
	muststart=1
	MinTime=00:10
	QuickPenalty1=20
	QuickPenalty2=5
	MaxTime=00:10
	StartProcedure=Sound_Kitchen
	SlowProcedure=AddWorkMerits
	RemindPenalty=20
	AddMerit=10
	Text=Minimum Duration: {!zzMinTime} | Completed: {!zzRunTime}

[job-Clean the bathroom]
	interval=5,7
	respit=5d
	NewStatus=house_work
	muststart=1
	MinTime=00:10
	QuickPenalty1=20
	QuickPenalty2=10
	MaxTime=00:10
	SlowProcedure=AddWorkMerits
	RemindPenalty=20
	AddMerit=10
	Text=Minimum Duration: {!zzMinTime} | Completed: {!zzRunTime}

[job-Vacuum and mop the house]
	interval=5,7
	respit=5d
	NewStatus=house_work
	muststart=1
	MinTime=00:10
	QuickPenalty1=20
	QuickPenalty2=5
	MaxTime=00:10
	StartProcedure=Sound_Vacuum
	SlowProcedure=AddWorkMerits
	RemindPenalty=20
	AddMerit=10
	Text=Minimum Duration: {!zzMinTime} | Completed: {!zzRunTime}

[job-Clean the living room]
	interval=3,7
	respit=3d
	NewStatus=house_work
	muststart=1
	MinTime=00:10
	QuickPenalty1=20
	QuickPenalty2=5
	MaxTime=00:10
	SlowProcedure=AddWorkMerits
	RemindPenalty=20
	AddMerit=10
	Text=Minimum Duration: {!zzMinTime} | Completed: {!zzRunTime}

[job-Clean the side room]
	notif=#Housing=0
	interval=14,30
	respit=7d
	NewStatus=house_work
	muststart=1
	MinTime=00:15
	QuickPenalty1=30
	QuickPenalty2=5
	MaxTime=00:15
	SlowProcedure=AddWorkMerits
	RemindPenalty=30
	AddMerit=15
	Text=Minimum Duration: {!zzMinTime} | Completed: {!zzRunTime}

[job-Clean the bedroom]
	interval=14,30
	respit=7d
	NewStatus=house_work
	muststart=1
	MinTime=00:15
	QuickPenalty1=30
	QuickPenalty2=5
	MaxTime=00:15
	SlowProcedure=AddWorkMerits
	RemindPenalty=30
	AddMerit=15
	Text=Minimum Duration: {!zzMinTime} | Completed: {!zzRunTime}

[job-Do a load of laundry]
	interval=3,5
	respit=3d
	NewStatus=house_work
	muststart=1
	MinTime=00:03
	QuickPenalty1=6
	QuickPenalty2=5
	MaxTime=00:03
	RemindPenalty=6
	AddMerit=5
	Text=Minimum Duration: {!zzMinTime} | Completed: {!zzRunTime}
	DoneProcedure=FoldLaundry
	
[procedure-FoldLaundry]
	Job=Fold the Laundry
	
[job-Fold the Laundry]
	respit=01:30
	NewStatus=house_work
	muststart=1
	MinTime=00:10
	MaxTime=00:15
	QuickPenalty1=20
	QuickPenalty2=5
	RemindPenalty=10
	AddMerit=10
	Text=Minimum Duration: {!zzMinTime} | Completed: {!zzRunTime}

;*******************************************************************
;* Yard Work
;*******************************************************************
[status-Yard_Work]
	substatus=1
	group=home
	Text=Report to me when finished.
	PointCamera=Point the camera where you will be doing your yard work (if possible).
	CameraInterval=00:01,00:10

[job-Clean the garage or car]
	notif=#Housing=0
	interval=5,7
	respit=5d
	NewStatus=Yard_Work
	muststart=1
	MinTime=00:15
	QuickPenalty1=30
	QuickPenalty2=5
	MaxTime=00:15
	SlowProcedure=AddWorkMerits
	RemindPenalty=30
	AddMerit=15
	Text=Minimum Duration: {!zzMinTime} | Completed: {!zzRunTime}

[job-Do yard work]
	notif=#Housing=0
	interval=5,7
	respit=5d
	NewStatus=Yard_work
	muststart=1
	MinTime=00:15
	QuickPenalty1=30
	QuickPenalty2=5
	MaxTime=00:15
	SlowProcedure=AddWorkMerits
	RemindPenalty=30
	AddMerit=15
	Text=Minimum Duration: {!zzMinTime} | Completed: {!zzRunTime}